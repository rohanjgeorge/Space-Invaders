#include "../../header/Bullet/BulletService.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Bullet/Controllers/FrostBulletController.h"
#include "../../header/Bullet/Controllers/LaserBulletController.h"
#include "../../header/Bullet/Controllers/TorpedoController.h"
#include "../../header/Collision/ICollider.h"
#include "../../header/Global/ServiceLocator.h"
#include <iostream>

namespace Bullet
{
	using namespace Controller;
	using namespace Entity;
	using namespace Global;
	using namespace Collision;

	BulletService::BulletService() { }

	BulletService::~BulletService() { destroy(); }

	void BulletService::initialize()
	{
		bullet_list.clear();
		flagged_bullet_list.clear();
	}

	void BulletService::update()
	{
		for (Projectile::IProjectile* bullet : bullet_list)
			bullet->update();

		destroyFlaggedBullets();
	}

	void BulletService::render()
	{
		for (Projectile::IProjectile* bullet : bullet_list)
			bullet->render();
	}

	BulletController* BulletService::createBullet(BulletType bullet_type, EntityType owner_type)
	{
		std::cout<<"created bullet/";

		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			std::cout << "created bullet 1/";
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, owner_type);

		case::Bullet::BulletType::FROST_BULLET:
			std::cout << "created bullet 2/";
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, owner_type);

		case::Bullet::BulletType::TORPEDO:
			std::cout << "created bullet 3/";
			return new TorpedoController(Bullet::BulletType::TORPEDO, owner_type);

		default:
			return nullptr;
		}
	}

	bool BulletService::isValidBullet(int index, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		return index >= 0 && index < bullet_list.size() && bullet_list[index] != nullptr;
	}

	void BulletService::destroyFlaggedBullets()
	{
		for (int i = 0; i < flagged_bullet_list.size(); i++)
		{
			if (!isValidBullet(i, flagged_bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bullet_list[i]));
			delete (flagged_bullet_list[i]);
		}
		flagged_bullet_list.clear();
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			if (!isValidBullet(i, bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_list[i]));
			delete (bullet_list[i]);
		}
		bullet_list.clear();
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, EntityType owner_type)
	{
		BulletController* bullet_controller = createBullet(bullet_type, owner_type);
		bullet_controller->initialize(position, direction);
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bullet_controller));
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		dynamic_cast<ICollider*>(bullet_controller)->disableCollision();
		flagged_bullet_list.push_back(bullet_controller);
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
	}

	void BulletService::reset() { destroy(); }
}