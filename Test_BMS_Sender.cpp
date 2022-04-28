// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Test for Checking weather read of data from file is successful ") 
{
  BatteryParameters BMS_Data[NO_OF_SAMPLES];
  FILE * file= fopen("./Sender/Sender.txt","r");
  FILE *OutputPath = stdout;
  
  
  //ReadBMS_DataFromFile( BMS_Data,file);
  
  float expectedoutput[3][3] = {{2,5,0.0}, {55,67,0.72},{35,47,0.38}};
  int j =0;
  for(int i=0;i<3;i++)
  {
    REQUIRE( (BMS_Data[j].Temperature) == expectedoutput[i][0]);
    REQUIRE( (BMS_Data[j].StateOfCharge) == expectedoutput[i][1]);
    REQUIRE( (BMS_Data[j].ChargeRate) == expectedoutput[i][2]);
    j=j+24;
  }
 // FILE * file2= fopen("./Sender/Sender.txt","r");

  BMS_Sender(BMS_Data,file2,OutputPath);
}
