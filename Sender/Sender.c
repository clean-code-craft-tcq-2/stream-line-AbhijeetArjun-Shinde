#include "Sender.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ReadBMS_DataFromFile(float* Temp, float* SOC, float* CR)
{
    float Temperature, StateOfCharge,ChargeRate;
    FILE * file= fopen("./Sender/Sender.txt","r");  
    if (file!=NULL) {
        for(int i=0;fscanf(file, "%f\t%f\t%f\n", &Temperature,&StateOfCharge,&ChargeRate)!=EOF ;i++)
        {
            *(Temp+i) = Temperature;
            *(SOC+i)  = StateOfCharge;
            *(CR+i)   = ChargeRate;
        }
    }
    fclose(file);  
}

void SendBMS_DataToConsole(float* Temp, float* SOC, float* CR)
{
    for(int i = 0; i<NO_OF_SAMPLES;i++);
    {
     printf(" Temperature: %f deg C , State of Charge: %f , Charge Rate:%f \n",  *(Temp+i),*(SOC+i),*(CR+i));
    }
}
void BMS_Sender()
{
  float Temperature[NO_OF_SAMPLES],StateOfCharge[NO_OF_SAMPLES],ChargeRate[NO_OF_SAMPLES] = {0};
  ReadBMS_DataFromFile( Temperature,StateOfCharge,ChargeRate);
  SendBMS_DataToConsole( Temperature,StateOfCharge,ChargeRate);
}
