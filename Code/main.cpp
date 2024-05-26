#include <iostream>
#include <string>
#include <string_view>

#include "session_class.h"
#include "session_play_func.h"
#include "word_space.h"

void testHangman()
{
    std::string_view testWord{ Words::getRandomWord() };
    std::cout << "Got random word '" << testWord << "'\n";
    
    Session s{ testWord };
    
    printState(s);

    char c{ getUserGuess(s) };
    s.updateState(c);
    printState(s);
}



int main()
{
    //testHangman();

    playHangman();

    return 0;
}

