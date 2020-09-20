#ifndef ALERTSTATE_H
#define ALERTSTATE_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


	class AlertState : public State
	{
	public:
		AlertState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Text text;
        sf::Font font;
		sf::Sprite _yesButton;
		sf::Sprite _noButton;

	};

#endif // PAUSESTATE_H

