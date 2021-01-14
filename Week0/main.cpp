
#include <iostream>

int add_two_numbers(int c, int d)
{
    int sum = c + d;
    return sum;
}

int main()
{
    int a = 0;
    int b = 0;
    int sum = 0;
    std::cin >> a;
    std::cin >> b;
    sum = add_two_numbers(a,b);
    std::cout << sum;
    return 0; 
}