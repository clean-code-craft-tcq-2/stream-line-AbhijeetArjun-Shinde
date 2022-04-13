#define NO_OF_SAMPLES 50

#include <stdio.h>

typedef struct{
  float Temperature;
  float StateOfCharge;
  float ChargeRate;
}BatteryParameters;


void ReadBMS_DataFromFile(BatteryParameters *BP, FILE *InputFile);
void SendBMS_DataToConsole(BatteryParameters *Bp, FILE *OutputFile);
void BMS_Sender(FILE *InputFile);
