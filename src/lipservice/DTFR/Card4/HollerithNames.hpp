struct HollerithNames {
  using Value_t = std::vector<std::string >;
  static std::string name(){ return "hollerithNames"; }

  static std::string description() {
    return 
      "HollerithNames is a vector of the six-character hollerith names for\n"
      "edits. User may enter names for as many cards as needed. There will\n"
      "be (iptotl - 3) names read.";
  }

  static bool verify( const Value_t& hollerithNames, int nConstants ){
    for ( auto hol : hollerithNames ){
      if ( hol.size() > 6 ) { return false; } 
    }
    return ( long(hollerithNames.size()) == (nConstants) );
  }
};
