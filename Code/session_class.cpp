#include <vector>
#include <string_view>

#include "session_class.h"
#include "word_space.h"



Session::Session(std::string_view word, int rounds, int wrongGuesses)
	: m_randWord{ word }
	, m_userGuesses{}
	, m_rounds{rounds}
	, m_wrongGuessesLeft{wrongGuesses}
	, m_rightGeusses(word.size())			// note parenthesis initilasation, to indicate size of bool vector that is false
	, m_wrongGuesses{}
{}







bool Session::checkRepeatGuess(char c)
{
	for ([[maybe_unused]] const auto& val : m_userGuesses)
	{
		if (val == c) return true;
	}
	return false;
}


void Session::updateState(char c)
{
	bool isWrongGuess{ true };

	m_userGuesses.emplace_back(c);

	for (std::size_t idx{0}; idx < m_randWord.size(); ++idx)
	{
		if (c == m_randWord[idx])
		{
			m_rightGeusses[idx] = true;
			isWrongGuess = false;
		}
	}

	if (isWrongGuess)
	{
		m_wrongGuesses.emplace_back(c);
		--m_wrongGuessesLeft;
	}
}

bool Session::checkVictory() const
{
	for (const auto& val : m_rightGeusses)
		if (val == false) return false;

	if (m_wrongGuessesLeft == 0) return false;

	return true;
}