#include "Game.h"
#include <random>
#include <iostream>

Game::Game() {
	std::cout << "How many guesses do you want: ";
	std::cin >> guesses;
	std::cout << "The hidden number shall be between 0 and: ";
	std::cin >> nmr;
}

void Game::Run(){
	std::srand(time(0));
	int hiddenNmr = std::rand() % nmr;

}

void Game::ConsoleSetup() {

}