#pragma once

#include "Player.h"
#include "PlayerChoices.h"

class Game
{
private:
	Player m_player;

	void Welcome();
	void GivePlayerChoices() const;
	void GetPlayerInput(std::string& playerInput) const;
	PlayerOptions EvaluateInput(std::string& playerInput) const;
public:

	void RunGame();
};