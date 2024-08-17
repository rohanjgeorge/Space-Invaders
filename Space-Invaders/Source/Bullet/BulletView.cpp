#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView() { createUIElements(); }

	BulletView::~BulletView() { destroy(); }

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		initializeImage();
	}

	void BulletView::createUIElements()
	{
		bullet_image = new ImageView();
	}

	void BulletView::initializeImage()
	{
		bullet_image->initialize(getBulletTexturePath(), bullet_sprite_width, bullet_sprite_height, bullet_controller->getProjectilePosition());
	}

	void BulletView::update()
	{
		bullet_image->setPosition(bullet_controller->getProjectilePosition());
		bullet_image->update();
	}

	void BulletView::render()
	{
		bullet_image->render();
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return BulletConfig::laser_bullet_texture_path;

		case::Bullet::BulletType::FROST_BULLET:
			return BulletConfig::frost_bullet_texture_path;

		case::Bullet::BulletType::TORPEDO:
			return BulletConfig::torpedo_texture_path;
		}
	}

	const sf::Sprite& BulletView::getBulletSprite()
	{
		return bullet_image->getSprite();
	}

	void BulletView::destroy()
	{
		delete (bullet_image);
	}
}