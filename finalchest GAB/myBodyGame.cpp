#include <iostream>
#include "myConstant.h"
#include "myFunction.h"

using namespace std;
extern void ClearScreen();
extern void Tapping(const char data[], int speed);



// Start the intro
void intro()
{
	Tapping("Hey my bro ! Quiet or what ? Well, you have reached the final stage of this session.\n"
		"Your objective ? : \n\n"
		"Find all keys and unlock the treasure ! \n"
		"For that, you will have to venture into the labyrinth filled with obstacles !\n"
		"Good luck my brother !\n\n", 5);



	system("pause");
	ClearScreen();

	startGame();


}

// Ask the player if he wants to start the game
void startGame()
{
	int myChoice(0);

	Tapping("Do you want to satrt the game :\n\n"
		"1/ Yes, i'm hot \n2/ NO, i'm lazy \n\n", 5);
	cin >> myChoice;

	system("pause");
	ClearScreen();

	while (myChoice != 1 && myChoice != 2)
	{
		Tapping("MAKE CHOICE !! ASSHOLE !!!!!!"
			"Do you want to satrt the game :\n\n"
			"1/ Yes, i'm hot \n2/ NO, i'm lazy \n\n", 5);
		cin >> myChoice;

		system("pause");
		ClearScreen();
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
	Tapping("Your remainig hp : ", 5);
	cout << hp << " / " << PVMAX << "\n\n";


	Tapping("Your number of keys : ", 5);
	cout << keys << " / " << CLE << "\n\n";

}

// Choice of boxes check found items
void result(int& hp, int& keys, int& line, int& column, bool mat2[][COLONNE], char mat[][COLONNE])
{

	do
	{


		Tapping(" What line do you want ? : \t", 5);
		cin >> line;
		line--;

		Tapping("Choose your column my bro :  \t", 5);
		cin >> column;
		column--;


		if (mat2[line][column] == false)
		{
			Tapping("Soory my bro, this box is already full, restart please. \n", 5);
		}

	} while (mat2[line][column] == true);

	if (mat[line][column] == CHAR_SOIN)
	{
		Tapping("Well done you found the popo \n\n", 5);
		hp += 1;
	}

	if (mat[line][column] == CHAR_CLE)
	{
		Tapping("Well done you found one of the key \n\n", 5);
		keys += 1;
	}

	if (mat[line][column] == CHAR_DEGAT)
	{
		Tapping("And hop a mess in your face, HARD!! \n\n", 5);
		hp -= 1;
	}

	if (mat[line][column] == CHAR_NEUTRE)
	{
		Tapping("It's empty ! \n\n", 5);
	}
}

//Restart the game
void endGame()
{
	int endGame(0);

	if (PVMAX <= 0)
	{
		Tapping("You lose ! LOOOOOOOSSSSSSEEEEERRRRR !!!!!!", 5);

		system("pause");
		ClearScreen();

		Tapping("Good I see that see that you are dying to see lost.\nDo you want start over ?\n\n"
			"1/ Yes \n2/ No", 5);
		cin >> endGame;

		system("pause");
		ClearScreen();
	}

	while (endGame != 1 && endGame != 2)
	{
		Tapping("CHOSE OR I DESTROY YOU !!!!\n\n"
			"Good I see that see that you are dying to see lost.\nDo you want start over ? \n\n"
			"1/ Yes \n2/ No", 5);
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
