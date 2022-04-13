#define NO_OF_SAMPLES 50

typedef struct{
  float Temperature;
  float StateOfCharge;
  float ChargeRate;
}BatteryParameters;

void ReadBMS_DataFromFile(float* Temp, float* SOC, float* CR);
void SendBMS_DataToConsole(float* Temp, float* SOC, float* CR);
void BMS_Sender();
