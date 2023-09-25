#include "maxmatch.h"
#include <iostream>

std::vector<std::wstring> Tokenize(std::wstring sentence, Dictionary* dictionary)
{
	/*
		We're going to go through the whole sentence, character by
		character, and segment it into probable words.
	*/

	std::vector<std::wstring> words;

	unsigned int longest = dictionary->GetLongestLength();
	unsigned int iter = 0;

	while (iter < sentence.size())
	{
		/*
			Let's set up our probable word.
			We start with the longest possible and work
			backwards.
		*/
		unsigned int length = (iter + longest < sentence.size()) ? longest : sentence.size() - iter;
		std::wstring probableWord = L"";

		while (length > 0)
		{
			probableWord = sentence.substr(iter, length);
			unsigned int freq = dictionary->GetFrequency(probableWord);
			
			/*
				If we have exhausted our potential words
				and not found any valid ones, we'll just break
				with one invalid character.

				We'll do the same if we've found a valid word.
			*/
			if (length == 1 && freq == 0)
			{
				probableWord = L"␕";
			}
			else if (freq != 0)
			{
				break;
			}

			/*
				If this isn't a valid word, let us try a
				slightly shorter word.
			*/
			length--;
		}

		/*
			If we can't get a valid word, we just skip it.
		*/
		if (probableWord == L"␕")
		{
			iter += 1;
			continue;
		}

		/*
			Now, we add the size of our probable word to the
			iterator and throw the word in our vector and
			call it a day.
		*/

		words.push_back(probableWord);
		iter += probableWord.size();
	}

	return words;
}