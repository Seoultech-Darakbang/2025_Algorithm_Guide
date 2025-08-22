import java.util.*;
import java.io.*;

/* 문제: 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
 * 입력: 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
 * 출력: 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
 * 
 * 2xn 채우는 방법 = n-1 채운 상태 + 2x1 타일 하나 + n-2 채운 상태 + 1x2 타일 두개
*/

public class boj11726 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];

        if (n == 1) {
            System.out.println(1);
            return;
        }

        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
        }

        System.out.println(arr[n]);
    }
}
