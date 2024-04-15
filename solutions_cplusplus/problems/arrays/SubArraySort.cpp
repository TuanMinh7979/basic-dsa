#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"
using namespace std;

bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
    {
        return x > arr[1];
    }
    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }

    return x > arr[i + 1] or x < arr[i - 1];
}




void subarraySort(vector<int> arr)
{

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    if(smallest==INT_MAX){
       cout<<"LEFT INDEX IS -1 RIGHT INDEX IS -1";
    }

    int leftIdx= 0;
    while(smallest >= arr[leftIdx]){
        leftIdx++;
    }
    int rightIdx = arr.size()-1;
    while(largest <= arr[rightIdx]){
        rightIdx--;
    }
   cout<<"LEFT INDEX IS "<<leftIdx<<" RIGHT INDEX IS "<<rightIdx;
}

int main()
{

 vector<int> arr= {1, 2, 3, 4,5, 8,6,7, 9, 10,11};
 subarraySort(arr);
 
}