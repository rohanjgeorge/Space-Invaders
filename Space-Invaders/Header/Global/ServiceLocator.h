#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Element/ElementService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../header/Bullet/BulletService.h"
#include "../../Header/Powerups/PowerupService.h"
#include "../../Header/Collision/CollisionService.h"
#include "../../Header/AnimationSystem/AnimationService.h"


// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

namespace Global {
    
    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphic_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;
        UI::UIService* ui_service;
        Enemy::EnemyService* enemy_service;
        Gameplay::GameplayService* gameplay_service;
        Element::ElementService* element_service;
        Sound::SoundService* sound_service;
        Bullet::BulletService* bullet_service;
        Powerup::PowerupService* powerup_Service;
        Collision::CollisionService* collision_service;
        Animation::AnimationService* animation_service;
        
        // Private Constructor and Destructor:

        // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void createServices(); 			// Creates instances of all services.
        void clearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

        void initialize(); 			//	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Graphic::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        UI::UIService* getUIService();
        Enemy::EnemyService* getEnemyService();
        Gameplay::GameplayService* getGameplayService();
        Element::ElementService* getElementService();
        Sound::SoundService* getSoundService();
        Bullet::BulletService* getBulletService();
        Powerup::PowerupService* getPowerupService();
        Collision::CollisionService* getCollisionService();
        Animation::AnimationService* getAnimationService();
    };
}
