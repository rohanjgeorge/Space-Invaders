#pragma once
#include "../../header/Powerups/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class ShieldController : public PowerupController
        {
        public:
            ShieldController(PowerupType type);
            virtual ~ShieldController();

            void onCollected() override;
        };
    }
}