# goonOS, an Operating System for goons, by goons.

There's not really much to it right now, but it's planned to be incredibly lightweight and accessible
-----------------------

The intent is to make an OS that is lightweight, can be ran in a terminal, or can use a very basic window manager, if it progresses that far.

So far, the OS

- Boots as a .BIN file
- ~~does not boot as an .ISO~~ Boots as an ISO as of Version 1.0.0

System Requirements
---
- 25MB RAM
(it will not boot in Virtualbox otherwise)
- x86 compatible CPU
- At least 6MB of Storage

------
Rules on Version Releases.

example: goonOS, ver. a.b.c

- 'a' notates the major update number 
- 'b' means the month it was compiled
- 'c' means that this version is the most recently created after an approved contribution.

example, a **4.10.7** release means that it's the 4th major update of the kernel, it was compiled in October, and that there were 7 approved contributions after Kernel Version 4.0.0

-----
Dependencies to build .ISO manually
(On Linux)

- grub-common
- grub-pc-bin 
