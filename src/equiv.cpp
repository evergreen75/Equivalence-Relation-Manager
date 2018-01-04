// CSCI 3300
// Assignment: 3
// Author:     Joshua Bowen
// File:       equiv.cpp
// Tab stops:  8

// **Say what this program does here.  (replace this comment)**



#include <cstdio>
#include "equiv.h"
using namespace std;


// newER(n) returns an array of n+1 integers.

ER newER(int n)
{
	ER R = new int[n+1];
	for (int i = 1; i <= n; i++)
	{
		R[i] = i;
	}
	return R;
}

// leader(ER &e, x) returns the leader of x in equivalence relation e. 

int leader(ER &e, int x)
{
	if (e[x] == x)
	{
		return x;
	}
	else
	{
		int m = e[x];
		return leader(e, m);
	}
}

// together(ER &e, x, y) determines if x and y are in the same equivalence class
// in equivalence relation e.

bool together(ER &e, int x, int y)
{
	if (leader(e, x) == leader(e, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// combine(ER &e, x, y) combines the equivalence classes of x and y in
// equivalence relation e.

void combine(ER &e, int x, int y)
{
	if (together(e, x, y))
	{
		
	}
	else
	{
		e[leader(e,x)] = leader(e, y);
	}
}

// destroy(ER &e) deallocates array e from the memory.

void destroyER(ER &e)
{
	delete [] e;
}

// showER(ER &e, n) prints the contents of array e of size n.

void showER(ER &e, int n)
{
	printf("\nIndex	Boss\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d	%d\n", i, e[i]);
	}
	printf("\n");
}

