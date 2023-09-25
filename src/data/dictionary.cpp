#include "dictionary.h"
#include <iostream>

/*------------------------------------------*/
/* Good Ol' Diccionario                     */
/*------------------------------------------*/
/*--------------------------------*/
/* General Functions              */
/*--------------------------------*/
void Dictionary::AddWord(std::wstring word)
{
	if (frequencyMap.find(word) != frequencyMap.end())
	{
		frequencyMap[word]++;
		return;
	}

	size++;
	frequencyMap.emplace(word, 1);

	if (word.size() > longestWord) longestWord = word.size();
}

unsigned int Dictionary::GetFrequency(std::wstring word)
{
	if (frequencyMap.find(word) != frequencyMap.end())
	{
		return frequencyMap[word];
	}

	return 0;
}

void Dictionary::AddSentence(std::wstring sentence)
{
	sentences.push_back(sentence);
}

std::wstring Dictionary::GetSentence(unsigned int index)
{
	if (index >= sentences.size()) return L"";
	return sentences[index];
}

unsigned int Dictionary::GetSentenceCount()
{
	return sentences.size();
}