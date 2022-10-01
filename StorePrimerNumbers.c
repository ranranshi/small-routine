#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>

int num = 0;

bool isPrime(long long n);

void store_the_prime_numbers();

int main()
{
	int a = clock();
	store_the_prime_numbers();
	int b = clock();

	printf("Time: %d", (b - a)/1000.0);
	
    return 0;
}

bool isPrime(long long n)
{
	long long i;
	for (i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

void store_the_prime_numbers()
{
	int sum = (int)2E5;		//科学计数法表示数字时，默认是double类型，赋值时需要进行强制转换
	
	FILE* fp = fopen("C:\\Users\\14666\\Desktop\\result.txt", "w");
	for (int i = 1; i <= sum; i++)
	{
		if (isPrime(i))
		{
			fprintf(fp, "%d\n", i);
			fflush(fp);
		}
	}
	fclose(fp);

	return;
}



