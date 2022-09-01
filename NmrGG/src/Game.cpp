#include "Game.h"
#include <random>
#include <iostream>

Game::Game(int nmrGuesses, int nmrNmr) {
	guesses = nmrGuesses;
	nmr = nmrNmr;
}

void Game::Run(){
	std::srand(time(0));
	std::cout << std::rand() % nmr << "\n";
}

void Game::ConsoleSetup() {

}