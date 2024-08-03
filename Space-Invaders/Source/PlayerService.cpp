#include "../Header/PlayerService.h"
#include "../Header/Player/PlayerController.h"

PlayerService::PlayerService()
{
	player_controller = new PlayerController();
}

PlayerService::~PlayerService()
{
	delete (player_controller);
}

void PlayerService::initialize()
{
	player_controller->initialize();
}

void PlayerService::update()
{
	player_controller->update();
}

void PlayerService::render()
{
	player_controller->render();
}
