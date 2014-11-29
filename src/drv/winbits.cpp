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

#include <string>

#include "winsup.hpp"

// GetStringRegKey from
// http://stackoverflow.com/questions/34065/how-to-read-a-value-from-the-windows-registry

#if 0
LONG
GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue)
{
    strValue = strDefaultValue;
    WCHAR szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError;
    nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE) szBuffer, &dwBufferSize);
    if(ERROR_SUCCESS == nError)
    {
        strValue = szBuffer;
    }
    return nError;
}

// Is64BitWindowsReg following the Registry Key from
// http://support.microsoft.com/kb/556009
bool
Is32BitWindowsReg(void)
{
    std::wstring strValue;
    LONG ret = GetStringRegKey("HKLM\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "Identifier", strValue, "");
    if(ret == ERROR_SUCCESS)
    {
        if(strValue.find("x86") == -1)
            return false;
    }
    return true;
}

#endif

namespace winbits {
    typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

// Is64BitWindows from Raymond Chen's blog
// http://blogs.msdn.com/b/oldnewthing/archive/2005/02/01/364563.aspx
// Adding dynamic loading of IsWow64Process and leaving out the 16 bit branch
    bool
    Is64BitWindows(void)
    {
#if defined(_WIN64)
        return true;  // 64-bit programs run only on Win64
#else
        // 32-bit programs run on both 32-bit and 64-bit Windows
        BOOL bIsWow64 = FALSE;
        LPFN_ISWOW64PROCESS fnIsWow64Process;

        fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
        if(fnIsWow64Process != NULL)
            return fnIsWow64Process(GetCurrentProcess(), &bIsWow64) && bIsWow64;
    
        return false;
#endif
    }

    bool
    IsWow64(void)
    {
        BOOL bIsWow64 = FALSE;
        LPFN_ISWOW64PROCESS fnIsWow64Process;

        //IsWow64Process is not available on all supported versions of Windows.
        //Use GetModuleHandle to get a handle to the DLL that contains the function
        //and GetProcAddress to get a pointer to the function if available.

        fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
        if(fnIsWow64Process != NULL)
            if(!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
                return false; // handle error -- Assume false

        return bIsWow64;
    }

    bool
    Is64BitApp(void)
    {
        return Is64BitWindows() && !IsWow64();
    }

    bool
    Is32BitApp(void)
    {
        return !Is64BitWindows() || IsWow64();
    }
}
