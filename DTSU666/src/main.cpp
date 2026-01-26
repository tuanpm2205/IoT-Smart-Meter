#include <stdio.h>
#include <stdint.h>
#include "dtsu666.h"
#include "ModbusMaster.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
    Serial.begin(9600);
    Init_dtsu666();

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Xin chao!");
}

void loop(){
    /*
    Serial.print("Ua:");
    Serial.println(Read_Voltage_A());
    Serial.print("Ub:");
    Serial.println(Read_Voltage_B());
    Serial.print("Uc:");
    Serial.println(Read_Voltage_C());
    delay(5000);
    */

}