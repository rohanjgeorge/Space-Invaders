#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;
    enum class EnemyType;

    class EnemyController
    {
    protected:

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0;
        void moveLeft();
        void moveRight();
        void moveDown();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
    };
}