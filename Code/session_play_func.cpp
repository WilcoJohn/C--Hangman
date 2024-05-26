#include <iostream>
#include <vector>
#include "session_class.h"
#include "session_play_func.h"






char getUserGuess(Session& s)
{
	char letter{};

	while (true)
	{
		std::cout << "Enter your next letter guess: ";
		std::cin >> letter;

		// Fix failed input
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That wasn't a valid input. Try again.\n";
			continue;
		}

		// Clear out any extraneous input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (letter < 'a' || letter > 'z')
		{
			std::cout << "That wasn't a valid input. Try again.\n";
			continue;
		}

		// check for repeated guesses
		if (s.checkRepeatGuess(letter))
		{
			std::cout << "You have already guessed that. Try again.\n";
			continue;
		}

		return letter;
	}
}


void printState(const Session& s)
{
	for (std::size_t idx{0}; idx < s.m_randWord.size(); ++idx)
	{
		if (s.m_rightGeusses[idx]) std::cout << s.m_randWord[idx];
		else std::cout << '_';
	}

	std::cout << '\t';

	for (int idx{ 0 }; idx < s.m_wrongGuessesLeft; ++idx) std::cout << "+";
	for ([[maybe_unused]]const auto& val : s.m_wrongGuesses) std::cout << val;

	std::cout << '\t';
	std::cout << "rounds : " << s.m_rounds;

	std::cout << '\n';
}




bool playAgain()
{
	char letter{};

	while (true)
	{
	std::cout << "Do you want to play again (Y/N)?";
	
	std::cin >> letter;
		// Fix failed input
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That wasn't a valid input. Try again.\n";
			continue;
		}

		// Clear out any extraneous input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (letter)
		{
		case 'y':
		case 'Y':
			return true;
		case 'n':
		case 'N':
			return false;

		default:
			std::cout << "Invalid input\n";
			continue;
		}
	}

}



void playHangman()
{
	std::cout << "Welcome to C++man (a variant of Hangman)\n";
	std::cout << "To win: guess the word.  To lose: run out of pluses.\n";


	while (true)
	{
	Session s{};
	int rounds{ s.getRoundsLeft() };

	while (s.getRoundsLeft())
	{
		printState(s);
		char c{ getUserGuess(s) };
		s.updateState(c);

		if (s.checkVictory())
		{
			printState(s);
			std::cout << "\nCongratulations you won!\n";
			break;
		}

		if (s.getWrongGuessesLeft() == 0) break;

		s.updateRounds(--rounds);
	}

	if (!s.checkVictory())
	{
		printState(s);
		std::cout << "Too bad. The word was " << s.getWord() << '\n';
	}
	std::cout << '\n';
	bool play(playAgain());

	if (play)
	{
		std::cout << "\n\n";
		continue;
	}
	else
		break;

	}

	std::cout << "\nThank you for playing.\n";
}