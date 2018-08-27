#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card18 skappa input values",
  "[LEAPR], [Card18], [Skappa]" ){
  GIVEN( "a value for nka" ){
    auto InvAng =  pow( 1.0 * dimwits::angstrom, dimwits::Ratio<-1> );
    Argument< LEAPR::Card17::Nka > nka;
    nka.value = 3;

    WHEN( "there are the correct number of skappas anka they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the skappa values can be extracted correctly" ){
        auto skappas = argument::extract< LEAPR::Card18::Skappa >( iss, nka );
        std::vector< decltype(InvAng) > refSkappas{ 1.0 * InvAng, 
                                                    2.0 * InvAng, 
                                                    3.0 * InvAng };
        REQUIRE( refSkappas == skappas.value );
      } // THEN
    } // WHEN
    WHEN( "the skappa values are invalid" ){
      iRecordStream< char> iss( std::istringstream("0.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card18::Skappa >( iss, nka ) );
      } // THEN
    } // WHEN
//    WHEN( "the skappa values are not in increasing order" ){
//      iRecordStream< char> iss( std::istringstream("1.0 3.0 2.0") );
//      THEN( "an exception is thrown" ){
//        REQUIRE_THROWS( argument::extract< 
//          LEAPR::Card18::Skappa >( iss, nka ) );
//      } // THEN
//    } // WHEN
    WHEN( "too few skappa values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card18::Skappa >( iss, nka ) );
      } // THEN
    } // WHEN
    WHEN( "too many skappa values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( argument::extract<
          LEAPR::Card18::Skappa >( iss, nka ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
