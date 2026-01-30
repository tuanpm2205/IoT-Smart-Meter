#include "PZEM_016.h"

ModbusMaster node_pzem;

void Init_Pzem(void){
    Serial2.begin(default_baudrate_pzem, SERIAL_8N1, RX_Pin_pzem, TX_Pin_pzem);
    node_pzem.begin(pzem_slaveid, Serial2);
}

uint16_t Read_Input_Reg(uint16_t reg){
    uint8_t result = node_pzem.readInputRegisters(reg, 1); // 0x04 function
    if (result == node_pzem.ku8MBSuccess) {
        return node_pzem.getResponseBuffer(0);
    }
    return READ_ERROR;
}

float PZEM_Read_Voltage(void){
    return (float)Read_Input_Reg(REG_VOLTAGE)/10.0;
}

float PZEM_Read_Current(void){
    uint16_t high, low;
    low = Read_Input_Reg(REG_CURRENT_L);
    high = Read_Input_Reg(REG_CURRENT_H);
    return (((uint32_t)high << 16) | low)/1000.0;
}

