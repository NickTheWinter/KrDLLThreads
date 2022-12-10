#include "Header.h"
int main()
{
	range rangeAB;
	int a = 10, b = 20, c;
	if (b < a)
	{
		c = b;
		b = a;
		a = c;
	}
	rangeAB.a = a;
	rangeAB.b = b;
	HINSTANCE dll = LoadLibrary(L"DLLKR.dll");
	CountSimple countSimple = (CountSimple)GetProcAddress(dll, "CountSimple");
	CountSimpleWithThreads countSimpleWithThreads = (CountSimpleWithThreads)GetProcAddress(dll, "CountSimpleWithThreads");
	int countSimp = countSimple(rangeAB);
	int countSimpT = countSimpleWithThreads(rangeAB, 3);
	printf("Count without: %d\n", countSimp);
	printf("Count with: %d\n", countSimpT);

	FreeLibrary(dll);
}