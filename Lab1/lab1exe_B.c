#include <stdio.h>
int foo (int x);
int jupiter (int x);
int mercury (int x, int y);

int main (void) {
	int x = 20, y = 30, z = 10;
	printf("Point 1 - Main:\n x: %d, y: %d, z: %d\n", x, y, z);
	y = foo(x++);
	printf("Point 2 - Main: \n x: %d, y: %d, z: %d\n", x, y, z);
	y = jupiter (z/x);
	// point 4
	return 0;
	
}

int mercury (int x, int y) {
	int z;
	z = x + 2 * y;
	// point 2
	printf("Point 2 - Mercury:\n x: %d, y: %d, z: %d\n", x, y, z);
	
	return z;
	
}

int jupiter (int x) {
	int y;
	printf("Point 2 - Jupiter:\n x: %d, y: %d\n", ++x, y);
	y = mercury (3 % 4, x);
	printf("Point 3 - Jupiter:\n x: %d, y: %d\n", x, y);
	// point 3
	return y++;
}

int foo(int x) {
	// point 1
	printf("Point 1 - Foo:\n x: %d\n", x);
	return ++x;
}