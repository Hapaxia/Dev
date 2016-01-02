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

namespace DEV
{

// Keeps console open when application is closed. Does not require external libraries.
class KeepConsoleOpen
{
public:
	~KeepConsoleOpen()
	{
		if (!m_allowToClose)
		{
			// enter to close
			std::cin.clear();
			std::cin.sync();
			std::cout << std::endl << m_waitMessage << std::flush;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // wait for Enter to be pressed
		}
	}

	void allowToClose() { m_allowToClose = true; }
	void forbidToClose() { m_allowToClose = false; }
	void setWaitMessage(const std::string& message) { m_waitMessage = message; }

private:
	bool m_allowToClose = false;
	std::string m_waitMessage = "Press Enter to close the console.";
};

} // namespace DEV

#endif // DEV_KEEPCONSOLEOPEN_HPP
