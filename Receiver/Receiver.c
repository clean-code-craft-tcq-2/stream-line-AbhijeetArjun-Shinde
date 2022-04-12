
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sliderAvg(float sample) {
    static int sampleSize = 0;
    static float SampleSlider[5] ={0};
    SampleSlider[sampleSize % 5] = sample/5.0;
    sampleSize++;
    if (sampleSize >= 5)
    {
        float avgTemperature = SampleSlider[0] +SampleSlider[1] + SampleSlider[2]+ SampleSlider[3]+ SampleSlider[4];
        printf("average temperature: %f\n", avgTemperature);
        return 1;
        
    } else{
        return -1;
    }
    
}

void Parse_ReceivedData(float* temperature, float* stateOfCharge, float* chargeRate, int streamSize) {
    char ignoreString[200];
    for(int i = 0; i < streamSize; i++){
        //todo If found time, find a prettier way to parse incoming data(right now doesnt come in a standard format))
        if(scanf("%50s", ignoreString) == EOF) 
        {
            break;
        } 
        scanf("%f", &temperature[i]);
        scanf("%50s", ignoreString); //deg
        scanf("%50s", ignoreString); //C
        scanf("%50s", ignoreString); //,
        scanf("%50s", ignoreString); // State
        scanf("%50s", ignoreString); //of
        scanf("%50s", ignoreString); //charge:
        scanf("%f", &stateOfCharge[i]);
        scanf("%50s", ignoreString); // ,
        scanf("%50s", ignoreString); //charge
        scanf("%50s", ignoreString); //rate:
        scanf("%f", &chargeRate[i]);
        sliderAvg(temperature[i]);
        //printf("%f, %f, %f\n", temperature[i], stateOfCharge[i], chargeRate[i]);
        
    }
}
void MinMaxValues(float* temperature, float* stateOfCharge, int streamSize) {
    static float min_temp=0, max_temp=0, min_soc=0, max_soc=0;
    for (int i = 0; i < streamSize; i++)
    {
        if(temperature[i] < min_temp) {
            min_temp = temperature[i];
        } else if(temperature[i]> max_temp) {
            max_temp = temperature[i];
        }

        if(stateOfCharge[i] < min_soc) {
            min_soc = stateOfCharge[i];
        } else if(stateOfCharge[i] > max_soc) {
            max_soc = stateOfCharge[i];
        }
    }
    printf("min temp: %f max temp: %f min charge: %f max charge: %f\n", min_temp, max_temp, min_soc, max_soc);

}



