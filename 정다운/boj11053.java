import java.util.*;
import java.io.*;

/*
 * 문제: 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10x, 30, 20x, 50} 이고, 길이는 4이다.

 * 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

 * 출력: 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
 * 
 * dp[n]: arr[n]으로 끝나는 가장 긴 증가하는 부분 수열의 길이
 * 점화식: if arr[i] > arr[j]: dp[i] = max(dp[i], dp[j]+1)
 */

public class boj11053 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp = new int[n];

        if (n == 1) {
            System.out.println(1);
            return;
        }

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }

        int length = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > length)
                length = dp[i];
        }
        System.out.println(length);
    }
}