#pragma once
#include "Character.h"

class Player :
	public Character
{
public:
	Player();
	~Player();

	void Update(sf::Time tmps);
	void Draw(sf::RenderWindow& rw);

	float GetSpeed() const;

private:
	float speed;
	float maxSpeed;
};
