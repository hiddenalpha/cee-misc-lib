
Cee Misc Lib
================

Personal garbage library to keep my snippets and tools somewhere.

For compilation and installation see "./doc/INSTALL.txt". See end of file for
make-em-all command.

For license see "./LICENCE.txt".

Releases:
https://hiddenalpha.ch/slnk/id/1:b60e212

Other Builds:
https://github.com/hiddenalpha/cee-misc-lib/releases



## Stats For Nerds

github.com/AlDanial/cloc
-------------------------------------------------
Language          files   blank   comment    code
-------------------------------------------------
C                   190    8397      5354   56429
Lua                  49    1471       732   12291
C/C++ Header         90    1913      1606    3071
HTML                 21     144         4    1612
Text                 13     281         0     931
Bourne Shell          3      33        10     110
JavaScript            3      25         0      84
Java                  2      28         2      78
JSON                  3       1         0      41
Assembly              2       8        26      14
-------------------------------------------------
SUM:                376   12301      7734   74661
-------------------------------------------------






## How to fix broken OpenGL inside VMs

VMs usually are not made for hardware acceleration in mind. But for
testing of some simpler OpenGL apps, it is still desirable to have a
working OpenGL API available. Be aware that this is a SOFTWARE
implementation. So it won't make anything "faster".

Can be found at https://github.com/pal1000/mesa-dist-win/releases

. unpack files (inside desired VM). Run "systemwidedeploy.cmd" and make your choice. For me
the 1st option works perfectly fine.

[Source](https://thomas.inf3.ch/2019-06-12-opengl-kvm-mesa3d/index.html)


