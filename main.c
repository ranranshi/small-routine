#include <stdio.h>
#include <stdbool.h>

int num = 0;

bool is_prime_number(int n);

void calculate_prime_number(int *prime_number);

void suppose(int *prime_number);

void write_result_to_file(int *prime_number);

int main()
{
    scanf("%d", &num);

    int prime_number[num];
    calculate_prime_number(prime_number);

    suppose(prime_number);
    write_result_to_file(prime_number);

    return 0;
}

bool is_prime_number(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void calculate_prime_number(int *prime_number)
{

    int i = 0;

    for (int j = 1;; ++j)
    {
        if (is_prime_number(j))
        {
            prime_number[i] = j;
            i++;
        }

        if (i == num)
        {
            break;
        }
    }

    return;
}

void suppose(int *prime_number)
{
    int sum = 0;
    for (int i = 0; i < num - 1; ++i)
    {
        if (prime_number[i + 1] - prime_number[i] == 2)
        {
            sum++;
        }
    }

    printf("%d", sum);
}

void write_result_to_file(int *prime_number)
{
    FILE *file = fopen("C:\\Users\\14666\\Desktop\\result.txt", "w");

    for (int i = 0; i < num; ++i)
    {
        if (i == 0 || i == num - 1)
        {
            fprintf(file, "%d\n", prime_number[i]);
            fflush(file);
        }
        else
        {
            fprintf(file, "%d\t%d\n", prime_number[i], prime_number[i] - prime_number[i - 1]);
            fflush(file);
        }
    }

    fflush(file);
    fclose(file);
}



