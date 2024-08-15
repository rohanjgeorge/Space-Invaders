#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            float vertical_travel_distance = 120.f;
            float vertical_movement_speed = 100.f;

            void move() override;
            void moveLeft();
            void moveRight();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
            void fireBullet() override;
        };
    }
}