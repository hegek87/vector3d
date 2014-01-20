all:
	g++ -c -g -Wall vector3d.cpp
	g++ -c -g -Wall vecmain.cpp
	g++ -o vector3d vector3d.o vecmain.o
	
	mv *.o vector3d bin
