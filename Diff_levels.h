#ifndef DIFF_LEVELS_H
#define DIFF_LEVELS_H


class Diff_level{
public:
void levels(Enemy**E,int x,int &t)
                            {

                                if(x == 1)
                                {
                                  t=30;
                                    for(int i=0;i<3;i++)
                                    {
                                        if(i==0)
                                        {
                                            for(int j=0,k=0;j<10;j++,k++)
                                            E[i][j].enemy.setPosition(i+k*75,0);
                                        }
                                        else if(i==1)
                                        {
                                            for(int j=0,k=0;j<10;j++,k++)
                                            E[i][j].enemy.setPosition(E[0][j].enemy.getPosition().x,70);
                                        }
                                        else 
                                        {
                                            for(int j=0;j<10;j++)
                                            E[i][j].enemy.setPosition(E[1][j].enemy.getPosition().x,150);
                                        }
                                    }
                                }
                                 if(x == 2)
                                {
                                      t=36;
                                      for(int i=0;i<3;i++)
                                      {
                                        
                                            
                                                if(i==0)
                                                {
                                                    for(int j=0,k=1,n=1;j<12;j++,k++)
                                                    if(j<6)
                                                    E[i][j].enemy.setPosition(70,k*60);
                                                    else
                                                    {
                                                    E[i][j].enemy.setPosition(420,n*60);
                                                    n++;
                                                    }

                                                }
                                                else if(i==1)
                                                {
                                                    for(int j=0,k=0;j<12;j++,k++)
                                                    E[i][j].enemy.setPosition(E[0][j].enemy.getPosition().x+130,E[0][k].enemy.getPosition().y+40);
                                                }
                                               else if(i == 2)
                                                {
                                                    for(int j=0,k=0;j<12;j++,k++)
                                                    E[i][j].enemy.setPosition(E[1][j].enemy.getPosition().x+100,E[1][k].enemy.getPosition().y-100);
                                                }                                
                                     }
                                }

                                    if(x == 3)
                                {
                                  t=19;
                                    for(int i=0;i<3;i++)
                                    {
                                        if(i==0)
                                        {
                                            for(int j=0,k=1;j<10;j++,k++)
                                            E[i][j].enemy.setPosition(i+k*70,k*45);
                                        }
                                        else if(i==1)
                                        {
                                            for(int j=0,k=9;j<10;j++,k--)
                                            if(j!=5)
                                            E[i][j].enemy.setPosition(E[0][j].enemy.getPosition().x,E[0][k].enemy.getPosition().y+30);
                                        }
                                       
                                    }
                                }
                               
                                  if(x == 4)
                                {
                                      t=36;
                                      for(int i=0;i<3;i++)
                                      {
                                        
                                            
                                                if(i==0)
                                                {
                                                    for(int j=0,k=0,n=0;j<12;j++,k++)
                                                    if(j<6)
                                                    E[i][j].enemy.setPosition(100,k*60);
                                                    else
                                                    {
                                                    E[i][j].enemy.setPosition(600,n*60);
                                                    n++;
                                                    }

                                                }
                                                else if(i==1)
                                                {
                                                    for(int j=0,k=0;j<12;j++,k++)
                                                    if(j<6)
                                                    E[i][j].enemy.setPosition(E[0][j].enemy.getPosition().x+100,E[0][k].enemy.getPosition().y+90);
                                                    else
                                                    E[i][j].enemy.setPosition(E[0][j].enemy.getPosition().x-100,E[0][k].enemy.getPosition().y+90);


                                                }
                                               else if(i == 2)
                                                {
                                                    for(int j=0,k=0;j<12;j++,k++)
                                                    if(j<6)
                                                    E[i][j].enemy.setPosition(E[1][j].enemy.getPosition().x+100,E[1][k].enemy.getPosition().y+90);
                                                    else
                                                    E[i][j].enemy.setPosition(E[1][j].enemy.getPosition().x-100,E[1][k].enemy.getPosition().y+90);


                                                }                                
                                     }
                                }
                                if(x == 5)
                                {
                                    t=45;
                                    for (int i = 0; i < 3; i++)
                                              {
                                                  if (i == 0)
                                                  {
                                                      for (int j = 0,k=5; j < 15; j++,k--)
                                                      {
                                                          if(j<8)
                                                          E[i][j].enemy.setPosition(j*50,j*40);
                                                          else
                                                          E[i][j].enemy.setPosition(E[0][j-1].enemy.getPosition().x+50,E[0][j-1].enemy.getPosition().y-40);

                                                      }
                                                  }
                                                  else if (i == 1)
                                                  {

                                                      for (int j = 0; j < 15; j++)
                                                      {
                                                          E[i][j].enemy.setPosition((E[0][j].enemy.getPosition().x), (E[0][j].enemy.getPosition().y+60));
                                                      }
                                                  }
                                                  else 
                                                  {
                                                      for (int j = 0; j < 15; j++)
                                                      {
                                                          E[i][j].enemy.setPosition((E[1][j].enemy.getPosition().x), (E[1][j].enemy.getPosition().y + 80));
                                                      }
                                                  }
                                              }
                                }

                            }
                     

};

#endif
