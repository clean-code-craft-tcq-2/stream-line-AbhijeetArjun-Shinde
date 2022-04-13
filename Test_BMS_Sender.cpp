// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Test for Checking weather read of data from file is successful ") 
{
  BatteryParameters B2[NO_OF_SAMPLES];
  FILE * file= fopen("./Sender/Sender.txt","r");
  ReadBMS_DataFromFile( B2,file);
  
  float expectedoutput[3][3] = {{2,5,0.0}, {55,67,0.72},{35,47,0.38}};
  int j =0;
  for(int i=0;i<3;i++)
  {
    REQUIRE( (B2[j].Temperature) == expectedoutput[i][0]);
    REQUIRE( (B2[j].StateOfCharge) == expectedoutput[i][1]);
    REQUIRE( (B2[j].ChargeRate) == expectedoutput[i][2]);
    j=j+24;
  }
  FILE * file2= fopen("./Sender/Sender.txt","r");
  BMS_Sender(file2);
}
