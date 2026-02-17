import java.io.*;
// import java.util.*;

public class Main {
    static int n;
    static int s;
    static int[] arrayN;
    static int count = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        s = Integer.parseInt(tmp[1]);

        tmp=br.readLine().split(" ");
        arrayN = new int[n];
        for(int i=0; i<n; i++) {
            arrayN[i] = Integer.parseInt(tmp[i]);
        }
        // 1개부터 n(최대20)개의 합까지 모든 경우의 수 파악 필요
        DFS(0, 0);
        if(s==0) count--; // 공집합 제외
        
        System.out.println(count);
    }

    public static void DFS(int index, int sum) {
        // 종료
        if(index ==n) {
            if(sum==s) {
                count++;
            }
            return;
        }
        
        // 현재 원소
        DFS(index+1, sum + arrayN[index]);

        // 다른 원소
        DFS(index+1, sum);
    }
}