//A number of items n must fit into a backpack with capacity W
//the values and the weights of the items are listed
//the i-th line contains integers v_i and w_i, the value and weight of the i-th item
//Constraints:
// 1<=n<=10e3, 0<=W<=2e6, 0<=v_1<=2e6, 0<w_i<2e6 for all 1<=i<=n
//all inputs are integers
//Output: the maximum value of fractions of items that fit into the napsack
//4 decimal place rounding

using namespace std;
#include <iostream>
#include <iomanip> //for formatting output
#include <vector>

float FillKnapsack(vector<int64_t> values, vector<int64_t> weights, int n, int W)
{
    //make a vector that holds the relative values of each item
    //value per unit weight
    vector<float> marginal_values(n);
    float most_valuable = 0;
    float current_weight = 0;
    float remaining_weight = W;
    float bag_value = 0; //value that the bag holds
    int largest_index = 0;
    for(int i = 0; i < n; i++)
    {
        marginal_values.push_back(float(values[i]/weights[i]));    
    }
    //now, find the (proportionally) most valuable item in this array
    //and place as much of it as you can in the bag
    //if you can fit all of it, add as much as you can as the next biggest item
    //repeat until the bag is full
    while(remaining_weight > 0)
    {
        for(int j = 0; j < n; j++) //find (proportionally) most valuable item
        {
            if (most_valuable < marginal_values[j]) 
            {
                most_valuable = marginal_values[j];
                largest_index = j; //so we can find the corresponding weight and value
                cout << "Largest index: " << j << "\n";
            }
        }
        if(current_weight+weights[largest_index] > W) //only take what you can fit, a fraction if you cannot
        {
            bag_value += (values[largest_index] * (remaining_weight/weights[largest_index]));
            //remaining_weight/weight[item] is the scaling factor
            //if the item is 300 and the remaning weight is 100, only 1/3 can fit
            current_weight += weights[largest_index]/remaining_weight;
        }
        else
        {
            bag_value += values[largest_index];
            current_weight += weights[largest_index];
        } 
        remaining_weight -= weights[largest_index];
        marginal_values.erase(marginal_values.begin()+largest_index); //ensure we don't repeat the item
    }
    


return bag_value;

}

int main()
{
    int n = 0;  //number of items
    int W = 0;  //weight of each item
    float Max_Value; //return of the function that finds the most value held
    int64_t v_i = 0;    //holder for each value for each item
    int64_t w_i = 0;    //holder for the weight of each item
    vector<int64_t> values(n); //holds list of values
    vector<int64_t> weights(n); //holds list of weights
    
    //fill the bag
    cout << "How many items? \n";
    cin >> n;
    cout << "How much weight can the bag hold? \n";
    cin >> W;
    //cout << "Entered " << n << " item values and weights";

    
    for(int i = 0; i < n; i++)
    {
        cout << "Enter a value and a weight \n";
        cin >> v_i >> w_i;
        values.push_back(v_i);
        weights.push_back(w_i);
    }
    Max_Value = FillKnapsack(values, weights, n, W);
    cout << "Maximum value: " << fixed << setprecision(4) << Max_Value << "\n";
    return 0;
}