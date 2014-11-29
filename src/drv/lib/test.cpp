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
#include <iostream>
#include <fstream>

#include "test.hpp"

HINSTANCE _hInst = NULL;
#if 0
void
SetHinstance(HINSTANCE hinst)
{
  _hInst = hinst;
}

void
printmsg(const std::string& msg)
{
  std::ofstream myfile;
  myfile.open("d:/dro/tmp/hola.txt", std::ios::out | std::ios::app | std::ios::binary);
  myfile << msg << std::endl;
  myfile.close();
}

int
testfunc(void)
{
  return 5;
}

bool
HookCBT(void)
{
  HHOOK hhretval = SetWindowsHookEx(WH_CBT, CBTProc, _hInst, 0);
  return hhretval != NULL;
}


LRESULT
CALLBACK
CBTProc(int nCode, WPARAM wParam, LPARAM lParam) 
{ 
  
  if(nCode < 0)  // do not process message 
      return CallNextHookEx(NULL, nCode, wParam, lParam); 

  HWND hwnd, hwnd2;
  CBTACTIVATESTRUCT *lpCbtAct;
  std::string msg;
  char wtext[1024] = "\0";
  switch (nCode) 
    { 
    case HCBT_ACTIVATE:
      msg += "HCBT_ACTIVATE ";
      hwnd = (HWND)wParam;
      GetWindowText((HWND)wParam, wtext, 1024);
      msg += wtext;
      msg += " ";
      msg += std::to_string((unsigned long long)hwnd);
      lpCbtAct = (CBTACTIVATESTRUCT *)lParam;
      msg += " ";
      msg += std::to_string((unsigned long long)lpCbtAct->hWndActive);
      break; 
    case HCBT_SETFOCUS:
      msg += "HCBT_SETFOCUS";
      hwnd = (HWND)wParam;
      GetWindowText((HWND)wParam, wtext, 1024);
      msg += wtext;
      msg += " ";
      msg += std::to_string((unsigned long long)hwnd);
      hwnd2 = (HWND)lParam;
      GetWindowText((HWND)lParam, wtext, 1024);
      msg += wtext;
      msg += " ";
      msg += std::to_string((unsigned long long)hwnd2);
      break; 
    } 
  if(msg != "")
    printmsg(msg);
  return CallNextHookEx(NULL, nCode, wParam, lParam); 
} 

LRESULT
CALLBACK
CBTProc2(int nCode, WPARAM wParam, LPARAM lParam) 
{ 
    if(nCode < 0)  // do not process message 
      return CallNextHookEx(NULL, nCode, wParam, lParam); 

    std::string msg;
    
    switch (nCode) 
    { 
        case HCBT_ACTIVATE:
	  msg += "HCBT_ACTIVATE";
	  break; 
        case HCBT_CLICKSKIPPED:
	  msg += "HCBT_CLICKSKIPPED";
	  break; 
 
        case HCBT_CREATEWND:
	  msg += "HCBT_CREATEWND";
	  break; 
 
        case HCBT_DESTROYWND:
	  msg += "HCBT_DESTROYWND";
	  break; 
 
        case HCBT_KEYSKIPPED:
	  msg += "HCBT_KEYSKIPPED";
	  break; 
 
        case HCBT_MINMAX:
	  msg += "HCBT_MINMAX";
	  break; 
 
        case HCBT_MOVESIZE:
	  msg += "HCBT_MOVESIZE";
	  break; 
 
        case HCBT_QS:
	  msg += "HCBT_QS";
	  break; 
 
        case HCBT_SETFOCUS:
	  msg += "HCBT_SETFOCUS";
	  break; 
 
        case HCBT_SYSCOMMAND:
	  msg += "HCBT_SYSCOMMAND";
	  break; 
        default:
	  msg += "default";
	  break; 
    } 
    printmsg(msg);
    return CallNextHookEx(NULL, nCode, wParam, lParam); 
} 

bool
HookShell(void)
{
  HHOOK hhretval = SetWindowsHookEx(WH_SHELL, ShellProc, _hInst, 0);
  return hhretval != NULL;
}

LRESULT
CALLBACK
ShellProc(int nCode, WPARAM wParam, LPARAM lParam) 
{ 
  if(nCode < 0)  // do not process message 
    return CallNextHookEx(NULL, nCode, wParam, lParam); 

  std::string msg;
  HWND hwnd, hwnd2;
  char wtext[1024] = "\0";
    
  switch (nCode) 
    { 
    case HSHELL_WINDOWACTIVATED:
      msg += "HSHELL_WINDOWACTIVATED";
      hwnd = (HWND)wParam;
      GetWindowText((HWND)wParam, wtext, 1024);
      msg += wtext;
      msg += " ";
      msg += std::to_string((unsigned long long)hwnd);
      msg += " lParam ";
      msg += std::to_string((unsigned long long)lParam);
      break; 

    case HSHELL_WINDOWCREATED:
      msg += "HSHELL_WINDOWCREATED";
      break; 

    case HSHELL_TASKMAN:
      msg += "HSHELL_TASKMAN";
      break; 
    } 
    if(msg != "")
      printmsg(msg);
    return CallNextHookEx(NULL, nCode, wParam, lParam); 
}
#endif
