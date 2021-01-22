/*Greatest Common Divisor
Find the greatest integer d that divides two non-negative numbers a, b (not both equal to 0)
Using the Euclidean algorithm*/


using namespace std;
#include <iostream>

int64_t GCD_Naive(int64_t a, int64_t b)
{
    //naive solution, computationally expensive
    //iterates from 1 to a+b
    //if it divides a and b it is a candidate
    //just find the highest number that divides both
    int64_t GCD;
    for(int64_t i = 1; i < a+b; i++)
    {
        if((a%i == 0) && (b%i == 0)) GCD = i;
    }
    return GCD;
}

int64_t Euclidean_Algorithm(int64_t a, int64_t b)
{
    int64_t t;
    if(b==0) return a;
    t = a%b;
    return(Euclidean_Algorithm(b,t));
}

int main()
{
    //sample input 28851538 1183019
    //sample output 17657
    int64_t a, b;
    int64_t result;
    cout << "Enter a and b" <<"\n";
    cin >> a >> b;
    result = Euclidean_Algorithm(a,b);
    cout << "GCD is : " << result << "\n";
    return 0;
}
