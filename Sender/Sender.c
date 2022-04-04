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
