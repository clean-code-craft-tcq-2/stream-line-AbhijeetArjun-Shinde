#include "Sender.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ReadBMS_DataFromFile(BatteryParameters *BP, FILE *InputFile)
{
    float Temperature, StateOfCharge,ChargeRate;
    if (InputFile!=NULL) {
        for(int i=0;fscanf(InputFile, "%f\t%f\t%f\n", &Temperature,&StateOfCharge,&ChargeRate)!=EOF ;i++)
        {
            (BP->Temperature) = Temperature;
            (BP->StateOfCharge)  = StateOfCharge;
            (BP->ChargeRate)   = ChargeRate;
            BP++;
        }
    }
    fclose(InputFile);  
}

void SendBMS_DataToConsole(BatteryParameters *BP, FILE *OutputFile)
{   
    char buffer[200];
    char *datastream = buffer;
    for(int i = 0; i<NO_OF_SAMPLES;i++)
    {
     sprintf(datastream, " {\"Temperature\": %.2f degC, \"StateOfCharge\": %.2f, \"ChargeRate\": %.2f}",  (BP->Temperature),(BP->StateOfCharge),(BP->ChargeRate));
     fprintf(OutputFile,"%s\n",datastream);
     BP++;
    }
}
void BMS_Sender(FILE *InputFile)
{
  BatteryParameters B1[NO_OF_SAMPLES];
  FILE *OutputPath = stdout;
  if (InputFile!=NULL) 
  {
  ReadBMS_DataFromFile(B1,InputFile);
  }
  SendBMS_DataToConsole(B1,OutputPath);
}
