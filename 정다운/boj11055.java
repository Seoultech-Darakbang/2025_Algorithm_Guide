import java.util.*;
import java.io.*;

/*
 * 문제: 수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가하는 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

 * 입력: 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

 * 출력: 첫째 줄에 수열 A의 합이 가장 큰 증가하는 부분 수열의 합을 출력한다.
 * 
 * dp[n]: n번째 까지의 부분 수열 최대 합
 * 점화식: if arr[i] > arr[j]: dp[i] = max(dp[i], dp[j]+arr[i])
 */

public class boj11055 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp = new int[n + 1];

        if (n == 1) {
            System.out.println(arr[n]);
            return;
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = arr[i];
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (arr[i] > arr[j])
                    dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            }
        }

        int max = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] > max)
                max = dp[i];
        }
        System.out.println(max);
    }
}