#ifndef INPUTSTATE_H
#define INPUTSTATE_H





#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include <string>


	class InputState: public State
	{
	public:
		InputState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);sf::String playerInput;

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _field;
        sf::Sprite _next;
        sf::Font font;

////////////////////////////////////////////////////::

        sf::Text playerText;
        sf::Text text;


	};




#endif // INPUTSTATE_H
