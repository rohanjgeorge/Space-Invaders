#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include <iostream>

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;


	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

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

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);
		return enemy_controller;
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

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::THUNDER_SNAKE:
				return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);

		case::Enemy::EnemyType::UFO:
				return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 4;  //since we only have 2 enemies right now
		return static_cast<Enemy::EnemyType>(randomType); //cast int to EnemyType enum class
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		// Erase the enemy_controller object from the enemy_list vector.
		// std::remove rearranges the elements in the vector so that all elements 
		// that are equal to enemy_controller are moved to the end of the vector,
		// then it returns an iterator pointing to the start of the removed elements.
		// The erase function then removes those elements from the vector.
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());

		// Delete the enemy_controller object from memory to free up resources.
		delete(enemy_controller);
	}
	
}