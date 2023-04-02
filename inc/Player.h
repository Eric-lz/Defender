#pragma once

class Player
{
private:
	// position
	int x, y;

	// speed
	int vel;

public:
	Player();
	Player(int initx, int inity);

	/// <summary>
	/// Receives keyboard input and acts accordingly
	/// </summary>
	/// <param name="k">Key pressed</param>
	void action(char k);

	/// <summary>
	/// Set player position
	/// </summary>
	/// <param name="posx">X coordinate</param>
	/// <param name="posy">Y coordinate</param>
	void setPos(int posx, int posy);

	int getX();
	int getY();

	int getVel();

private:
	void fire();
};
