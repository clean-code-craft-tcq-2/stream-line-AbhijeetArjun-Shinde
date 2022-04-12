// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/Receiver.h"

#define EPSILON 0.03

TEST_CASE("test average readiness") 
{
    float values[5] = {2,4,6,8,10};
    for (int i = 0; i < 4; i++)
    {
        REQUIRE(sliderAvg(values[i]) == -1 );
    }
    REQUIRE(sliderAvg(values[4]) == 1 );
    
}

TEST_CASE("Test for Checking wether read of data from console input") 
{
  float Temperature[1] = {0};
  float StateOfCharge[1] = {0};
  float ChargeRate[1] = {0};
  float Temperature_ref[1] = {5.1};
  float StateOfCharge_ref[1] = {6.2};
  float ChargeRate_ref[1] = {7.3};
  printf(" Temperature: %.2f deg C , State of Charge: %.2f , Charge Rate: %.2f \n", Temperature_ref[0], StateOfCharge_ref[0], ChargeRate_ref[0] );
  //copy paste the following line on the console to perform test:
  //Temperature: 5.1 deg C , State of Charge: 6.2 , Charge Rate: 7.3
  Parse_ReceivedData( Temperature,StateOfCharge,ChargeRate, 1);
  REQUIRE(Temperature[0] - Temperature_ref[0] <= EPSILON);
  REQUIRE(StateOfCharge[0] - StateOfCharge_ref[0] <= EPSILON);
  REQUIRE(ChargeRate[0] - ChargeRate_ref[0] <= EPSILON);
}

//TODO: Add test for min max function

