//////////////////////////////////////////////
////////Yishay seroussi 305027948/////////////
//////////////////////////////////////////////

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>
class Player {
private:
	string name;
	int num_of_cards;
	vector<Card> cards;

public:
	Player() : num_of_cards(1), name(""){};//default constructor
	Player(string name, int num_of_cards);//constructor
	const Card play(const Card&);
	void remove_card(int);
	void get_card();
	int get_num_of_cards();
	friend ostream& operator << (ostream &os, const Player&);
	string get_name();
};
#endif



