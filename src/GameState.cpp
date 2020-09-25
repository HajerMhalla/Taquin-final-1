

#include <sstream>
#include "GameState.h"
#include "MainMenuState.h"
#include "definitions.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "SFML/Audio.hpp"
#include <string>
using namespace std;
#include <iostream>

GameState::GameState(GameDataRef data,std::string nom) : _data(data)
{
    name=nom;
}

void GameState::Init()
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
    if(!buffer.loadFromFile("resource/res/button-11.wav"))
    {
        std::cout<<"Error downloading sound";
    }
    this->sound.setBuffer(buffer);


    this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
    this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);

    this->_data->assets.LoadTexture("puzzle", PUZZLE_FILEPATH);
    this->_data->assets.LoadTexture("shuffle", shuffle_FILEPATH);


    this->_data->assets.LoadTexture("0", ZERO_FILEPATH);
    this->_data->assets.LoadTexture("1", ONE_FILEPATH);
    this->_data->assets.LoadTexture("2", TWO_FILEPATH);
    this->_data->assets.LoadTexture("3", THREE_FILEPATH);
    this->_data->assets.LoadTexture("4", FOUR_FILEPATH);
    this->_data->assets.LoadTexture("5", FIVE_FILEPATH);
    this->_data->assets.LoadTexture("6", SIX_FILEPATH);
    this->_data->assets.LoadTexture("7", SEVEN_FILEPATH);
    this->_data->assets.LoadTexture("8", EIGHT_FILEPATH);
    this->_data->assets.LoadTexture("9", NINE_FILEPATH);
    this->_data->assets.LoadTexture("10", TEN_FILEPATH);
    this->_data->assets.LoadTexture("11", ELEVEN_FILEPATH);
    this->_data->assets.LoadTexture("12", TWELVE_FILEPATH);
    this->_data->assets.LoadTexture("13", THIRTEEN_FILEPATH);
    this->_data->assets.LoadTexture("14", FOURTEEN_FILEPATH);
    this->_data->assets.LoadTexture("15", FIVETEEN_FILEPATH);



    _background.setTexture(this->_data->assets.GetTexture("Background"));
    _pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
    _puzzleSprite.setTexture(this->_data->assets.GetTexture("puzzle"));
    _shuffleSprite.setTexture(this->_data->assets.GetTexture("shuffle"));

    _pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
    _shuffleSprite.setPosition(500,5);

    InitGridPieces();



}

void GameState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)//fermer la fenetre de jeu
        {
            this->_data->window.close();
        }
        if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
            //mettre le  jeu en pause
        }
        if (this->_data->input.IsSpriteClicked(this->_shuffleSprite, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new GameState(_data,name)), true);//melanger les tuiles
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][0], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();
            ii++;score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][1], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][2], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[0][3], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][0], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][1], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][2], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[1][3], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][0], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][1], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][2], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[2][3], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[3][0], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[3][1], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[3][2], sf::Mouse::Left, this->_data->window))
        {
            this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
        }
        else if	(this->_data->input.IsSpriteClicked(this->_gridPieces[3][3], sf::Mouse::Left, this->_data->window))
        {
            if (STATE_PLAYING==gameState)
            {
                this->CheckAndSwipPiece();ii++; score.setString(std::to_string(ii));
            }
        }

    }
}

void GameState::Update(float dt)
{


}

void GameState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);

    this->_data->window.draw( this->_background );

    this->_data->window.draw(this->_pauseButton );
    this->_data->window.draw(this->_shuffleSprite );
    this->_data->window.draw(this->score);
    this->_data->window.draw( this->text);


    for (int x = 0; x <4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            this->_data->window.draw(this->_gridPieces[x][y]);
        }
    }
    this->_data->window.display();
}
bool GameState::checkExistance(int n)
{

    for (int i=0 ; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (grid[i][j]==n) {return true;}
        }
    }
    return false;
}
void GameState::InitGridPieces()
{
    sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("1").getSize();
    int n=1;
    srand(time(0));
    int num;
    for (int i=0 ; i<4;i++)
    {
        for (int j=0; j<4; j++)
        {grid[i][j]=100;}//initialiser la matrice grid par un entier different de 1 a 15 pour ne pas avoir une boucle infinie
    }
    for (int x = 0; x < 4;x++)
    {
        for (int y = 0;y< 4;y++)

        {
            if(x==3&&y==3) {num=0;}
            else
            {do
            {num =(rand()%16);}
            while(checkExistance(num)==true|| num==0);}//choisir un entier aleatoire a condition qu'il n'est pas dans grid
            grid[x][y]=num;
            grid1[x][y]=num;
            if (num!=0)
            {_gridPieces[x][y].setTexture(this->_data->assets.GetTexture(std::to_string(num)));//affecter la texture
            _gridPieces[x][y].setPosition(88 + (tempSpriteSize.x * x) -7, 274 + (tempSpriteSize.y * y) - 7);//mettre a sa position
            _gridPieces[x][y].setColor(sf::Color(255, 255, 255, 255));}
            n++;

            /*if (n==1)
            {
                grid[x][y]=1;
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("1"));

            }
            if (n==2)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("2"));
                grid[x][y]=2;
            }
            if (n==3)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("3"));
                grid[x][y]=3;
            }
            if (n==4)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("4"));
                grid[x][y]=4;
            }
            if (n==5)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("5"));
                grid[x][y]=5;
            }
            if (n==6)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("6"));
                grid[x][y]=6;
            }
            if (n==7)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("7"));
                grid[x][y]=7;
            }
            if (n==8)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("8"));
                grid[x][y]=8;
            }
            if (n==9)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("9"));
                grid[x][y]=9;
            }
            if (n==10)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("10"));
                grid[x][y]=10;
            }
            if (n==11)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("11"));
                grid[x][y]=11;
            }
            if (n==12)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("12"));
                grid[x][y]=12;
            }
            if (n==13)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("13"));
                grid[x][y]=13;
            }
            if (n==14)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("14"));
                grid[x][y]=14;
            }
            if (n==15)
            {
                //_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("0"));
                grid[x][y]=16;
            }
            if (n==16)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("15"));
                grid[x][y]=15;
            }*/



        }

    }for (int i=0 ; i<4 ; i++ )
        {
            for (int j =0 ; j<4 ; j++)
            {
                if (grid[i][j]==0)
                    grid[i][j]=16;
            }
        }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            std::cout<<grid[y][x]<<"  ";

        }

        std::cout<<std::endl;

    }
}
void GameState::CheckAndSwipPiece()
{
    sf::Vector2i touchPoint= this->_data->input.GetMousePosition(this->_data->window);
    sf::Vector2f gapOutsideOfGrid= sf::Vector2f(88,278);
    int column=0;
    int row=0;
    sf::Vector2f gridLocalTouchPos=sf::Vector2f(touchPoint.x-gapOutsideOfGrid.x, touchPoint.y-gapOutsideOfGrid.y);
    sf::Vector2f gridSectionSize=sf::Vector2f(147,147);
    //getting the column and the row of the clicked tile
    if (gridLocalTouchPos.x<gridSectionSize.x)
    {column=0;}
    else if (gridLocalTouchPos.x<gridSectionSize.x*2)
    {column=1;}
    else if (gridLocalTouchPos.x<gridSectionSize.x*3)
    {column=2;}
    else if (gridLocalTouchPos.x<gridSectionSize.x*4)
    {column=3;};
    if (gridLocalTouchPos.y<gridSectionSize.y)
    {row=0;}
    else if (gridLocalTouchPos.y<gridSectionSize.y*2)
    {row=1;}
    else if (gridLocalTouchPos.y<gridSectionSize.y*3)
    {row=2;}
    else if (gridLocalTouchPos.y<gridSectionSize.y*4)
    {row=3;}
    int dx=0;
    int dy=0;// vecteur de deplacement
    if (grid[column+1][row]==16 && column <=3)
    {dx=1;dy=0;}
    else if (grid[column][row+1]==16 &&row<=3)
    {dx=0;dy=1;}
    else if (grid[column][row-1]==16&& row>=1)
    {dx=0;dy=-1;}
    else if (grid[column-1][row]==16&& column>=1)
    {dx=-1;dy=0;};

    int n=grid[column][row];
    grid[column][row]=16;
    grid[column+dx][row+dy]=n;

    sf::Sprite a16 =_gridPieces[column+dx][row+dy];
    sf::Sprite a=_gridPieces[column][row];


    int w=147;
    float speed=3;
    std::cout<<"dx = "<<dx<<" dy= "<<dy<<std::endl;
    for (int i=0 ; i<4;i++)
    {
        for(int j=0; j<4; j++)
        {
            if (grid1[i][j]==n)
            {pos1=i;pos2=j;}
        }
    }


    for (int i=0; i<w; i+=speed)
    {
        _gridPieces[pos1][pos2].move(speed*dx,speed*dy);
        //_gridPieces[pos1+dx][pos2+dy].move(-speed*dx,-speed*dy);
        if((dx!=0)||(dy!=0))
        {sound.play();}
        this->_data->window.draw(this->_gridPieces[pos1][pos2]);
       // this->_data->window.draw(this->_gridPieces[pos1+dx][pos2+dy]);
        this->_data->window.display();
    }

    if(this->checkwin()==true)
    {
        this->_data->machine.AddState(StateRef (new GameOverState(_data,name,ii)),true);
    }


    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            std::cout<<grid[y][x]<<"  ";
        }
        std::cout<<std::endl;
    }







}
bool GameState::checkwin()
{

    int n=1;
    for (int i=0; i<4; i++)
    {
        for( int j =0; j<4; j++)
        {
            if (grid[i][j]!=n)
            {
                return false;
            }
            n++;
        }

    }
    return true;
}
