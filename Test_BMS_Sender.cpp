// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/Sender.h"


TEST_CASE("Test for Checking sensed current values within range- Sensor 1 ") {
  bool result=0;
  int Temperature[NO_OF_SAMPLES] = {0};
  int StateOfCharge[NO_OF_SAMPLES] = {0};
  float ChargeRate[NO_OF_SAMPLES] = {0};
  ReadBMS_DataFromFile( Temperature,StateOfCharge,ChargeRate);
  REQUIRE(Temperature[0]==2 && StateOfCharge[0]==5 && ChargeRate[0]==0.0);
  REQUIRE(Temperature[25]==56 && StateOfCharge[0]==70 && ChargeRate[0]==0.75); 
  REQUIRE(Temperature[49]==27 && StateOfCharge[49]==67 && ChargeRate[49]==0.85); 
}
