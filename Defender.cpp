// Defender.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "Enemy.h"
#include "Map.h"
#include "Projectile.h"
#include "Render.h"
#include "Input.h"

using std::string;
using std::vector;

int main()
{
	// Map file name
	const string mapname = "nivel1.txt";

	// Objects
	Player player;					// Player object
	vector <Enemy> enemies;	// Enemy object vector
	Map map(mapname);				// Map object
	Render render;					// Renderer object
	vector <Projectile> projectiles;

	// Framebuffer
	vector<string> frame;

	// Parse the map (get player and enemies position)
	frame = map.parse(player, enemies);

	// Tick counter
	unsigned long long tick = 0;

	// Tick loop
	while (true) {
		// Capture input
		char key = Input::keyPressed();

		// Character action
		player.action(key);

		// Draw frame
		render.drawMap(frame, player.getX());
		render.drawPlayer(30, player.getY());

		// Update every 80 ms
		Sleep(80);
		tick++;
	}

	return 0;
}