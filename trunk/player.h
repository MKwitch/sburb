class player
{
   public:
      std::vector<grist> grists; // grist class is defined in sburb.h
};

// stores all players in one class
// size is constant, but nu
class players: public std::vector<player>
{
   public:
};
