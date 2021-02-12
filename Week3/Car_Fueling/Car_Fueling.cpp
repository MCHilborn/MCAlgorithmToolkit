/*Car Fueling problem
Travelling to a city d miles away. You can travel at most m miles on a full tank
you start with a full tank.
Along the way there are gas stations
What is the minimum number of refills needed?

Input format:
First line: integer d, total distance
Second line: integer m, range of the car on a full tank
Third line: integer n, the number of gas stations
Fourth line: integers for the stop distances 1 through n, less than m

output format: the minimum number of refills needed
If it is not possible to reach the destination, return -1*/

using namespace std;
#include <iostream>
#include <vector>


long int travel(int distance, int range, vector<int64_t> stops)
{
    //initialize some conditions
    long int number_of_stops = 0;           //number of stops made on the trip, initially 0
    long int current_position = 0;          //where the car is along the array of stops, start at home
    long int previous_fill = 0;             //previous refill

    //procedure: make a "safe move"
    //see how many stops you can make before you run out of gas
    while(stops[current_position] < stops[stops.size()-1]) //stops.size() returns the number of elements, 1-indexed, we want the last element
    {
        //previous_fill = current_position; //update the previous stop made
        //this is required

        //ensure that your current position is before the end, and that the distance between the stops is less than the range
        while((stops[current_position] <  stops[stops.size()-1]) && ((stops[current_position+1]-stops[previous_fill]) <= range))
        {
            //cout << "Current position number: " << current_position << "\n";
            cout << "Distance from last fuelling at " << stops[previous_fill]  << " to next stop at: "<< stops[current_position+1] 
            << " is " << stops[current_position+1]-stops[previous_fill] << " miles \n";
            current_position++; //take as many steps as you can before range is emptied
            cout << "travelled to: " << stops[current_position] << "\n";
            //cout << "Previous fill at: " << stops[previous_fill] << "\n";  
        }
        if(stops[current_position] == stops[previous_fill]) //if the current position cannot be updated, the trip is impossible
        {
            return -1;
        }
        if(stops[current_position] <  stops[stops.size()-1]) //if we've made a stop but aren't at the end, update it.
        {
            number_of_stops +=1; //increment number of stops made
            previous_fill = current_position; //update the place the stop was made
            cout << "Filled up at: " << stops[previous_fill] << "\n";
        }

    }
    return number_of_stops;

}
int main()
{
    int d, n, m;
    cout << "Enter the trip distance: \n";
    cin >> d;
    cout << "Enter the range of the car on a full tank: \n";
    cin >> m;
    cout << "Enter the number of gas stations: \n";
    cin >> n;

    vector<int64_t> stops(n+2); //4 stops plus 0 and end destination
    stops[0] = 0; //start at 0km
    stops[n+1] = d; //final position is at trip distance
    for(int i = 1; i <= n; i++)
    {
        cout << "Enter the location of station " << i << ": \n";
        cin >> stops[i];
        //possible errors: Stops out of order, or beyond the end of the trip
        while((stops[i] > d) || (stops[i] <= stops[i-1]))
        {
            while (stops[i] > d)
            {
                cout << "Stop must be before the end, enter a new one \n";
                cin >> stops[i];
            }
             while(stops[i] <= stops[i-1])
            {
                cout << "Stops must be sequential, enter a new one \n";
                cin >> stops[i];
            }
        }
       
    }
    
    int number_of_stops = travel(d,m,stops); //run the algorithm

    if(number_of_stops < 0 ) 
    {
        cout << "Trip is impossible. \n";
    }
    else cout << "Minimum number of stops: " << number_of_stops << "\n";

    return 0;
    
}