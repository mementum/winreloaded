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

// #define _WIN32_WINNT 0x0501
// #define WINVER 0x0501
#include <windows.h>

#include "test.hpp"

#if 0
// Entry Point for a DLL
BOOL
WINAPI
DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  std::string msg;
  switch (fdwReason)
  {
    case DLL_PROCESS_ATTACH:
      SetHinstance(hinstDLL);
      /* Code path executed when DLL is loaded into a process's address space. */
      msg += "Attaching to process ";
      msg += std::to_string((unsigned long long)hinstDLL);
      msg += " / ";
      msg += std::to_string(fdwReason);
      break;

    case DLL_THREAD_ATTACH:
      /* Code path executed when a new thread is created within the process. */
      msg += "Attaching to thread ";
      msg += std::to_string((unsigned long long)hinstDLL);
      msg += " / ";
      break;

    case DLL_THREAD_DETACH:
      /* Code path executed when a thread within the process has exited *cleanly*. */
      msg += "Detaching from thread ";
      msg += std::to_string((unsigned long long)hinstDLL);
      msg += " / ";
      msg += std::to_string(fdwReason);
      break;

    case DLL_PROCESS_DETACH:
      /* Code path executed when DLL is unloaded from a process's address space. */
      msg += "Detaching from process ";
      msg += std::to_string((unsigned long long)hinstDLL);
      msg += " / ";
      msg += std::to_string(fdwReason);
      break;
  }
  printmsg(msg);
      
  return TRUE;
}
#endif
// Entry Point for a DLL
BOOL
WINAPI
DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  std::string msg;
  switch (fdwReason)
  {
    case DLL_PROCESS_ATTACH:
      /* Code path executed when DLL is loaded into a process's address space. */
      break;

    case DLL_THREAD_ATTACH:
      /* Code path executed when a new thread is created within the process. */
      break;

    case DLL_THREAD_DETACH:
      /* Code path executed when a thread within the process has exited *cleanly*. */
      break;

    case DLL_PROCESS_DETACH:
      /* Code path executed when DLL is unloaded from a process's address space. */
      break;
  }
  return TRUE;
}
