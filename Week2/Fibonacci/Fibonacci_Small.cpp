using namespace std;

#include <iostream>
#include <vector>
//calculate small fibonacci numbers

//the long way of calculating a fibonacci number
//note: Fib(1) is 1 in this case. Some people define Fib(1) as 0.
int64_t FibonacciNaive(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return FibonacciNaive(n-1)+FibonacciNaive(n-2);
}
//a more efficient way to calculate fibonacci numbers
//create a list to store the successive numbers
//then calculate the fibonacci number based on the list
//NOTE: Only works up to the 91st fibonacci number before int64_t overflows
int64_t FibonacciEfficient(int n)
{
    int64_t current_number = 0;
    int64_t previous_number = 0;
    //1,1,2,3,5...
    vector<int64_t> fibonacci_vector;
    fibonacci_vector.push_back(0);
    if(n>1) fibonacci_vector.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        fibonacci_vector.push_back(fibonacci_vector[i-1]+fibonacci_vector[i-2]);
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
    int64_t result;
    int64_t result_efficient;
    cout << "enter a nth fibonacci number to calculate: \n";
    cin >> n;
    //result = FibonacciNaive(n);
    result_efficient = FibonacciEfficient(n);
    cout << n << "th Number is: " << result_efficient << "\n";
    return 0;
}