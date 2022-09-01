#include "Game.h"
#include <random>
#include <iostream>
#include <string>


Game::Game() {
	std::cout << "Welcome to Number Guessing Game! In this game you guess numbers no way! First you input how many guesses you want, then between which numbers the hidden number shall be and the you guess away! Have fun!\n";
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

	while (true){
		std::cout << "Your guess: ";
		std::cin >> userGuess;

		if (userGuess == hiddenNmr) {
			wins++;
			std::cout << "\x1B[2J\x1B[H";
			std::cout << "YOU WON!!!\n";
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
			uGuesses -= 1;
			ConsoleSetup();
			std::cout << "Higher than that!\n";
		}
		else if (userGuess > hiddenNmr) {
			uGuesses -= 1;
			ConsoleSetup();
			std::cout << "Lower than that!\n";
		}
		if (uGuesses == 0) {
			std::cout << "\x1B[2J\x1B[H";
			std::cout << "You lost :(\n" << "The correct number was: " << hiddenNmr << "\nPlay again? y/n: ";
			std::cin >> playAgain;
			if (playAgain == "y") {
				hiddenNmr = GameReset();
			}
			else
			{
				break;
			}
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