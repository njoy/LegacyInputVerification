template< typename Istream >
static std::optional< Card10a >
 readCard10a( Istream& is, const int ileg )
{

  if( ileg == 2 ){
    return Card10a( is );
  }
  return std::nullopt;
}
