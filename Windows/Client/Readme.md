Remeber to link ws2_32.dll (winsock api) when compiling using a pragma comment or linker options or cmake add library.
For cygwin and MinGW users the file to link is libws2_32.a
The provided Cmake example (CmakeLists-example.txt in /CocoIP/example (in this repo)) works provided you have the windows SDK installed.
