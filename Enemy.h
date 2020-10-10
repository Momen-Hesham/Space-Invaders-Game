struct EnemyShips {
	unsigned long x;      // x coordinate
	unsigned long y;      // y coordinate
	const unsigned char *image[2]; // ptr->image
	unsigned long life;            // 0=dead, 1=alive
	unsigned long center;
	unsigned long Is_Bomb;
	unsigned long Bomb_Counter;
};
typedef struct EnemyShips Strikes;

struct FastEnemy {
unsigned long x;
	unsigned long y;
	unsigned long life;
	const unsigned char * Image;
	unsigned long Is_Bomb;
	unsigned long Bomb_Counter;
	unsigned long Free_Space;
};
typedef struct FastEnemy ExtraEnemy;

//Initialize The EnemyShips , Init = first Player Ship you want to Initialize , size= No.Of EnemyShips,Image = The Required Image to That EnemyShip
void Init_Enemy(int size,int init,unsigned long Image,Strikes Enemy1[],unsigned char ENEMY10H1,unsigned char ENEMY10W1,const unsigned char *Enemies1[]);
//Function used to move the EnemyShips
void Move_Enemy(int size,Strikes Enemy[],unsigned char ENEMYH,unsigned long temp2);

//void Move_Bonus(ExtraEnemy * FS_Ptr);

void Init_Bonus(ExtraEnemy *FS_Ptr , unsigned long ENEMYH ,const unsigned char * SB0,void (*Sound_Fun_Ptr)(void));
