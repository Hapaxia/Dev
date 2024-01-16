//////////////////////////////////////////////////////////////////////////////
//
// Dev
//
// Copyright(c) 2014-2024 M.J.Silk
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

#ifndef DEV_CONSOLEINPUT_HPP
#define DEV_CONSOLEINPUT_HPP

#include <string>
#include <vector>
#ifndef DEV_REMOVE_ABOVE_CPP11
#include <optional> // requires C++17
#endif // DEV_REMOVE_ABOVE_CPP11

#ifdef min
#undef min
#endif // min
#ifdef max
#undef max
#endif // max

namespace DEV
{

void pressEnterToContinue(const std::string& message = "Press Enter to continue.");

std::string inputLine(const std::string& prompt = "", bool newLine = false);

#ifndef DEV_REMOVE_ABOVE_CPP11
template <class T>
std::optional<T> extractNumberFromString(bool isInteger, const std::string& string);

template <class T>
std::optional<T> inputNumber(bool isInteger, const std::string& prompt = "", bool newLine = false);

template <class T>
std::optional<T> repeatInputNumberUntilValid(bool isInteger, const std::string& prompt = "", bool newLine = false, const std::string& repeatPrompt = "", const std::vector<std::string>& validBreakawayStrings = {});
#endif // DEV_REMOVE_ABOVE_CPP11

} // namespace DEV

#include "ConsoleInput.inl"

#endif // DEV_CONSOLEINPUT_HPP
