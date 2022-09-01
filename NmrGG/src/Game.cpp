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
	int userGuess;

	while (guesses > 0){
		ConsoleSetup();
		std::cout << "Your guess: ";
		std::cin >> userGuess;

		std::cin.get();
	}

}

void Game::ConsoleSetup() {
	std::cout << "\x1B[2J\x1B[H";
	std::cout << "Guesses left: " << guesses << "\n" << "Rounds won: " << wins << "\n";
}