#include <stdio.h>
#include <iostream>
using namespace std;

class Board
{
private:

    int X_size=10, Y_size=10 , bombs=10, markcount=0;

    char hiddenboard[11][11];
    char visibleboard[11][11];

    bool end_of_game=false;

public:

    void rules()
    {
        cout<<"WASD - move"<<endl;
        cout<<"x - mark bomb"<<endl;
        cout<<"v - open cell"<<endl;
        cout<<"Good luck! Press any key to proceed";
        getch();
        system("CLS");
    }
    void fill_boards()
    {
        for(int x=1;x<=X_size;x++)
        {
            for(int y=1;y<=Y_size;y++)
            {
               visibleboard[x][y]='*';
               hiddenboard[x][y]='0';
            }
        }
    }
    void only_move(int current_x, int current_y)
    {
         for(int x=1;x<=X_size;x++)
            {
                for(int y=1;y<=Y_size;y++)
                {
                    if(x==current_x&&y==current_y)
                    {
                        cout<<"+";
                    }
                    else
                    cout<<visibleboard[x][y];
                }
                cout<<endl;
            }
    }
    void action(int current_x, int current_y, char action)
    {
        if(action=='v'&&hiddenboard[current_x][current_y]<'B'&&hiddenboard[current_x][current_y]!='0')
        {
            visibleboard[current_x][current_y]=hiddenboard[current_x][current_y];
            only_move(current_x,current_y);
        }
        else if(action=='v'&&hiddenboard[current_x][current_y]=='0')
        {
            show_safe_field(current_x,current_y);
            visibleboard[current_x][current_y]='0';
            only_move(current_x,current_y);
        }
        else if(action=='v'&&hiddenboard[current_x][current_y]=='B')
        {
            loser();
        }
        else if(action=='x')
        {
            if(visibleboard[current_x][current_y]='*')
            {
                visibleboard[current_x][current_y]='X';
                only_move(current_x,current_y);
                markcount++;
            }
            else if(visibleboard[current_x][current_y]!='*')
            {
                only_move(current_x,current_y);
            }
        }
    }

    void check_for_win()
    {
        int bombs_and_marks=0;
        cout<<endl<<endl<<"Bombs left:"<<bombs-markcount;
        if(markcount==bombs)
        {
            for(int x=1;x<=X_size;x++)
            {
                for(int y=1;y<=Y_size;y++)
                {
                    if(visibleboard[x][y]=='X'&&hiddenboard[x][y]=='B')
                    {
                        bombs_and_marks++;
                    }
                }
            }
            if(bombs_and_marks==10)
            {
                system("CLS");
                end_of_game=true;
                show_hiddenboard();
                cout<<endl<<endl<<"Winner winner chicken dinner!";
            }
            else
            {
                cout<<endl<<"Sorry you failed to correctly mark bombs ;(";
                getch();
                loser();
            }
        }

    }
    void loser()
    {
        system("CLS");
        show_hiddenboard();
        cout<<endl<<"You lose ;(";
        end_of_game=true;

    }

    void show_safe_field(int x,int y)
    {
        if(hiddenboard[x][y]=='0'&&visibleboard[x][y]=='*')
        {
            visibleboard[x][y]=hiddenboard[x][y];
            show_safe_field(x+1,y);
            show_safe_field(x,y+1);
            show_safe_field(x-1,y);
            show_safe_field(x,y-1);
            show_safe_field(x+1,y+1);
            show_safe_field(x+1,y-1);
            show_safe_field(x-1,y+1);
            show_safe_field(x-1,y-1);
        }
        else if(hiddenboard[x][y]!='0')
        visibleboard[x][y]=hiddenboard[x][y];
    }
    void generate_bombs()
    {
        srand(time(NULL));
        int x,y;
        for(int i=0;i<bombs;i++)
        {
            x=rand()%X_size+1;
            y=rand()%Y_size+1;
            if(hiddenboard[x][y]=='B')
            {
                i--;
            }
            else
            hiddenboard[x][y]='B';
        }
    }
    void filling_empty_cells()
    {
        int bomb_count=0;
        for(int x=1;x<=X_size;x++)
        {
            for(int y=1;y<=Y_size;y++)
            {
                if(hiddenboard[x][y]!='B')
                {
                    if(hiddenboard[x+1][y]=='B')
                        bomb_count++;
                    if(hiddenboard[x][y+1]=='B')
                        bomb_count++;
                    if(hiddenboard[x-1][y]=='B')
                        bomb_count++;
                    if(hiddenboard[x][y-1]=='B')
                        bomb_count++;
                    if(hiddenboard[x+1][y+1]=='B')
                        bomb_count++;
                    if(hiddenboard[x+1][y-1]=='B')
                        bomb_count++;
                    if(hiddenboard[x-1][y-1]=='B')
                        bomb_count++;
                    if(hiddenboard[x-1][y+1]=='B')
                        bomb_count++;

                    hiddenboard[x][y]='0'+ bomb_count;
                    bomb_count=0;
                }
            }
        }
    }
    void show_hiddenboard()
    {
        for(int x=1;x<=X_size;x++)
        {
            for(int y=1;y<=Y_size;y++)
            {
                cout<<hiddenboard[x][y];
            }
            cout<<endl;
        }
    }
    bool get_end_of_game()
    {
        return end_of_game;
    }
};
