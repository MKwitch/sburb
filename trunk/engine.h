// manages all of the non-graphical engine elements, such as tiles, floors, and of course the entire map.

class indicator
{
   public:
      indicator();
      indicator(unsigned int, unsigned int);
      
      unsigned int x, y;
};

class tile
{
   public:
      tile();
      tile(bool, bool, char);
      bool IsObstructed;
      bool IsOpenSpace;
      
      bool HasStructure();
      
      std::vector<object> ObjectsOnTile;
      char type;
};

class level: public std::vector< std::vector<tile> >
{
   public:
      level();
      level(unsigned int, unsigned int);
      
      void CreateRoom(unsigned int, unsigned int, unsigned int, unsigned int);
      void CreateFloor(unsigned int, unsigned int, unsigned int, unsigned int);
      void CreateHole(unsigned int, unsigned int, unsigned int, unsigned int);
      
      void PlaceFloorFeature(unsigned int, unsigned int, char);
};

class world: public std::vector<level>
{
   public:
      world();
      world(unsigned int, unsigned int, unsigned int);
      
      void NewLevel();
      void SetLevel(unsigned int);
      void UpOneLevel();
      void DownOneLevel();
      
      void SetPosition(unsigned int, unsigned int, unsigned int);
      
      void Show();
      
      indicator PlayerPosition;
      
      unsigned int currentlevel;
      unsigned int x;
      unsigned int y;
};

#include "engine.cpp"
