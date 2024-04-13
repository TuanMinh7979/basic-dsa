using System;
using System.Collections.Generic;
namespace problems.arrays
{

    class Rain
    {
        public static int TrappedWater(List<int> heights)
        {
            int n = heights.Count;
            // Store the nearest left max value
            List<int> left = new List<int>(new int[n]);
            // Store the nearest right max value
            List<int> right = new List<int>(new int[n]);
            left[0] = heights[0];
            right[n - 1] = heights[n - 1];

            // Create data for lists
            for (int i = 1; i < n; i++)
            {
                left[i] = Math.Max(left[i - 1], heights[i]);
            }
            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = Math.Max(right[i + 1], heights[i]);
            }

            int rs = 0;
            for (int j = 0; j < n; j++)
            {
                rs += Math.Min(left[j], right[j]) - heights[j];
            }

            return rs;
        }

       public static void Solve()
        {
            List<int> water = new List<int> { 0, 1, 2, 5, 1, 3 };
            Console.WriteLine(TrappedWater(water));
        }
    }

}

