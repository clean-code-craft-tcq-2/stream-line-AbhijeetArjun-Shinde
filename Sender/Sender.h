void BMS_Sender(FILE *InputFile , FILE *OutputPath );#define NO_OF_SAMPLES 50

#include <stdio.h>

typedef struct{
  float Temperature;
  float StateOfCharge;
  float ChargeRate;
}BatteryParameters;


void ReadBMS_DataFromFile(BatteryParameters *BMS_DataPtr, FILE *InputFile);
void SendBMS_Data(BatteryParameters *BMS_DataPtr, FILE *OutputFile);
void BMS_Sender(FILE *InputFile , FILE *OutputPath );
