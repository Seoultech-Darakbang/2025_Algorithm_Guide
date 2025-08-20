import java.util.*;
import java.io.*;

/*
 * scores 배열에 각 계단의 점수 저장
 * dp 배열에 각 계단까지 얻을 수 있는 최댓값 저장
 * dp[i] = 최대(i-2번 최대값 + i계단 점수, i-1번 최대값 + i계단 점수)
 * 
 * 조건: 연속된 세 개의 계단을 모두 밞아서는 안 된다.
 * 조건 적용한 점화식
 * dp[i] = 최대(2칸점프한 값, 2칸점프 -> 1칸 점프한 값)
 */

public class boj2579 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numStairs = Integer.parseInt(br.readLine());
        int[] scores = new int[numStairs + 1];

        for (int i = 1; i <= numStairs; i++) {
            scores[i] = Integer.parseInt(br.readLine());
        }

        if (numStairs == 0) {
            System.out.println(0);
            return;
        } else if (numStairs == 1) {
            System.out.println(scores[1]);
            return;
        }

        int[] dp = new int[numStairs + 1];
        dp[1] = scores[1];
        dp[2] = scores[1] + scores[2];
        for (int i = 3; i <= numStairs; i++) {
            int path1 = dp[i - 2] + scores[i];
            int path2 = dp[i - 3] + scores[i - 1] + scores[i];
            dp[i] = Math.max(path1, path2);
        }

        System.out.println(dp[numStairs]);
    }
}
