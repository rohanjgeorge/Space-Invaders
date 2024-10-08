#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;
            float subzero_rate_of_fire = 2.f;

            void move() override;
            void moveDown();

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void initialize() override;
            void fireBullet() override;
        };
    }
}