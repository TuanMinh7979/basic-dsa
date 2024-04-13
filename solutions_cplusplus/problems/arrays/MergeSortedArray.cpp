#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"

using namespace std;

vector<int> mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> rs;
    int i = 0, j = 0;

    int minSize = min(arr1.size(), arr2.size());
    while (i <minSize)
    {
        if (arr1[i] <= arr2[j])
        {
            rs.push_back(arr1[i]);
            i++;
        }
        else
        {
            rs.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        rs.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        rs.push_back(arr2[j]);
        j++;
    }

    return rs;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    vector<int> rs = mergeSortedArrays(arr1, arr2);

    cout << "Merged array: ";
    for (int num : rs)
    {
        cout << num << " ";
    }
    cout << endl;
    

    return 0;
}
