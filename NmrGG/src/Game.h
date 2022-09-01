#pragma once


class Game {
public:
	Game();

	void ConsoleSetup();
	void Run();
	int GameReset();

private:
	int guesses = 0;
	int wins = 0;
	int nmr = 0;
	int uGuesses = 0;
};
