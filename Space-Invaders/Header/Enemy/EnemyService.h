#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:

		const float spawn_interval = 3.f;

		std::vector <EnemyController*> enemy_list;
		float spawn_timer;

		void updateSpawnTime();
		void processEnemySpawn();
		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy();
	};
}