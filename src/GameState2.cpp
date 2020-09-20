

#include <sstream>
#include "GameState2.h"
#include "GameState4.h"
#include "MainMenuState.h"
#include "definitions.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "SFML/Audio.hpp"


#include <iostream>

	GameState2::GameState2(GameDataRef data,std::string nom) : _data(data)
	{
        name=nom;
	}

	void GameState2::Init()
	{
		gameState = STATE_PLAYING;

		if(!this->font.loadFromFile("resource/fonts/Marker Felt.ttf"))
    {
        std::cout<<"error font";
    }
    score.setFont(font);
    text.setFont(font);
    score.setString(std::to_string(ii));
    text.setString("clic :");
    score.setPosition(110,20);
    text.setPosition(20,20);
    score.setFillColor(sf::Color::White);
    text.setFillColor(sf::Color::White);
    score.setCharacterSize(50);text.setCharacterSize(50);


		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);

		this->_data->assets.LoadTexture("puzzle", PUZZLE_FILEPATH);


		this->_data->assets.LoadTexture("0", ZERO_FILEPATH);
		this->_data->assets.LoadTexture("1", ONE_FILEPATH);
		this->_data->assets.LoadTexture("2", TWO_FILEPATH);
		this->_data->assets.LoadTexture("3", THREE_FILEPATH);
		this->_data->assets.LoadTexture("4", FOUR_FILEPATH);
		this->_data->assets.LoadTexture("5", FIVE_FILEPATH);
		this->_data->assets.LoadTexture("6", SIX_FILEPATH);
		this->_data->assets.LoadTexture("7", SEVEN_FILEPATH);
		this->_data->assets.LoadTexture("8", EIGHT_FILEPATH);
        this->_data->assets.LoadTexture("shuffle", shuffle_FILEPATH);




		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
		_puzzleSprite.setTexture(this->_data->assets.GetTexture("puzzle"));

		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
        _shuffleSprite.setTexture(this->_data->assets.GetTexture("shuffle"));
        _shuffleSprite.setPosition(500,5);

		InitGridPieces();
		int n=0;

		if(!buffer.loadFromFile("resource/res/button-11.wav"))
    {
        std::cout<<"Error downloading sound";
    }
    this->sound.setBuffer(buffer);



	}

	void GameState2::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{


				this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
			}

            if (this->_data->input.IsSpriteClicked(this->_shuffleSprite, sf::Mouse::Left, this->_data->window))
            {

                this->_data->machine.AddState(StateRef(new GameState2(_data,name)), true);
            }

			else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][0], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }
            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][1], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }
            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][2], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }

            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][0], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }
            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][1], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }
            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][2], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }

            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][0], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }
            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][1], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }
            else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][2], sf::Mouse::Left, this->_data->window))
            {
                this->CheckAndSwipPiece();ii++;score.setString(std::to_string(ii));
            }



		}
	}

	void GameState2::Update(float dt)
	{


	}

	void GameState2::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background );

		this->_data->window.draw( this->_pauseButton );
        this->_data->window.draw( this->_shuffleSprite );
        this->_data->window.draw( this->score );
        this->_data->window.draw( this->text );


		for (int x= 0; x <3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				this->_data->window.draw(this->_gridPieces[x][y]);
			}
		}
		this->_data->window.display();
	}
bool GameState2::checkExistance(int n)
{

    for (int i=0 ; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (grid[i][j]==n) {return true;}
        }
    }
    return false;
}
	void GameState2::InitGridPieces()
	{
		sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("1").getSize();
		int n=1;
		    srand(time(0));
    int num;
for (int i=0 ; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
             grid[i][j]=100;
        }
    }


		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
			    do
            {
                num = (rand()%9);

            }
            while(checkExistance(num)==true);
             grid[x][y]=num;
            _gridPieces[x][y].setTexture(this->_data->assets.GetTexture(std::to_string(num)));
			   /* if (n==1)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("1"));grid[x][y]=1;}
                if (n==2)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("2"));grid[x][y]=2;}
                if (n==3)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("3"));grid[x][y]=3;}
                if (n==4)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("4"));grid[x][y]=4;}
                if (n==5)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("5"));grid[x][y]=5;}
                if (n==6)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("6"));grid[x][y]=6;}
                if (n==7)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("7"));grid[x][y]=7;}
                if (n==8)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("8"));grid[x][y]=8;}

                if (n==9)
                {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("0"));grid[x][y]=16;}*/



				_gridPieces[x][y].setPosition(170 + (tempSpriteSize.x * x) -7, 350 + (tempSpriteSize.y * y) - 7);
				_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 255));
				n++;
			}

		}
		for (int i=0 ; i<3 ; i++ )
        {
            for (int j =0 ; j<3 ; j++)
            {
                if (grid[i][j]==0)
                    grid[i][j]=16;
            }
        }
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{std::cout<<grid[y][x]<<"  ";}
			std::cout<<std::endl;

        }
	}
	void GameState2::CheckAndSwipPiece()
	{
	    sf::Vector2i touchPoint= this->_data->input.GetMousePosition(this->_data->window);
        sf::Vector2f gapOutsideOfGrid= sf::Vector2f(170,350);
        int column,row;
        sf::Vector2f gridLocalTouchPos=sf::Vector2f(touchPoint.x-gapOutsideOfGrid.x, touchPoint.y-gapOutsideOfGrid.y);
        sf::Vector2f gridSectionSize=sf::Vector2f(148,147);
        //getting the column and the row
        if (gridLocalTouchPos.x<gridSectionSize.x)
        {
            column=0;
        }
        else if (gridLocalTouchPos.x<gridSectionSize.x*2)
        {
            column=1;
        }
        else if (gridLocalTouchPos.x<gridSectionSize.x*3)
        {
            column=2;
        };
        if (gridLocalTouchPos.y<gridSectionSize.y)
        {
            row=0;
        }
        else if (gridLocalTouchPos.y<gridSectionSize.y*2)
        {
            row=1;
        }
        else if (gridLocalTouchPos.y<gridSectionSize.y*3)
        {
            row=2;
        };


        int dx=0;
        int dy=0;//deplacement
        std::cout<<grid[column+1][row]<<std::endl;
        std::cout<<grid[column][row+1]<<std::endl;
        std::cout<<grid[column-1][row]<<std::endl;
        std::cout<<grid[column][row-1]<<std::endl;

        if (grid[column+1][row]==16) {dx=1; dy=0; }
        else if (grid[column][row+1]==16) {dx=0; dy=1;}
        else if (grid[column][row-1]==16) {dx=0; dy=-1;}
        else if (grid[column-1][row]==16) {dx=-1;dy=0;};

        int n=grid[column][row];
        grid[column][row]=16;
        grid[column+dx][row+dy]=n;
        int w=148;
        float speed=1;

        for (int i=0;i<w;i+=speed)
                     {_gridPieces[column][row].move(speed*dx,speed*dy);
                     if((dx!=0)||(dy!=0))
        {sound.play();}
        this->_data->window.draw(this->_gridPieces[column][row]);
        this->_data->window.draw(this->_gridPieces[column+dx][row+dy]);
        this->_data->window.display();}
        for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{std::cout<<grid[y][x]<<"  ";}
			std::cout<<std::endl;
        }
        if(this->checkwin()==true)
        {
            this->_data->machine.AddState(StateRef (new GameOverState(_data,name)),true);
        }






	}
	bool GameState2::checkwin()
	{

	    int n=1;
	    for (int i=0;i<4;i++)
	    {
	        for( int j =0;j<4;j++)
	        {
	            if (grid[i][j]!=n)
                    {return false;}
                n++;
	        }

	    }
	    return true;
	}
