#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include <iostream>

namespace Global {

	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		createServices();
	}


	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();

		time_service = new TimeService();

		event_service = new EventService();

		player_service = new PlayerService();

		ui_service = new UIService();

		enemy_service = new EnemyService();

	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete (time_service);
		delete(event_service);
		delete(player_service);
		delete(ui_service);
		delete(enemy_service);

	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		event_service->initialize();
		player_service->initialize();
		ui_service->initialize();
		enemy_service->initialize();

	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY) {
			player_service->update();
			enemy_service->update();
		}
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			player_service->render();
			enemy_service->render();
		}
		ui_service->render();
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	TimeService* ServiceLocator::getTimeService() { return time_service; }

	UIService* ServiceLocator::getUIServiec() { return ui_service; }
}