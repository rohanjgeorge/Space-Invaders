#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../header/Entity/EntityConfig.h"


namespace Bullet
{
    class BulletView;
    class BulletModel;
    enum class BulletType;

    class BulletController : public Projectile::IProjectile {

    protected:
        BulletView* bullet_view;
        BulletModel* bullet_model;

        void updateProjectilePosition() override;

        void moveUp();
        void moveDown();
        void handleOutOfBounds();

    public:
        BulletController(BulletType type, Entity::EntityType owner_type);
        virtual ~BulletController() override;
        void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
        void update() override;
        void render() override;

        sf::Vector2f getProjectilePosition() override;
        BulletType getBulletType();
        Entity::EntityType getOwnerEntityType();

    };
}