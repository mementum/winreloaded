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

#include "winsup.hpp"
#include "childproc.hpp"

ChildProcess::ChildProcess(const std::wstring &strName)
{
    m_bProcStarted = false;
    m_strName = strName;
}

std::pair<bool, std::wstring>
ChildProcess::StartProcess(void)
{
    if(m_bProcStarted)
        return std::make_pair(true, L"");

    std::pair<bool, std::wstring> ret = CreateHandles();
#if 0
    if(ret[0] == false)
        return ret;
#endif
    return CreateProcess();
}

bool
ChildProcess::WriteString(const std::wstring &strData)
{
    DWORD dwWritten;
    BOOL bSuccess = ::WriteFile(m_hChildStdInWr,
                                strData.c_str(), strData.size() * sizeof(wchar_t),
                                &dwWritten, NULL);
    return static_cast<bool>(bSuccess);
}

void
ChildProcess::TerminateProcess(void)
{
    if(m_bProcStarted) {
        m_bProcStarted = false;
        ::CloseHandle(m_hChildStdInWr);
    }
}

std::pair<bool, std::wstring>
ChildProcess::CreateHandles(void)
{
    SECURITY_ATTRIBUTES saAttr;

    // Set the bInheritHandle flag so pipe handles are inherited.
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    // Create a pipe for the child process's STDOUT.
    if (!::CreatePipe(&m_hChildStdOutRd, &m_hChildStdOutWr, &saAttr, 0))
        return std::make_pair(false, L"Stdout CreatePipe");

    // Ensure the read handle to the pipe for STDOUT is not inherited.
    if (!SetHandleInformation(m_hChildStdOutRd, HANDLE_FLAG_INHERIT, 0))
        return std::make_pair(false, L"StdoutRd SetHandleInformation");

    // Ensure the write handle to the pipe for STDOUT is not inherited.
    if (!SetHandleInformation(m_hChildStdOutWr, HANDLE_FLAG_INHERIT, 0))
        return std::make_pair(false, L"StdoutWr SetHandleInformation");

    // Create a pipe for the child process's STDIN.
    if (!CreatePipe(&m_hChildStdInRd, &m_hChildStdInWr, &saAttr, 0))
        return std::make_pair(false, L"Stdin CreatePipe");

    // Ensure the write handle to the pipe for STDIN is not inherited.
    if (!SetHandleInformation(m_hChildStdInWr, HANDLE_FLAG_INHERIT, 0) )
        return std::make_pair(false, L"StdInWr SetHandleInformation");

    return std::make_pair(true, L"");
}

std::pair<bool, std::wstring>
ChildProcess::CreateProcess(void)
{
    // TCHAR szCmdline[] = m_strName.c_str();

    // Set up members of the PROCESS_INFORMATION structure.
    PROCESS_INFORMATION piProcInfo;
    ::ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

    // Set up members of the STARTUPINFO structure.
    // This structure specifies the STDIN and STDOUT handles for redirection.
    STARTUPINFO siStartInfo;
    ::ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
    siStartInfo.cb = sizeof(STARTUPINFO);
    siStartInfo.hStdError = m_hChildStdOutWr;
    siStartInfo.hStdOutput = m_hChildStdOutWr;
    siStartInfo.hStdInput = m_hChildStdInRd;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

    // Create the child process.
    BOOL bSuccess = FALSE;
    bSuccess = ::CreateProcess(
        NULL,
        (LPWSTR)m_strName.c_str(),     // command line
        NULL,          // process security attributes
        NULL,          // primary thread security attributes
        TRUE,          // handles are inherited
        // DETACHED_PROCESS,             // creation flags
        0,
        NULL,          // use parent's environment
        NULL,          // use parent's current directory
        &siStartInfo,  // STARTUPINFO pointer
        &piProcInfo);  // receives PROCESS_INFORMATION
  
    // If an error occurs, exit the application.
    if (!bSuccess)
        return std::make_pair(false, L"CreateProcess");
    else
    {
        // Close handles to the child process and its primary thread.
        // Some applications might keep these handles to monitor the status of the child process, for example.
        ::CloseHandle(piProcInfo.hProcess);
        ::CloseHandle(piProcInfo.hThread);
    }
    return std::make_pair(true, L"");
}
