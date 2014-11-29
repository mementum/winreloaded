/*
  WinSplit Reloaded - Window Positioning Manager

  Copyright (C) 2014 Daniel Rodriguez

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __WINSUP__HPP__
#define __WINSUP__HPP__

// #define _WIN32_WINNT 0x0501
// #define WINVER 0x0501

#define UNICODE
#if defined(UNICODE)
  #define _tcout std::wcout
#else
  #define _tcout std::cout
#endif

#include <windows.h>

#endif
