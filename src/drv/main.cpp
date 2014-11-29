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


#include <cstdlib>
#include <string>
#include <fstream>

#include "winsup.hpp"
#include "winbits.hpp"

//printmsg(int read, const std::wstring& msg)
void
printmsg(int read, const wchar_t *msg)
{
  std::wofstream myfile;
  myfile.open("d:/dro/tmp/hola.txt", std::ios::out | std::ios::app | std::ios::binary);
  myfile << read << L"-" << msg << std::endl;
  myfile.close();
}

int
main(int argc, char *argv[])
{
#if 0
    bool hooked = HookShell();
    if(!hooked)
    {
        printmsg("Could not install the CBTProc Hook");
        LPVOID lpMsgBuf;
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
                      GetLastError(),
                      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                      (LPTSTR) &lpMsgBuf,
                      0,
                      NULL);
        printmsg((const char*)lpMsgBuf);
        LocalFree(lpMsgBuf);
        exit(1);
    }

    // Create an event which will be waiting for
    HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, "myname");
    DWORD dwretval = WaitForSingleObject(hEvent, INFINITE);
    exit(0);
#endif


    HANDLE hStdout = ::GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hStdin = ::GetStdHandle(STD_INPUT_HANDLE);
    if((hStdout == INVALID_HANDLE_VALUE) || (hStdin == INVALID_HANDLE_VALUE))
        return 1; // ExitProcess(1);

    int BUFSIZE=4096;
    BOOL bSuccess;
    CHAR chBuf[BUFSIZE];
    WCHAR wchBuf[BUFSIZE];
    DWORD dwRead;
    DWORD dwWritten;
    
    // Wait for initial message (HWDN string)
    bSuccess = ::ReadFile(hStdin, wchBuf, BUFSIZE, &dwRead, NULL);
    if(!bSuccess || dwRead == 0)
        return 1;
    //wchBuf[dwRead / sizeof(wchar_t)] = ''; // NULL Terminate the string
    printmsg(dwRead, (const wchar_t *)wchBuf);

    // Wait for initial message (HWND string)
    bSuccess = ::ReadFile(hStdin, chBuf, BUFSIZE, &dwRead, NULL);
    if(!bSuccess || dwRead == 0)
        return 1;
    HWND hwndServer = (HWND)::atol(chBuf);
    // Wait for second message (RegisterWindowMessage string)
    bSuccess = ::ReadFile(hStdin, wchBuf, BUFSIZE, &dwRead, NULL);
    if(!bSuccess || dwRead == 0)
        return 1;
    std::wstring strWinMsg = wchBuf;
    UINT uiWinMsg = ::RegisterWindowMessage(strWinMsg.c_str());
    bool is64Bit = winbits::Is64BitApp();
    while(true)
    {
        // This simple algorithm uses the existence of the pipes to control execution.
        // It relies on the pipe buffers to ensure that no data is lost.
        // Larger applications would use more advanced process control.

        // Read from standard input and stop on error or no data.
        bSuccess = ::ReadFile(hStdin, chBuf, BUFSIZE, &dwRead, NULL);
      
        if(!bSuccess || dwRead == 0)
            break;

        
        
#if 0
        // Write to standard output and stop on error.
        bSuccess = ::WriteFile(hStdout, chBuf, dwRead, &dwWritten, NULL);

        if(!bSuccess)
            break;
#endif
    }
    return 0;
}
