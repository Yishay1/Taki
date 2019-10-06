//////////////////////////////////////////////
////////Yishay seroussi 305027948/////////////
//////////////////////////////////////////////

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
class Game {
private:
	vector<Player> players;
	int direction;
	Card top;
	int turn;
	int num_of_players;
	int num_of_cards;
	bool flagCD;
	bool flagSTOP;
	bool flagPLUS;
	Game(const Game&);//copy constructor-private because we don't need it
	Game operator=(const Game&);//insertion operator-private because we don't need it
public:
	Game();//constructor
	void start();
	void set_direction();
	void set_turn();
	void set_top(const Card&);
	void set_players();
	bool set_properties();
	void turn_details();
	void card_auction(const Card&);
	
};
#endif




