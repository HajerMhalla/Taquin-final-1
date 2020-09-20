#ifndef GameOverState_H
#define GameOverState_H


#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include <string>



	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data,std::string nom);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;
        sf::Text text;
        sf::Font font;
		sf::Sprite _homeButton;
		std::string name;


	};


#endif // MAINMENUSTATE_H
