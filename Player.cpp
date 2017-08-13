#include "StdAfx.h"
#include "Player.h"
#include "Game.h"


Player::Player() :
	speed(2.0),
	maxSpeed(5.0f)
{
	Load("sprite_heros_face.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);

}


Player::~Player()
{
}

void Player::Draw(sf::RenderWindow & rw)
{
	Character::Draw(rw);
}

float Player::GetSpeed() const
{
	return speed;
}



void Player::Update(sf::Time tmps)
{
	//Conditions on player's position
	//TODO Collisions


	//Movements of the player

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		GetSprite().move(0, -speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		GetSprite().move(0, speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		GetSprite().move(-speed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		GetSprite().move(speed, 0);
	}





}