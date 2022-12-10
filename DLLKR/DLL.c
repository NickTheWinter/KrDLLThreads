#include "HeaderDLL.h"
BOOL WINAPI DllMain(HINSTANCE hlnstDll, DWORD dwReason, LPVOID IpReserved)
{
	BOOL bAllWentWell = TRUE;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	if (bAllWentWell)
		return TRUE;
	else
		return FALSE;
}
int CountSimple(range rangeAB)
{
	int c;
	int counter = 0;
	for (size_t i = rangeAB.a; i <= rangeAB.b; i++)
	{
		if (isSimple(i))
		{
			counter++;
		}
	}
	return counter;
}
int CountSimpleWithThreads(range rangeAB, int threadCount)
{
	HANDLE* arrayThreads = calloc(threadCount, sizeof(HANDLE));
	if ((rangeAB.b - rangeAB.a) < threadCount)
	{ 
		printf("Choose another thread count\n");
		return 1;
	}
	float devidor = (rangeAB.b - rangeAB.a) / (float)threadCount;
	devidor = ceil(devidor);
	int cycleCount = 1;
	int simpleCountThread = 0;
	int simpleCountSum = 0;
	for (size_t i = 0; i < threadCount; i++)
	{
		if (i != 0)
		{
			rangeAB.a += devidor;
		}
		for (size_t j = rangeAB.a; j <= devidor; j++)
		{
			arrayThreads[cycleCount] = CreateThread(NULL, 0, CountSimple, &rangeAB, 0, 0);
			cycleCount++;
		}
		WaitForMultipleObjects(cycleCount, arrayThreads, 1, INFINITE);
		GetExitCodeThread(arrayThreads[cycleCount], simpleCountThread);
		simpleCountSum += simpleCountThread;
	}

}
int isSimple(int a)
{
	for (size_t i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}