// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Test for Checking weather read of data from file is successful ") 
{
  float Temperature[NO_OF_SAMPLES] = {0};
  float StateOfCharge[NO_OF_SAMPLES] = {0};
  float ChargeRate[NO_OF_SAMPLES] = {0};
  ReadBMS_DataFromFile( Temperature,StateOfCharge,ChargeRate);
  
  float expectedoutput[3][3] = {{2,5,0.0}, {55,67,0.72},{35,47,0.38}};
  int j =0;
  for(int i=0;i<3;i++)
  {
    REQUIRE(Temperature[j] == expectedoutput[i][0]);
    REQUIRE(StateOfCharge[j] == expectedoutput[i][1]);
    REQUIRE(ChargeRate[j] == expectedoutput[i][2]);
    j=j+24;
  }
  BMS_Sender();
}
