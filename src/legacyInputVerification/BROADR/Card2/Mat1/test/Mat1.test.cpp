#define CATCH_CONFIG_MAIN
 
#include "catch.hpp"
#include "legacyInputVerification.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("   0") ); 
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Mat1 >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   1") );
    REQUIRE( argument::extract< BROADR::Card2::Mat1 >( iss ).value == 1 );
  }{
    iRecordStream<char> iss( std::istringstream("   5000") );
    REQUIRE( argument::extract< BROADR::Card2::Mat1 >( iss ).value == 5000 );
  }{
    iRecordStream<char> iss( std::istringstream("   9999") );
    REQUIRE( argument::extract< BROADR::Card2::Mat1 >( iss ).value == 9999 );
  }{
    iRecordStream<char> iss( std::istringstream("   10000") );
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Mat1 >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Mat1 >( iss ) );
  }
}
