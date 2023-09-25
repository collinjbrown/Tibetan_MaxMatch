#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <sstream>

std::wstringstream ReadFile(std::string path);

void WriteFile(std::string path, std::wstring data);

#endif