#include "Enemy.h"
#include "Player.h"

struct Missile{
	unsigned long x;
	unsigned long y;
	const unsigned char * Image;
	unsigned long life;
};
typedef struct Missile MissileElement;


struct Laser{
	unsigned long x;
	unsigned long y;
	const unsigned char * Image;
	unsigned long life;
};
typedef struct Laser LaserElement;

struct Bunker{
	unsigned long x;
	unsigned long y;
	const unsigned char *Image;
	unsigned long life;
};
typedef struct Bunker BunkerElement;
void Does_MissileHit(PlayerShip *PS_Ptr,MissileElement MS[],int MS_Size,BunkerElement *BK_Ptr,unsigned long *GREEN_Ptr);

void Does_LaserHit(Strikes Enemy1[],int Enemy_Size,LaserElement LS[],int LS_Size,BunkerElement *BK_Ptr,unsigned long *Score_Ptr,ExtraEnemy * FS_Ptr,unsigned long *RED_Ptr);

void Fires_Init(LaserElement LS[] , MissileElement MS[],int LS_Size,int MS_Size,const unsigned char *MS_Image1,const unsigned char * LS_Image);

void Does_PlayerHit(Strikes Enemy1[],int Enemy_Size,PlayerShip *PS_Ptr);


void Does_EnemyHit(Strikes Enemy1[],int Enemy_Size,BunkerElement *BK_Ptr);
