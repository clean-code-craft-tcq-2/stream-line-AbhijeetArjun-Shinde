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
  
  float expectedoutput[3][3] = {{2,5,0.0}, {55,67,0.72},{35,47,0.38}};
  int j =0;
  for(int i=0;i<3;i++)
  {
    REQUIRE(Temperature[j] == expectedoutput[i,0]);
    REQUIRE(StateOfCharge[j] == expectedoutput[i,1]);
    REQUIRE(ChargeRate[j] == expectedoutput[i,2]);
    j=j+24;
  }
  //result = (Temperature[0]==2 && StateOfCharge[0]==5 && ChargeRate[0]==0.0 && Temperature[49]==float(27) && StateOfCharge[49]==float(67) && ChargeRate[49]==float(0.85));
  //REQUIRE(result ==1);
  
  //result = (Temperature[49]==float(27) && StateOfCharge[49]==float(67) && ChargeRate[49]==float(0.85));
  //REQUIRE(result ==1);

}
