#include <SFML/Graphics.hpp>
#include<string.h>
#include "Bullet.h"
#include "Add_ons.h"
#include "Enemy.h"
#include "Bomb.h"
#include "Lives.h"
using namespace sf;
class Player {
private:
	static int count;
	int x, y;
	float time_count1 = 0;
	float time_count2 = 0;
	int c = 1;////for  chaniging fire of bullet
	float all_bull = 0;
	float sh = 0;
	int bullet_remove_counter = 0;
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.7;
	bool rotate=0;
	bool is_powermode = false;
	bool is_firemode = false;
	

	////////////////////////////Collion With Add-on///////////////

	bool collion(Add_ons* A)
	{
		if (A != nullptr)
		{

			if (((A->add_on->getPosition().y + 5 >= sprite.getPosition().y - 15) && (A->add_on->getPosition().y - 50 <= sprite.getPosition().y + 10)) &&
				((A->add_on->getPosition().x + 5 >= sprite.getPosition().x - 15) && (A->add_on->getPosition().x - 5 <= sprite.getPosition().x + 55)))
			{
				return 1;
			}
		}
		return 0;

	}

	/////////////////////////////////////////////////
	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340; y = 625;
		sprite.setPosition(x, y);
		sprite.setScale(0.60, 0.60);
	}
	///////////////rotate////////
	void rotate_ship()
	{
		rotate=1;
		if(rotate)
		{
		if (count == 1)
		{
			tex.loadFromFile("img/player2.png");
			sprite.setTexture(tex);
		}
		else if (count == 2)
		{
			tex.loadFromFile("img/player4.png");
			sprite.setTexture(tex);
		}
		else if (count == 3)
		{
			tex.loadFromFile("img/player5.png");
			sprite.setTexture(tex);
		}
		else if(count == 4)
        {
			tex.loadFromFile("img/player3.png");
			sprite.setTexture(tex);
		}
		else if(count == 5)		
		 {
			tex.loadFromFile("img/player_ship.png");
			sprite.setTexture(tex);
			count = 0;
		}
		count++;
		}	
		rotate=0;
	}
	void rot(int x)
	{
		if (x == 1)
		{
			tex.loadFromFile("img/player2.png");
			sprite.setTexture(tex);
		}
		else if (x == 2)
		{
			tex.loadFromFile("img/player3.png");
			sprite.setTexture(tex);
		}
		else if (x == 3)
		{
			tex.loadFromFile("img/player4.png");
			sprite.setTexture(tex);
		}
		else if(x == 4)
        {
			tex.loadFromFile("img/player5.png");
			sprite.setTexture(tex);
		}
		else
		 {
			tex.loadFromFile("img/player_ship.png");
			sprite.setTexture(tex);
		}

	}
	////////////////Player Collion With enemy /////////////
	bool bombCollion(Bomb * B,Lives**L)
	{
		for(int i=0;i<7;i++)
		{
		           if ((B[i].bomb.getPosition().x+8 >= sprite.getPosition().x - 30) && (B[i].bomb.getPosition().x-8  <=  sprite.getPosition().x + 50)
						&& (B[i].bomb.getPosition().y+15 >= sprite.getPosition().y - 15) && (B[i].bomb.getPosition().y-10  <=sprite.getPosition().y + 10) && is_powermode!=true)
					{
						cout<<"Life Decremented\n";
						for(int i=2;i>=0;i--)
			            {
			            	if(L[i]!= nullptr)
			            	{
                                 delete L[i];
			            	      L[i]=nullptr;
			            		  break;				
			            	}
			            }
						if(B[i].bomb.getPosition().x > 355 || B[i].bomb.getPosition().x < 320) 
						sprite.setPosition(-20,650);


						return 1;
					}
		}
		return 0;
	}

	bool bombCollion1(Bomb* B,Lives**L,bool &enemy_sc)
{
    if ((B->bomb.getPosition().x + 20.25 >= sprite.getPosition().x - 35)
        && (B->bomb.getPosition().x - 10.25 <= sprite.getPosition().x + 30)
        && (B->bomb.getPosition().y + 878.5 >= sprite.getPosition().y - 15)
        && (B->bomb.getPosition().y - 878.5 <= sprite.getPosition().y + 10)
        && !is_powermode)
    {
        cout << "Life Decremented\n";	
		    for(int i=2;i>=0;i--)
			{
				if(L[i]!= nullptr)
				{
                     delete L[i];
				      L[i]=nullptr;
     	  				enemy_sc=0;
					  break;				
				}
			}	
			sprite.setPosition(-40,650);
        return true;
    }
    return false;
}
bool bombCollion2(Bomb **B,Lives**L,int dr_b,bool &enemy_sc)
	{
		for(int i=0;i<dr_b;i++)
		{
		           if ((B[i]->bomb.getPosition().x+4 >= sprite.getPosition().x - 30) && (B[i]->bomb.getPosition().x  <=  sprite.getPosition().x + 50)
						&& (B[i]->bomb.getPosition().y+15 >= sprite.getPosition().y - 15) && (B[i]->bomb.getPosition().y-10  <=sprite.getPosition().y + 10) && is_powermode!=true)
					{
						cout<<"Life Decremented\n";
						for(int i=2;i>=0;i--)
			            {
			            	if(L[i]!= nullptr)
			            	{
                                 delete L[i];
			            	      L[i]=nullptr;
				  				enemy_sc=0;
			            		  break;				
			            	}
			            }
						sprite.setPosition(0,650);


						return 1;
					}
		}
		return 0;
	}



	///////////with Invadors///////////////////////////////
	bool playerCollion(Enemy** E,Lives**L)
	{
		for(int i=0;i<3;i++)
		for(int j=0;j<15;j++)
		if (E[i][j].enemy.getPosition().x != -100)
		{
		           if ((E[i][j].enemy.getPosition().x + 30 >=sprite.getPosition().x - 35) && (E[i][j].enemy.getPosition().x - 30 <=  sprite.getPosition().x + 55)
						&& (E[i][j].enemy.getPosition().y + 10 >= sprite.getPosition().y - 15) && (E[i][j].enemy.getPosition().y - 10 <=sprite.getPosition().y + 10) && is_powermode!=true)
					{
						cout<<"Life Decremented\n";
						for(int i=2;i>=0;i--)
							{
								if(L[i]!= nullptr)
								{
            				         delete L[i];
								      L[i]=nullptr;
									  break;				
								}
							}
						sprite.setPosition(340,650);
						return 1;
					}
					
	    }
		return 0;
	}
	////////////With Monster/////
	 bool playerCollion1(Enemy * E,Lives**L,bool &enemy_sc)
	{
		if (E->enemy.getPosition().x <= 700)
		{
		           if ((E->enemy.getPosition().x + 66.55 >=sprite.getPosition().x - 35) && (E->enemy.getPosition().x - 10.55 <=  sprite.getPosition().x + 55)
						&& (E->enemy.getPosition().y + 100.15 >= sprite.getPosition().y - 15) && (E->enemy.getPosition().y - 60.15 <=sprite.getPosition().y + 10) && is_powermode !=true)
					{
						cout<<"Life Decremented\n";
						for(int i=2;i>=0;i--)
							{
								if(L[i]!= nullptr)
								{
            				         delete L[i];
								      L[i]=nullptr;
					  				enemy_sc=0;

									  break;				
								}
							}
							
						sprite.setPosition(0,650);
						return 1;
					}					
	    }
		return 0;
	}
	///////////////////////////////collion with dragon//////
	 bool playerCollion2(Enemy * E,Lives**L,bool &enemy_sc)
	{
		if (E->enemy.getPosition().y <= 700 && E->enemy.getPosition().y >= 0)
		{
		           if ((E->enemy.getPosition().x + 200 >=sprite.getPosition().x - 35) && (E->enemy.getPosition().x <=  sprite.getPosition().x + 55)
						&& (E->enemy.getPosition().y + 140 >= sprite.getPosition().y - 15) && (E->enemy.getPosition().y - 30 <=sprite.getPosition().y + 10) && is_powermode !=true)
					{
						cout<<"Life Decremented\n";
						for(int i=2;i>=0;i--)
							{
								if(L[i]!= nullptr)
								{
            				         delete L[i];
								      L[i]=nullptr;
					  				enemy_sc=0;
									  break;				
								}
							}
						sprite.setPosition(0,650);
						return 1;
					}					
	    }
		return 0;
	}
	//////////////////////////////////////////////////////
	void fire7(Bullet**& b, int& s, float x, int u)
{
    s += u;
    Bullet* ptr = new Bullet;

    if (b == nullptr)
    {
        b = new Bullet * [s];
    }
    else
    {
        Bullet** temp = b;
        b = new Bullet * [s];
        for (int i = 0; i < s - 1; i++)
        {
            b[i] = temp[i];
        }
        delete[] temp;
    }

    b[s - 1] = ptr;
    if (b[s - 1] != nullptr) // Add null check
    {
        b[s - 1]->fire.setPosition(sprite.getPosition().x + 28, sprite.getPosition().y - 40);
        for (int i = 0; i < s; i++)
        {
            if (b[i] != nullptr && b[i]->fire.getPosition().y < -10)
            {
                s--;
                bullet_remove_counter++;
                delete b[i];
                b[i] = nullptr;
                Bullet** temp = b;
                b = new Bullet * [s];
                int j = 0;
                for (int k = 0; k < s + 1; k++)
                {
                    if (temp[k] != nullptr)
                    {
                        b[j] = temp[k];
                        j++;
                    }
                }
                delete[] temp;
            }
        }
    }
}

	/////////////////fire//////////////////////////////////
	float gt = 0.0;
	void fire(Bullet**& b, int& s, int& coll_check, float x,Enemy** E,Lives** L)
	{
		if (coll_check == 1 || time_count1 != 0)
		{
			is_powermode = true;
			gt += x;
			if (gt >= 1.0)
			{
				time_count1++;
				gt = 0.0;
			}
	       fire7(b,s,x,1);

			if (time_count1 >= 5)
			{
				time_count1 = 0;
				is_powermode = false;
				cout << "ok\n";
				coll_check = 0;
			}
		}
		else if (coll_check == 2 || time_count2 != 0)
		{

			s++;
			Bullet* ptr = new Bullet(1);

			if (b == nullptr)
			{
				b = new Bullet * [s];
			}
			else
			{
				Bullet** temp = b;
				b = new Bullet * [s];
				for (int i = 0; i < s - 1; i++)
				{
					b[i] = temp[i];
				}
				delete[] temp;
			}

			b[s - 1] = ptr;
			b[s - 1]->fire.setPosition(sprite.getPosition().x+4, sprite.getPosition().y - 36);
			for (int i = 0; i < s; i++)
			{
				if (b[i] != nullptr && b[i]->fire.getPosition().y < -10)
				{
					s--;
					bullet_remove_counter++;
					delete b[i];
					b[i] = nullptr;
					Bullet** temp = b;
					b = new Bullet * [s];
					int j = 0;
					for (int k = 0; k < s + 1; k++)
					{
						if (temp[k] != nullptr)
						{
							b[j] = temp[k];
							j++;
						}
					}
					delete[] temp;
				}
			}
	
			is_firemode = true;
			gt += x;
			if (gt >= 1.0)
			{
				time_count2++;
				gt = 0.0;
			}
			if (time_count2 >= 5.0)
			{
				is_firemode = false;
				time_count2 = 0.0;
				cout << "ok\n";
				coll_check = 0;
			}

		}
		else if (coll_check == 3)//////////////////////////here we implement the life class
		{
			for(int i=0;i<3;i++)
			{
				if(L[i] == nullptr)
				{
				L[i]=new Lives;
				break;
				}
			}
			cout << "life Incremented\n";
			coll_check = 0;
			gt = 0.0;
		}
		else if (coll_check == 4)//Here we implement the live class
		{
			for(int i=2;i>=0;i--)
			{
				if(L[i]!= nullptr)
				{
                     delete L[i];
				      L[i]=nullptr;
					  break;				
				}
			}
			cout << "danger life Dcremented\n";
			coll_check = 0;
			gt = 0.0;
		}
		else
		{			
	       fire7(b,s,x,1);
		}
		
	}

	void move(std::string s) {
		float delta_x = 0, delta_y = 0;
		///////Left Right Up Down//////
		if (s == "l")
			delta_x = -1;
		else if (s == "r")
			delta_x = 1;
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;
		/////////Diagonals///////
		if (s == "7")
		{
			delta_x = -1;
			delta_y = -1;
			rot(2);
		}
		else if (s == "9")
		{
			delta_x = 1;
			delta_y = -1;
			rot(1);
		}
		else if (s == "1")
		{
			delta_x = -1;
			delta_y = 1;
			rot(4);
		}
		else if (s == "3")
		{
			delta_x = 1;
			delta_y = 1;
			rot(3);
		}

		delta_x *= speed;
		delta_y *= speed;
		///////////////////////Wrap Around/////////
		float xpos = sprite.getPosition().x;
		float ypos = sprite.getPosition().y;
		if (ypos >= 700)
			sprite.setPosition(xpos, -60);
		else if (ypos <= -60)
			sprite.setPosition(xpos, 700);
		else if (xpos <= -75)
			sprite.setPosition(720, ypos);
		else if (xpos >= 720)
			sprite.setPosition(-75, ypos);
		else if(xpos >= 700 && ypos >= 720)
			sprite.setPosition(0, 0);
		else if(xpos >= 700 && ypos <= -700)
			sprite.setPosition(0, 700);
		else if(xpos <= 0 && ypos >= 720)
			sprite.setPosition(700, 0);
		else if(xpos <= 0 && ypos <= -720)
			sprite.setPosition(700, 720);
		    sprite.move(delta_x, delta_y);


	}

};
int Player::count=1;
