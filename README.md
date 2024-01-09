# goonOS, an Operating System for goons, by goons.

There's not really much to it right now, but it's planned to be incredibly lightweight and accessible
-----------------------

### Plans for the OS

- Lightweight
- Runnable in a terminal
- A basic window manager if enough progress is made

### So far, the OS

- Boots as a .BIN file
- ~~does not boot as an .ISO~~ Boots as an ISO as of Version 1.0.0

System Requirements
---
These are required for the OS to be able to boot.

- 25MB RAM
- x86 compatible CPU
- At least 6MB of Storage

Version Rules
------

example: goonOS, ver. a.b.c

- 'a' → Main release candidate
- 'b' → Month of compilation
- 'c' → Number of patches/hotfixes in the current R.C

### Release Example
<pre>
  4    .    10    .    7  
  ↓         ↓          ↓  
4th RC   October   Patch Number
</pre>

Build Dependencies & How To Compile
-----

### Dependencies Required

- grub-common
- grub-mkrescue
- grub-pc-bin 
- build-essential
- xorriso

### Windows Compilation

- Install WSL
- install the Ubuntu subsystem(wsl.exe --install Ubuntu-23.04)
- in WSL, install the Linux dependencies listed above
- run 'make goonOS.iso'

### Linux Compilation

- Install dependencies listed above
- run 'make goonOS.iso'