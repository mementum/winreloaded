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

#ifndef __CHILDPROC_HPP__
#define __CHILDPROC_HPP__

#include <string>

#include "winsup.hpp"

class ChildProcess
{
public:
    ChildProcess(const std::wstring &strName);
    ~ChildProcess() { TerminateProcess(); }
    std::pair<bool, std::wstring> StartProcess(void);
    void TerminateProcess(void);

    bool WriteString(const std::wstring &strData);
    
protected:
    bool m_bProcStarted;
    std::wstring m_strName;
    HANDLE m_hChildStdOutRd, m_hChildStdOutWr;
    HANDLE m_hChildStdInRd, m_hChildStdInWr;

    std::pair<bool, std::wstring> CreateHandles(void);
    std::pair<bool, std::wstring> CreateProcess(void);
};

#endif
