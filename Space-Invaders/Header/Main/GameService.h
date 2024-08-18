#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main {

	enum class GameState
	{
		BOOT,
		SPLASH_SCREEN,
		MAIN_MENU,
		INSTRUCTIONS,
		GAMEPLAY,
		CREDITS,
	};

	class GameService
	{
	private:

		static GameState current_state;
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();		// Handles game initialization.
		void initializeVariables();
		void showSplashScreen();
		void destroy();			// Handles cleanup tasks.

	public:
		GameService();			// Constructor for initializing the GameService object.
		~GameService();	    // Destructor for cleaning up resources upon object deletion.

		void ignite();			// Initiates the game.
		void update();			// Updates the game logic and game state.
		void render();			// Renders each frame of the game.
		bool isRunning();		// Checks if the game is currently running.
		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}