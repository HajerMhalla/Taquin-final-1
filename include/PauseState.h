#ifndef PAUSESTATE_H
#define PAUSESTATE_H


#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};

#endif // PAUSESTATE_H
