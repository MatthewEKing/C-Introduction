#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	// Print welcome messages to the terminal
	std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
	std::cout << "secure server room...\nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	// Declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;


	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print sum and product to terminal
	std::cout << std::endl;
	std::cout << "- There are 3 numbers in the code";
	std::cout << "\n- The codes add up to " << CodeSum;
	std::cout << "\n- The codes multiply to give " << CodeProduct << std:endl;

	// Store Player Guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if Player Guess Is Correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\nOnto The Next Level!";
		return true;
	}
	else
	{
		std::cout << "\nWrong Code, Try Again!";
		return false;
	}
}

int main()
{
	srand(time(NULL));

	int LevelDifficulty = 1;
	const int MaxDifficulty = 10;

	while (LevelDifficulty <= MaxDifficulty) // Loop game while all levels are completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << "\nCongratulations for completing the game!";
	return 0;
} 