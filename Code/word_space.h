#ifndef WORD_SPACE_H
#define WORD_SPACE_H

#include <vector>
#include <string>
#include <string_view>


namespace Words
{
    inline const std::vector<std::string_view>& List{ "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

    std::string_view getRandomWord();
}


#endif










#ifndef WORD_SPACE_SETTINGS_H
#define WORD_SPACE_SETTINGS_H


namespace Settings
{
    constexpr int wrongGuessesAllowed{ 6 };
    constexpr int defaultRounds{ 13 };
}

#endif