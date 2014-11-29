--[[
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
--]]


function newplatform(plf)
    local name = plf.name
    local description = plf.description
 
    -- Register new platform
    premake.platforms[name] = {
        cfgsuffix = "_"..name,
        iscrosscompiler = false
    }
 
    -- Allow use of new platform in --platforms
    table.insert(premake.option.list["platform"].allowed, { name, description })
    table.insert(premake.fields.platforms.allowed, name)
 
    -- Add compiler support
    -- gcc
    premake.gcc.platforms[name] = plf.gcc
    --other compilers (?)
end
 
function newgcctoolchain(toolchain)
    newplatform {
        name = toolchain.name,
        description = toolchain.description,
        gcc = {
            cc = toolchain.prefix .. "gcc",
            cxx = toolchain.prefix .. "g++",
            ar = toolchain.prefix .. "ar",
            -- cppflags = "-MMD " .. toolchain.cppflags
            cppflags = toolchain.cppflags
        }
    }
end

newgcctoolchain {
    name = "w32",
    description = "mingw-w64 32bits",
    prefix = "i686-w64-mingw32-",
    cppflags = ""
}

newgcctoolchain {
    name = "w64",
    description = "mingw-w64 64bits",
    prefix = "x86_64-w64-mingw32-",
    cppflags = ""
}

solution "WinReload64"
  language "C++"
  buildoptions { "-std=gnu++11" }
  platforms { "w64" }

  configurations { "debug", "release" }
  targetdir "bin"
  includedirs { "./src/include" }

  project "WinReloadLib64"
    kind "SharedLib"
    objdir "obj/lib/64"

    files {
      "src/drv/lib/*.cpp",
      "src/drv/lib/*.hpp"
    }

    defines { "BUILDING_DLL" }
    flags { "ExtraWarnings" }

  project "WinReloadDrv64"
    kind "ConsoleApp"

    objdir "obj/drv/64"

    files {
      "src/drv/*.cpp",
      "src/drv/*.hpp"
    }

    links { "WinReloadLib64" }
    includedirs { "./src/drv/lib" }

    flags { "ExtraWarnings" }

solution "WinReload32"
  language "C++"
  buildoptions { "-std=gnu++11" }
  platforms { "w32" }

  configurations { "debug", "release" }
  targetdir "bin"
  includedirs { "./src/include" }

  project "WinReloadLib32"
    kind "SharedLib"
    objdir "obj/lib/32"

    files {
      "src/drv/lib/*.cpp",
      "src/drv/lib/*.hpp"
    }

    defines { "BUILDING_DLL" }
    flags { "ExtraWarnings" }

  project "WinReloadDrv32"
    kind "ConsoleApp"

    objdir "obj/drv/32"

    files {
      "src/drv/*.cpp",
      "src/drv/*.hpp"
    }

    links { "WinReloadLib32" }
    includedirs { "./src/drv/lib" }

    flags { "ExtraWarnings" }


solution "WinReload"
  language "C++"
  buildoptions { "-std=gnu++11" }
  platforms { "w32" }

  configurations { "debug", "release" }
  targetdir "bin"
  includedirs { "./src/include" }

  project "WinReload"
    kind "WindowedApp"

    objdir "obj/gui"

    files {
      "src/reload/*.cpp",
      "src/drv/*.hpp",
      "src/reload/*.h",
    }

    includedirs {
      -- wx/xxxx.h files
      "/opt/i686-w64-mingw32/lib/wx/include/i686-w64-mingw32-msw-unicode-3.0",
      -- wx/setup.h
      "/opt/i686-w64-mingw32/include/wx-3.0",
    }
    libdirs { "/opt/i686-w64-mingw32/lib" }
    links {
      "wx_mswu-3.0-i686-w64-mingw32",
      "wx_mswu_gl-3.0-i686-w64-mingw32",
    }

    flags { "ExtraWarnings" }
