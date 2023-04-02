#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Goto.h"

using std::string;
using std::vector;

class Render
{
	// frame width
	const int frame_width = 140;
	const char* windowSize = "MODE 140,42";

public:
	Render();

	/// <summary>
	/// Draw the map starting from specified position
	/// </summary>
	/// <param name="map">Map to be drawn</param>
	/// <param name="frame_start">Position to start drawing from</param>
	void drawMap(vector<string>& map, int frame_start);

	/// <summary>
	/// Draw the player icon on the screen
	/// </summary>
	/// <param name="x">X coordinate</param>
	/// <param name="y">Y coordinate</param>
	void drawPlayer(int x, int y);

};

