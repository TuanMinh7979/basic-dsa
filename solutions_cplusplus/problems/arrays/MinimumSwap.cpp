#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"

using namespace std;


int countMinSwaps( vector<int> arr)
{

   int n = arr.size();
    pair<int, int> valIdxPairs[n];
    for (int i = 0; i < n; i++)
    {
        valIdxPairs[i].first = arr[i];
        valIdxPairs[i].second = i;
    }
    sort(valIdxPairs, valIdxPairs + n);
    vector<bool> visited(n, false);
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        // if element is visited or element is in good position
        int oldPosition = valIdxPairs[i].second;
        if (visited[i] == true or oldPosition == i)
        {
            continue;
        }

        int curPosition = i;
        int cycle = 0;
        while (!visited[curPosition]){
            visited[curPosition]= true;
            int nextPosition= valIdxPairs[curPosition].second;
            curPosition=nextPosition;
            cycle+=1;
        }

        ans+=(cycle-1);
    }

    return ans;
}

int main(){
    vector<int> arr = {3, 1, 2};
    cout<<countMinSwaps(arr);

}