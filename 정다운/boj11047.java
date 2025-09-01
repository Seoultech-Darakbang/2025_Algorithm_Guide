import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int numberOfCoin = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] <= k) {
                numberOfCoin += k / arr[i];
                k %= arr[i];
            }
        }

        System.out.println(numberOfCoin);
    }
}
