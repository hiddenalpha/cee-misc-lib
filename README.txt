
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

Taken at 2026-06-27.

github.com/AlDanial/cloc
-------------------------------------------------
Language          files   blank   comment    code
-------------------------------------------------
C                   209    9092      6039   65689
Lua                  49    1438       730   12083
C Header             96    2264      1891    3603
HTML                 20     138         0    1516
Text                 16     310         0    1008
Bourne Shell          3      33        10     110
JavaScript            3      25         0      84
Java                  2      28         2      78
Assembly              3      21        51      29
-------------------------------------------------
SUM:                401   13349      8723   84200
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


