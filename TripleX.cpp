#include <iostream>

void PrintIntroduction()
{
	// Print welcome messages to the terminal
	std::cout << "\n\nYou are a secret agent breaking into a secure server room...\n";
	std::cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame()
{
	PrintIntroduction();

	// Declare 3 number code
	const int CodeA = 4;
	const int CodeB = 3;
	const int CodeC = 9;


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
		std::cout << "\nYou Win!";
		return true;
	}
	else
	{
		std::cout << "\nWrong Code";
		return false;
	}
}

int main()
{
	while (true)
	{
		bool bLevelComplete = PlayGame();
		std::cin.clear();
		std::cin.ignore();
	}
	return 0;
} 