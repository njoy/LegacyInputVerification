class Card9 {
public:
  #include "lipservice/ACER/Card9/Mti.hpp"
  #include "lipservice/ACER/Card9/Nbint.hpp"
  #include "lipservice/ACER/Card9/Mte.hpp"
  #include "lipservice/ACER/Card9/Ielas.hpp"
  #include "lipservice/ACER/Card9/Nmix.hpp"
  #include "lipservice/ACER/Card9/Emax.hpp"
  #include "lipservice/ACER/Card9/Iwt.hpp"

  Argument< Mti > mti;
  Argument< Nbint > nbint;
  Argument< Mte > mte;
  Argument< Ielas > ielas;
  Argument< Nmix > nmix;
  Argument< Emax > emax;
  Argument< Iwt > iwt;

  template< typename Char >
  Card9( iRecordStream< Char >& is )
    try:
    mti( argument::extract< Mti >( is ) ),
    nbint( argument::extract< Nbint >( is ) ),
    mte( argument::extract< Mte >( is ) ),
    ielas( argument::extract< Ielas >( is ) ),
    nmix( argument::extract< Nmix >( is ) ),
    emax( argument::extract< Emax >( is ) ),
    iwt( argument::extract< Iwt >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 9" );
      throw e;
    }
};
