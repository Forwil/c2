#include <stdio.h>

void increment ();

static int x = 2;

main ()
{
	increment ();

	increment ();

	increment ();

	printf ("%d\n", x);
}

void increment ()
{

	int x = 0;
	x += 1;
}

