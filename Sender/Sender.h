#define NO_OF_SAMPLES 50


void ReadBMS_DataFromFile(float* Temp, float* SOC, float* CR);
void SendBMS_DataToConsole(float* Temp, float* SOC, float* CR);
void BMS_Sender();
