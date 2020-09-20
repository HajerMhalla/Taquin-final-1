#ifndef GAMESTATE2_H
#define GAMESTATE2_H


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include <string>

	class GameState2 : public State
	{
	public:
		GameState2(GameDataRef data,std::string nom);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		bool checkExistance(int );

	private:
		void InitGridPieces();
		void CheckAndSwipPiece();//check if you can move the piece you clicked on
        bool checkwin();
		GameDataRef _data;
        sf::Text score;
        sf::Text text;
        sf::Font font;
        int ii=0;

		sf::Sprite _background;

		sf::Sprite _pauseButton;
		sf::Sprite _shuffleSprite;

		sf::Sprite _puzzleSprite;

		sf::Sprite _gridPieces[3][3];
		int gridArray[3][3];
		int grid [3][3]={0};
		sf::Sprite sprite[20];
		std::string name;
		//int w=64;


		int gameState;
		sf::Clock _clock;
		sf::SoundBuffer buffer;
		sf::Sound sound;
	};

#endif
