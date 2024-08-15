#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy {


	using namespace Global;
	using namespace Bullet;

	namespace Controller {

		UFOController::UFOController(EnemyType type) : EnemyController(type) {}
		
		Enemy::Controller::UFOController::~UFOController()
		{
		}

		void Enemy::Controller::UFOController::initialize()
		{
			EnemyController::initialize();
		}

		void Enemy::Controller::UFOController::move()
		{
			// Switch statement based on the movement direction of the enemy
			switch (enemy_model->getMovementDirection())
			{
				// If the movement direction is LEFT
			case Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

				// If the movement direction is RIGHT
			case Enemy::MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}

		void Enemy::Controller::UFOController::moveLeft()
		{

			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			// Update the position to move left
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			enemy_model->setEnemyPosition(currentPosition);
		}

		void Enemy::Controller::UFOController::moveRight()
		{
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			// Update the position to move right
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			enemy_model->setEnemyPosition(currentPosition);
		}

		void Enemy::Controller::UFOController::fireBullet()
		{
		}

		Powerup::PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			//We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}



		
	}
}