#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <map>
#include <vector>



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
#include "Game.h"

#include <string>


	class GameState : public State
	{
	public:
		GameState(GameDataRef data,std::string nom);

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
        sf::Text score;
        sf::Text text;
        sf::Font font;
        int ii=0;
		sf::Sprite _pauseButton;

		sf::Sprite _puzzleSprite;
		sf::Sprite _shuffleSprite;

		sf::Sprite _gridPieces[4][4];
		int gridArray[4][4];
		int grid [4][4];
		int grid1 [4][4];
		sf::Sprite sprite[20];
		int pos1;
		int pos2;
		//int w=64;
		sf::SoundBuffer buffer;
		sf::Sound sound;
		std::string name;


        int oo,uu;

		int gameState;
		sf::Clock _clock;

	};

#endif
