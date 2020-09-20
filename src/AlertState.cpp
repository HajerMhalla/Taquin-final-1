#include "AlertState.h"

#include "GameState.h"
#include "MainMenuState.h"
#include "definitions.h"

#include <iostream>


	AlertState::AlertState(GameDataRef data) : _data(data)
	{

	}

	void AlertState::Init()
	{
	    if(!this->font.loadFromFile("resource/fonts/Marker Felt.ttf"))
    {
        std::cout<<"error font";
    }


    text.setFont(font);
    text.setString("Really quit? ");
    text.setPosition(250,400);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(60);

		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("No Button", no_FILEPATH);
		this->_data->assets.LoadTexture("Yes Button", yes_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_noButton.setTexture(this->_data->assets.GetTexture("No Button"));
		this->_yesButton.setTexture(this->_data->assets.GetTexture("Yes Button"));

		this->_noButton.setPosition(100, (this->_data->window.getSize().y / 3) - (this->_noButton.getLocalBounds().height / 2)+200);
		this->_yesButton.setPosition(480, (this->_data->window.getSize().y / 3) - (this->_noButton.getLocalBounds().height / 2)+200);
	}

	void AlertState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_noButton, sf::Mouse::Left, this->_data->window))
			{
				// Resume Game By Popping Of The Current State (Pause State)
				this->_data->machine.RemoveState();

			}

			if (this->_data->input.IsSpriteClicked(this->_yesButton, sf::Mouse::Left, this->_data->window))
			{
				// Remove The Pause State Off The Stack
				//this->_data->machine.RemoveState();

				// Switch To Main Menu State By Replacing The Game State
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

			}
		}
	}

	void AlertState::Update(float dt)
	{

	}

	void AlertState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_noButton);
		this->_data->window.draw(this->_yesButton);
		this->_data->window.draw(this->text);

		this->_data->window.display();
	}


