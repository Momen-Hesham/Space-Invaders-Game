//#include "Fires.h"
struct Player
{
	unsigned long x;
	unsigned long y;
	const unsigned char* Image;
	unsigned long lives;
	unsigned long center;

};

typedef struct Player PlayerShip;

//Function to Move The PlayerShip
void Move_Player(unsigned long Readings ,PlayerShip *PS);
