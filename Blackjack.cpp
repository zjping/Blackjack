//filename: Blackjack
//use: develop a 21 clock game
//user: zhangjianping
//date: 2015/4/1

#include<iostream>
#include<ctime> 
#include<cstdlib>

using namespace std;

int player_card[10] = {53, 53, 53, 53, 53, 53, 53, 53, 53, 53}, a = 0, b = 0, computer_card[10] = {53, 53, 53, 53, 53, 53, 53, 53, 53, 53};//a represents the number of the player cards and b represents the number of the computer cards 
double player_number = 0, computer_number = 0; //number represents the scores
int main()
{
l2:	int get_card(int who);
	int output(int who);
	int judge(int tho);
	int result;
	char get; 
	
	
	cout << "Player Time" << endl;
	get_card(0);
	get_card(0);
	cout << "Your Card ";
	output(0);
	cout << endl;
	cout << "Are you going to get another card?(Y/N): ";
	cin >> get;
	while (get == 'Y')
	{
		get_card(0);
		cout << "You get another card ";
		output(0);
		cout << endl;
		result = judge(0);
		if (result == 1)
		{
			goto l1;
		}
		cout << "Are you going to get another card?(Y/N): ";
	    cin >> get;
	}
	cout << "Computer Time" << endl;
	get_card(1);
	get_card(1);
	cout << "Computer Card ";
	output(1);
	cout << endl;
	while (computer_number < player_number || computer_number == player_number && b < a)
	{
		get_card(1);
		cout << "Computer get another card ";
		output(1);
		cout << endl;
		result = judge(1);
		if (result == 1)
		{
			goto l1;
		}
	}
l1:	for (int i=0; i<10; ++i){    
    player_card[i] = 53; 
    computer_card[i] = 53;}
	a = 0;
	b = 0; 
    player_number = 0, computer_number = 0;
    cout << "Do you want to play again?(Y/N)";
    cin >> get;
    if (get == 'Y')
        {
    	    goto l2;
	    }
}

int get_card(int who) //the function can get a card
{
	int check(int card);
	srand(time(NULL));
	int card;
	double score;
	
	do
	{
	
	card = rand() * 52 / (RAND_MAX + 1);
    }
    while (check(card) != 0);
    {
    	switch(card / 4)
    	{
    		case 0 : score = card/4 + 1; break;
    		case 1 : score = card/4 + 1; break;
    		case 2 : score = card/4 + 1; break;
    		case 3 : score = card/4 + 1; break;
    		case 4 : score = card/4 + 1; break;
    		case 5 : score = card/4 + 1; break;
    		case 6 : score = card/4 + 1; break;
    		case 7 : score = card/4 + 1; break;
    		case 8 : score = card/4 + 1; break;
    		case 9 : score = card/4 + 1; break;
    		case 10 : score = 0.5; break;
    		case 11 : score = 0.5; break;
    		case 12 : score = 0.5; break;
    	}
    	if (who == 0)
    	{
    		player_card[a] = card;
	        a += 1;
	        player_number += score;
		}
		else
		{
			computer_card[b] = card;
			b += 1;
			computer_number += score;
		}
	}

}

int check(int card)// the function can check whether the card has been used
{
	int check = 0;
	for (int i=0; i<10; ++i)
	{
		if (card == player_card[i]){check += 1;}
	}
	for (int i=0; i <10; ++i)
	{
		if (card == computer_card[i]){check += 1;}
	}
	return (check);
}

int output(int who)// the function can output the card to the user
{
	int suit, number, i;
	if (who == 0)
	{
		for(i=0; i<10; ++i)
		{
			if (player_card[i] == 53){break;}
			else
			{
				number = player_card[i]/4;
				suit = player_card[i]%4;
				switch (suit)
				{
					case 0 : cout << "blade "; break;
					case 1 : cout << "diamond "; break;
					case 2 : cout << "club "; break;
					case 3 : cout << "heart"; break;
				}
				switch (number)
				{
					case 0 : cout << "A "; break;
					case 1 : cout << "2 "; break;
					case 2 : cout << "3 "; break;
					case 3 : cout << "4 "; break;
					case 4 : cout << "5 "; break;
					case 5 : cout << "6 "; break;
					case 6 : cout << "7 "; break;
					case 7 : cout << "8 "; break;
					case 8 : cout << "9 "; break;
					case 9 : cout << "10 "; break;
					case 10 : cout << "J "; break;
					case 11 : cout << "Q "; break;
					case 12 : cout << "k "; break;
				}				
			}
		}
	}
	else 
	{
		for(i=0; i<10; ++i)
		{
			if (computer_card[i] == 53){break;}
			else
			{
				number = computer_card[i]/4;
				suit = computer_card[i]%4;
				switch (suit)
				{
					case 0 : cout << "blade "; break;
					case 1 : cout << "diamond "; break;
					case 2 : cout << "club "; break;
					case 3 : cout << "heart"; break;
				}
				switch (number)
				{
					case 0 : cout << "A "; break;
					case 1 : cout << "2 "; break;
					case 2 : cout << "3 "; break;
					case 3 : cout << "4 "; break;
					case 4 : cout << "5 "; break;
					case 5 : cout << "6 "; break;
					case 6 : cout << "7 "; break;
					case 7 : cout << "8 "; break;
					case 8 : cout << "9 "; break;
					case 9 : cout << "10 "; break;
					case 10 : cout << "J "; break;
					case 11 : cout << "Q "; break;
					case 12 : cout << "k "; break;
				}				
			}
		}
	}
}

int judge(int who)//the function can judge the rusult of the game
{
	if (who == 0)
	{
		if (player_number > 21)
		{
			cout << "You Lose" << endl;
			return 1;
		}
		return 0;
	}
	if (who == 1)
	{
		if (computer_number > 21)
		{
			cout << "You Win" << endl;
			return 1;
		}
		else 
		{
			if (computer_number > player_number)
		    {
			    cout << "You Lose" << endl;
			    return 1;
		    }
		    if (computer_number == player_number)
		    {
		    	if (b > a)
		    	{
		    		cout << "You Lose" << endl;
		    		return 1;
				}
				else if(b == a)
				{
					cout << "It is a tie";
					return 1;
				}
			}
		}
		 return 0;
	}

	}




