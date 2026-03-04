#pragma once
#ifndef METHODS_H
#define METHODS_H

#include <string>

std::string trimLeadingZeros(std::string str);
std::string decToBinary(int number);
std::string binaryTohexadecimal(std::string number);
std::string hexToBinary(std::string number);
int binaryToDec(std::string number);
int fromHexConversion(char c);
std::string hexConversion(int num);


#endif