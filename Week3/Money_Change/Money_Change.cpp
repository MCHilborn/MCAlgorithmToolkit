/*
Design and implement a greedy algorithm
TASK: Find the minimum number of coins needed to change the input value into coins
with denominations 1, 5, and 10.
Input format: one integer m between 1 and 10000
Output format: The minimum number of coins with denominations 1, 5, 10 that changes m
*/

using namespace std;
#include <iostream>

int64_t  make_change(int m)
{
    int64_t arg = m;

    //lesson learned: cannot simply do ten_counter, five_counter, one_counter = 0
    int ten_counter = 0;
    int five_counter = 0;
    int one_counter = 0;

    //first, find out how many times 10 coins divides it
    while((ten_counter + 1) * 10 <= arg )
    {
        ++ten_counter;
        //cout << "Ten counter: " << ten_counter << "\n";
    }
    //now subtract those coins from the balance
    arg = (arg - 10*ten_counter);
    //cout << "After subtracting 10s amount is: " << arg << "\n";

    //next, find out how many times 5 coins divides the remaining balance
    while((five_counter + 1) * 5 <= arg)
    {
        ++five_counter;
        //cout << "Five counter: " << five_counter << "\n";
    }
    //subtract the coins from the five counter
    arg = (arg - 5*five_counter);
    //cout << "After subtracting 5s amount is: " << arg << "\n";

    
    //finally, count out how many 1 coins divides the last balance
    while((one_counter +1) * 1 <= arg)
    {
        ++one_counter;
        //cout << "One counter: " <<  one_counter << "\n";
    }

    return ten_counter + five_counter + one_counter;
}


int main()
{
    int64_t m, result;
    cout << "Enter the amount of money to change betwen 0 and 10000 \n";
    cin >> m;
    result = make_change(m);
    cout << "Number of coins: " << result << "\n";
    return 0;
}