#include "InputState.h"



#include <sstream>
#include "MainMenuState.h"
#include "definitions.h"
#include "InputState.h"
#include "ChoiceState.h"




#include <iostream>


	InputState::InputState(GameDataRef data) : _data(data)
	{

	}

	void InputState::Init()
	{
	    if(!this->font.loadFromFile("resource/fonts/Marker Felt.ttf"))
        {
        std::cout<<"error font";
        }
        playerText.setFont(font);
        text.setFont(font);
        text.setString("Please enter your name");
        text.setPosition(140,430);
        text.setColor(sf::Color::Green);

        playerText.setPosition(140,510);

        playerText.setColor(sf::Color::White);


		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Next", next_FILEPATH);
		this->_data->assets.LoadTexture("Field", field_FILEPATH);


        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_field.setTexture(this->_data->assets.GetTexture("Field"));
        this->_next.setTexture(this->_data->assets.GetTexture("Next"));


        _field.setPosition(130,500);
        _next.setPosition(600,600);



	}

	void InputState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{


		     if (event.type == sf::Event::TextEntered)
                            {
                                if(event.text.unicode < 128)
                                    {
                                        playerInput +=event.text.unicode;
                                        playerText.setString(playerInput);
                                    }
                            }



			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_next, sf::Mouse::Left, this->_data->window))
			{
				// Switch To choice State
				this->_data->machine.AddState(StateRef(new ChoiceState(_data,playerInput.toAnsiString())), true);

				std::cout << playerInput.toAnsiString() ;
			}


		}
	}

	void InputState::Update(float dt)
	{

	}

	void InputState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);




		this->_data->window.draw(this->_field);

		this->_data->window.draw(this->playerText);
		this->_data->window.draw(this->text);
		this->_data->window.draw(this->_next);

		this->_data->window.display();


	}


