#include <stdio.h>
long long fibbonachi_numbers[91];

long long get_fibbonachi_via_recursion(int number);

int main()
{
    return 0;
}

long long get_fibbonachi_via_recursion(int number)
{
    if (number <= 0)
    {
        printf("Wrong index");

        return -1;
    }
    else if (number == 1)
    {
        return 0;
    }
    else if (number == 2)
    {
        return 1;
    }
    else if (number > 93)
    {
        return get_fibbonachi_via_recursion(number - 2) + get_fibbonachi_via_recursion(number - 1); //Переполнение!!!
    }
    else if (fibbonachi_numbers[number - 3] == 0)
    {
        fibbonachi_numbers[number - 3] = get_fibbonachi_via_recursion(number - 2) + get_fibbonachi_via_recursion(number - 1);
    }
    
    return fibbonachi_numbers[number - 3];
}