#pragma once

#include <sstream>
#include "GameOverState.h"
#include "definitions.h"
#include "GameState.h"
#include "MainMenuState.h"

#include <iostream>



	GameOverState::GameOverState(GameDataRef data,std::string nom) : _data(data)
	{
        nom=name;
	}

	void GameOverState::Init()
	{
	    if(!this->font.loadFromFile("resource/fonts/Marker Felt.ttf"))
        {
            std::cout<<"error font";
        }

        text.setFont(font);
        text.setString("congrats you did it!");
        text.setPosition(200,100);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(60);
		this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_retryButton.setPosition((this->_data->window.getSize().x / 2) - (this->_retryButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3) - (this->_retryButton.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Main Menu State By Replacing The Game Over State
				this->_data->machine.AddState(StateRef(new GameState(_data,name)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Main Menu State By Replacing The Game Over State
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

			}
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Yellow);

		this->_data->window.draw(this->_retryButton);
		this->_data->window.draw(this->_homeButton);
		this->_data->window.draw(this->text);

		this->_data->window.display();
	}

