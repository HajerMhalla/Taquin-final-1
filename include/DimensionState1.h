#ifndef DIMENSIONSTATE1_H
#define DIMENSIONSTATE1_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include <string>


	class DimensionState1: public State
	{
	public:
		DimensionState1(GameDataRef data,std::string nom);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _return;

		sf::Sprite _3x3;

		sf::Sprite _4x4;
		std::string name;


	};


#endif // MAINMENUSTATE_H

