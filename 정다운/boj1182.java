import java.util.*;
import java.io.*;

/*
 * (idx, sum) 을 매개변수로 가지는 백트래킹 함수 이용,
 *  모든 부분집합 탐색 S = 0 일 경우 공집합일 때도 해당되므로 count--로 조정 필요
 */

public class Main {
    static int count = 0;
    static int n, s;
    static int[] arr;

    public static void backTracking(int idx, int sum) {
        if (idx == n) {
            if (sum == s)
                count++;
            return;
        }

        backTracking(idx + 1, sum + arr[idx]);
        backTracking(idx + 1, sum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        backTracking(0, 0);

        if (s == 0)
            count--;
        System.out.println(count);
    }
}
