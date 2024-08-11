#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../header/Element/Bunker/BunkerController.h"
#include "../../header/Element/Bunker/BunkerModel.h"

namespace Element
{
	class BunkerController;

	class ElementService
	{
	private:
		//const vector so that the default values will not be changed down the road by mistake.
		const std::vector<Bunker::BunkerData> bunker_data_list = { Bunker::BunkerData(sf::Vector2f(130.f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(430.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f)) };

		std::vector<Bunker::BunkerController*> bunker_list;

		void destroy();

	public:
		ElementService();
		virtual ~ElementService();

		void initialize();
		void update();
		void render();
	};
}