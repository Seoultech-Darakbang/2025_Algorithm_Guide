import java.util.*;
import java.io.*;

/*
 * DP
 * 배열 최소 회수 저장, X-1, X/2, X/3를 1로 만드는 최소 회수 재활용
 */

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());

        int[] dp = new int[num + 1];
        for (int i = 2; i <= num; i++) {
            dp[i] = dp[i - 1] + 1;

            if (i % 2 == 0)
                dp[i] = Math.min(dp[i], dp[i / 2] + 1);
            if (i % 3 == 0)
                dp[i] = Math.min(dp[i], dp[i / 3] + 1);
        }
        System.out.println(dp[num]);
    }
}
