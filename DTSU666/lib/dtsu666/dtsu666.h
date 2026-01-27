#ifndef __DTSU666
#define __DTSU666

#include <stdint.h>
#include <ModbusMaster.h>

extern ModbusMaster node1;

#define dtsu_slaveid 0x01 // Datasheet
#define default_baudrate_dtsu666 9600 // Default

#define TX_Pin_dtsu666 16
#define RX_Pin_dtsu666 17

#define READ_ERROR -1

void Init_dtsu666();

float ReadFloat_Value(uint16_t);

float Read_Voltage_A();
float Read_Voltage_B();
float Read_Voltage_C();

typedef union{
    uint32_t u32;
    float f;
} Data_Convert;

enum Register_Map : uint16_t {
    // ----------------------------------------------------------------
    // 1. Keyboard & Communication Parameters (Signed / 1 Word)
    // ----------------------------------------------------------------
    REV         = 0x0000,   // Software Version
    UCODE       = 0x0001,   // Programming code
    CLR_E       = 0x0002,   // Energy reset
    NET         = 0x0003,   // Network selection
    IRAT        = 0x0006,   // Current transformer rate
    URAT        = 0x0007,   // Voltage transformer rate
    DISP        = 0x000A,   // Rotating display time
    B_LCD       = 0x000B,   // Backlight time control
    ENDIAN      = 0x000C,   // Endian setting
    PROTOCOL    = 0x002C,   // Protocol switching
    BAUD        = 0x002D,   // Communication baud rate
    ADDR        = 0x002E,   // Communication address

    // ----------------------------------------------------------------
    // 2. Electricity Data (Float / 2 Words)
    // _H = Address, _L = Address + 1
    // ----------------------------------------------------------------
    
    // Line Voltage (Điện áp dây)
    UAB_H       = 0x2000, UAB_L       = 0x2001,
    UBC_H       = 0x2002, UBC_L       = 0x2003,
    UCA_H       = 0x2004, UCA_L       = 0x2005,

    // Phase Voltage (Điện áp pha)
    UA_H        = 0x2006, UA_L        = 0x2007,
    UB_H        = 0x2008, UB_L        = 0x2009,
    UC_H        = 0x200A, UC_L        = 0x200B,

    // Phase Current (Dòng điện pha)
    IA_H        = 0x200C, IA_L        = 0x200D,
    IB_H        = 0x200E, IB_L        = 0x200F,
    IC_H        = 0x2010, IC_L        = 0x2011,

    // Active Power (Công suất tác dụng)
    PT_H        = 0x2012, PT_L        = 0x2013, // Combined
    PA_H        = 0x2014, PA_L        = 0x2015, // Phase A
    PB_H        = 0x2016, PB_L        = 0x2017, // Phase B
    PC_H        = 0x2018, PC_L        = 0x2019, // Phase C

    // Reactive Power (Công suất phản kháng)
    QT_H        = 0x201A, QT_L        = 0x201B, // Combined
    QA_H        = 0x201C, QA_L        = 0x201D, // Phase A
    QB_H        = 0x201E, QB_L        = 0x201F, // Phase B
    QC_H        = 0x2020, QC_L        = 0x2021, // Phase C

    // Power Factor (Hệ số công suất)
    PFT_H       = 0x202A, PFT_L       = 0x202B, // Combined
    PFA_H       = 0x202C, PFA_L       = 0x202D, // Phase A
    PFB_H       = 0x202E, PFB_L       = 0x202F, // Phase B
    PFC_H       = 0x2030, PFC_L       = 0x2031, // Phase C

    // Frequency (Tần số)
    FREQ_H      = 0x2044, FREQ_L      = 0x2045,

    // ----------------------------------------------------------------
    // 3. Energy Data (Float / 2 Words)
    // _H = Address, _L = Address + 1
    // ----------------------------------------------------------------

    // Forward Active Energy (Điện năng tác dụng chiều thuận - Tiêu thụ)
    IMPEP_H     = 0x101E, IMPEP_L     = 0x101F, // Total
    IMPEPA_H    = 0x1020, IMPEPA_L    = 0x1021, // Phase A
    IMPEPB_H    = 0x1022, IMPEPB_L    = 0x1023, // Phase B
    IMPEPC_H    = 0x1024, IMPEPC_L    = 0x1025, // Phase C
    NETIMPEP_H  = 0x1026, NETIMPEP_L  = 0x1027, // Net Forward

    // Reverse Active Energy (Điện năng tác dụng chiều ngược - Phát ra)
    EXPEP_H     = 0x1028, EXPEP_L     = 0x1029, // Total
    EXPEPA_H    = 0x102A, EXPEPA_L    = 0x102B, // Phase A
    EXPEPB_H    = 0x102C, EXPEPB_L    = 0x102D, // Phase B
    EXPEPC_H    = 0x102E, EXPEPC_L    = 0x102F, // Phase C
    NETEXPEP_H  = 0x1030, NETEXPEP_L  = 0x1031  // Net Reverse
};

#endif