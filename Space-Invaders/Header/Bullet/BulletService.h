#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../header/Entity/EntityConfig.h"
#include "../../Header/Projectile/IProjectile.h"


namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> bullet_list;

		BulletController* createBullet(BulletType bullet_type, Entity::EntityType owner_type);
		void destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();

		BulletController* spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, Entity::EntityType owner_type);
		void destroyBullet(BulletController* bullet_controller);
	};
}