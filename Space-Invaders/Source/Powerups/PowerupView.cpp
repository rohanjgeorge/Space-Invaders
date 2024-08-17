#include "../../header/Powerups/PowerupView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Powerups/PowerupController.h"
#include "../../header/Powerups/PowerupConfig.h"


namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView() { createUIElements(); }

	PowerupView::~PowerupView() { destroy(); }

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		initializeImage();
	}

	void PowerupView::createUIElements()
	{
		powerup_image = new ImageView();
	}

	void PowerupView::initializeImage()
	{
		powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition());
	}

	void PowerupView::update()
	{
		powerup_image->setPosition(powerup_controller->getCollectiblePosition());
		powerup_image->update();
	}

	void PowerupView::render()
	{
		powerup_image->render();
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->getPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shield_texture_path;

		case::Powerup::PowerupType::TRIPLE_LASER:
			return Config::tripple_laser_texture_path;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}

	const sf::Sprite& PowerupView::getPowerupSprite()
	{
		return powerup_image->getSprite();
	}

	void PowerupView::destroy()
	{
		delete(powerup_image);
	}
}