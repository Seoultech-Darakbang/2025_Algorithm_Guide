import java.util.*;
import java.io.*;

/*
 * DP
 * n을 1, 2, 3의 합으로 나타내는 방법의 수를 배열에 저장 
 * dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
 */

public class boj9095 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            int n = Integer.parseInt(br.readLine());
            int[] dp = new int[n + 1];
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            for (int j = 4; j <= n; j++) {
                dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
            }
            System.out.println(dp[n]);
        }
    }
}
