#ifndef CHOICESTATE_H
#define CHOICESTATE_H



#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include <string>

	class ChoiceState: public State
	{
	public:
		ChoiceState(GameDataRef data,std::string nom);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _image;

		sf::Sprite _numbers;
		std::string name;


	};


#endif // MAINMENUSTATE_H
