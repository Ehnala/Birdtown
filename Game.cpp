#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Map.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	//Creation of game windows
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Birdtown");
	_mainWindow.setFramerateLimit(60);
	//TODO - Creation de l'inventaire

	//Creation of the map
	//Map carte = Map.create("map.png");

	//Creation of game's entities
	Player *player1 = new Player();
	player1->SetPosition((SCREEN_WIDTH / 2), 700);

	_gameObjectManager.Add("Paddle1", player1);
	//TODO PNJs

	//First game state
	_gameState = Game::ShowingSplash;


	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}


sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

void Game::GameLoop()
{
	sf::View vue;
	sf::Event event;


	switch (_gameState)
	{
	case Game::ShowingMenu:
	{
		ShowMenu();
		break;
	}
	case Game::ShowingSplash:
	{
		ShowSplashScreen();
		break;
	}
	case Game::Playing:
	{
		_mainWindow.clear(sf::Color(0, 0, 0));

		//If the main window is closed, stop the game
		if (event.type == sf::Event::Closed)
		{
			_gameState = Game::Exiting;
		}

		//Particular cases of pressed keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			ShowMenu();
		}

		//Map management
		//TODO

		Map carte;
		carte.create("map.png");
		_mainWindow.draw(carte.sprite_map);


		_gameObjectManager.UpdateAll();
		_gameObjectManager.DrawAll(_mainWindow);

		_mainWindow.display();

		break;
	}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Exiting;
		break;
	case MainMenu::Play:
		_gameState = Playing;
		break;
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
