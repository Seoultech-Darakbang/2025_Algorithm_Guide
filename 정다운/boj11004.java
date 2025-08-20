import java.util.*;
import java.io.*;

// 1, Array sort을 사용하는 솔루션,
// 메모리 377,864kb, 시간 1940ms 소요
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }



        Arrays.sort(arr);
        System.out.println(arr[k - 1]);
    }
}



// 2. quick select, 랜덤피벗를 사용하는 솔루션
// 시간 초과
// public class Main {
// public static void swap(int[] arr, int indexA, int indexB) {
// int temp = arr[indexA];
// arr[indexA] = arr[indexB];
// arr[indexB] = temp;
// }

// // left~right 부분을 피벗 기준으로 정렬하는 함수
// public static int partition(int[] arr, int left, int right) {
// int pivotIndex = left + (int) (Math.random() * (right - left + 1));
// swap(arr, pivotIndex, right); // 피벗을 맨 뒤로 보내기
// int pivot = arr[right];
// int i = left;
// for (int j = left; j < right; j++) {
// if (arr[j] <= pivot) {
// swap(arr, i, j);
// i++;
// }
// }
// swap(arr, i, right); // 피벗을 확정 위치로 이동
// return i;
// }

// // k번째로 큰 값을 찾는 함수
// public static void quickSelect(int[] arr, int left, int right, int k) {
// if (left < right) {
// int pivotIndex = partition(arr, left, right);

// if (pivotIndex == k) {
// System.out.println(arr[k]);
// return;
// } else if (k < pivotIndex) {
// quickSelect(arr, left, pivotIndex - 1, k);
// } else {
// quickSelect(arr, pivotIndex + 1, right, k);
// }
// } else if (left == right && left == k) {
// System.out.println(arr[k]);
// }

// }

// public static void main(String[] args) throws IOException {
// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// StringTokenizer st = new StringTokenizer(br.readLine());

// int n = Integer.parseInt(st.nextToken());
// int k = Integer.parseInt(st.nextToken());

// st = new StringTokenizer(br.readLine());

// int[] arr = new int[n];

// for (int i = 0; i < n; i++) {
// arr[i] = Integer.parseInt(st.nextToken());
// }

// quickSelect(arr, 0, n - 1, k - 1);
// }
// }
