#ifndef MAXMATCH_H
#define MAXMATCH_H

#include <vector>
#include <string>

#include "dictionary.h"

/*------------------------------------------*/
/* MaxMatch Algorithms                      */
/*------------------------------------------*/
/*
	MaxMatch goes through and hopefully
	finds the word-boundaries in the
	sentence it is handed.
*/
std::vector<std::wstring> Tokenize(std::wstring sentence, Dictionary* dictionary);

#endif