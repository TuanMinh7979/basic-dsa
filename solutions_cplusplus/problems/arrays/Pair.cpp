#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"
using namespace std;
vector<int> test2(vector<int> arr, int sum)
{

  //    O(n2)
  vector<int> rs;
  // int complexCmd = 0;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {

      // complexCmd++;
      if (arr[i] != arr[j] && arr[i] + arr[j] == sum)
      {

        rs.push_back(arr[i]);
        rs.push_back(arr[j]);

        // cout << "C-TEST2 COMPLEXCMD : " << complexCmd << endl;

        return rs;
      }
    }
  }

  // cout << "C-TEST2 COMPLEXCMD : " << complexCmd << endl;
  return rs;
}
vector<int> test1(vector<int> arr, int sum)
{
  // int complexCmd = 0;
  //    O(NlogN)
  vector<int> rs;

  sort(arr.begin(), arr.end()); // Sort the vector  O(NlogN)
  int target = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    // complexCmd++;
    //  O(NlogN) using binary search

    target = sum - arr[i];
    if (target != arr[i])
    {
      auto it = std::lower_bound(arr.begin(), arr.end(), target);

      // Kiểm tra nếu phần tử được tìm thấy và in ra index nếu tìm thấy
      if (it != arr.end() && *it == target)
      {

        rs.push_back(arr[i]);
        rs.push_back(*it);
        // cout << "B-TEST1 COMPLEXCMD : " << complexCmd << endl;
        return rs;
      }
    }
  }
  // cout << "B-TEST1 COMPLEXCMD : " << complexCmd << endl;

  return rs;
}

vector<int> newTest(vector<int> arr, int targetSum)
{
  unordered_set<int> complements;

  for (int i = 0; i < arr.size(); i++)
  {
    int complement = targetSum - arr[i];
    if (complements.find(complement) != complements.end())
    {
      // Tìm thấy cặp số có tổng bằng targetSum
      return vector<int>{complement, arr[i]};
    }
    complements.insert(arr[i]);
  }

  // Không tìm thấy cặp số nào có tổng bằng targetSum
  return vector<int>();
}

// O(n) without sorting (o(NLogN))
std::vector<int> test(vector<int> arr, int sum)
{
  // int complexCmd = 0;
  unordered_set<int> s;
  vector<int> rs;

  for (int i = 0; i < arr.size(); i++)
  {
    // complexCmd++;
    int target = sum - arr[i];
    if (s.find(target) != s.end())
    {

      rs.push_back(arr[i]);
      rs.push_back(target);
      // cout << "A-TEST COMPLEXCMD : " << complexCmd << endl;
      return rs;
    }

    s.insert(arr[i]);
  }
  // cout << "A-TEST COMPLEXCMD : " << complexCmd << endl;
  return rs;
}

// FOR TESTING:
template <typename T>
void totalTestCaseRs(std::vector<int> &totalResult, std::vector<T> (*func)(std::vector<T>, int), std::vector<T> arr, int sum)
{
  std::vector<T> result = func(arr, sum);
  totalResult.insert(totalResult.end(), result.begin(), result.end());
}
int main()
{

  int maxRandomVal = 2000;
  int randomSize = 1500;
  int caseNum = 1500;
  vector<int> arr = GenerateUtils::randomIntVector(randomSize, 1, maxRandomVal);
  ArraysUtils::info(arr);

  double time = 0;
  double time1 = 0;
  double time2 = 0;

  int S = 0;
  for (int i = 0; i < caseNum; i++)
  {
    S = GenerateUtils::randomPick(arr) + 50;
    time += Timer::timeTaken(newTest, arr, S);
    time1 += Timer::timeTaken(test1, arr, S);
    time2 += Timer::timeTaken(test2, arr, S);
    cout << "............." << time + 1 << ">>>" << time1 + 1 << ">>" << time2 + 1 << endl;
  }

  ArraysUtils::info(ArraysUtils::sort_indices(time, time1, time2));
  // ---
}
