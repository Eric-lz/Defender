#pragma once

#include <string>
#include <vector>
#include "Player.h"
#include "Enemy.h"

using std::string;
using std::vector;
using std::ifstream;

class Map
{
  vector<string> map;
  int mapLength;

public:
  Map(string filename);

  vector<string> parse(Player& player, vector<Enemy>& enemies);

  int length();
};

