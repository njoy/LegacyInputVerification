#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Ec output values", "[GROUPR],[Card8c], [Ec]"){
  Argument< GROUPR::Card8c::Eb > eb;
  eb.value = 0.5;

  GIVEN( "valid Ec parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto ec : { 1.0, 1E3, 10.0} ){
        iRecordStream<char> issEc( 
            std::istringstream( std::to_string( ec ) ) );

        REQUIRE( ec == 
                argument::extract< GROUPR::Card8c::Ec >( issEc, eb ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ec parameters" ){

    THEN( "an exception is thrown" ){
      for( auto ec : {-1.0, 0.0}){
        iRecordStream<char> issEc( 
            std::istringstream( std::to_string( ec ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8c::Ec >( issEc, eb ) );
      }
    }
    WHEN( "Ec < Eb" ){
      iRecordStream<char> issEc( std::istringstream( "0.25" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< GROUPR::Card8c::Ec >( issEc, eb ) );
      }
    }
  } // GIVEN
} // SCENARIO
