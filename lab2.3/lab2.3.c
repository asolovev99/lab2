#include <stdio.h>

int nth_power_of_number(int power_of_number, int number);

char int_to_char(int number);

char* from_10th_to_targetth(int number, int target, char* target_number);

int from_sourceth_to_10th(int source, int number);

void power(int number, int source, int target);

int main()
{
    //for (int i = 2; i <= 10; i++)
    //{
    //    for (int j = 2; j <= 36; j++)
    //    {
    //        printf("source = %d, power = %d\n", i, j);
    //        power(1000000000, i, j);
    //        printf("\n");
    //    }
    //}
    //printf("%d\n", -(int)2147483648);
    //power(-(int)2147483647, 10, 2);
    //power(-(int)2147483648, 10, 2);
    //power(-1111, 2, 16);

    return 0;
}

int nth_power_of_number(int power_of_number, int number)
{
    int result = 1;

    for (int i = 1; i <= power_of_number; i++)
    {
        result *= number;
    }

    return result;
}

char int_to_char(int number)
{
    if ((0 <= number) && (number <= 9))
    {
        return number + '0';
    }
    else if ((10 <= number) && (number <= 35))
    {
        return number - 10 + 'A';
    }
    else
    {
        printf("Error in int_to_char function: number < 0 or number > 35");

        return -1;
    }
}

char* from_10th_to_targetth(int number, int target, char* target_number)
{
    const int length_of_array = 34;
    int current_index = length_of_array - 2;

    if (number < 0)
    {
        target_number[0] = '-';
        number *= -1;
    }

    if (number == 0)
    {
        target_number[0] = '0';
        target_number[1] = '\0';
    }
    else
    {
        while (number > 0)
        {
            target_number[current_index] = int_to_char(number % target);
            number = number / target;
            current_index--;
        }

        if (target_number[0] == '-')
        {
            for (int i = 1; i <= length_of_array - 2 - current_index; i++)
            {
                target_number[i] = target_number[i + current_index];
            }
            target_number[length_of_array - 1 - current_index] = '\0';
        }
        else
        {
            for (int i = 0; i <= length_of_array - 3 - current_index; i++)
            {
                target_number[i] = target_number[i + current_index + 1];
            }
            target_number[length_of_array - 2 - current_index] = '\0';
        }
    }

    return target_number;
}

int from_sourceth_to_10th(int source, int number)
{
    int result = 0;
    int digit = 0;
    int sign = 1;

    if (number < 0)
    {
        sign = -1;
        number *= -1;
    }

    while (number > 0)
    {
        result += (number % 10) * nth_power_of_number(digit, source);
        number = number / 10;
        digit++;
    }
    result *= sign;

    return result;
}

void power(int number, int source, int target)
{
    if (source == target)
    {
        printf("%d\n", number);
    }
    else if (source == 10)
    {
        char target_number[33];
        printf("%s\n", from_10th_to_targetth(number, target, target_number));
    }
    else if (target == 10)
    {
        printf("%d\n", from_sourceth_to_10th(source, number));
    }
    else
    {
        char target_number[34];
        printf("%s\n", from_10th_to_targetth(from_sourceth_to_10th(source, number), target, target_number));
    }
}