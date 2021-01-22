/*The goal of this problem is to find the last digit of nth fibonacci number
This is easy to do, just like in Fibonacci_Small, except only taking %10 of the number
This allows us to avoid integer overflows*/

using namespace std;

#include <iostream>
#include <vector>

int FibonacciEfficient(int n)
{
    //0,1,1,2,3,5...
    vector<int64_t> fibonacci_vector;
    fibonacci_vector.push_back(0);
    if(n>1) fibonacci_vector.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        fibonacci_vector.push_back((fibonacci_vector[i-1]+fibonacci_vector[i-2])%10);
    }
   /* for(int j = 1; j < n; j++)
    {
        cout << "fib(" << j <<") = " << fibonacci_vector[j] << "\n";
    }*/
    return fibonacci_vector[n];

}

int main()
{   
    int n;
    int result;
    cout << "Enter the nth fibonacci number of which to compute its last digit: \n";
    cin >> n;
    result = FibonacciEfficient(n);
    cout << "Last digit of the " << n <<"th Fibonacci number is : " << result << "\n";
    return 0;
}