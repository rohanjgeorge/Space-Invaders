#include "../../header/Bullet/BulletConfig.h"

namespace Bullet
{
	const sf::String BulletConfig::laser_bullet_texture_path = "assets/textures/laser_bullet.png";

	const sf::String BulletConfig::torpedo_texture_path = "assets/textures/torpedoe.png";

	const sf::String BulletConfig::frost_bullet_texture_path = "assets/textures/frost_beam.png";

	sf::String BulletConfig::getBulletTexturePath(BulletType bullet_type)
	{
		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return laser_bullet_texture_path;

		case::Bullet::BulletType::FROST_BULLET:
			return frost_bullet_texture_path;

		case::Bullet::BulletType::TORPEDO:
			return torpedo_texture_path;
		}
	}
}