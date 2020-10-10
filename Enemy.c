#include "Enemy.h"

void (*SFI_Ptr)(void);

//Intialize Enemies life ,Images ,Position and other Properties 
void Init_Enemy(int size,int init,unsigned long Image,Strikes Enemy1[],unsigned char ENEMY10H1,unsigned char ENEMY10W1,const unsigned char *Enemies1[]) 
{	
	int i;
  for(i=init;i<size;i++)
	{
		
		
    Enemy1[i].x = ENEMY10W1*(i%4)+4*(i%4);
    Enemy1[i].y = ENEMY10H1+ENEMY10H1*(i/4);
    Enemy1[i].image[0] = Enemies1[Image];
    Enemy1[i].image[1] = Enemies1[Image+1];		
    Enemy1[i].life = 1;
		Enemy1[i].center=Enemy1[i].y-ENEMY10H1/2;
		Enemy1[i].Is_Bomb=0;
		Enemy1[i].Bomb_Counter=10;		
		
	}
}

 void Init_Bonus(ExtraEnemy *FS_Ptr , unsigned long ENEMYH ,const unsigned char * SB0,void (*Sound_Fun_Ptr)(void))
 {
 	FS_Ptr->x=0;
	FS_Ptr->y=ENEMYH;
	FS_Ptr->Image=SB0;
	FS_Ptr->life=1;
	FS_Ptr->Is_Bomb=0;
	FS_Ptr->Bomb_Counter=10;
	SFI_Ptr=Sound_Fun_Ptr;
	FS_Ptr->Free_Space=0;
 }


 //Move Enemy 2 pixels each time and down 2 pixels after moving each row
int r=0,d=0;  
int Down=0;
void Move_Enemy(int size,Strikes Enemy[],unsigned char ENEMYH,unsigned long temp2)
{ 
	int i;
	if(temp2==10)
	{
		if(Enemy[size-1].x == 68)
		{
			r=0;
			d=1;
			if(Down==0)
				Down=1;
		}
		if(Enemy[0].x==0)
		{
			r=1;
			d=0;
			Down=0;
		}
		
		for(i=0;i<size;i++)
		{
			if(r == 1 && Down!=1 )	
			{				
				Enemy[i].x += 2; // move to right
				Enemy[i].center=Enemy[i].y-ENEMYH/2;	
			}
			else if (r==0 && Down!=1)
			{		
				Enemy[i].x -= 2; // move to left
				Enemy[i].center=Enemy[i].y-ENEMYH/2;	
			}
				if(d==1 && Down==1 && Enemy[i].y < 46)
			{
				
				Enemy[i].y+=2;	// move Down		
				Enemy[i].center=Enemy[i].y-ENEMYH/2;	
				if(i==(size-1))
					Down=2;
			}	
		}
	}
}
