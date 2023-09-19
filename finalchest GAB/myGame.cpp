#include <iostream>
#include "myConstant.h"
#include "myFunction.h"

using namespace std;


// Displays the matrix

void myGame()
{
	char mat[LIGNE][COLONNE];
	bool mat2[LIGNE][COLONNE];
	int line = 0;
	int column = 0;
	int key = 0;
	int Hp = PVMAX;
	display(mat, mat2);


	do
	{
		displayStat(Hp, key);
		iniTab(mat2);
		result(line, column, Hp, key, mat2, mat);

		system("pause");
		system("CLS");

	} while (Hp > 0 && key < 3);

	if (Hp <= 0)
	{
		endGame();
	}

	if (key == 3)
	{
		cout << " You win the final test ! You are true warrior \n\n" << " See you again, my friend \n";


		system("pause");
		exit(0);
	}
}
// Start the intro
void intro()
{
	cout << "Hey my bro ! Quiet or what ? Well, you have reached the final stage of this session.\n"
		"Your objective ? : \n\n"
		"Find all keys and unlock the treasure ! \n"
		"For that, you will have to venture into the labyrinth filled with obstacles !\n"
		"Good luck my brother !\n\n";



	system("pause");
	system("CLS");

	startGame();


}

// Ask the player if he wants to start the game
void startGame()
{
	int myChoice(0);

	cout << "Do you want to satrt the game :\n\n"
		"1/ Yes, i'm hot \n2/ NO, i'm lazy \n\n";
	cin >> myChoice;

	system("pause");
	system("CLS");

	while (myChoice != 1 && myChoice != 2)
	{
		cout << "MAKE CHOICE !! ASSHOLE !!!!!!"
			"Do you want to satrt the game :\n\n"
			"1/ Yes, i'm hot \n2/ NO, i'm lazy \n\n";
		cin >> myChoice;

		system("pause");
		system("CLS");
	}
	switch (myChoice)
	{
	case 1:
		myGame();
	case 2:
		exit(0);

	default:
		startGame();
		break;
	}
}

// Array initialisation
void iniTab(char mat[][COLONNE])
{
	for (int i = 0; i < LIGNE; i++)
	{
		for (int j = 0; j < COLONNE; j++)
		{
			cout << " [ " << mat[LIGNE][COLONNE] << " ] " << "\t";
		}
		cout << "\n";
	}
}

// Row / column mark
void iniTab(bool mat2[][COLONNE])
{
	int index = 1;

	cout << "1	2	3	4	5	6	7	8	9	10\n";

	for (int line = 0; line < LIGNE; line++)
	{
		if (index < 10)
		{
			cout << index << " ";
		}
		else
		{
			cout << index;
		}
		for (int column = 0; column < COLONNE; column++)
		{
			if (mat2[line][column] == false)
			{
				cout << " [ " << " " << " ] ";
			}
			else
			{
				cout << " [ " << " * " << " ] ";
			}
		}
		index++;
		cout << "\n";
	}


}

// Random distribution of healing, keys and damage and check if the objects are found 
void display(char mat[][COLONNE], bool mat2[][COLONNE])
{
	int line = rand() % 10;
	int column = rand() % 10;

	int careCounter = SOIN;
	int dommageCounter = DEGAT;
	int keyCounter = CLE;

	for (int line = 0; line < LIGNE; line++)
	{
		for (int column = 0; column < COLONNE; column++)
		{
			mat[line][column] = CHAR_NEUTRE;
		}
	}

	do
	{
		if (mat[line][column] == CHAR_NEUTRE)
		{
			mat[line][column] = CHAR_CLE;
			keyCounter--;
		}
	} while (keyCounter >= 0);

	do
	{
		if (mat[line][column] == CHAR_NEUTRE)
		{
			mat[line][column] = CHAR_SOIN;
			careCounter--;
		}
	} while (careCounter >= 0);

	do
	{

		if (mat[line][column] == CHAR_NEUTRE)
		{
			mat[line][column] = CHAR_DEGAT;
			dommageCounter--;
		}
	} while (dommageCounter >= 0);


	for (int line = 0; line < LIGNE; line++)
	{
		for (int column = 0; column < COLONNE; column++)
		{
			mat2[line][column] = false;
		}
	}

}

// Stats of players 
void displayStat(int hp, int keys)
{
	cout << "Your remainig hp : ";
	cout << hp << " / " << PVMAX << "\n\n";


	cout << "Your number of keys : ";
	cout << keys << " / " << CLE << "\n\n";

}

// Choice of boxes check found items
void result(int& hp, int& keys, int& line, int& column, bool mat2[][COLONNE], char mat[][COLONNE])
{

	do
	{


		cout << " What line do you want ? : \t";
		cin >> line;
		line--;

		cout << "Choose your column my bro :  \t";
		cin >> column;
		column--;


		if (mat2[line][column] == false)
		{
			cout << "Soory my bro, this box is already full, restart please. \n";
		}

	} while (mat2[line][column] == true);

	if (mat[line][column] == CHAR_SOIN)
	{
		cout << "Well done you found the popo \n\n";
		hp += 1;
	}

	if (mat[line][column] == CHAR_CLE)
	{
		cout << "Well done you found one of the key \n\n";
		keys += 1;
	}

	if (mat[line][column] == CHAR_DEGAT)
	{
		cout << "And hop a mess in your face, HARD!! \n\n";
		hp -= 1;
	}

	if (mat[line][column] == CHAR_NEUTRE)
	{
		cout << "It's empty ! \n\n";
	}
}

//Restart the game
void endGame()
{
	int endGame(0);

	if (PVMAX <= 0)
	{
		cout << "You lose ! LOOOOOOOSSSSSSEEEEERRRRR !!!!!!";

		system("pause");
		system("CLS");

		cout << "Good I see that see that you are dying to see lost.\nDo you want start over ?\n\n"
			"1/ Yes \n2/ No";
		cin >> endGame;

		system("pause");
		system("CLS");
	}

	while (endGame != 1 && endGame != 2)
	{
		cout << "CHOSE OR I DESTROY YOU !!!!\n\n"
			"Good I see that see that you are dying to see lost.\nDo you want start over ? \n\n"
			"1/ Yes \n2/ No";
		cin >> endGame;
	}

	switch (endGame)
	{
	case 1:
		intro();
		break;

	case 2:
		exit(0);

	default:

		exit(0);
	}

}
