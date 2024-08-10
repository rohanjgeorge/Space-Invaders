#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphic/GraphicService.h"
#include <iostream>

namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;

	GameplayView::GameplayView() { }

	GameplayView::~GameplayView() { }

	void GameplayView::initialize() {	
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializeBackgroundSprite();
	}

	void GameplayView::update() { }

	void GameplayView::render() { 
		game_window->draw(background_sprite); }

	void GameplayView::initializeBackgroundSprite()
	{
		if (background_texture.loadFromFile(background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			scaleBackgroundSprite();
		}
	}

	void GameplayView::scaleBackgroundSprite()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}
}