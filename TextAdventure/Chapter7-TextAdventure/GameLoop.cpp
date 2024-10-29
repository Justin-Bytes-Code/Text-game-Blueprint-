#include "GameLoop.h"
#include <iostream>


//Justin perez


using namespace std;

void Game::Welcome()
{
	cout << "Welcome to Text Game!" << endl << endl;
	cout << "What is your name?" << endl << endl;

	string name;
	cin >> name;
	m_player.SetName(name);

	cout << endl << "Hello " << m_player.GetName() << endl;
}

void Game::GivePlayerChoices() const
{
	cout << "Enter a number" << endl << endl;
	cout << "1: Quit" << endl << endl;

	//Added Another Option here blue print
	cout << "2: Another Option" << endl << endl;

	//console
	cout << "3: What console do you like? " << endl << endl;
}

void Game::GetPlayerInput(string& playerInput) const
{
	cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(string& playerInput) const
{
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0)
	{
		cout << "You have chosen to Quit!" << endl << endl;
		chosenOption = PlayerOptions::Quit;
	}
	//Added Another Option here blue print
	if (playerInput.compare("2") == 0)
	{
		cout << "You picked another option!" << endl << endl;
		cout << "Try another option!" << endl << endl;
	}
	//Console
	if (playerInput.compare("3") == 0) 
	{
		cout << "What console do you like?" << endl;
		cin >> playerInput; // Overwrite playerInput with user's response
		cout << endl;
		cout << "So you like? " << playerInput << endl << endl; // Print back the user's response
	}
	else
	{
		cout << "Try again!" << endl << endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
	Welcome();

	bool shouldEnd = false;
	while (shouldEnd == false)
	{
		GivePlayerChoices();

		string playerInput;
		GetPlayerInput(playerInput);

		shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
	}
}