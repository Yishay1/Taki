//////////////////////////////////////////////
////////Yishay seroussi 305027948/////////////
//////////////////////////////////////////////

#include "Game.h"
/*
default constructor
*/
Game::Game()
{
	this->direction=1;
	this->turn=0;
	this->flagCD=false;
	this->flagSTOP=false;
	this->flagPLUS=false;
}
/*this function run the game*/
void Game::start()
{
	if(!set_properties())
	{
		cout<<"not enough players/cards\n";
		return;
	}
	set_players();
	top=generate_card();
	while(true)
	{
		turn_details();
		Card tmp=players[turn].play(top);
		set_top(tmp);
		card_auction(tmp);
		if(players[turn].get_num_of_cards()==0)
			break;
		set_turn();
	}
	cout<<players[turn].get_name()<<" wins!\n";
	return;
}
/*
set how much players and cards at the begining.
if there are less than 2 player or less then 
1 card-return false.
else, every thing is fine-return true
*/
bool Game::set_properties()
{
	cout<<"How many players?\n";
	cin>>this->num_of_players;
	if(num_of_players<=1)return false;
	cout<<"How many cards?\n";
	cin>>this->num_of_cards;
	if(num_of_cards<=0) return false;
	return true;
}
/*set the direction of game*/
void Game::set_direction()
{
	this->direction*=-1;
}
/*set whos player play the next turn*/
void Game::set_turn()
{
	if(flagSTOP)
	{
		turn+=direction;
		flagSTOP=false;
	}
	else if(flagCD)
	{
		set_direction();
		flagCD=false;
		if(num_of_players==2)
			return;
	}
	else if(flagPLUS)
	{
		flagPLUS=false;
		return;
	}
	turn+=direction;
	if(this->turn==-2)
		turn=this->players.size()-2;
	else if(this->turn==-1) 
		turn=this->players.size()-1;
	else if(this->turn==players.size())
		turn=0;
	else if(this->turn==players.size()+1)
		turn=1;
}
/*set the top card */
void Game::set_top(const Card& c)
{
	if(c.get_sign()==NAS)
		return;
	top=c;
}
/*make list of all players*/
void Game::set_players()
{
	for(int i=0 ; i!=num_of_players ; i++)
	{
		string name;
		cout<<"player number "<<i+1<<" name?\n";
		cin>>name;
		players.push_back(Player(name, this->num_of_cards));
	}
}
/*show information of the current turn(player, current top)*/
void Game::turn_details()
{
	cout<<"current: ";
	if(!(top.get_sign()==NAS)) cout<<top;
	cout<<"\n";
	cout<<players[turn].get_name()<<", your turn -\n";
}
/*if there is special card on top than the one flag become true*/
void Game::card_auction(const Card& c)
{
	switch(c.get_sign()){
	case STOP:
		flagSTOP=true;
		break;
	case CD:
		flagCD=true;
		break;
	case PLUS:
		flagPLUS=true;
		break;
	default:
		break;	
	
	}
}	

