#pragma once
#include "../../header/Projectile/IProjectile.h"
#include "../../header/Entity/EntityConfig.h"
#include "../Collision/ICollider.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;


    enum class BulletType;


    class BulletController : public Projectile::IProjectile, public Collision::ICollider
    {
    protected:
        BulletView* bullet_view;
        BulletModel* bullet_model;

        void updateProjectilePosition() override;

        void processBulletCollision(ICollider* other_collider);
        void processEnemyCollision(ICollider* other_collider);
        void processPlayerCollision(ICollider* other_collider);
        void processBunkerCollision(ICollider* other_collider);

        void moveUp();
        void moveDown();
        void handleOutOfBounds();

    public:
        BulletController(BulletType bullet_type, Entity::EntityType owner_type);
        virtual ~BulletController();

        void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
        void update() override;
        void render() override;

        sf::Vector2f getProjectilePosition() override;
        BulletType getBulletType();
        Entity::EntityType getOwnerEntityType();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}