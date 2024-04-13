#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"
using namespace std;

//  o(NlogN)+o(N^2)= o(N^2)
vector<vector<int>> triplets(vector<int> arr, int sum)
{
    vector<vector<int>> rs;
    // o(NlogN)
    sort(arr.begin(), arr.end());
    int lstIdx = arr.size() - 1;

    // o(N^2)
    for (int i = 0; i <= lstIdx - 2; i++)
    {
        int j = i + 1;
        int k = lstIdx;
        while (j < k)
        {
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];

            if (currentSum == sum)
            {

                rs.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (currentSum > sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return rs;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int S = 17;

    auto ans = triplets(arr, S);

    ArraysUtils::info(ans);
    return 0;
}