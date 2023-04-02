#include "Player.h"

Player::Player()
{
  x = 30;
  y = 15;
  vel = 0;
}

Player::Player(int initx, int inity)
{
	x = initx;
	y = inity;
	vel = 0;
}

void Player::action(char k)
{
  switch (k) {
    // Move keys
    case 'w':
      y--;
      break;
    case 's':
      y++;
      break;
    case 'a':
      if (vel > 1)
        vel--;
      break;
    case 'd':
      if (vel < 3)
        vel++;
      break;

    // Fire
    case ' ':
      fire();

    // Key not bound
    default:
      break;
  }

  // Update position
  x += vel;

  // hard limit 1 < y < 35
  if (y <= 1)
    y = 1;
  else if (y >= 35)
    y = 35;

  // hard limit 0 < x < map length
  if (x > 415) {
    x = 0;
  }
}

void Player::setPos(int posx, int posy)
{
	x = posx % 415;
	y = posy;
}

int Player::getX()
{
  return x;
}

int Player::getY()
{
  return y;
}

int Player::getVel()
{
	return vel;
}

void Player::fire()
{

}
