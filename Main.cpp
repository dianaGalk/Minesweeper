#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "Moves.h"
#include "Board.h"

using namespace std;


int main()
{
    Board playground;
    Moves_and_actions input;

    playground.rules();
    playground.fill_boards();
    playground.generate_bombs();
    playground.filling_empty_cells();


    while(playground.get_end_of_game()!=true)
    {
        input.player_input();
        system("CLS");
        if(input.get_action()=='1')
        {
            playground.only_move(input.get_current_x(),input.get_current_y());
        }
        else playground.action(input.get_current_x(),input.get_current_y(),input.get_action());
        playground.check_for_win();
    }

getch();

    return 0;
}
