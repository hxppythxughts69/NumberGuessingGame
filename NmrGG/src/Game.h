#pragma once


class Game {
public:
	Game(int nmrGuesses, int nmrNmr);

	void ConsoleSetup();
	void Run();

private:
	int guesses = 0;
	int wins = 0;
	int nmr = 0;
};
