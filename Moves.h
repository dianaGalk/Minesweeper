#include<iostream>
using namespace std;

class Moves_and_actions
{
private:
    int current_X=1;
    int current_Y=1;
    char player_action;
public:
    void player_input()
    {
        int X_size=10;
        int Y_size=10;

        char player_move;
        player_move=_getch();

        switch (player_move)
        {
            case 'w':
                if (current_X>1)
                {
                    current_X--;
                    player_action ='1';
                    break;
                }
            case 'd':
                if (current_Y<Y_size)
                {
                    current_Y++;
                    player_action ='1';
                    break;
                }
            case 's':
                if (current_X<X_size)
                {
                    current_X++;
                    player_action ='1';
                    break;
                }
            case 'a':
                if (current_Y>1)
                {
                    current_Y--;
                    player_action ='1';
                    break;
                }
            case 'v':
                player_action ='v';
                break;
            case 'x':
                player_action ='x';
                break;
            default:
                cout<<endl<<endl<<"Wrong key entered"<<endl;
                getch();
                break;
        }
    }

    int get_current_x()
    {
        return current_X;
    }
    int get_current_y()
    {
        return current_Y;
    }
    char get_action()
    {
        return player_action;
    }
};
