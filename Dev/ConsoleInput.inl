//////////////////////////////////////////////////////////////////////////////
//
// Dev
//
// Copyright(c) 2014-2023 M.J.Silk
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

#ifndef DEV_CONSOLEINPUT_INL
#define DEV_CONSOLEINPUT_INL

#include "ConsoleInput.hpp"
#include "ConsoleOutput.hpp"
#include <iostream>
#include <string>
#include <limits> // for std::numeric_limits

namespace DEV
{

inline void pressEnterToContinue(const std::string& message)
{
	std::cin.clear();
	std::cin.sync();
	print('\n' + message);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // wait for Enter to be pressed
}

inline std::string inputLine(const std::string& prompt, const bool newLine)
{
	std::string inputString;
	if (newLine)
		printLine(prompt);
	else
		print(prompt);
	std::getline(std::cin, inputString);
	return inputString;
}

template <class T>
inline std::optional<T> extractNumberFromString(const bool isInteger, const std::string& string)
{
	try
	{
		return isInteger ? static_cast<T>(std::stoll(string)) : static_cast<T>(std::stold(string));
	}
	catch (...)
	{
	}
	return {};
}

template <class T>
inline std::optional<T> inputNumber(const bool isInteger, const std::string& prompt, const bool newLine)
{
	std::string inputString{ inputLine(prompt, newLine) };
	return extractNumberFromString<T>(isInteger, inputString);
}

template <class T>
inline std::optional<T> repeatInputNumberUntilValid(const bool isInteger, const std::string& prompt, const bool newLine, const std::string& repeatPrompt, const std::vector<std::string>& validBreakawayStrings)
{
	std::optional<T> o;
	bool firstTime{ true };
	while (!o)
	{
		std::string inputString{ DEV::inputLine(firstTime ? prompt : repeatPrompt, newLine) };
		if (std::find(validBreakawayStrings.begin(), validBreakawayStrings.end(), inputString) != validBreakawayStrings.end())
			return std::nullopt;
		o = DEV::extractNumberFromString<T>(isInteger, inputString);
		firstTime = false;
	}
	return o;
}

} // namespace DEV

#endif // DEV_CONSOLEINPUT_INL
