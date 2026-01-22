#include "dtsu666.h"


ModbusMaster node1;

void Init_dtsu666(){
    Serial1.begin(default_baudrate, SERIAL_8N1, RX_Pin, TX_Pin);
    node1.begin(dtsu_slaveid, Serial1);
}


float Read_Voltage_A(){
    Data_Convert Voltage;
    uint8_t result = node1.readHoldingRegisters(UA_H, 2);
    if (result == node1.ku8MBSuccess) {
        Voltage.u32 = ((uint32_t)node1.getResponseBuffer(0) << 16)| node1.getResponseBuffer(1);
        return Voltage.f;
    }
    return READ_ERROR;
}

float Read_Voltage_B(){
    Data_Convert Voltage;
    uint8_t result = node1.readHoldingRegisters(UB_H, 2);
    if (result == node1.ku8MBSuccess) {
        Voltage.u32 = ((uint32_t)node1.getResponseBuffer(0) << 16)| node1.getResponseBuffer(1);
        return Voltage.f;
    }
    return READ_ERROR;
}

float Read_Voltage_C(){
    Data_Convert Voltage;
    uint8_t result = node1.readHoldingRegisters(UC_H, 2);
    if (result == node1.ku8MBSuccess) {
        Voltage.u32 = ((uint32_t)node1.getResponseBuffer(0) << 16)| node1.getResponseBuffer(1);
        return Voltage.f;
    }
    return READ_ERROR;
}