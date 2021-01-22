/*Find the least common multiple of two positive integers a,b
//find the least positive integer m that is divisible by both a and  b*/
//sample input: 761457 614573
//sample output: 467970912861

using namespace std;
#include <iostream>
#include "GCD.h"

int64_t LCM(int64_t a, int64_t b)
{
    //a novel solution is using the greatest common factor
    //find the GCF with the Euclidean Algorithm
    //then find the product of a and b and divide it by GCF
    int64_t Greatest_Common_Denominator;
    Greatest_Common_Denominator = Euclidean_Algorithm(a,b);
    return a*b/Greatest_Common_Denominator;
}

int main()
{   
    int64_t a, b;
    int64_t Lo_com_mult;
    cout << "Enter numbers to find GCD: " << "\n";
    cin >> a >> b;
    Lo_com_mult = LCM(a,b);
    cout << "LCM: " << Lo_com_mult << "\n";
    return 0;
}