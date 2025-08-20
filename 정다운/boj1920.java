import java.util.*;
import java.io.*;

public class Main {
    // 이진 탐색을 수행하는 함수
    public static int binarySearch(int[] arr, int start, int end, int k) {
        if (start > end) // 탐색 실패 시 0 반환
            return 0;

        int mid = start + (end - start) / 2;
        if (k < arr[mid]) {
            return binarySearch(arr, start, mid - 1, k);
        } else if (k > arr[mid]) {
            return binarySearch(arr, mid + 1, end, k);
        } else if (k == arr[mid]) {
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arrA = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arrA[i] = Integer.parseInt(st.nextToken());
        }
        // 이진 탐색 수행 전 배열 오름차순 정렬
        Arrays.sort(arrA);

        int m = Integer.parseInt(br.readLine());
        int[] arrB = new int[m];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            arrB[i] = Integer.parseInt(st.nextToken());
            System.out.println(binarySearch(arrA, 0, n - 1, arrB[i]));
        }
    }
}
