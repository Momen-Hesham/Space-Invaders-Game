#include "Fires.h"
#include "Sound.h"
#include "LED.h"
void Does_MissileHit(PlayerShip *PS_Ptr,MissileElement MS[],int MS_Size,BunkerElement *BK_Ptr,unsigned long * RED_Ptr)
{
	unsigned long MissileTail=0;
	int i;
	for(i=0;i<MS_Size;i++)
	{
		MissileTail=MS[i].y-2;
		if(MS[i].life==1 && BK_Ptr ->life==1) //Check if the missile hit he bunker
		{
			if((BK_Ptr->y >= MissileTail && MissileTail >= (BK_Ptr->y-4))&&(( BK_Ptr->x<= MS[i].x && MS[i].x <=(BK_Ptr->x+18))||((BK_Ptr -> x >= MS[i].x)&&(BK_Ptr ->x <=MS[i].x+2))))
			{
				MS[i].life=0;
			}
		}
		if(PS_Ptr->lives>0 && MS[i].life==1)//check if the missile hit the PlayerShip
			if(PS_Ptr->y >= MissileTail && MissileTail >= (PS_Ptr->y-6)&& PS_Ptr->x<= MS[i].x && MS[i].x <=(PS_Ptr->x+14))
			{
				MS[i].life=0;
				PS_Ptr->lives--;
				Sound_Highpitch();
				(*RED_Ptr)=1;
			}
	}
}

void Does_LaserHit(Strikes Enemy1[],int Enemy_Size,LaserElement LS[],int LS_Size,BunkerElement *BK_Ptr,unsigned long *Score_Ptr,ExtraEnemy * FS_Ptr,unsigned long *GREEN_Ptr)
{
	unsigned long LaserHead=0;
	int i;
	int j;
	for(i=0;i<LS_Size;i++)
	{
		LaserHead=LS[i].y-4;
		for(j=0;j<Enemy_Size;j++)
		{
		
			if(LS[i].life==1 && Enemy1[j].life==1)//Check if a laser shoot hit an enemy
				if(Enemy1[j].y>=LaserHead && LaserHead >= (Enemy1[j].y-4)&& Enemy1[j].x<= LS[i].x && LS[i].x <=(Enemy1[j].x+14))
				{
					Enemy1[j].life=0;
					LS[i].life=0;
					Enemy1[j].Is_Bomb=1;
					(*Score_Ptr)=(*Score_Ptr)+10;
					Sound_Explosion();
					(*GREEN_Ptr)=1;
				}
		}
		if(LS[i].life==1 && BK_Ptr->life==1)//Check if a laser shoot hit the bunker
		{
			if(BK_Ptr->y >= LaserHead && LaserHead >= (BK_Ptr->y-4)&& BK_Ptr->x<= LS[i].x && LS[i].x <=(BK_Ptr->x+18))
			{
				LS[i].life=0;			
			}
		}
		if(FS_Ptr->life==1 && LS[i].life==1 && FS_Ptr->Free_Space==1)//Check if a laser shoot hit a Fast Enemy
		{
			if((FS_Ptr->y)>=LaserHead && LaserHead >= (FS_Ptr->y-7)&& FS_Ptr->x<= LS[i].x && LS[i].x <=(FS_Ptr->x+20))
			{	
			FS_Ptr->life=0;
			FS_Ptr->Is_Bomb=1;
			LS[i].life=0;
			(*Score_Ptr)=(*Score_Ptr)+20;
			Sound_Explosion();
			(*GREEN_Ptr)=1;
			}
		}
		}
}
	

//Initialize The Image and Life of both Missiles and Lasers
void Fires_Init(LaserElement LS[] , MissileElement MS[],int LS_Size,int MS_Size,const unsigned char *MS_Image1,const unsigned char * LS_Image)
{
	int i;
	for(i=0;i<MS_Size;i++)
	{
		MS[i].Image=MS_Image1;
		MS[i].life=0;
	}
	for(i=0;i<LS_Size;i++)
	{
		LS[i].Image=LS_Image;
		LS[i].life=0;
	}

}
//Check if an enemy hit the bunker so the bunker's life will be equal to zero
void Does_EnemyHit(Strikes Enemy1[],int Enemy_Size,BunkerElement *BK_Ptr)
{
	int i;
	for(i=0;i<Enemy_Size;i++)
	{
		for(i=0;i<Enemy_Size;i++)
		{
			if(Enemy1[i].life==1 && BK_Ptr ->life==1)
			{
				if((BK_Ptr->y >= Enemy1[i].y && Enemy1[i].y >= (BK_Ptr->y-4) )&&(( BK_Ptr->x <= Enemy1[i].x && Enemy1[i].x <=(BK_Ptr->x+16)) || ( Enemy1[i].x <= BK_Ptr->x && (Enemy1[i].x+14) >= BK_Ptr->x)  ))
				{
					BK_Ptr->life=0;
				
				}
			}
		}
	}	
}
//Check if an enemy hit the player ship which led to Game Over state
void Does_PlayerHit(Strikes Enemy1[],int Enemy_Size,PlayerShip *PS_Ptr)
{
	int i;
	for(i=0;i<Enemy_Size;i++)
	{
			if(Enemy1[i].life==1 && PS_Ptr->lives >0)
		{
			if((PS_Ptr->y >= Enemy1[i].y && Enemy1[i].y >= (PS_Ptr->y-5))&&( (PS_Ptr->x<= Enemy1[i].x && Enemy1[i].x <=(PS_Ptr->x+16))|| ( Enemy1[i].x <= PS_Ptr->x && (Enemy1[i].x+14) >= PS_Ptr->x)))
			{
				PS_Ptr->lives=0;
				
			}
		}
	}
}
