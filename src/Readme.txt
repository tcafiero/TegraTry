ReadMe for building linux

Command line needs to look a bit like this:

g++ -lrt -lpthread a.cpp b.cpp etc.

the -lrt = RealTime lib. Needed for timers
the -lpthread is for posix threading support

