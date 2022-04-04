// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Test for Checking weather read of data from file is successful ") {
  bool result=0;
  float Temperature[NO_OF_SAMPLES] = {0};
  float StateOfCharge[NO_OF_SAMPLES] = {0};
  float ChargeRate[NO_OF_SAMPLES] = {0};
  ReadBMS_DataFromFile( Temperature,StateOfCharge,ChargeRate);
  result = (Temperature[0]==2 && StateOfCharge[0]==5 && ChargeRate[0]==0.0);
  REQUIRE(result ==1);
  
  //result = (Temperature[25]==56 && StateOfCharge[0]==70 && ChargeRate[0]==0.75);
  //REQUIRE(result ==1);
  printf(" %f   %f   %f\n", Temperature[25],StateOfCharge[25],ChargeRate[25]);
  
  result = (Temperature[49]==27 && StateOfCharge[49]==67 && ChargeRate[49]==0.85);
  REQUIRE(result ==1);
  printf(" %f   %f   %f\n", Temperature[49],StateOfCharge[49],ChargeRate[49]);
}
