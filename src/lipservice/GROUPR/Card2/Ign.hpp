struct Ign {
  using Value_t = int;
  static std::string name(){ return "ign"; }

  static std::string description(){
    return 
        "The ign option specfies the neutron group structure. The allowed\n"
        "values and their meanings are:\n"
        "     ign          meaning\n"
        "     ---          -------\n"
        "      1           arbitrary structure (read in)\n"
        "      2           csewg 239-group structure\n"
        "      3           lanl 30-group structure\n"
        "      4           anl 27-group structure\n"
        "      5           rrd 50-group structure\n"
        "      6           gam-i 68-group structure\n"
        "      7           gam-ii 100-group structure\n"
        "      8           laser-thermos 35-group structure\n"
        "      9           epri-cpm 69-group structure\n"
        "     10           lanl 187-group structure\n"
        "     11           lanl 70-group structure\n"
        "     12           sand-ii 620-group structure\n"
        "     13           lanl 80-group structure\n"
        "     14           eurlib 100-group structure\n"
        "     15           sand-iia 640-group structure\n"
        "     16           vitamin-e 174-group structure\n"
        "     17           vitamin-j 175-group structure\n"
        "     18           xmas nea-lanl\n"
        "     19           ecco  33-group structure\n"
        "     20           ecco 1968-group structure\n"
        "     21           tripoli 315-group structure\n"
        "     22           xmas lwpc 172-group structure\n"
        "     23           vit-j lwpc 175-group structure\n"
        "     24           shem cea 281-group structure\n"
        "     25           shem epm 295-group structure\n"
        "     26           shem cea/epm 361-group structure\n"
        "     27           shem epm 315-group structure\n"
        "     28           rahab aecl 89-group structure\n"
        "     29           ccfe   660-group structure  (30 MeV)\n"
        "     30           ukaea 1025-group structure  (30 MeV)\n"
        "     31           ukaea 1067-group structure (200 MeV)\n"
        "     32           ukaea 1102-group structure   (1 GeV)\n"
        "     33           ukaea  142-group structure (200 MeV)\n"
        "     34           lanl 618-group structure";
  }

  static bool verify( const Value_t i ) { return ( i > 0 ) and ( i < 35 ); }
};
