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
#ifndef __MYFRAME1_H__
#define __MYFRAME1_H__

/**
   @file
   Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "maingui.h"
//// end generated include

#include <memory>
#include "childproc.hpp"

/** Implementing MyFrame1 */
class MainFrame : public MyFrame1
{
 protected:
  // Handlers for MyFrame1 events.
  void OnButtonClickExit( wxCommandEvent& event );

  // Handlers for MyFrame1 events.
  void OnButtonClickClearList( wxCommandEvent& event );

  // Handlers for MyFrame1 events.
  void OnButtonClickReloadWindow( wxCommandEvent& event );

  // Handlers for MyFrame1 events.
  void OnButtonClickStartChildProcesses( wxCommandEvent& event );

 public:
  /** Constructor */
  MainFrame( wxWindow* parent );
  //// end generated class members

  typedef std::unique_ptr<ChildProcess> childproc_ptr;
  childproc_ptr m_child32;
};

#endif // __myframe1__
