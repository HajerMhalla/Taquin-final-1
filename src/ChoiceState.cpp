

#include <sstream>
#include "ChoiceState.h"
#include "definitions.h"
#include "DimensionState.h"
#include "DimensionState1.h"
#include "InputState.h"




#include <iostream>


	ChoiceState::ChoiceState(GameDataRef data,std::string nom) : _data(data)
	{
        name=nom;
	}

	void ChoiceState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Numbers", Numbers_FILEPATH);
		this->_data->assets.LoadTexture("Image", Image_FILEPATH);

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));


		this->_numbers.setTexture(this->_data->assets.GetTexture("Numbers"));
		this->_image.setTexture(this->_data->assets.GetTexture("Image"));
		//this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));

		this->_numbers.setPosition(160, (SCREEN_HEIGHT / 2) -50- (this->_numbers.getGlobalBounds().height ));
		this->_image.setPosition(150, (SCREEN_HEIGHT / 2) +50- (this->_image.getGlobalBounds().height / 2));

	}

	void ChoiceState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_numbers, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Dimension State


                this->_data->machine.AddState(StateRef(new DimensionState(_data,name)), true);



			}
			 if (this->_data->input.IsSpriteClicked(this->_image, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Dimension State



                this->_data->machine.AddState(StateRef(new DimensionState1(_data,name)), true);

			}
		}
	}

	void ChoiceState::Update(float dt)
	{

	}

	void ChoiceState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_image);
		this->_data->window.draw(this->_numbers);

		this->_data->window.display();
	}

