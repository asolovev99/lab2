#include <stdio.h>

int exponentiation(int power_of_number, int number);

char int_to_char(int number);

int is_number_correct(int number, int source);

char* from_10_numeral_system_to_target_numeral_system(int number, int target, char* target_number);

int from_source_numeral_system_to_10_numeral_system(int source, int number);

void power(int number, int source, int target);

int main()
{
    return 0;
}

int exponentiation(int power_of_number, int number)
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

int is_number_correct(int number, int numeral_system)
{
    int sign = 1;
    
    if (number < 0)
    {
        sign = -1;
    }

    while (number != 0)
    {
        if (number % 10 * sign >= numeral_system)
        {
            return 0;
        }
        number /= 10;
    }

    return 1;
}

char* from_10_numeral_system_to_target_numeral_system(int number, int target, char* target_number)
{
    const int length_of_array = 34;
    int current_index = length_of_array - 2;
    int sign = 1;

    if (number < 0)
    {
        target_number[0] = '-';
        sign = -1;
    }

    if (number == 0)
    {
        target_number[0] = '0';
        target_number[1] = '\0';
    }
    else
    {
        while (number != 0)
        {
            target_number[current_index] = int_to_char(number % target * sign);
            number = number / target;
            current_index--;
        }

        if (sign == -1)
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

int from_source_numeral_system_to_10_numeral_system(int source, int number)
{
    int result = 0;
    int current_digit = 0;

    while (number != 0)
    {
        result += (number % 10) * exponentiation(current_digit, source);
        number = number / 10;
        current_digit++;
    }

    return result;
}

void power(int number, int source, int target)
{
    if ((source >= 11) || (source <= 1))
    {
        printf("Error: source >= 11 or source <= 1\n");
    }
    else if ((target >= 32) || (target <= 1))
    {
        printf("Error: target >= 32 or target <= 1\n");
    }
    else if (is_number_correct(number, source))
    {
        printf("Error: wrong number or source numeral system (digit of number >= source)");
    }
    else if (source == target)
    {
        printf("%d\n", number);
    }
    else if (source == 10)
    {
        char target_number[34];
        printf("%s\n", from_10_numeral_system_to_target_numeral_system(number, target, target_number));
    }
    else if (target == 10)
    {
        printf("%d\n", from_source_numeral_system_to_10_numeral_system(source, number));
    }
    else
    {
        char target_number[34];
        printf("%s\n", from_10_numeral_system_to_target_numeral_system(from_source_numeral_system_to_10_numeral_system(source, number), target, target_number));
    }
}