#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("   -1") );
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Istart >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   0") );
    REQUIRE( argument::extract< BROADR::Card2::Istart >( iss ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream("   1") );
    REQUIRE( argument::extract< BROADR::Card2::Istart >( iss ).value == 1 );
  }{
    iRecordStream<char> iss( std::istringstream("   2") );
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Istart >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("/") );
    REQUIRE( argument::extract< BROADR::Card2::Istart >( iss ).value == 0 );
  }
}
