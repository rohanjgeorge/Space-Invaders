#include "../../header/Powerups/Controllers/TripleLaserController.h"

namespace Powerup
{
    namespace Controller
    {
        TripleLaserController::TripleLaserController(PowerupType type) : PowerupController(type) {}

        TripleLaserController::~TripleLaserController() {}

        void TripleLaserController::onCollected() {};
    }
}