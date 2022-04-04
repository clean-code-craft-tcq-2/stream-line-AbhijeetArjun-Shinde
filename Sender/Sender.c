#include "Sender.h"

void ReadBMS_DataFromFile(float* Temp, float* SOC, float* CR)
{
    int senderInputValue = 0;
    FILE * file= fopen("./Sender/Sender.txt","r");  
    if (file!=NULL) {
        for(int i=0;fscanf(file, "%f\t%f\t%f\n", &Temp,&SOC,&CR)!=EOF ;i++)
        {
            *(Temp+i) = Temp;
            *(SOC+i)  = SOC;
            *(CR+i)   = CR;
        }
    }
    fclose(file);  
}
