#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Tb output values", "[GROUPR],[Card8c], [Tb]"){

  GIVEN( "valid Tb parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto tb : { 1.0, 1E-3, 10.0} ){
        iRecordStream<char> issTb( 
            std::istringstream( std::to_string( tb ) ) );

        REQUIRE( tb == 
                argument::extract< GROUPR::Card8c::Tb >( issTb ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Tb parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto tb : {-1.0, 0.0}){
        iRecordStream<char> issTb( 
            std::istringstream( std::to_string( tb ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8c::Tb >( issTb ) );
      }
    }
  } // GIVEN
} // SCENARIO
