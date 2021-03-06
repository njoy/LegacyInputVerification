#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "ismooth output values",
         "[GROUPR],[Card2], [Ismooth]"){

  long ln{0};
  GIVEN( "valid ismooth values" ){
    std::vector<int> validValues{0, 1};

    for( auto& ismooth : validValues ){
      std::string situ( "valid input " + std::to_string( ismooth ) +
                                       " is provided. The value is verified." );
      THEN( situ.c_str() ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(ismooth) ) );

        REQUIRE( 
          ismooth == argument::extract< GROUPR::Card2::Ismooth >( iss ).value );
      }
    }
  }
  GIVEN( "no ismooth values" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( 1 == argument::extract< GROUPR::Card2::Ismooth >( iss ).value );
    }
  }
  
  GIVEN( "invalid ismooth values" ){
    std::vector<int> invalidValues{-1, 2};

    for( auto& ismooth : invalidValues ){
      std::string situ( "invalid input " + std::to_string( ismooth ) +
                                      " is provided. An exception is thrown." );
      THEN( situ.c_str() ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(ismooth) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Ismooth >( iss ) );
      }
    }
  }

} // SCENARIO
