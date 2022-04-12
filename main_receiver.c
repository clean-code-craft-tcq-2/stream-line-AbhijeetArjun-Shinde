
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Receiver/Receiver.h"


int main()
{

    float Temperature[50],StateOfCharge[50],ChargeRate[50] = {0};
    Parse_ReceivedData(Temperature, StateOfCharge, ChargeRate, 50);
    OutOfBounds(Temperature, StateOfCharge, 50);


    
}