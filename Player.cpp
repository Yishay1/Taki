#include "Player.h"
#include<string>

/*
this function get the top card as an argument
return the card that he choose. 
or return top if the player took new card.
*/
const Card Player::play(const Card& top)
{
	bool leagal_choice=false;
	Card ret;
	int chosen;
	cout<<"Your cards: "<<*this<<"\n";
	cin>>chosen;
	while(!leagal_choice)
	{
		if(chosen>0  && chosen<=this->num_of_cards)
		{
			if(!cards[chosen-1].is_leggal(top))
			{
				cout<<"You can't put "<<(cards[chosen-1])<<" on "<<top<<endl;
				cin>>chosen;
			}
			else
			{
				ret=cards[chosen-1];
				remove_card(chosen-1);
				return ret;
			}
		}
		else
		{
			get_card();
			return ret;
		}
	}
}
/*
remove the "card_num" from "cards" vector.
*/
void Player::remove_card(int card_num)
{
	Card tmp=cards[card_num];
	cards.erase(cards.begin()+card_num);
	//delete tmp;
	this->num_of_cards--;
}

/* 
generate and insert new card to "cards" vector.
*/
void Player::get_card()
{
	Card c;
	c=generate_card();
	cards.push_back(c);
	this->num_of_cards++;
}
//////////////////////////////////////////////
////////Yishay seroussi 305027948/////////////
//////////////////////////////////////////////
#include "Player.h"

/*
  <<operator
  return ostream& that contains all the list of cards. 
*/
ostream& operator << (ostream &os, const Player& p)
{
	for(int i=0 ; i<p.num_of_cards ; i++)
	{
		os<< " (" << i+1 << ")" <<p.cards[i]<<" ";
		
	}
	return os;
}
/*
return int, the num_of_cards
*/
int Player::get_num_of_cards()
{
	return this->num_of_cards;
}

/*return string, the name of this player*/
string Player::get_name()
{
	return this->name;
}
/*
consructor: arguments: num of card, name of player
*/
Player::Player(string name, int num_of_cards)
{
	this->name=name;
	this->num_of_cards=num_of_cards;
	for(int i=0; i<num_of_cards; i++)
	{
		Card tmp;
		tmp=generate_card();
		cards.push_back(tmp);
	}
}
