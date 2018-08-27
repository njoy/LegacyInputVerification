struct Matd : public argument::common::Matd {
  using Value_t = argument::common::Matd::Value_t;
  static std::string name(){ return "matd"; }
  static std::string description(){
    return
      "The matd argument specifies the next Material number to be processed.\n"
      "It is an integer corresponding to an ENDF material number and refers\n"
      "to a material number on the PENDF tape.\n"
      "\n"
      "If matd value of 0 indicates that GROUPR is to be finished.";
  }
  
  static bool verify( const Value_t& m ){ 
    return ( m >= 0 ) and ( m < 10000 ); }
};
