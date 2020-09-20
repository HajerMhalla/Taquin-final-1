#ifndef GAMESTATE1_H
#define GAMESTATE1_H

#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include <string>

	class GameState1 : public State
	{
	public:
		GameState1(GameDataRef data,std::string  nom);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		bool checkExistance(int);

	private:
		void InitGridPieces();
		void CheckAndSwipPiece();//check if you can move the piece you clicked on
        bool checkwin();
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _pauseButton;
        sf::Sprite _shuffleSprite;
		sf::Sprite _puzzleSprite;

        sf::Text score;
        sf::Text text;
        sf::Font font;
        int ii=0;

		sf::Sprite _gridPieces[4][4];
		int gridArray[4][4];
		int grid [4][4];
		sf::Sprite sprite[20];
		int w=64;
		std::string name;


		int gameState;
		sf::Clock _clock;
		sf::SoundBuffer buffer;
		sf::Sound sound;
	};

#endif
