// this is the file that runs the main loop and manages all those silly SDL things

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

// i think stl is a pretty cool guy eh has templates and doesnt afraid of anything
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <queue>
#include <stack>

#include "sburb.h"
#include "engine.h"

using namespace std;

int main(int argv, char * argc[])
{
   world GWorld(25,25,3); // initialize a world with three 25x25 floors
   GWorld[0].CreateRoom(5,5,15,15); // draw a wall-enclosed room on the bottom floor
   GWorld[1].CreateRoom(5,5,15,15); // do the same on the floor above
   GWorld[2].CreateFloor(5,5,15,15); // and finally add a roof
   
   GWorld.SetPosition(8,8,1);
   GWorld.Show();

   return 0;
}
