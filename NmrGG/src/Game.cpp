#include "Game.h"
#include <random>
#include <iostream>
#include <string>


Game::Game() {
	std::cout << "How many guesses do you want: ";
	std::cin >> guesses;
	uGuesses = guesses;
	std::cout << "The hidden number shall be between 0 and: ";
	std::cin >> nmr;
}

void Game::Run(){
	int hiddenNmr = GameReset();
	int userGuess = 0;
	std::string playAgain = "";

	while (uGuesses > 0){
		std::cout << hiddenNmr << "\n";
		std::cout << "Your guess: ";
		std::cin >> userGuess;

		if (userGuess == hiddenNmr) {
			wins++;
			std::cout << "Play again? y/n: ";
			std::cin >> playAgain;
			if (playAgain == "y") {
				hiddenNmr = GameReset();
			}
			else
			{
				exit(0);
			}
			
		}
		else if (userGuess < hiddenNmr) {
			ConsoleSetup();
			std::cout << "Higher than that!\n";
			uGuesses -= 1;
		}
		else if (userGuess > hiddenNmr) {
			ConsoleSetup();
			std::cout << "Lower than that!\n";
			uGuesses -= 1;
		}
	}


}

void Game::ConsoleSetup() {
	std::cout << "\x1B[2J\x1B[H";
	std::cout << "Guesses left: " << uGuesses << "\n" << "Rounds won: " << wins << "\n";
}
int Game::GameReset() {
	std::srand(time(0));
	int hiddenNmr = std::rand() % nmr;
	uGuesses = guesses;
	ConsoleSetup();

	return hiddenNmr;
}