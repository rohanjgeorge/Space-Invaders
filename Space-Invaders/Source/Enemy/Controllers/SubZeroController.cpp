#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) { }

		SubzeroController::~SubzeroController() { }

		void SubzeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			rate_of_fire = subzero_rate_of_fire;
		}

		void SubzeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubzeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}

		void SubzeroController::fireBullet()
		{
			// we spawn the bullet and pass the needed parameters
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BULLET,
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}
	}


}