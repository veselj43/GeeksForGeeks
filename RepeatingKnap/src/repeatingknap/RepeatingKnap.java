package repeatingknap;

import java.util.*;
import java.lang.*;
import java.io.*;

/**
 *
 * @author Jaroslav Vesely
 */
public class RepeatingKnap {
    
    public static void main(String[] args) {
        RepeatingKnap repeatingKnap = new RepeatingKnap();
    }
    
    private RepeatingKnap() {
        Scanner knapIn = new Scanner(System.in);

        String line;
        int T, N, W;
        int[] val, wt;

        line = knapIn.nextLine().trim();

        T = Integer.parseInt(line);

        for (int t = 0; t < T; t++) {

            line = knapIn.nextLine();
            String[] data = line.split(" ");

            N = Integer.parseInt(data[0]);
            W = Integer.parseInt(data[1]);
        
            val = new int[N];
            wt = new int[N];

            line = knapIn.nextLine();
            parseArrayLine(line, val);

            line = knapIn.nextLine();
            parseArrayLine(line, wt);
            
            System.out.println(solve(W, N, val, wt));

        }
    }
    
    public void parseArrayLine(String line, int[] array) {
        String[] data = line.trim().split(" ");

        for (int i = 0; i < data.length; i++) {
            array[i] = Integer.parseInt(data[i]);
        }
    }
    
    public int bestOf(int v1, int v2, int v3) {
        return (v1 > v2 && v1 > v3) ? v1 : (v2 > v3) ? v2 : v3;
    }
    
    public int solve(int W, int N, int[] val, int[] wt) {
        int best = 0;
        
        int size = N;
        
        int[][] cache = new int[size][W+1];
        int down, left, add;
        
        for (int i = 0; i < size; i++) {
            for (int w = 0; w <= W; w++) {
                down = (w == 0) ? 0 : cache[i][w - 1];
                left = (i == 0) ? 0 : cache[i - 1][w];
                add = (w - wt[i] < 0) ? 0 : cache[i][w - wt[i]] + val[i];
                
                cache[i][w] = bestOf(add, down, left);
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (best < cache[i][W]) best = cache[i][W];
        }
        
        return best;
    }

}
