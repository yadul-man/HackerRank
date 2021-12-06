/*
Input Format

Read some unknown n lines of input from stdin(System.in) until you reach EOF; each line of input contains a non-empty String.

Output Format

For each line, print the line number, followed by a single space, and then the line content received as input.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        int a = 1;
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            String s = sc.nextLine();
            System.out.println(a + " " + s);
            a++;
        }
    }
}
