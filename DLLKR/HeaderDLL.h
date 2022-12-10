#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int isSimple(int);

typedef struct aba {
	int a;
	int b;
} range;
extern __declspec(dllimport) int CountSimple(range);
extern __declspec(dllimport) int CountSimpleWithThreads(range, int);

__declspec(dllimport) clock_t start;
clock_t start;
__declspec(dllimport) clock_t startT;
clock_t startT;