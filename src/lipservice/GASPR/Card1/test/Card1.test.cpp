#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "bugless" ){
  {
    iRecordStream<char> iss( std::istringstream("   20 21 22\n") );
    GASPR::Card1 card1( iss );
    REQUIRE( card1.nendf.value == 20 );
    REQUIRE( card1.nin.value == 21 );
    REQUIRE( card1.nout.value == 22 );
  }{
    iRecordStream<char> iss( std::istringstream("   -20 21 22\n") );
    GASPR::Card1 card1( iss );
    REQUIRE( card1.nendf.value == -20 );
    REQUIRE( card1.nin.value == 21 );
    REQUIRE( card1.nout.value == 22 );
  }
}

SCENARIO( "bugged" ){
  {
    iRecordStream<char> iss( std::istringstream("   20 20 21\n") );
    REQUIRE_THROWS( GASPR::Card1( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20 21 20\n") );
    REQUIRE_THROWS( GASPR::Card1( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20 21 21\n") );
    REQUIRE_THROWS( GASPR::Card1( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20 -21 22\n") );
    REQUIRE_THROWS( GASPR::Card1( iss ) );
  }
}
