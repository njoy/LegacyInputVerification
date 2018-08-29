#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "legacyInputVerification.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR nlmax values",
  "[DTFR],[Card3], [Nlmax]"){

  GIVEN( "valid nlmax values" ){
    std::vector<int> validValues{1, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& nlmax : validValues ){
        iRecordStream<char> iss( std::istringstream( 
          std::to_string( nlmax ) ) );
        REQUIRE( nlmax == argument::extract< 
          DTFR::Card3::Nlmax >( iss ).value );
      } 
    } // THEN
  } // GIVEN

  GIVEN( "invalid nlmax values" ){
    std::vector<int> invalidValues{0, -1};

    THEN( "an exception is thrown" ){
      for( auto& nlmax : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( nlmax ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card3::Nlmax >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
