import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < t; tc++) {
            int m = Integer.parseInt(br.readLine());
            int[] arr = new int[m];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            int maxPrice = 0;
            long profit = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (arr[i] > maxPrice)
                    maxPrice = arr[i];
                else
                    profit += maxPrice - arr[i];
            }

            System.out.println(profit);
        }
    }
}
