#include"../Header/GameService.h"
#include"../Header/GraphicService.h"
#include <iostream>;

void GameService::initialize()
{
	initializeVariables();
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
std::cout << "I was here";
}

GameService::~GameService()
{
	destroy();
}

void GameService::ignite()
{
	service_locator = ServiceLocator::getInstance();
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
	game_window->clear(service_locator->getGraphicService()->getWindowColor());
	service_locator->render();
	game_window->display();
}

bool GameService::isRunning()
{
	return service_locator->getGraphicService()->isGameWindowOpen();
}