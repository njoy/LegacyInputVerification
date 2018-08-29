struct Iedit {
  using Value_t = int;
  static std::string name(){ return "iedit"; }

  static std::string description(){
    return
      "The iedit value is for edit control, and can either equal 0 or 1.\n"
      "A value of 0 correspond to table-edits option, while a value of 1\n"
      "corresponds to the separate-edits option (used for 'CLAW'-format cross\n"
      "sections). The former (iedit = 0) invokes use of cards 3-5, while the\n"
      "latter (iedit = 1 ) invokes use of card 6.\n"
      "\n"
      "iedit should not equal any value aside from 0 or 1, and has a default\n"
      "value of 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ){ return i == 0 or i == 1; }
};

