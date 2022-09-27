#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdio.h>
#include <time.h> 
#include <string.h>

int main()
{
	//产生随机数种子
	srand((unsigned int)time(NULL));
	
	//产生10阶数组
	int matrix[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix[i][j] = rand() % 10;
			printf("%d\t", matrix[i][j]);
		}

		printf("\n");
	}
	
	//录入数组的n阶幂
	int n = 0;
	printf("请输入数组的幂数：");
	scanf("%d", &n);
	
	//计算该数组的n阶幂
	int result[10][10] = {0};
	int temp[10][10];
	memcpy(temp, matrix, sizeof(int) * 100);
	
	for (int count = 0; count < n; count++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				int sum = 0;
				for (int k = 0; k < 10; k++)
				{
					sum += temp[i][k] * matrix[k][j];
				}

				result[i][j] += sum;
			}
		}

		memcpy(temp, result, sizeof(int) * 100);
	}
	
	//输出结果
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d\t", result[i][j]);
		}

		printf("\n");
	}
	
	return 0;
}


