#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
    using namespace Global;
    using namespace Bullet;

    namespace Controller
    {
        ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type) { }

        ThunderSnakeController::~ThunderSnakeController() { }

        void ThunderSnakeController::initialize()
        {
            EnemyController::initialize();
        }

        void ThunderSnakeController::move()
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
        void ThunderSnakeController::moveLeft()
        {

            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move left
            currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                // Set movement direction to DOWN and update reference position
                enemy_model->setMovementDirection(MovementDirection::RIGHT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemy_model->setEnemyPosition(currentPosition);
                enemy_model->setMovementDirection(MovementDirection::LEFT);
            }
        }
        void ThunderSnakeController::moveRight()
        {

            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            // Update the position to move right
            currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
            currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                // Set movement direction to DOWN and update reference position
                enemy_model->setMovementDirection(MovementDirection::LEFT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemy_model->setEnemyPosition(currentPosition);
                enemy_model->setMovementDirection(MovementDirection::RIGHT);
            }
        }

        void ThunderSnakeController::fireBullet()
        {
            // we spawn the bullet and pass the needed parameters
            ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::TORPEDO,
                enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                Bullet::MovementDirection::DOWN);
        }
    }
}