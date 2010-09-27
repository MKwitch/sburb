using namespace std;

// indicator
indicator::indicator()
{
   x = 0;
   y = 0;
}

indicator::indicator(unsigned int nx, unsigned int ny)
{
   x = nx;
   y = ny;
}

// tile
tile::tile()
{
   IsObstructed = 0;
   IsOpenSpace = 0;
   type = ' ';
}

tile::tile(bool obstruction, bool open, char tiletype)
{
   IsObstructed = obstruction;
   IsOpenSpace = open;
   type = tiletype;
}

bool tile::HasStructure()
{
   cout << "Why are you even calling this when structures DNE?\n";
   return 0;
}

// level
level::level()
{
   vector<tile> temp;
   
   for ( unsigned int i = 0; i < 25; i ++ )
   {
      for ( unsigned int j = 0; j < 25; j ++ )
      {
         temp.push_back(tile(0,1,' '));
      }
      push_back(temp);
      temp.clear();
   }
}

level::level(unsigned int xdimension, unsigned int ydimension)
{
   vector<tile> temp;
   
   for ( unsigned int i = 0; i < xdimension; i ++ )
   {
      for ( unsigned int j = 0; j < ydimension; j ++ )
      {
         temp.push_back(tile(0,1,' '));
      }
      push_back(temp);
      temp.clear();
   }
}

void level::CreateRoom(unsigned int leftmost, unsigned int uppermost, unsigned int xdimension, unsigned int ydimension)
{
   if ( leftmost + xdimension > size() )
   {
      cout << "NONFATAL: Room larger than level. May not perform properly.";
   }
   
   for ( unsigned int i = 0; i < size(); i ++ )
   {
      if ( uppermost + ydimension > at(i).size() )
      {
         cout << "NONFATAL: Room larger than level. May not perform properly.";
      }
      for ( unsigned int j = 0; j < at(i).size(); j ++ )
      {
         if ( i > leftmost && i < leftmost + xdimension && j > uppermost && j < uppermost + ydimension ) // if inside room
         {
            at(i)[j].IsOpenSpace = 0;
            at(i)[j].IsObstructed = 0;
            at(i)[j].type = '+';
         }
         else if ( ( i == leftmost && j >= uppermost && j <= uppermost + ydimension ) || ( i == leftmost + xdimension && j >= uppermost && j <= uppermost + ydimension ) || ( j == uppermost && i >= leftmost && i <= leftmost + xdimension ) || ( j == uppermost + ydimension && i >= leftmost && i <= leftmost + xdimension ) )
         {
            at(i)[j].IsOpenSpace = 0;
            at(i)[j].IsObstructed = 1;
            at(i)[j].type = '=';
         }
      }
   }
}

void level::CreateFloor(unsigned int leftmost, unsigned int uppermost, unsigned int xdimension, unsigned int ydimension)
{
   if ( leftmost + xdimension > size() )
   {
      cout << "NONFATAL: Room larger than level. May not perform properly.";
   }
   
   for ( unsigned int i = 0; i < size(); i ++ )
   {
      if ( uppermost + ydimension > at(i).size() )
      {
         cout << "NONFATAL: Room larger than floor. May not perform properly.";
      }
      for ( unsigned int j = 0; j < at(i).size(); j ++ )
      {
         if ( i >= leftmost && i <= leftmost + xdimension && j >= uppermost && j <= uppermost + ydimension ) // if inside room
         {
            at(i)[j].IsOpenSpace = 0;
            at(i)[j].IsObstructed = 0;
            at(i)[j].type = '+';
         }
      }
   }
}

void level::CreateHole(unsigned int leftmost, unsigned int uppermost, unsigned int xdimension, unsigned int ydimension)
{
   if ( leftmost + xdimension > size() )
   {
      cout << "NONFATAL: Hole larger than floor. May not perform properly.";
   }
   
   for ( unsigned int i = 0; i < size(); i ++ )
   {
      if ( uppermost + ydimension > at(i).size() )
      {
         cout << "NONFATAL: Hole larger than floor. May not perform properly.";
      }
      for ( unsigned int j = 0; j < at(i).size(); j ++ )
      {
         if ( i >= leftmost && i <= leftmost + xdimension && j >= uppermost && j <= uppermost + ydimension ) // if inside room
         {
            at(i)[j].IsOpenSpace = 1;
            at(i)[j].IsObstructed = 0;
            at(i)[j].type = ' ';
         }
      }
   }
}  

void level::PlaceFloorFeature(unsigned int x, unsigned int y, char feature)
{
   if ( x < size() )
   {
      if ( y < at(x).size() )
      {
         at(x)[y].type = feature;
      }
   }
   else { cout << "NONFATAL: Feature placed outside room."; }
}

// world

world::world()
{
   push_back(level(25,25));
   push_back(level(25,25));
   push_back(level(25,25));
   
   x = 25;
   y = 25;
}

world::world(unsigned int xdimension, unsigned int ydimension, unsigned int zdimension)
{
   for ( unsigned int i = 0; i < zdimension; i ++ )
   {
      push_back(level(xdimension,ydimension));
   }
   
   x = xdimension;
   y = ydimension;
}

void world::NewLevel()
{
   push_back(level(x,y));
}

void world::SetLevel(unsigned int nlevel)
{
   if ( nlevel < size() )
   {
      currentlevel = nlevel;
   }
   else { cout << "Causing access boundary areas in the world is probably a bad idea."; }
}

void world::UpOneLevel()
{
   if ( currentlevel + 1 < size() )
   {
      currentlevel += 1;
   }
   else { cout << "You have reached the end of the floors. Please turn back."; }
}

void world::DownOneLevel()
{
   if ( currentlevel > 0 )
   {
      currentlevel -= 1;
   }
   else { cout << "There is nowhere further down to go!"; }
}

void world::SetPosition(unsigned int x, unsigned int y, unsigned int z)
{
   if ( z < size() )
   {
      if ( x < at(z).size() )
      {
         if ( y < at(z)[x].size() )
         {
            PlayerPosition.x = x;
            PlayerPosition.y = y;
            currentlevel = z;
         }
      }
   }
}

void world::Show()
{
   for ( unsigned int i = 0; i < at(currentlevel).size(); i ++ )
   {
      for ( unsigned int j = 0; j < at(currentlevel)[i].size(); j ++ )
      {
         cout << at(currentlevel)[i][j].type;
      }
      cout << endl;
   }
}
