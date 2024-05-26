
#include <string>
#include "word_space.h"
#include "rand_h.h"







std::string_view Words::getRandomWord()
{
	return Words::List[Random::get<std::size_t>(0, Words::List.size() - 1)];
}