#include "../../header/Powerups/Controllers/RapidFireController.h"

namespace Powerup
{
    namespace Controller
    {
        RapidFireController::RapidFireController(PowerupType type) : PowerupController(type) {}

        RapidFireController::~RapidFireController() {}

        void RapidFireController::onCollected() {};
    }
}