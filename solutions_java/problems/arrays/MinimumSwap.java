package solutions_java.problems.arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Pair {
    private int val;
    private int idx;

    public Pair(int val, int idx) {
        this.val = val;
        this.idx = idx;
    }

    public int getFirst() {
        return val;
    }

    public int getSecond() {
        return idx;
    }

}

public class MinimumSwap {

    private int countMinSwaps(List<Integer> arr) {
        int n = arr.size();
        List<Pair> pairs = new ArrayList<Pair>();

        for (int i = 0; i < arr.size(); i++) {
            pairs.add(new Pair(arr.get(i), i));

        }

        
        Collections.sort(pairs, 
        (o1, o2) -> Integer.valueOf(o1.getFirst()).compareTo(Integer.valueOf(o2.getFirst())));
        // idx: 2-1-4-3-0
        boolean[] visited = new boolean[n];
        int ans = 0;

        for (int i = 0; i < pairs.size(); i++) {
            int oldPosition = pairs.get(i).getSecond();
// compare index before sorting(oldPosition) and new index (i)
            if (visited[i] == true || oldPosition == i) {
                continue;
            }

            int curPos = i;
            int cycle = 0;
            while (!visited[curPos]) {
                visited[curPos] = true;
                int nextPos = pairs.get(curPos).getSecond();
                curPos = nextPos;
                cycle += 1;
            }

            ans += (cycle - 1);

        }

        return ans;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(6,2, 1, 4, 3);
        
        // oval: 6|2|1|4|3
        // oidx: 0|1|2|3|4

        // nval: 1|2|3|4|6
        // nidx: 2|1|4|3|0
        MinimumSwap minimunSwap = new MinimumSwap();
        System.out.println(minimunSwap.countMinSwaps(arr));

    }

}
