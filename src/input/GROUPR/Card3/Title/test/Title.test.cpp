#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "GROUPR card3 title",
         "[Card3], [Title]"){
  GIVEN( "valid title values" ){
    std::vector< std::string > validValues{ 
      "",
      "This is a test descriptive string.",
      "123456789012345678901234567890123456789012345678901234567890123456",
      "1234567890123456789012345678901234567890123456789012345678901234567890"
    };

    THEN( "the tname value is correctly read and returned" ){
      for( auto& title : validValues ){
        iRecordStream<char> iss( std::istringstream( "'" + title + "'" ) );

        REQUIRE( 
            title == argument::extract< GROUPR::Card3::Title >( iss ).value );
      }
    }
  }
  GIVEN( "invalid titles" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 12");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< GROUPR::Card3::Title >( iss ) );
    }
  }
} // SCENARIO
