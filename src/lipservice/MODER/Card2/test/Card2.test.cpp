#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "bugless" ){
  std::string value("012345678901234567890123456789012345678901234567890123456789012345");
  iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
  MODER::Card2 card2( iss );
  REQUIRE( card2.tapeid.value == value );
}

SCENARIO( "bugged" ){
  std::string value("'0123456789012345678901234567890123456789012345678901234567890123456'");
  iRecordStream<char> iss( ( std::istringstream(value) ) );
  REQUIRE_THROWS( MODER::Card2( iss ) );
}
