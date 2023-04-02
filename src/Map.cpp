#include "Map.h"
#include <fstream>

Map::Map(string filename)
{
  ifstream file(filename);

  // read and save map file to string
  string line;
  while (getline(file, line)) {
    map.push_back(line);
  }

  //mapLength = line.length();

  file.close();
}

vector<string> Map::parse(Player& player, vector<Enemy>& enemies)
{
  bool playerfound = false;
  int lineNumber = 0;

  for (auto& line : map) {
    // look for player symbol @
    size_t found = line.find('@');

    // if @ is found, set player position
    if (found != string::npos) {
      player.setPos(found, lineNumber);
      playerfound = true;

      // remove @ from map
      line.at(found) = ' ';
      map[lineNumber] = line;
    }


    // look for enemy symbol X
    found = line.find('X');

    while (found != string::npos) {
      // create enemy and push it into enemy vector
      Enemy e(found, lineNumber);
      enemies.push_back(e);

      // remove X from map
      line.at(found) = ' ';
      map[lineNumber] = line;

      // look for another enemy on the same line
      found = line.find('X', found + 1);
    }

    // next line
    lineNumber++;
  }

  // if player was not found, set arbitrary position
  if (!playerfound) {
    player.setPos(30, map.size() / 2);
  }

  return map;
}

int Map::length()
{
  return mapLength;
}
