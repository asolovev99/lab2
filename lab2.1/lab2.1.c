long long get_fibbonachi_via_cycle(int number);

int main()
{
    return 0;
}

long long get_fibbonachi_via_cycle(int number)
{
    int first = 0;
    int second = 1;

    if (number == 1)
    {
        return first;
    }
    for (int i = 3; i <= number; i++)
    {
        second = first + second;
        first = second - first;
    }

    return second;
}