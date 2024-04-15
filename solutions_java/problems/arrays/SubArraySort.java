package solutions_java.problems.arrays;

import java.util.Arrays;
import java.util.List;

public class SubArraySort {
     boolean outOfOrder(List<Integer> arr, int idx) {
        int val = arr.get(idx);
        if (idx == 0) {
            return val > arr.get(1);
        }
        if (idx == arr.size() - 1) {
            return val < arr.get(idx - 1);
        }

        return val > arr.get(idx + 1) || val < arr.get(idx - 1);
    }

     void subarraySort(List<Integer> arr) {
        int smallestVal = 1000;
        int largestVal = -1000;
        for (int i = 0; i < arr.size(); i++) {
            int val = arr.get(i);
            if (outOfOrder(arr, i)) {
                smallestVal = Math.min(smallestVal, val);
                largestVal = Math.max(largestVal, val);
            }

        }
        if (smallestVal == Integer.MAX_VALUE) {
            System.out.println("LEFT INDEX IS -1, RIGHT INDEX IS -1");
        }
        int left = 0;
        int right = arr.size() - 1;

        while (arr.get(left) <= smallestVal) {

            left++;
        }

        while (arr.get(right) >= largestVal) {
            right--;
        }

        System.out.println("LEFT IDX IS " + left + " RIGHT IDX IS " + right);

    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11);
        new SubArraySort().subarraySort(arr);
    }

}
