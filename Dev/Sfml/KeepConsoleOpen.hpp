//////////////////////////////////////////////////////////////////////////////
//
// Dev
//
// Copyright(c) 2014-2016 M.J.Silk
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

#ifndef DEV_KEEPCONSOLEOPEN_HPP
#define DEV_KEEPCONSOLEOPEN_HPP

// http:://github.com/hapaxia

#include <iostream>
#include <string>
#include <SFML\Window\Keyboard.hpp>

namespace DEV
{

class KeepConsoleOpen
{
public:
	enum class KeyRequirement
	{
		Escape,
		Enter,
		Any
	};

	~KeepConsoleOpen()
	{
		if (!m_allowToClose)
		{
			// make sure that a key isn't still being pressed
			while (isAnyKeyPressed()) {}

			std::cout << std::endl << m_waitMessage << std::flush;
			if (m_keyRequirement == KeyRequirement::Escape)
				// escape to close
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {}
			else if (m_keyRequirement == KeyRequirement::Enter)
				// enter to close
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {}
			else if (m_keyRequirement == KeyRequirement::Any)
				// any key to close
				while (!isAnyKeyPressed()) {}
		}
	}

	void allowToClose()
	{
		m_allowToClose = true;
	}

	void setWaitMessage(const std::string& message)
	{
		m_useCustomMessage = true;
		m_waitMessage = message;
	}

	void resetMessageToDefault()
	{
		m_useCustomMessage = false;
		if (m_keyRequirement == KeyRequirement::Enter)
			m_waitMessage = defaultWaitMessageEnterKey;
		else if (m_keyRequirement == KeyRequirement::Any)
			m_waitMessage = defaultWaitMessageAnyKey;
		else if (m_keyRequirement == KeyRequirement::Escape)
			m_waitMessage = defaultWaitMessageEscapeKey;
		else
			m_waitMessage = "";
	}

	void setKeyRequirement(const KeyRequirement& keyRequirement)
	{
		m_keyRequirement = keyRequirement;
		if (!m_useCustomMessage)
			resetMessageToDefault();
	}

private:
	const std::string defaultWaitMessageEscapeKey = "Press Escape to close the console.";
	const std::string defaultWaitMessageEnterKey = "Press Enter to close the console.";
	const std::string defaultWaitMessageAnyKey = "Press any key to close the console.";
	bool m_allowToClose = false;
	std::string m_waitMessage = defaultWaitMessageEnterKey;
	KeyRequirement m_keyRequirement = KeyRequirement::Enter;
	bool m_useCustomMessage = false;

	bool isAnyKeyPressed()
	{
		for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
		{
			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
				return true;
		}
		return false;
	}
};

} // namespace DEV

#endif // DEV_KEEPCONSOLEOPEN_HPP
