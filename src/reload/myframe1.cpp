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
#include "myframe1.h"
#include "childproc.hpp"

MainFrame::MainFrame(wxWindow* parent)
    : MyFrame1(parent)
{
}

void
MainFrame::OnButtonClickExit(wxCommandEvent& event)
{
    event.Skip();
    this->Close();
}

void
MainFrame::OnButtonClickClearList(wxCommandEvent& event)
{
    event.Skip();
    this->m_listBoxWindows->Clear();
}

void
MainFrame::OnButtonClickReloadWindow(wxCommandEvent& event)
{
    event.Skip();
}

void
MainFrame::OnButtonClickStartChildProcesses(wxCommandEvent& event)
{
    event.Skip();
    // m_child32 = childproc_ptr(new ChildProcess(L"WinReloadDrv32.
    m_child32 = std::make_unique(new ChildProcess(L"WinReloadDrv32.exe"));
    m_child32->StartProcess();
    m_child32->WriteString(L"something");
}
