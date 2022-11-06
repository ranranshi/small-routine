#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int data[100];

void OutputArray();

int InitArray();

void SortArray();

int SearchArray(int target);

int main()
{
    InitArray();

    SortArray();

    int result = SearchArray(50);

    printf("result index is %d.\n", result);

    return 0;
}

void OutputArray()
{
    for (int i = 0; i < 100; ++i)
    {
        printf("%d\n", data[i]);
    }
}

int InitArray()
{
    FILE *fp = fopen("C:\\Users\\14666\\CLionProjects\\CLionDataStructure\\RandomNumbers.txt", "r");

    if (fp != NULL)
    {
        char *string = (char *) calloc(1024, sizeof(char));

        int count = 0;
        while (true)
        {
            fgets(string, 10, fp);

            if (feof(fp))
            {
                break;
            }
            else
            {
                data[count] = atoi(string);

                count++;
            }
        }
    }
    else
    {
        printf("File open failed!\n");

        return -1;
    }

    int result = fclose(fp);
    if (result == 0)
    {
        return 0;
    }
    else
    {
        printf("File close failed!");

        return -1;
    }
}

void SortArray()
{
    for (int i = 0; i < 100; ++i)
    {
        for (int j = i + 1; j < 100; ++j)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int SearchArray(int target)
{
    int low = 0;
    int high = sizeof(data) / sizeof(int);
    int middle = (high + low) / 2;

    while (true)
    {
        if (target == data[middle])
        {
            return middle;
        }
        else if (target > data[middle])
        {
            low = middle + 1;
        }
        else if (target < data[middle])
        {
            high = middle - 1;
        }

        middle = (high + low) / 2;
    }
}

