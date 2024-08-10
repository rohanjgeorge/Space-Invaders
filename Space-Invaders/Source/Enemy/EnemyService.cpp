#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include <iostream>

namespace Enemy
{
	using namespace Global;
	using namespace Time;


	EnemyService::EnemyService() {}

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		//Spawn Enemy
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTime();
		processEnemySpawn();
		for (int i = 0; i < enemy_list.size(); i++) {
			enemy_list[i]->update();
		}
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
	}

	void EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = new EnemyController();
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);
	}

	void EnemyService::updateSpawnTime()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); // increase timer
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy(); //spawn 
			spawn_timer = 0.0f; // reset
		}
	}
	void EnemyService::destroy()
	{
		//deallocate memory 
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]); //delete all enemies
	}
	
}