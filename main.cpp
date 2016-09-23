/*************************************************
	      01 Higher/Lower, Heads/Tails
	- This Higher/Lower, Heads/Tails Games.
	- Author : Ibrahim Mohamed Abdul-Meged.
	         : facebook.com/Ibrahiim.Pasha
		 : github.com/Ibrahiim-Pasha
	- Date : 23/9/2016 - 4:53 AM

*************************************************/

#include <iostream>
#include <cstdlib>   // for use rand() and srand()
#include <ctime>     // for use time()
#include <string>
#include <Windows.h> // for use sleep() -optional-
using namespace std;

// Creating functions
void start();
void higherLower();
void headsTails();
void againForHL();
void againForHT();
string getAnswerGameHT();
void exit();


int main()
{
	start(); // Start of the program

	system("PAUSE");
	return 0;
}

void start()
{
	int gameNumber;
	cout << "\t\tChoose whichever you want to play ?\n\n" << endl
		 << "\t\t\t1- Higher Or Lower" << endl
		 << "\t\t\t2- Heads Or Tails"  << endl
	   	 << "\t\t\t3- Exit"  << endl << endl;
	cin >> gameNumber;

	if (gameNumber == 1)
	{
		higherLower();
	}
	else if (gameNumber == 2)
	{
		headsTails();
	}
	else if (gameNumber == 3)
	{
		exit();
	}
}

void higherLower() // Higher or Lower Game
{
	int number, guess, answer;

	cout << "\nEnter the number to be guessed between 1 and : ";
	cin >> number;

	srand(time(NULL)); // seed random -> seed is a valid number assigned value of time (seconds) through the function time().
	guess = rand() % number; // rand() % number -> A random value between zero and number(Who enters the user).

	cout << "I've been to guess a number between 1 and " << number << ", do you know the number?" << endl << endl
	  	 << "Available for you only 10 attempts!" << endl << endl;

	for (int i = 0; i <= 10; i++)
	{
		cout << "Enter the number : ";
		cin >> answer;
		if (answer > guess)
		{
			cout << "Higher!\n";
		}
		else if (answer < guess)
		{
			cout << "Lower!\n";
		}
		else
		{
			cout << "Congratulations, correct answer!" << endl;
			againForHL();
		}
	}

	cout << "Game over!, You've skipped 10 attempts. The Guess number was : " << guess << endl << endl;
	againForHL();
}

void headsTails() // Heads or Tails Game
{
	string answer;

	srand(time(NULL)); // seed random -> seed is a valid number assigned value of time (seconds) through the function time().

	cout << endl << "Heads or Tails ?" << endl << endl;
	cin >> answer;

	if (answer == "Heads" || answer == "heads")
	{
		if (getAnswerGameHT() == "Heads")
		{
			cout << "-" << answer << "-" << " Congratulations, You win!\n\n";
			againForHT();
		}
		if (getAnswerGameHT() == "Tails")
		{
			cout << "-" << answer << "-" << " You lose!\n\n";
			againForHT();
		}
	}

	if (answer == "Tails" || answer == "tails")
	{
		if (getAnswerGameHT() == "Tails")
		{
			cout << "-" << answer << "-" << " Congratulations, You win!\n\n";
			againForHT();
		}
		if (getAnswerGameHT() == "Heads")
		{
			cout << "-" << answer << "-" << " You lose!\n\n";
			againForHT();
		}
	}
}

string getAnswerGameHT() // Get a random value , Is Heads or Tails ?
{
	string ht[2] = { "Heads", "Tails" };
	string answerGameHT;

	srand(time(NULL));
	answerGameHT = ht[rand() % 2]; // rand() % 2 -> A random value between zero and 2(Heads, Tails).
	return answerGameHT; // Return a random value
}

void againForHL() // To play again in : Higher or Lower Game
{
	char againAnswer;
	cout << "Again[Y/N]? : ";
	cin >> againAnswer;
	if (againAnswer == 'Y' || againAnswer == 'y')
	{
		higherLower();
	}
	else if (againAnswer == 'N' || againAnswer == 'n')
	{
		system("CLS"); // For clear console screen -optional-
		start();
	}
}

void againForHT() // To play again in : Heads or Tails Game
{
	char againAnswer;
	cout << "Again[Y/N]? : ";
	cin >> againAnswer;
	if (againAnswer == 'Y' || againAnswer == 'y')
	{
		headsTails();
	}
	else if (againAnswer == 'N' || againAnswer == 'n')
	{
		system("CLS"); // For clear console screen -optional-
		start();
	}
}

void exit()
{
	cout << endl << "Goodbye!" << endl;
	Sleep(2000);
	exit(0);
}
