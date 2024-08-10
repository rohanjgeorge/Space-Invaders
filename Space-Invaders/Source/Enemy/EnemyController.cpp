#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		std::cout << "inside enemy controller'";
		enemy_model->initialize();
		enemy_view->initialize(this); // we will discuss this soon
	}

	void EnemyController::update()
	{
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}