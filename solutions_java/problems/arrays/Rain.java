package solutions_java.problems.arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Rain {

    private static int trappedWater(List<Integer> heights) {

        int n = heights.size();
        // store the nearest left max value
        List<Integer> left = new ArrayList<>(Collections.nCopies(heights.size(), 0));
        // store the nearest right max value
        ArrayList<Integer> right = new ArrayList<>(Collections.nCopies(heights.size(), 0));
        left.add(heights.get(0));
        right.set(n-1, heights.get(n-1));

        // create data for lists
        for (int i = 1; i <= n-1; i++) {
            left.set(i, Math.max(left.get(i - 1), heights.get(i)));
            right.set(n-(i+1), Math.max(right.get(n-i ), heights.get(n - (i+1))));
        }

        int rs=0;
        for (int j = 0; j <= n-1; j++) {
            rs+=(Math.min(left.get(j),right.get(j))-heights.get(j));
        }

        return rs;
    }

    public static void main(String[] args) {
        List<Integer> water = Arrays.asList(0, 1, 2, 5, 1, 3);
        System.out.println(trappedWater(water));
    }

}
