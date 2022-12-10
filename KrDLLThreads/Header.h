#pragma once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
typedef struct aba {
	int a;
	int b;
} range;
typedef int(_cdecl* CountSimple)(range);
typedef int(_cdecl* CountSimpleWithThreads)(range, int);