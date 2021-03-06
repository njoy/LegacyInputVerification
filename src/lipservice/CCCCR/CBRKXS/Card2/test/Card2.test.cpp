#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "CCCCR, CBRKXS, Card2",
          "[CCCCR] [CBRKXS] [Card2]" ){
  const int nti = 3;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS::Card2 card2( iss, nti );

        auto atem = card2.atem.value;

        REQUIRE( 0.1 == atem.at(0) );
        REQUIRE( 0.2 == atem.at(1) );
        REQUIRE( 0.3 == atem.at(2) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card2( iss, nti ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 0.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card2( iss, nti ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
