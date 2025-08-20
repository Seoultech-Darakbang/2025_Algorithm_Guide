import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[] arr = new int[k];
        int max = 0;

        for (int i = 0; i < k; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            if (arr[i] > max)
                max = arr[i];
        }

        long start = 1;
        long end = max;
        long result = 0;

        while (start <= end) { // 이분 탐색 수행
            long mid = (start + end) / 2;

            long count = 0;
            for (int len : arr) { // 각 랜선마다 mid 길이로 잘랐을 때 최대 개수
                count += len / mid;
            }

            if (count < n) { // 자른 개수가 n보다 작으면 자르는 길이 줄임
                end = mid - 1;
            } else { // 자른 개수가 n보다 크거나 같으면 자르는 길이 늘림
                result = mid;
                start = mid + 1;
            }
        }

        System.out.println(result);
    }
}
