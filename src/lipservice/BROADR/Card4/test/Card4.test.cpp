#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "value range" ){
  Argument< BROADR::Card2::Ntemp2 > ntemp2; ntemp2.value = 1;
  Argument< BROADR::Card2::Istrap > istrap; istrap.value = 1;
  Argument< BROADR::Card2::Temp1 > temp1; temp1.value = 10.0;
  {
    iRecordStream<char> iss( std::istringstream("   9.0\n") );
    REQUIRE_THROWS( BROADR::Card4( iss, ntemp2, istrap, temp1 ) );
  }{
    iRecordStream<char> iss( std::istringstream("   10.0\n") );
    REQUIRE( 
      BROADR::Card4( iss, ntemp2, istrap, temp1 ).temp2.value.front() == 10.0 );
  }{
    iRecordStream<char> iss( std::istringstream("   11.0\n") );
    REQUIRE( 
      BROADR::Card4( iss, ntemp2, istrap, temp1 ).temp2.value.front() == 11.0 );
  }{
    iRecordStream<char> iss( std::istringstream("   \n") );
    REQUIRE_THROWS( BROADR::Card4( iss, ntemp2, istrap, temp1 ) );
  }{
    iRecordStream<char> iss( std::istringstream("  20.0 30.0 40.0 \n") );
    ntemp2.value = 3;

    BROADR::Card4 card4( iss, ntemp2, istrap, temp1 );
    REQUIRE( card4.temp2.value.front() == 20.0 );
    REQUIRE( card4.temp2.value.at(1) == 30.0 );
    REQUIRE( card4.temp2.value.back() == 40.0 );
  }
}
