#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class Dragon :public Enemy {
    private:
    static int counter;
    int direction=0;
    public:

Dragon()
{
        emy.loadFromFile("img/dragon2.png");
        enemy.setTexture(emy);
        enemy.setScale(0.35, 0.35);
        enemy.setPosition(340,-248);
        enemy.setOrigin(0.9/2,0.9/2); 
}

    void move(int x,int y)
    {
        enemy.move(0,1*coming_speed);
        if(enemy.getPosition().y >= 10)
        enemy.setPosition(340,10);
    }
   
   void cpattack(int &dr_b,Bomb**&B3,Enemy*&E,float& dr_b_time)
   {
       if (dr_b_time > 0.15) 
                        {
                        dr_b++;
                        Bomb* ptr = new Bomb;
                        ptr->setSprite("img/B2.png");

                        Bomb** temp = new Bomb*[dr_b - 1];
                        for (int i = 0; i < dr_b - 1; i++) 
                        {
                            temp[i] = B3[i];
                        }
                        delete[] B3;
                        B3 = new Bomb*[dr_b];

                        for (int i = 0; i < dr_b - 1; i++) {
                            B3[i] = temp[i];
                        }

                        delete[] temp;

                        B3[dr_b - 1] = ptr;
                        B3[dr_b - 1]->bomb.setPosition(E->enemy.getPosition().x + 94, E->enemy.getPosition().y +165);
                        dr_b_time = 0;
                        }
                        for (int i = 0; i < dr_b; i++)
			            {
			            	if (B3[i] != nullptr && B3[i]->bomb.getPosition().y > 700)
			            	{
			            		dr_b--;
			            		delete B3[i];
			            		B3[i] = nullptr;
			            		Bomb** temp = B3;
			            		B3 = new Bomb * [dr_b];
			            		int j = 0;
			            		for (int k = 0; k < dr_b + 1; k++)
			            		{
			            			if (temp[k] != nullptr)
			            			{
			            			 B3[j] = temp[k];
			            				j++;
			            			}
			            		}
			            		delete[] temp;
			            	}
			            }
    }

    void b_move(Bomb **B,int dr_b,float direction)
    {
       for (int i = 0; i < dr_b; i++) 
        {
             if (B != nullptr)
              {
                 B[i]->bomb.move(direction*B[i]->bomb_speed, 1*B[i]->bomb_speed);
              }
       
        }
    }

    void attack(Bomb* b)
    {
                     
    }
     void Score_inc(Score * S)
    {
        S->setScore(50);
    }

~Dragon()
{
    
}

};
int Dragon::counter=0;

#endif