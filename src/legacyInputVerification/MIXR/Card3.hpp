class Card3 {
public:

#include "legacyInputVerification/MIXR/Card3/Matn.hpp"
#include "legacyInputVerification/MIXR/Card3/Wtn.hpp"

#include "legacyInputVerification/MIXR/Card3/src/readMatnWtnList.hpp"

std::vector< std::pair< Argument< Matn >, Argument< Wtn > > > matnWtnList;

template< typename Istream >
Card3( Istream& is, const size_t nnin )
try:
  matnWtnList( readMatnWtnList( is, nnin ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
