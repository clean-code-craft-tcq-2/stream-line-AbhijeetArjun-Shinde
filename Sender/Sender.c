#include "Sender.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ReadBMS_DataFromFile(BatteryParameters *BP, char *filepath)
{
    float Temperature, StateOfCharge,ChargeRate;
    FILE * file= fopen(filepath,"r");  
    if (file!=NULL) {
        for(int i=0;fscanf(file, "%f\t%f\t%f\n", &Temperature,&StateOfCharge,&ChargeRate)!=EOF ;i++)
        {
            BP->Temperature = Temperature;
            BP->StateOfCharge  = StateOfCharge;
            BP->ChargeRate   = ChargeRate;
            BP++;
        }
    }
    fclose(file);  
}

void SendBMS_DataToConsole(BatteryParameters *BP)
{   
    char buffer[100];
    for(int i = 0; i<NO_OF_SAMPLES;i++)
    {
     sprintf(buffer, " {\"Temperature\": %.2f degC, \"StateOfCharge\": %.2f, \"ChargeRate\": %.2f}",  (BP[i].Temperature),(BP[i].StateOfCharge),(BP[i].ChargeRate));
     printf("%s\n",buffer);
    }
}
void BMS_Sender()
{
  BatteryParameters B1[NO_OF_SAMPLES];
  char FilePath[100] = ".Sender/Sender.txt";
  ReadBMS_DataFromFile(B1,FilePath);
  SendBMS_DataToConsole(B1);
}
