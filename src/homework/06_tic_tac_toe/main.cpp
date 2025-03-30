#include "tic_tac_toe.h"
#include <iostream>
#include <string>
using std::cout;
using namespace std;
using std::string;
int main() 
{
	TicTacToe game;
	string first_player;
	char choice;
	do
	{
		cout<<"Enter First player: ";
		cin>>first_player;
		game.start_game(first_player);
		int position;
		while (!game.game_over())
		{
			cout<<"Enter a position";
			cin>>position;
			game.mark_board(position);
			game.display_board();


		}
		

		cout<<"Do you want to play again?(Y/N )";
		cin>> choice;

	} while(choice=='y'|| choice=='Y');

	return 0;
}