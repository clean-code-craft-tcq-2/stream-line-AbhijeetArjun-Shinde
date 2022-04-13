#define NO_OF_SAMPLES 50

typedef struct{
  float Temperature;
  float StateOfCharge;
  float ChargeRate;
}BatteryParameters;

void ReadBMS_DataFromFile(BatteryParameters *, char *);
void SendBMS_DataToConsole(BatteryParameters *);
void BMS_Sender();
