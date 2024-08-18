#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"
#include "../../header/UI/UIElement/TextView.h"
#include <iostream>

namespace UI
{
	using namespace Main;
	using namespace MainMenu;

	using namespace GameplayUI;

	using namespace UIElement;
	using namespace Interface;
	using namespace SplashScreen;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
		splash_screen_ui_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
		delete(main_menu_controller);
		delete(gameplay_ui_controller);
		delete(splash_screen_ui_controller);

	}
}