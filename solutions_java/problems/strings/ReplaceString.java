package solutions_java.problems.strings;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class ReplaceString {

    private static String replaceString(Character[] input) {

        int newAdditionalSpace = 0;
        for (int i = 0; i < input.length; i++) {
            if (input[i] == ' ') {
                newAdditionalSpace += 2;
            }
        }
        // create new arr with new len
        int newLen = input.length + newAdditionalSpace;
        Character[] rs = new Character[newLen];
        // start from right to left
        for (int i = input.length - 1; i >= 0; i--) {
            if (input[i].equals(' ')) {
                rs[newLen -= 1] = '0';
                rs[newLen -= 1] = '2';
                rs[newLen -= 1] = '%';

            } else {
                rs[newLen -= 1] = input[i];

            }

        }
        // count num of
        StringBuilder rsstr = new StringBuilder();
        for (int i = 0; i < rs.length; i++) {
            rsstr.append(rs[i]);
        }
        return rsstr.toString();
    }

    public static void main(String[] args) {

        Character[] charArr = { 'h', 'e', 'l', 'l', 'o', ' ', 'e', 'v', 'e', 'r', 'y', ' ', 'o', 'n', 'e' };
        System.out.println(replaceString(charArr));
    }

}
