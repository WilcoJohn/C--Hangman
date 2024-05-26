#ifndef SESSION_CLS_H
#define SESSION_CLS_H

#include <vector>
#include <string>
#include <string_view>

#include "word_space.h"


class Session
{
private:
    std::string_view m_randWord{ Words::getRandomWord() };
    std::vector<char> m_userGuesses{};
    int m_rounds{ Settings::defaultRounds };
    int m_wrongGuessesLeft{Settings::wrongGuessesAllowed};
    std::vector<bool> m_rightGeusses{};
    std::vector<char> m_wrongGuesses{};


public:
    Session(std::string_view word = Words::getRandomWord(), 
            int rounds = Settings::defaultRounds, 
            int wrongGuesses = Settings::wrongGuessesAllowed);




    // Getters
    std::string_view getWord() const { return m_randWord; }
    int getWrongGuessesLeft() const { return m_wrongGuessesLeft; }
    int getRoundsLeft() const { return m_rounds; }
    
    // setters
    void updateRounds(int val) { m_rounds = val; }


    // forwards declerations of "heavy" functions
    bool checkRepeatGuess(char c);
    void updateState(char c);
    bool checkVictory() const;


    // friend non-member function
    friend void printState(const Session& s);
};



#endif