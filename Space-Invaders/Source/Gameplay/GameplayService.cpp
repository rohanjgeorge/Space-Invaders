#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"
#include <iostream>

namespace Gameplay
{
	GameplayService::GameplayService() { gameplay_controller = new GameplayController(); }

	GameplayService::~GameplayService() { delete (gameplay_controller); }

	void GameplayService::initialize() { gameplay_controller->initialize(); }

	void GameplayService::update() { gameplay_controller->update(); }

	void GameplayService::render() { 
		gameplay_controller->render(); }
}