// contains classes for Sburb game abstractions: structures, objects, and grists

class grist
{
   public:
      grist();
      grist(std::string);
      grist(std::string, int);
      grist(std::string, int, bool);
      
      std::string name;
      int amount;
      /* On the "amount" variable:
         This variable has entirely different roles depending on context.
         gristList class: entirely ignored
         player class: stores amount of grist held by the player
         object class: stores grist costs of that object
      */
      bool found; // only used in player grist vector, to see if the player has "discovered" this grist yet
};

// stores grist types
class gristlist: public std::map<std::string, grist>
{
   public:
      gristlist();
};

class object
{
   public:
      gristlist grists;
};

class structure
{
   public:
      std::vector< std::vector<bool> > TileObstructions; // if TileObstructions[x][y] == 1, tile at [x][y] from the upper left cannot be passed
};

