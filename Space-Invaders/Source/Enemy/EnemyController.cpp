#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletConfig.h"
#include <iostream>

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		move();
		updateFireTimer();
		processBulletFire();
		enemy_view->update();
		handleOutOfBounds();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	/*void EnemyController::move()
	{
		switch (enemy_model->getMovementDirection())
		{
		case Enemy::MovementDirection::LEFT:
			moveLeft();
			break;

		case Enemy::MovementDirection::RIGHT:
			moveRight();
			break;

		case Enemy::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}*/
		/*void EnemyController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else {
				enemy_model->setEnemyPosition(currentPosition);
			}
		}*/

		//void EnemyController::moveLeft()
		//{
		//	// Get current pos
		//	// Move left by multiplying by speed and delta time
		//	sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		//	currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		//	//check for bounds
		//	if (currentPosition.x <= enemy_model->left_most_position.x)
		//	{
		//		//if reached the left most pos
		//		//start moving down
		//		//set ref pos for the downwards movement
		//		enemy_model->setMovementDirection(MovementDirection::DOWN);
		//		enemy_model->setReferencePosition(currentPosition);
		//	}
		//	else enemy_model->setEnemyPosition(currentPosition);
		//}

		//void EnemyController::moveDown()
		//{
		//	sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		//	currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		//	//check if enemy has moved the specified distance downwards
		//	if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance)
		//	{
		//		//check where to move them based on position
		//		if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x) enemy_model->setMovementDirection(MovementDirection::RIGHT);
		//		else enemy_model->setMovementDirection(MovementDirection::LEFT);
		//	}
		//	else enemy_model->setEnemyPosition(currentPosition);
		//}

		sf::Vector2f EnemyController::getRandomInitialPosition()
		{
			// Calculate the distance between the leftmost and rightmost positions of the enemy.
			float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

			// Calculate the x position by adding the x offset distance to the leftmost position.
			float x_position = enemy_model->left_most_position.x + x_offset_distance;

			// The y position remains the same.
			float y_position = enemy_model->left_most_position.y;

			// Return the calculated position as a 2D vector.
			return sf::Vector2f(x_position, y_position);
		}

		void EnemyController::handleOutOfBounds()
		{
			sf::Vector2f enemyPosition = getEnemyPosition();
			sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

			// Destroy the enemy if it goes out of bounds.
			if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
				enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
			{
				ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
			}
		}

		void EnemyController::updateFireTimer()
		{
			elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); //update the elapsed duration
		}

		void EnemyController::processBulletFire() //if elapsed duration is equal to or more than the amount of time we want to wait until firing than call the fire method.
		{
			if (elapsed_fire_duration >= rate_of_fire)
			{
				fireBullet();
				elapsed_fire_duration = 0.f; //set elapsed duration back to 0.
			}
		}
	
}