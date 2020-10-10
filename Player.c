#include "Player.h"


//Move the player shp in x axis only depending on the reading of the "JoyStick" NOT potentiometer
void Move_Player(unsigned long Readings,PlayerShip *PS)
{
	if(Readings>4000 & PS->x<64)
		PS->x+=2;
	if(Readings<100 & PS->x >0)
		PS->x-=2;
}

