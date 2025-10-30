
Cee Misc Lib
================

Personal garbage library to keep my snippets and tools somewhere.

For compilation and installation see "./doc/INSTALL.txt". See end of file for
make-em-all command.

For license see "./LICENCE.txt".


## How to fix broken OpenGL inside VMs

VMs usually are not made for hardware acceleration in mind. But for
testing of some simpler OpenGL apps, it is still desirable to have a
working OpenGL API available. Be aware that this is a SOFTWARE
implementation. So it won't make anything "faster".

Download

https://github.com/pal1000/mesa-dist-win/releases

. unpack files (inside desired VM). Run "systemwidedeploy.cmd" and make your choice. For me
the 1st option works perfectly fine.

[Source](https://thomas.inf3.ch/2019-06-12-opengl-kvm-mesa3d/index.html)


