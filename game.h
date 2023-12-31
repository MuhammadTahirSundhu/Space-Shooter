
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "Bomb.h"
#include "Enemy.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
#include "Monster.h"
#include "Dragon.h"
#include "Diff_levels.h"

#include "Add_ons.h"
#include "Powerup_addon.h"
#include "Live_addon.h"
#include "Fire_addon.h"
#include "Danger_addon.h"
#include "Lives.h"
#include "Score.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
private:
ofstream outfile;
ifstream infile;
Player* p; //player 
    Bullet** b; //Bullet
    int sizeofBullet = 0;
    float Bullet_timer = 0;
    float Bullet_move_timer = 0;
    int Bullet_counter = 0;
    bool gameover=0;
    Enemy* E[7]; //Enemy
    Alpha alpha[15];
    Beta beta[15];
    Gamma gamma[15];
    Monster monster;
    Dragon dragon;
    bool isdragon=false;
    bool dragonrt=false;
    bool isMonster = false;
    bool monstert=false;
    bool ispause=false;
    Bomb *B1=new Bomb[7];
    Bomb *B2 = new Bomb("img/laser1.png");
    Bomb **B3;
    int dr_b;
    Dragon*ptr=(Dragon*)E[4];
    
    int random_bomb = 0;
    float bomb_time = 0;
    float t1 = 0;
    float t2=0;
    float monster_time = 0;
    float enemy_time=0;
    float monsterGap=0;
    bool mongo=true;
    bool anima=false;
    float direction=0;
    int random_enemy=0;
    int random_assign_bomb=0;
    int bombarr[7] = {};

    Add_ons* A;
    Powerup* P;
    Live_addon* L;
    Fire_addon* F;
    Danger_addon* D;
    Diff_level lv;
    Score S;
    Lives *lives[3];
    bool enemy_sc=1;
    float level_time=0;
    
int total_enemy_count=0;
int level_counter=0;


public:
    Sprite background; //Game background sprite
    Texture bg_texture;
    Sprite animation; //Game background sprite
    Texture ani;
    Sprite over; //Game background sprite
    Texture bg_over;
    Sprite side_bar;
    Texture bar;
    Font font;
    Text text;
    Text pause;
     SoundBuffer cf,b_l,l_l;
     Sound s,bl,ml;
    string nme;
    // add other game attributes
    ////////////////////////

    Game()
    {

        E[0] = alpha;
        E[1] = beta;
        E[2] = gamma;
        E[3] = &monster;
        E[4] = &dragon;
        E[5] = new Alpha;
        E[6] = new Gamma;
        E[5]->enemy.setPosition(-100,200);
        E[6]->enemy.setPosition(900,200);
        P = new Powerup;
        L = new Live_addon;
        F = new Fire_addon;
        D = new Danger_addon;

        cf.loadFromFile("img/pickup.wav");
        s.setBuffer(cf);
        s.setVolume(200);

        b_l.loadFromFile("img/fire.wav");
        bl.setBuffer(b_l);
        bl.setVolume(15);


        l_l.loadFromFile("img/laugh.wav");
        ml.setBuffer(l_l);
        ml.setVolume(200);


        bar.loadFromFile("img/side_bar.png");
        side_bar.setTexture(bar);
        side_bar.setScale(0.09,3.5);
        side_bar.setPosition(750,-250);


        ani.loadFromFile("img/anii.png");
        animation.setTexture(ani);
        animation.setScale(0.3,0.3);
        animation.setPosition(330,180);


        A = nullptr;
        b = nullptr;
        B3=nullptr;
        dr_b=0;
        p = new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(0.95, 1.4);

        bg_over.loadFromFile("img/over.jpg");
        over.setTexture(bg_over);
        over.setScale(0.48, 0.7);

        font.loadFromFile("img/F2/Goldrops.otf"); 
     text.setFont(font);
    text.setCharacterSize(34);
    text.setFillColor(Color::Yellow);
      text.setPosition(780,50);
        text.setString("Lives\n\n\n\n\nScore\n\n\n\n\nTime");

          pause.setFont(font);
    pause.setCharacterSize(70);
    pause.setFillColor(Color::Green);
      pause.setPosition(260,340);
      pause.setStyle(Text::Bold);
        pause.setString("PAUSED");
        for(int i=0;i<3;i++)
        lives[i]=new Lives;  

outfile.open("game_data.txt", std::ios::app);

if (!outfile.is_open()) {
    cout << "Error opening file for writing!" << endl;
    return;
}   

}
    void start_game()
    {
        /////////////////////////////////////////////
        cout<<"Enter Name:\n";
        cin>>nme;
        ////////////////////////////////////////////
        srand(time(0));
        RenderWindow window(VideoMode(900, 780), title);
        Clock clock;
        float timer = 0;
        
        int a = 0; // generate the random powerup
        float ct = 0;//make sure that the 1 po
        float  aa = 0;//werup will come in one second
        float gt = 0;//basically it controls the Addon-on time
        int xpos_powerup=340;//chages the powerup x position after one move
        float Bull = 0.0;
        int forattack=0;
        float dr_b_time=0;

        int coll_check = 0;//means check collion and then said to fire function to proceed according to it
        
        while (window.isOpen())
        {
             Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game      
                    else if(e.type == Event::KeyReleased)
                    {
                    if(e.key.code == Keyboard:: P)
                    {
                    ispause=true ; 
                    bl.stop();
                    }
                    else if(e.key.code == Keyboard:: R)
                    ispause=false ; 
                    else if(e.key.code == Keyboard:: Backspace)
                    {
                    window.close(); 
                    bl.stop();
                    ml.stop();
                    }
                    else if(e.key.code == Keyboard:: R)
                    p->rotate ; 
                    }
                                   	    
            }
        if(ispause == false)///////////////Here I pause the game
          {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            ct += time;
            gt += time;
            bomb_time += time;
            monster_time += time;
            t1+=time; // control the time for Random bomb
            t2+=time;
            if(mongo)
            monsterGap += time;
            dr_b_time+=time;
            float clk;
            clk+=time;
               if(clk >= 1)
                {
                S.setTime(1);
                clk=0;
                }
            ///////////////////////Sound/////////////////
            
            ///////////////////Random Add-on generate///////
            if (int(timer) % 25 == 0 )
            {

                if (ct >= 1.0)
                {
                    a = rand() % 4 + 1;
                    xpos_powerup = rand() % 650 + 40;
                    if (a == 1)
                    {
                        A = P;
                        a++;
                        aa = 1;
                    }
                    else if (a == 2)
                    {
                        A = F;
                        a++;
                        aa = 2;
                    }
                    else if (a == 3)
                    {
                        A = L;
                        a++;
                        aa = 3;
                    }
                    else if (a == 4)
                    {
                        A = D;
                        a = 1;
                        aa = 4;
                    }
                    A->add_on->setPosition(xpos_powerup, -200);

                    ct = 0.0;
                }
               
            }
    
             if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
                p->move("l");    // Player will move to left
             if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");  //player will move to right
             if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
                p->move("u");    //playet will move upwards
             if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                p->move("d");  //player will move downwards
             if (Keyboard::isKeyPressed(Keyboard::Num7)) // If down key is pressed
                p->move("7");
            else if (Keyboard::isKeyPressed(Keyboard::Num9)) // If down key is pressed
                p->move("9");
            else if (Keyboard::isKeyPressed(Keyboard::Num1)) // If down key is pressed
                p->move("1");
            else if (Keyboard::isKeyPressed(Keyboard::Num3)) // If down key is pressed
             p->move("3");
                else
                {
                    p->rot(7);
                }
            
            /////////////////////////////////////////////////
            /////  Call your functions here            /////
            ///////////////////////////////////////////////


            /////////////////////////////Lives////////////

             ///////////////////////Add-on///////////////
            if (A != nullptr)
            {
                if (A->add_on->getPosition().y >= 700)
                {
                    if(aa == 4)
                    S.setScore(5);
                    A = nullptr;
                }
                else
                A->move();
               
                 if (p->collion(A))
                    {
                        A = nullptr;
                        s.play();
                        coll_check=aa;
                    }
            }

                   /////////////////Shoot for SpaceShip and collide with invadrs
              Bullet_move_timer += time;
              if (Bullet_move_timer > 0.15)
              {
                  p->fire(b, sizeofBullet, coll_check, 0.1, E,lives);
                  Bullet_move_timer = 0;
                  bl.play();
                  
              }
              for (int i = 0; i < sizeofBullet; i++)
              { 
                if (b[i] != nullptr)
                          b[i]->move(1);
                          if(isdragon != true && isMonster != true)
                            if(b[i]->bulletCollion(b[i],E,S,level_counter))
                          {
                            if(!p->is_firemode)
                            {
                            b[i]->fire.setPosition(-200,-200);
                            }
                            total_enemy_count--;
                          }
                  }
              
              /////////////////////////Space ship collion with enemy/
             if(isMonster !=true && isdragon!=true)
              p->playerCollion(E,lives);
              p->playerCollion1(E[3],lives,enemy_sc);
              p->playerCollion2(E[4],lives,enemy_sc);
                 /////////////Space ship Collion with Bombs////
                p->bombCollion(B1,lives);
                p->bombCollion1(B2,lives,enemy_sc);
                p->bombCollion2(B3,lives,dr_b,enemy_sc);
                ////////////////////////////////////////////////////////////////////////////////////
                             
               //////////////Enemy////////////////////////////////////////////////////////////////
              //////////////////Invaders/////////
             if(total_enemy_count <= 0)
             {                
                level_time+=time;
                if(anima == false)
                {
                E[5]->enemy.move(1*0.5,0);
                E[6]->enemy.move(-1*0.5,0);
                if(E[5]->enemy.getPosition().x+8 >= E[6]->enemy.getPosition().x-8)
                {
                   E[5]->enemy.setPosition(-100,200);
                   E[6]->enemy.setPosition(900,200);
                    anima=true;
                }
                }
                            
                if(level_time >= 2.5)
                {
                anima=false;
                level_counter++;
                if(level_counter == 4) 
                {
                for(int i=0;i<7;i++)
                B1[i].bomb_speed=0.4*2;
                }
                else if(level_counter == 5)
                {
                for(int i=0;i<7;i++)
                B1[i].bomb_speed=0.4*3;
                }               
                lv.levels(E,level_counter,total_enemy_count);
                level_time=0;
                if(level_counter  > 5)
                level_counter=0;
                }             
             }
                          //////////////////Attack By Invadors//////////////////////
             if(isMonster !=true && isdragon!=true)
             {
              if(t1 >= 1.0)
              {
                if (t2 >=2.0 && timer > 1 && random_assign_bomb == 0)
              {
                 forattack = 1;
                 for (int i = 0; i < 7; i++)
                 {
                     bombarr[i] = rand() % 15 + 1;
                     B1[i].bomb.setPosition(E[2][bombarr[i]].enemy.getPosition().x, E[2][bombarr[i]].enemy.getPosition().y);
                 }
                 random_assign_bomb++;
                 t2=0.0;
              }
              else if ( t2 >= 3.0 && random_assign_bomb == 1 )
              {
                 forattack = 2;
                 for (int i = 0; i < 7; i++)
                 {
                     bombarr[i] = rand() % 15 + 1;
                     B1[i].bomb.setPosition(E[1][bombarr[i]].enemy.getPosition().x, E[1][bombarr[i]].enemy.getPosition().y);
                 }
                 random_assign_bomb++;
                t2=0.0;
              }
               else if (t2 >= 5.0 && random_assign_bomb == 2)
              {
                 forattack = 3;
                 for (int i = 0; i < 7; i++)
                 {
                     bombarr[i] = rand() % 15 + 1;
                     B1[i].bomb.setPosition(E[0][bombarr[i]].enemy.getPosition().x, E[0][bombarr[i]].enemy.getPosition().y);
                 }
                    random_assign_bomb=0;
                    t2=0.0;
              }
              t1=0.0;
              }
              

              for (int i = 0; i < 7; i++)
              {
                 if (forattack == 1)
                     E[2][bombarr[i]].attack(&B1[i]);
                 else if (forattack == 2)
                     E[1][bombarr[i]].attack(&B1[i]);
                 else if (forattack == 3)
                     E[0][bombarr[i]].attack(&B1[i]);
              }
             }
             
            
              ////////////////////////////////Attack By Monster/////
              if (monsterGap >= 25)
              {
                random_enemy=rand()%2+1;
                monsterGap=0.0;
                mongo=false;
                cout<<random_enemy<<endl;
              }
              if(random_enemy == 1)
              {  
                  isMonster = true;
                  monstert=true;
                  monster_time=0.0;
                  random_enemy=0;
              }
              else if(random_enemy == 2) 
              {
                 if(p->sprite.getPosition().x < 100)
                direction =-0.50;
                else if(p->sprite.getPosition().x >= 100 && p->sprite.getPosition().x < 200 )
                direction =-0.30;
               else if(p->sprite.getPosition().x >= 200 && p->sprite.getPosition().x < 300 )
                direction= 1;
               else if(p->sprite.getPosition().x >= 300 && p->sprite.getPosition().x < 400 )
                direction =0.30;
                else if(p->sprite.getPosition().x >= 400 && p->sprite.getPosition().x <= 500 )
                direction =0.50;
                else if(p->sprite.getPosition().x > 500 && p->sprite.getPosition().x < 700 )
                direction=0.60;
                     
                  isdragon = true;
                  dragonrt=true;
                  monster_time=0.0;
                  random_enemy=0;
              }
              if(isMonster)
              {
                  if(monstert)
                  {
                  E[3]->move(-1, 0);
                  if(E[3]->enemy.getPosition().x <= 700)
                  if(int(timer) % 2 == 0)
                  E[3]->attack(B2);
                  if(int(timer) % 2 != 0)
                  B2->bomb.setPosition(-200,-200);
                  }
                  
                  if (monster_time >= 20)
                  {
                    B2->bomb.setPosition(-200,-200);
                    monstert=false;
                    E[3]->enemy.move(1*0.3, 0);
                    if(E[3]->enemy.getPosition().x >= 800)
                    E[3]->enemy.setPosition(900,10);
                  }
                  if (monster_time >= 25)
                  {
                      isMonster = false;
                      mongo=true;
                      monster_time=0.0;
                      if(enemy_sc == 1)
                      S.setScore(40);
                      enemy_sc=1;
                  }
              }
              else if(isdragon)
              {
                    if (dragonrt) 
                    {
                       if (E[4]->enemy.getPosition().y != 15)
                        E[4]->move(-1, 0);
                        ptr->cpattack(dr_b,B3,E[4],dr_b_time);  //////////////////Here Down cassting occur
                    }
                 
                    if (monster_time >= 9) 
                    {
                        dragonrt = false;
                        E[4]->enemy.move(0, 1 * 0.3);
                    }

                    if (E[4]->enemy.getPosition().y >= 700) {
                        E[4]->enemy.setPosition(340, -248);
                        isdragon = false;
                        mongo = true;
                        monster_time = 0.0;
                     if(enemy_sc == Lives::getCount())
                      S.setScore(50);
                        if(enemy_sc == 1)
                      S.setScore(50);
                      enemy_sc=1;
                    }
                }  
                ptr->b_move(B3,dr_b,direction);

              /////////////////Alternate for fire//////////////////
             if(gameover==1)
             {
                 ml.play();

             }
                if(Lives::getCount() <= 0)
                {

                    gameover=1;
                    window.clear(Color::Black); //clears the screen
                    window.draw(over);

                    s.stop();
                    bl.stop();                
                    outfile << S.getScore()<<"---------"<<nme<< endl;
                    
                    outfile.close();

                }
}
            //////////////////////////////////////////////
            if(gameover == 0)
            {
            window.clear(Color::Black); //clears the screen
            window.draw(side_bar);
            window.draw(background);  // setting background
            window.draw(p->sprite);   // setting player on screen
            window.draw(text);
            window.draw(E[5]->enemy);
            window.draw(E[6]->enemy);

  
                if(level_time > 0 && level_time < 5 && anima==true)
                {
                    window.draw(animation);
                }

            for (int i = 0; i < sizeofBullet; i++)
            {
                if (b != nullptr)
                {
                        if (b[i] != nullptr)
                        window.draw(b[i]->fire);

                }
            }
             if(isMonster !=true && isdragon!=true)
            {
            for (int i = 0; i < 3; i++)
             {
                for (int j = 0; j < 15; j++)
                {
                    if(E[i][j].enemy.getPosition().x!= -100)
                    window.draw(E[i][j].enemy);
                }
             }
            }
           
            window.draw(E[3]->enemy);
            window.draw(E[4]->enemy);
            window.draw(B2->bomb);

            for (int i = 0; i < 7; i++)
            {
                if (B1 != nullptr)
                window.draw(B1[i].bomb);
            }
            for(int i=0;i<dr_b;i++)
            {
                if(B3 !=nullptr)
                if(B3[i]!=nullptr)
                window.draw(B3[i]->bomb);
            }
            if (A != nullptr)
            {
                if (A->add_on != nullptr)
                    window.draw(*(A->add_on));
            }
             for(int i=0;i<Lives::getCount();i++)
              window.draw(lives[i]->lives);
              window.draw(S.sc);
              window.draw(S.time);
                 if(ispause)
           window.draw(pause);
         }
         window.display();  //Displying all the sprites
        }

    }


};

