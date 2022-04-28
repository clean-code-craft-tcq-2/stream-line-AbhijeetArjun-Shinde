#include "Sender.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ReadBMS_DataFromFile(BatteryParameters *BMS_DataPtr, FILE *InputFile)
{
    float Temperature_loc, StateOfCharge_loc,ChargeRate_loc;
    if (InputFile!=NULL) {
        for(int i=0;fscanf(InputFile, "%f\t%f\t%f\n", &Temperature_loc,&StateOfCharge_loc,&ChargeRate_loc)!=EOF ;i++)
        {
            (BMS_DataPtr->Temperature) = Temperature_loc;
            (BMS_DataPtr->StateOfCharge)  = StateOfCharge_loc;
            (BMS_DataPtr->ChargeRate)   = ChargeRate_loc;
            BMS_DataPtr++;
        }
    }
    fclose(InputFile);  
}

void SendBMS_Data(BatteryParameters *BMS_DataPtr, FILE *OutputFile)
{   
    char buffer[200];
    char *datastream = buffer;
    for(int i = 0; i<NO_OF_SAMPLES;i++)
    {
     sprintf(datastream, " {\"Temperature\": %.2f degC, \"StateOfCharge\": %.2f, \"ChargeRate\": %.2f}",  (BMS_DataPtr->Temperature),(BMS_DataPtr->StateOfCharge),(BMS_DataPtr->ChargeRate));
     fprintf(OutputFile,"%s\n",datastream);
     BMS_DataPtr++;
    }
}
void BMS_Sender(FILE *InputFile , FILE *OutputPath )
{

  
  if (InputFile!=NULL) 
  {
  BatteryParameters InpReadFromFile[NO_OF_SAMPLES];
  ReadBMS_DataFromFile(InpReadFromFile,InputFile);
  }
  if (OutputPath!=NULL) 
  {
  SendBMS_Data(InpReadFromFile,OutputPath);
  }
  
}
