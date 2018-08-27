#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1( "-30 -32 0 -34 /\n" );
std::string sCard3( "GROUPR Card3 title for testing" );
std::string sCard4( "293.6 600/\n" );
std::string sCard5( "1E6 1E-10 /\n" );
std::string sCard9_10{
      "3 19 'MF3 MT19' /\n"         // Card 9.1.1
      "3 103 'MF3 MT103' /\n"       // Card 9.1.2
      "10 /\n"                      // Card 9.1.3
      "0 /\n"                       // Card 9.2.4
      "3 20 'MF3 MT20' /\n"         // Card 9.2.1
      "6 104 'MF6 MT104' /\n"       // Card 9.2.2
      "12 /\n"                      // Card 9.2.3
      "0 /\n"                       // Card 9.2.4
      "9235 /\n"                    // Card10.1
      "3 18 'MF3 MT18' /\n"         // Card 9.3.1
      "3 102 'MF3 MT102' /\n"       // Card 9.3.2
      "0 /\n"                       // Card 9.3.3
      "5 17 'MF5 MT17' /\n"         // Card 9.4.1
      "8 100 'MF8 MT100' /\n"       // Card 9.4.2
      "0 /\n"                       // Card 9.4.3
      "0 /\n"                       // Card10.2
};

void verifyReactionMatrix( GROUPR::reactionMatrix_t& );

SCENARIO( "Parsing valid GROUPR input" ){
  WHEN( "reading in a very generic input" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 2 4 2 2 1 0 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + sCard9_10
    ) );

    GROUPR groupr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == groupr.card1.nendf.value );
      REQUIRE( -32 == groupr.card1.npend.value );
      REQUIRE(   0 == groupr.card1.ngout1.value );
      REQUIRE( -34 == groupr.card1.ngout2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == groupr.card2.matb.value );
      REQUIRE( 2 == groupr.card2.ign.value );
      REQUIRE( 0 == groupr.card2.igg.value );
      REQUIRE( 2 == groupr.card2.iwt.value );
      REQUIRE( 4 == groupr.card2.lord.value );
      REQUIRE( 2 == groupr.card2.ntemp.value );
      REQUIRE( 2 == groupr.card2.nsigz.value );
      REQUIRE( 1 == groupr.card2.iprint.value );
      REQUIRE( 0 == groupr.card2.ismooth.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3 == groupr.card3.title.value );
    }
    THEN( "the Card4 input values can be verified" ){
      REQUIRE( 2 == groupr.card4.temp.value.size() );
      REQUIRE( 293.6*dimwits::kelvin == groupr.card4.temp.value[0] );
      REQUIRE( 600*dimwits::kelvin == groupr.card4.temp.value[1] );
    }
    THEN( "the Card5 input values can be verified" ){
      REQUIRE( 2 == groupr.card5.sigz.value.size() );
      REQUIRE( std::numeric_limits<double>::infinity()*dimwits::barn == 
               groupr.card5.sigz.value[0] );
      REQUIRE( 1E-10*dimwits::barn == groupr.card5.sigz.value[1] );
    }

    THEN( "the Card8 variant must be false (i.e., not exist )" ){
      REQUIRE( not groupr.card8Variant.index() );
    }

    THEN( "the Card9 and Card10 values can be verified" ){
      verifyReactionMatrix( groupr.reactionMatrix );
    }

  }
  WHEN( "reading in a more complicated input, ign=1, ign=1, iwt=-1" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 1 -1 4 2 2 0 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "4 /\n"              // Card6a
      + "1 2 3 4 5/\n"       // Card6b
      + "5 /\n"              // Card7a
      + "1 2 3 4 5 6 /\n"    // Card7b
      + "400 10.6 5000 0 0 0.7768 7.5 0.40 1.6E-7 0.086 /\n" // Card8a
      + "0. 0. 0 0 1 6\n"                                                             // Card 8b
      + "6 5\n"
      + "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08 \n"
      + "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08 /\n"
      + sCard9_10
    ) );

    GROUPR groupr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == groupr.card1.nendf.value );
      REQUIRE( -32 == groupr.card1.npend.value );
      REQUIRE(   0 == groupr.card1.ngout1.value );
      REQUIRE( -34 == groupr.card1.ngout2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == groupr.card2.matb.value );
      REQUIRE( 1 == groupr.card2.ign.value );
      REQUIRE( 1 == groupr.card2.igg.value );
      REQUIRE( -1 == groupr.card2.iwt.value );
      REQUIRE( 4 == groupr.card2.lord.value );
      REQUIRE( 2 == groupr.card2.ntemp.value );
      REQUIRE( 2 == groupr.card2.nsigz.value );
      REQUIRE( 0 == groupr.card2.iprint.value );
      REQUIRE( 1 == groupr.card2.ismooth.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3 == groupr.card3.title.value );
    }
    THEN( "the Card4 input values can be verified" ){
      REQUIRE( 2 == groupr.card4.temp.value.size() );
      REQUIRE( 293.6*dimwits::kelvin == groupr.card4.temp.value[0] );
      REQUIRE( 600*dimwits::kelvin == groupr.card4.temp.value[1] );
    }
    THEN( "the Card5 input values can be verified" ){
      REQUIRE( 2 == groupr.card5.sigz.value.size() );
      REQUIRE( std::numeric_limits<double>::infinity()*dimwits::barn == 
               groupr.card5.sigz.value[0] );
      REQUIRE( 1E-10*dimwits::barn == groupr.card5.sigz.value[1] );
    }
    THEN( "the Card9 and Card10 values can be verified" ){
      verifyReactionMatrix( groupr.reactionMatrix );
    }

    THEN( "the Card6a input values can be verified" ){
      auto card6a = groupr.arbitraryNeutronStructureCards->first;
      REQUIRE( 4 == card6a.ngn.value );
    }
    THEN( "the Card6b input values can be verified" ){
      auto card6b = groupr.arbitraryNeutronStructureCards->second;
      REQUIRE( 5 == card6b.egn.value.size() );
      REQUIRE( 1*dimwits::electronVolt == card6b.egn.value[0] );
      REQUIRE( 2*dimwits::electronVolt == card6b.egn.value[1] );
      REQUIRE( 3*dimwits::electronVolt == card6b.egn.value[2] );
      REQUIRE( 4*dimwits::electronVolt == card6b.egn.value[3] );
      REQUIRE( 5*dimwits::electronVolt == card6b.egn.value[4] );
    }
    THEN( "the Card7a input values can be verified" ){
      auto card7a = groupr.arbitraryGammaStructureCards->first;
      REQUIRE( 5 == card7a.ngg.value );
    }
    THEN( "the Card7b input values can be verified" ){
      auto card7b = groupr.arbitraryGammaStructureCards->second;
      REQUIRE( 6 == card7b.egg.value.size() );
      REQUIRE( 1*dimwits::electronVolt == card7b.egg.value[0] );
      REQUIRE( 2*dimwits::electronVolt == card7b.egg.value[1] );
      REQUIRE( 3*dimwits::electronVolt == card7b.egg.value[2] );
      REQUIRE( 4*dimwits::electronVolt == card7b.egg.value[3] );
      REQUIRE( 5*dimwits::electronVolt == card7b.egg.value[4] );
      REQUIRE( 6*dimwits::electronVolt == card7b.egg.value[5] );
    }
    THEN( "the card8a input values can be verified" ){
      auto card8a = (*groupr.card8a);
      REQUIRE( 400*dimwits::electronVolt == card8a.fehi.value );
      REQUIRE( 10.6*dimwits::barn == card8a.sigpot.value );
      REQUIRE( 5000 == card8a.nflmax.value );
      REQUIRE( 0 == card8a.ninwt.value );
      REQUIRE( 0 == card8a.jsigz.value );
      REQUIRE( 0.7768 == card8a.alpha2.value );
      REQUIRE( 7.5*dimwits::barn == card8a.sam.value );
      REQUIRE( 0.40 == card8a.beta.value );
      REQUIRE( 1.6E-7 == card8a.alpha3.value );
      REQUIRE( 0.086 == card8a.gamma.value );
    }
    THEN( "the card8b values can be verified" ){
      auto& card8b = std::experimental::get<GROUPR::Card8b>( groupr.card8Variant );
      REQUIRE( 1E-5        == card8b.wght.value.x()[0] );
      REQUIRE( 1E3         == card8b.wght.value.x()[1] );
      REQUIRE( 1E4         == card8b.wght.value.x()[2] );
      REQUIRE( 1.00925E4   == card8b.wght.value.x()[3] );
      REQUIRE( 1.01859E4   == card8b.wght.value.x()[4] );
      REQUIRE( 1.02802E4   == card8b.wght.value.x()[5] );

      REQUIRE( 8.0E-20     == card8b.wght.value.y()[0] );
      REQUIRE( 9.13415E-10 == card8b.wght.value.y()[1] );
      REQUIRE( 6.13955E-8  == card8b.wght.value.y()[2] );
      REQUIRE( 6.17490E-8  == card8b.wght.value.y()[3] );
      REQUIRE( 6.09190E-8  == card8b.wght.value.y()[4] );
      REQUIRE( 6.19874E-8  == card8b.wght.value.y()[5] );
    }
  }
  WHEN( "reading in an input where iwt=4" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 4 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + ".10 .025 820.3e3 1.4e6 /\n"
      + sCard9_10
    ) );

    GROUPR groupr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == groupr.card1.nendf.value );
      REQUIRE( -32 == groupr.card1.npend.value );
      REQUIRE(   0 == groupr.card1.ngout1.value );
      REQUIRE( -34 == groupr.card1.ngout2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == groupr.card2.matb.value );
      REQUIRE( 2 == groupr.card2.ign.value );
      REQUIRE( 0 == groupr.card2.igg.value );
      REQUIRE( 4 == groupr.card2.iwt.value );
      REQUIRE( 4 == groupr.card2.lord.value );
      REQUIRE( 2 == groupr.card2.ntemp.value );
      REQUIRE( 2 == groupr.card2.nsigz.value );
      REQUIRE( 1 == groupr.card2.iprint.value );
      REQUIRE( 1 == groupr.card2.ismooth.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3 == groupr.card3.title.value );
    }
    THEN( "the Card4 input values can be verified" ){
      REQUIRE( 2 == groupr.card4.temp.value.size() );
      REQUIRE( 293.6*dimwits::kelvin == groupr.card4.temp.value[0] );
      REQUIRE( 600*dimwits::kelvin == groupr.card4.temp.value[1] );
    }
    THEN( "the Card5 input values can be verified" ){
      REQUIRE( 2 == groupr.card5.sigz.value.size() );
      REQUIRE( std::numeric_limits<double>::infinity()*dimwits::barn == 
               groupr.card5.sigz.value[0] );
      REQUIRE( 1E-10*dimwits::barn == groupr.card5.sigz.value[1] );
    }
    THEN( "the card8c input values can be verified" ){
      auto& card8c = std::experimental::get<GROUPR::Card8c>( 
          groupr.card8Variant );
      REQUIRE( 0.10*dimwits::electronVolt == card8c.eb.value );
      REQUIRE( 0.025*dimwits::electronVolt == card8c.tb.value );
      REQUIRE( 820.3E3*dimwits::electronVolt == card8c.ec.value );
      REQUIRE( 1.4E6*dimwits::electronVolt == card8c.tc.value );
    }
    THEN( "the Card9 and Card10 values can be verified" ){
      verifyReactionMatrix( groupr.reactionMatrix );
    }

  }
  WHEN( "reading in an input where iwt=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 0 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "22 /\n"                      // Card8d
      + sCard9_10
    ) );

    GROUPR groupr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == groupr.card1.nendf.value );
      REQUIRE( -32 == groupr.card1.npend.value );
      REQUIRE(   0 == groupr.card1.ngout1.value );
      REQUIRE( -34 == groupr.card1.ngout2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == groupr.card2.matb.value );
      REQUIRE( 2 == groupr.card2.ign.value );
      REQUIRE( 0 == groupr.card2.igg.value );
      REQUIRE( 0 == groupr.card2.iwt.value );
      REQUIRE( 4 == groupr.card2.lord.value );
      REQUIRE( 2 == groupr.card2.ntemp.value );
      REQUIRE( 2 == groupr.card2.nsigz.value );
      REQUIRE( 1 == groupr.card2.iprint.value );
      REQUIRE( 1 == groupr.card2.ismooth.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3 == groupr.card3.title.value );
    }
    THEN( "the Card4 input values can be verified" ){
      REQUIRE( 2 == groupr.card4.temp.value.size() );
      REQUIRE( 293.6*dimwits::kelvin == groupr.card4.temp.value[0] );
      REQUIRE( 600*dimwits::kelvin == groupr.card4.temp.value[1] );
    }
    THEN( "the Card5 input values can be verified" ){
      REQUIRE( 2 == groupr.card5.sigz.value.size() );
      REQUIRE( std::numeric_limits<double>::infinity()*dimwits::barn == 
               groupr.card5.sigz.value[0] );
      REQUIRE( 1E-10*dimwits::barn == groupr.card5.sigz.value[1] );
    }
    THEN( "the Card9 and Card10 values can be verified" ){
      verifyReactionMatrix( groupr.reactionMatrix );
    }


    THEN( "the card8d input value can be verified" ){
      auto& card8d = std::experimental::get<GROUPR::Card8d>( 
          groupr.card8Variant );
      REQUIRE( 22 == card8d.ninwt.value );
    }
  }
}

void verifyReactionMatrix( GROUPR::reactionMatrix_t& matrix ){

  REQUIRE( 2 == matrix.size() );
  int i;
  { i = 0;
    auto pair = matrix[ i ];
    REQUIRE( 125 == pair.first );
    auto tempPairs = pair.second;

    REQUIRE( 2 == tempPairs.size() );

    int j;
    { j = 0;
      auto tPair = tempPairs[ j ];
      REQUIRE( 293.6*dimwits::kelvin == tPair.first );
      auto reactions = tPair.second;
      REQUIRE( 3 == reactions.size() );
      
      int k;
      { k = 0;
        REQUIRE( 3 == reactions[ k ].mfd.value );
        REQUIRE( 19 == reactions[ k ].mtd.value );
        REQUIRE( "MF3 MT19" == reactions[ k ].mtname.value );
      }
      { k = 1;
        REQUIRE( 3 == reactions[ k ].mfd.value );
        REQUIRE( 103 == reactions[ k ].mtd.value );
        REQUIRE( "MF3 MT103" == reactions[ k ].mtname.value );
      }
      { k = 2;
        REQUIRE( 10 == reactions[ k ].mfd.value );
        REQUIRE( 0 == reactions[ k ].mtd.value );
        REQUIRE( "" == reactions[ k ].mtname.value );
      }
    }
    { j = 1;
      auto tPair = tempPairs[ j ];
      REQUIRE( 600*dimwits::kelvin == tPair.first );
      auto reactions = tPair.second;
      REQUIRE( 3 == reactions.size() );
      
      int k;
      { k = 0;
        REQUIRE( 3 == reactions[ k ].mfd.value );
        REQUIRE( 20 == reactions[ k ].mtd.value );
        REQUIRE( "MF3 MT20" == reactions[ k ].mtname.value );
      }
      { k = 1;
        REQUIRE( 6 == reactions[ k ].mfd.value );
        REQUIRE( 104 == reactions[ k ].mtd.value );
        REQUIRE( "MF6 MT104" == reactions[ k ].mtname.value );
      }
      { k = 2;
        REQUIRE( 12 == reactions[ k ].mfd.value );
        REQUIRE( 0 == reactions[ k ].mtd.value );
        REQUIRE( "" == reactions[ k ].mtname.value );
      }
    }
  }
  { i = 1;
    auto pair = matrix[ i ];
    REQUIRE( 9235 == pair.first );
    auto tempPairs = pair.second;

    REQUIRE( 2 == tempPairs.size() );

    int j;
    { j = 0;
      auto tPair = tempPairs[ j ];
      REQUIRE( 293.6*dimwits::kelvin == tPair.first );
      auto reactions = tPair.second;
      REQUIRE( 2 == reactions.size() );
      
      int k;
      { k = 0;
        REQUIRE( 3 == reactions[ k ].mfd.value );
        REQUIRE( 18 == reactions[ k ].mtd.value );
        REQUIRE( "MF3 MT18" == reactions[ k ].mtname.value );
      }
      { k = 1;
        REQUIRE( 3 == reactions[ k ].mfd.value );
        REQUIRE( 102 == reactions[ k ].mtd.value );
        REQUIRE( "MF3 MT102" == reactions[ k ].mtname.value );
      }
    }
    { j = 1;
      auto tPair = tempPairs[ j ];
      REQUIRE( 600*dimwits::kelvin == tPair.first );
      auto reactions = tPair.second;
      REQUIRE( 2 == reactions.size() );
      
      int k;
      { k = 0;
        REQUIRE( 5 == reactions[ k ].mfd.value );
        REQUIRE( 17 == reactions[ k ].mtd.value );
        REQUIRE( "MF5 MT17" == reactions[ k ].mtname.value );
      }
      { k = 1;
        REQUIRE( 8 == reactions[ k ].mfd.value );
        REQUIRE( 100 == reactions[ k ].mtd.value );
        REQUIRE( "MF8 MT100" == reactions[ k ].mtname.value );
      }
    }
  }
}

SCENARIO( "Parsing invalid GROUPR input" ){
  WHEN( "too many neutron groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 0 2 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "4 /\n"                // Card6a
      + "1 2 3 4 5 6/\n"       // Card6b
      + sCard9_10
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR( iss ) );
    }
  }
  WHEN( "too few neutron groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 0 2 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "4 /\n"                // Card6a
      + "1 2 3 4 /\n"       // Card6b
      + sCard9_10
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR( iss ) );
    }
  }
  WHEN( "too many gamm groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 1 2 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "4 /\n"                // Card7a
      + "1 2 3 4 5 6/\n"       // Card7b
      + sCard9_10
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR( iss ) );
    }
  }
  WHEN( "too few gamma groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 1 2 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "4 /\n"                // Card7a
      + "1 2 3 4 /\n"       // Card7b
      + sCard9_10
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR( iss ) );
    }
  }
  WHEN( "No terminating mfd=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 2 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "3 18 'MF3 MT18' /\n"         // Card 9.1
      + "3 102 'MF3 MT102' /\n"       // Card 9.2
      + "10 /\n"                      // Card 9.3
      + "0 /\n"                       // Card 9.4
      + "3 18 'MF3 MT18' /\n"         // Card 9.1
      + "3 102 'MF3 MT102' /\n"       // Card 9.2
      // + "0 /\n"                       // Card 9.4
      + "9235 /\n"                       // Card10
      + "0 /\n"                       // Card10
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR( iss ) );
    }
  }
  WHEN( "No terminating matd=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 2 4 2 2 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + "3 18 'MF3 MT18' /\n"         // Card 9.1
      + "3 102 'MF3 MT102' /\n"       // Card 9.2
      + "10 /\n"                      // Card 9.3
      + "0 /\n"                       // Card 9.4
      + "3 18 'MF3 MT18' /\n"         // Card 9.1
      + "3 102 'MF3 MT102' /\n"       // Card 9.2
      + "0 /\n"                       // Card 9.4
      + "9235 /\n"                       // Card10
      // + "0 /\n"                       // Card10
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR( iss ) );
    }
  }
}
