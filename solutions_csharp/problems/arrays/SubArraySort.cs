using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
namespace problems.arrays
{

    class SubArraySort
    {

        private bool outOfOrder(List<int> arr, int idx)
        {
            int val = arr[idx];
            if (idx == 0)
            {
                return val > arr[idx + 1];
            }
            if (idx == arr.Count - 1)
            {
                return val < arr[idx - 1];
            }
            return val > arr[idx + 1] || val < arr[idx - 1];

        }
        public void subArraySort(List<int> arr)
        {
            int smallestVal = Int32.MaxValue;
            int largestVal = Int32.MinValue;
            for (int i = 0; i < arr.Count; i++)

            {
                if (outOfOrder(arr, i))
                {

                    smallestVal = Math.Min(smallestVal, arr[i]);
                    largestVal = Math.Max(largestVal, arr[i]);
                }

            }

            if (smallestVal == Int32.MaxValue)
            {
                Console.WriteLine("-1,-1");
                return;
            }
            int leftIdx = 0;
            int rightIdx = arr.Count - 1;

            while (arr[leftIdx]<=smallestVal )
            {
                leftIdx++;

            }
            while (largestVal <= arr[rightIdx])
            {
                rightIdx--;

            }

            Console.WriteLine("-----LEFT IDX IS: " + leftIdx + " RIGHT IDX IS: " + rightIdx);


        }

        public static void Solve()
        {
            List<int> arr = new List<int> {1, 2, 3, 4,5,6,7,8, 9, 10,11};
            new SubArraySort().subArraySort(arr);

        }
    }

}

