/*
You are given q queries in the form of a, b, and n. For each query, print the series corresponding to the given a, b, and b values as a single line of n space-separated integers.

Input Format

The first line contains an integer, q, denoting the number of queries.
Each line i of the q subsequent lines contains three space-separated integers describing the respective ai, bi, and ni values for that query.

Sample Input

2
0 2 10
5 3 5

Sample Output

2 6 14 30 62 126 254 510 1022 2046
8 14 26 50 98
*/

import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            
            for (int k = 0; k < n; k++) {
                    a += Math.pow(2, k)*b;
                    System.out.print(a +" ");
            }
            
            System.out.println();
        }
        in.close();
    }
}
