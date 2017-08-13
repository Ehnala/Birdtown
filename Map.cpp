#include "Map.h"

using namespace std;

void Map::create(char* texture)
{

	//Map texture
	if (!texture_map.loadFromFile(texture)) {
		printf("Probleme chargement PNJ");
	}
	texture_map.setSmooth(true);
	sprite_map.setTexture(texture_map);

	/*if (!macarte.load("./carte.tmx")) {
		printf("ca marche pas!\n");
	}

	//Map layers
	MapLayer layerZero(macarte, 0);
	MapLayer layerOne(macarte, 1);
	MapLayer layerTwo(macarte, 2);
	MapLayer layerThree(macarte, 3);
	MapLayer layerFour(macarte, 4);
	MapLayer layerFive(macarte, 5);
	MapLayer layerSix(macarte, 6);
	MapLayer layerSeven(macarte, 7);
	MapLayer layerEight(macarte, 8);
	MapLayer layerNine(macarte, 9);*/


}

/*void Map::draw(sf::RenderWindow& window)
{
	
	//Drawing of the map on the window
	/*window.draw(layerZero);
	window.draw(layerOne);
	window.draw(layerTwo);

	//Map animation
	/*if (animation) {
		window.draw(layerThree);
		animation = false;
	}
	else {
		window.draw(layerFour);

		animation = true;
	}*/

	/*window.draw(layerfour);
	window.draw(layerFive);*/

	//mapMenu.create("menu_birdtown.png");

//}