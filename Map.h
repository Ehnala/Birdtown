#pragma once
#ifndef DEF_MAP
#define DEF_MAP
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
//#include "tmxlite/Map.hpp"
//#include "SFMLOrthogonalLayer.hpp"

class Map
{
	//Attributes
public:
	char* name;
	/*tmx::Map macarte;
	const auto& layers = macarte.getLayers();*/


	sf::Texture texture_map;
	sf::Sprite sprite_map;

	//Functions
	void create(char* texture);
	//static draw(sf::RenderWindow& window);

};

#endif
