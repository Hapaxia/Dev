//////////////////////////////////////////////////////////////////////////////
//
// Dev
//
// Copyright(c) 2014-2015 M.J.Silk
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions :
//
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software.If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
// M.J.Silk
// MJSilk2@gmail.com
//
//////////////////////////////////////////////////////////////////////////////

#include "ConsoleOutput.hpp"
#include <iostream>

namespace DEV
{

void pressEnterToContinue(const std::string& message)
{
	std::cin.clear();
	std::cin.sync();
	print('\n' + message);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // wait for Enter to be pressed
}

void print(const std::string& string)
{
	std::cout << string << std::flush;
}

void printLine(const std::string& string)
{
	std::cout << string << std::endl;
}

void printLine(const std::vector<std::string>& strings)
{
	for (auto& string : strings)
		std::cout << string;
	std::cout << std::endl;
}

void printLineRepeat(const std::string& string, const unsigned int numberOfLines)
{
	for (unsigned int i{ 0 }; i < numberOfLines; ++i)
		printLine(string);
}

void printLines(const std::vector<std::string>& strings)
{
	for (auto& string : strings)
		printLine(string);
}

void printLines(const unsigned int numberOfLines)
{
	printLineRepeat("", numberOfLines);
}

} // namespace DEV
