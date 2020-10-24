long get_fibbonachi_via_recursion(int number);

int main()
{
    return 0;
}

long get_fibbonachi_via_recursion(int number)
{
    if (number == 1)
    {
        return 0;
    }
    else if (number == 2)
    {
        return 1;
    }
    else
    {
        return get_fibbonachi_via_recursion(number - 2) + get_fibbonachi_via_recursion(number - 1);
    }
}