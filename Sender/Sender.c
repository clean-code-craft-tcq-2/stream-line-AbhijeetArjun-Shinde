#include "Sender.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ReadBMS_DataFromFile(BatteryParameters *BP, FILE *file)
{
    float Temperature, StateOfCharge,ChargeRate;
    
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
    char buffer[200];
    char *datastream = buffer;
    FILE *endPoint = stdout;
    for(int i = 0; i<NO_OF_SAMPLES;i++)
    {
     sprintf(datastream, " {\"Temperature\": %.2f degC, \"StateOfCharge\": %.2f, \"ChargeRate\": %.2f}",  BP->Temperature,BP->StateOfCharge,BP->ChargeRate);
     fprintf(endPoint,"%s\n",datastream);
     BP++;
    }
}
void BMS_Sender()
{
  BatteryParameters B1[NO_OF_SAMPLES];
  FILE *file= fopen(".Sender/Sender.txt","r");  
  //ReadBMS_DataFromFile(B1,file);
  //SendBMS_DataToConsole(B1);
}
