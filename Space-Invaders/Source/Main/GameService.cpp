#include"../../Header/Main/GameService.h"
#include"../../Header/Graphic/GraphicService.h"
#include"../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>

namespace Main {

	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;

	void GameService::initialize()
	{
		service_locator->initialize();
		std::cout << "Service locator initialized";
		initializeVariables();
		showSplashScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::destroy()
	{
		//cleanup resources
	}

	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::ignite()
	{
		service_locator = Global::ServiceLocator::getInstance();
		std::cout << "before initialize";
		initialize();
	}

	void GameService::update()
	{
		//Process Events
		service_locator->getEventService()->processEvents();

		//Update Game Logic
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear();
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	void GameService::setGameState(GameState new_state) { current_state = new_state; }

	GameState GameService::getGameState() { return current_state; }

	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::getInstance()->getUIService()->showScreen();
	}
}