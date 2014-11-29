/*
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
#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <windows.h>

#include <string>
#include "dllsupport.hpp"

extern "C" DLL_PUBLIC void printmsg(const std::string& msg);
extern "C" DLL_PUBLIC void SetHinstance(HINSTANCE hinst);


extern "C" DLL_PUBLIC int testfunc(void);

extern DLL_PUBLIC bool HookCBT(void);
extern DLL_PUBLIC LRESULT CALLBACK CBTProc(int, WPARAM, LPARAM);

extern DLL_PUBLIC bool HookShell(void);
extern DLL_PUBLIC LRESULT CALLBACK ShellProc(int, WPARAM, LPARAM);

#endif
