//this program finds the greatest product of two numbers in an array of numbers
//input: n, followed by n digits
//output: the greatest product of two of those digits
#include <iostream>
#include <random>
#include <vector>

int64_t maxPairwiseProduct(const std::vector<int64_t>& numbers) //trivial, inefficient solution
{
    //simply find the product of every combo and find the max number
    int64_t product = 0;
    int64_t n = numbers.size(); //call the size of the vector
    for (int64_t i = 0; i < n; ++i)
    {
        for (int64_t j = i+1; j<n; ++j)
        {
            product = std::max(product,numbers[i]*numbers[j]);
        }
    }
    return product;
}

int64_t maxPairwiseFast(const std::vector<int64_t>& numbers)
{   
    //2n-1 comparisons
    //finds the two largest numbers in the vector
    //find the largest element in the vector
    int64_t largest_number = 0;
    int64_t largest_index = 0;
    int64_t second_largest_number = 0;
    int64_t n = numbers.size();
    int64_t product = 0;
    for(int64_t i = 0; i < n; ++i)
    {
        if (numbers[i] > largest_number)
        {
            largest_number = numbers[i];
            largest_index = i;
        }
    }
    //skip over the element found at the previous scan for the next number
    for (int64_t i = 0; i < n ; ++i)
    {
        if((i != largest_index) && (numbers[i] > second_largest_number))
        {
            second_largest_number = numbers[i];
        }
    }
   // std::cout << "Fast Highest number: (i) " << largest_index << " " << largest_number << "\n";
   // std::cout << "Fast Second highest number: " << second_largest_number << "\n";
    product = largest_number * second_largest_number;
    return product;
}


int64_t maxPairwiseFaster(const std::vector<int64_t>& numbers)
{
    //compare each element i with its neighbor 2i, 0.5n comparisons
    //swap them to (high,low) pairs
    //then compare only the first elements to find the largest, 0.5n comparisons
    //then compare the other (high) elements, plus the (high, low) pair
    //for another 0.5n+1 comparisons
    //total 1.5n+1 comparisons
    int64_t n = numbers.size();
    int64_t largest_number = 0;
    int64_t second_largest_number = 0;
    int64_t highest_index = 0; //index of highest number

    //array for sorting the pairs
    std::vector<int64_t> sorted_numbers(n);
    for (int64_t i = 0; 2*i < n; ++i)
    {
        //compare a pair of numbers (2i,2i+1) (referred to as x, y)
        if(numbers[2*i] < numbers[2*i+1])  //if x is smaller than y, swap
        {
            sorted_numbers[2*i] = numbers[2*i+1];
            sorted_numbers[2*i+1] = numbers[2*i];
        }
        else 
        {
            sorted_numbers[2*i] = numbers[2*i];
            sorted_numbers[2*i+1] = numbers[2*i+1];
        }
    }
    //find largest number by searching each even element (0->n-1)
    for(int64_t j = 0; 2*j < n; ++j) 
    {
        if(sorted_numbers[2*j] > largest_number)
        {
            largest_number = sorted_numbers[2*j];
            highest_index = 2*j;
        }
    }
    //now compare the other even (2n) elements to find second largest number
    for (int64_t k = 0; 2*k < n; ++k)
    {
        //std::cout << " sorted_numbers[2*k] " << sorted_numbers[2*k] << "\n";
        //std::cout << "second_largest_number: " << second_largest_number << "\n";
        //ensure we don't get the same largest number
        if((2*k != highest_index) && (sorted_numbers[2*k] > second_largest_number))
        {
            second_largest_number = sorted_numbers[2*k];
        }
        //std::cout << "Faster Second highest number: (k) " << k << " " << second_largest_number << "\n";
    }
    //also +1 comparison with the number in the pair with the largest number
    if (sorted_numbers[highest_index+1] > second_largest_number)
    {
        second_largest_number = sorted_numbers[highest_index+1];
    }
    /*for (int m = 0; m < n; ++m)
    {
        std::cout << "numbers[" << m << "] " << numbers[m] << "\n";
    }

    for (int l = 0; l < n; ++l)
    {
        std::cout << "sorted_numbers[" << l << "] " << sorted_numbers[l] << "\n";
    }*/

    int64_t product = largest_number * second_largest_number;

    //std::cout << "Faster Highest number: " << largest_number << "\n";
    //std::cout << "Faster Second highest number: " << second_largest_number << "\n";
    //std::cout << "Faster product of the highest numbers: " << product << "\n";
    return product;
}

void stressTest()
{
    //see if output is the same for both functions
    
    //some test sets:
    //std::vector<int64_t> numbers{68165, 87637, 74297, 2904, 32873, 86010, 
    //87637, 66131, 82858, 82935};
    //std::vector<int64_t> numbers{2, 9, 3, 1, 9}

    //random test set with seed:
    int n;
    int s;
    std::cout << "Enter a seed: " << "\n";
    std::cin >> s;
    std::cout << "Enter a number of digits to compare: " << "\n";
    std::cin >> n;
    srand(s);
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand();
    }
    int64_t first_result = maxPairwiseProduct(numbers);
    int64_t second_result = maxPairwiseFast(numbers);
    int64_t third_result = maxPairwiseFaster(numbers);

    if(first_result == second_result && second_result == third_result) 
    {
        std::cout << "all three work." << "\n";
        std::cout << "first result: " << first_result << "\n";
        std::cout << "second result: " << second_result << "\n";
        std::cout << "third result: " << third_result << "\n";
    }
    else std::cout << "wrong " << first_result << " " << second_result << " " << third_result << "\n"; 
}

int main()
{
    /*int64_t n = 2e5;
    //load the vector with 1 to 2e5
    std::vector<int64_t> numbers(n); //vector called numbers of size n
    for (int64_t i = 1; i <= n; i++)
    {
        numbers[i-1] = i;
    }
    int64_t product = maxPairwiseFast(numbers);
    */
    stressTest();
    //std::cout << "Max Pair product " << product << "\n";
    return 0;
}