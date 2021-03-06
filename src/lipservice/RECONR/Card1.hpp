class Card1 {
public:
#include "lipservice/RECONR/Card1/Nendf.hpp"
#include "lipservice/RECONR/Card1/Npend.hpp"

  Argument< Nendf > nendf;
  Argument< Npend > npend;
  
  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      npend( argument::extract< Npend >( is, this->nendf ) ){
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1");
      throw e;
    }
};

