

#include <sstream>
#include "DimensionState.h"
#include "definitions.h"
#include "GameState.h"
#include "GameState2.h"
#include "ChoiceState.h"


#include <iostream>


	DimensionState::DimensionState(GameDataRef data,std::string nom) : _data(data)
	{
            name=nom;
	}

	void DimensionState::Init()
	{
	    std::cout<<"le choix est "<<choix;
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("3x3", x3_FILEPATH);
		this->_data->assets.LoadTexture("4x4", x4_FILEPATH);
		this->_data->assets.LoadTexture("return", return_FILEPATH);

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));

		this->_3x3.setTexture(this->_data->assets.GetTexture("3x3"));
		this->_4x4.setTexture(this->_data->assets.GetTexture("4x4"));
		this->_return.setTexture(this->_data->assets.GetTexture("return"));
		//this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));

		this->_3x3.setPosition(160, (SCREEN_HEIGHT / 2) -50- (this->_3x3.getGlobalBounds().height )-10);
		this->_4x4.setPosition(163, (SCREEN_HEIGHT / 2) +55- (this->_4x4.getGlobalBounds().height / 2));
		this->_return.setPosition(20,20);

	}

	void DimensionState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_return, sf::Mouse::Left, this->_data->window))
			{

                this->_data->machine.AddState(StateRef(new ChoiceState(_data,name)), true);

			}

			if (this->_data->input.IsSpriteClicked(this->_4x4, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Game State
				std::cout<<"4x4 choice";
                this->_data->machine.AddState(StateRef(new GameState(_data,name)), true);

			}
			 if (this->_data->input.IsSpriteClicked(this->_3x3, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Game State
				std::cout<<"3x3 choice";
                this->_data->machine.AddState(StateRef(new GameState2(_data,name)), true);

			}
		}
	}

	void DimensionState::Update(float dt)
	{

	}

	void DimensionState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_3x3);
		this->_data->window.draw(this->_4x4);
		this->_data->window.draw(this->_return);

		this->_data->window.display();
	}

