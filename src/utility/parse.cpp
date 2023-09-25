#include "parse.h"

#include <iostream>

#include "filehandling.h"

void Parse(std::wstring input, Dictionary* dictionary)
{
	std::wstring word = L"";
	std::wstring sentence = L"";

	/*
		While there is still text to iterate over.
	*/
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == L'\n')
		{
			// If we've hit the end of a sentence
			// we pass it to the dictionary.
			dictionary->AddSentence(sentence);
			sentence.clear();
			continue;
		}
		else if (input[i] == L' ')
		{
			// If we've hit the end of a word, we
			// do the same.
			dictionary->AddWord(word);
			word.clear();

			sentence += input[i];

			continue;
		}
		
		sentence += input[i];
		word += input[i];
	}
}