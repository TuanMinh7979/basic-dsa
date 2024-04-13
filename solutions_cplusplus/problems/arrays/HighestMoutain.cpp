#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"
using namespace std;

//  o(N^2)
int highestMoutain(vector<int> arr)
{



    int lstIdx = arr.size() - 1;
    int maxLen = 0;
    for (int i = 1; i <= lstIdx - 1; i++)
    {

        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            int j = i;
            int cnt = 1;
            while (j >= 1 && arr[j - 1] < arr[j])
            {
                cnt++;
                j--;
            }
            j = i;
            while (j <= lstIdx - 1 && arr[j] >= arr[j + 1])
            {
                cnt++;
                j++;
            }

            maxLen = max(maxLen, cnt);
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highestMoutain(arr);
    return 0;
}