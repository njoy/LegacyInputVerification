#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "bugless" ){
  std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 ");
  iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
  PLOTR::Card6a card6a( iss );
  REQUIRE( card6a.ylabl.value == value );
}

SCENARIO( "bugged" ){
  GIVEN( "a string that's too long" ){
    std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 1");
    iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
    REQUIRE_THROWS( PLOTR::Card6a( iss ) );
  }
}
