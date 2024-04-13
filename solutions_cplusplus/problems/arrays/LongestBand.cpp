#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"

using namespace std;
// O(NlogN) + O(N)
int test1(vector<int> arr)
{

    // O(NlogN)
     sort(arr.begin(), arr.end());
    int maxLen = 0;

    int curCnt = 1;
    // O(N)
    for (int i = 0; i <= arr.size() - 2; i++)
    {

        if (arr[i + 1] == arr[i] + 1)
        {
            curCnt++;
        }
        else
        {

            maxLen = max(curCnt, maxLen);
            curCnt = 1;
        }
    }

    return maxLen;
}
//  O(N)
int test(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;

    for (int x : arr)
    {
        s.insert(x);
    }

    int maxLen = 1;
    int cnt = 1;
    for (auto ele : s)
    {
        int prevVal = ele - 1;
        if (s.find(prevVal) == s.end())
        {
            int nextVal = ele + 1;
            cnt = 1;
            while (s.find(nextVal) != s.end())
            {
                nextVal++;
                cnt++;
            }
            maxLen = max(cnt, maxLen);
        }
    }
    return maxLen;
}
int main()
{

    // vector<int> arr = {1, 2, 3, 6, 7, 8, 9, 15, 26};
    vector<int> arr = GenerateUtils::randomIntVector(10000, 1, 6000);
    double time = 0;
    double time1 = 0;
    time = Timer::timeTaken(test, arr);
    time1 = Timer::timeTaken(test1, arr);

    ArraysUtils::info(ArraysUtils::sort_indices(time, time1));
}