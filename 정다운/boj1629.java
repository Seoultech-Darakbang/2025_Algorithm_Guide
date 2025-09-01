import java.util.*;
import java.io.*;

public class Main {
    // a^b%c를 구하는 함수
    public static int power(int a, int b, int c) {
        if (b == 1) { // 1제곱이면 a % c 반환
            return a % c;
        }

        int half = power(a, b / 2, c);
        int result = (int) (((long) half * half) % c);
        // b/2 제곱으로 나누어 재귀 호출

        if (b % 2 == 1) { // b가 홀수면 a를 한 번 더 곱해줌
            result = (int) (((long) result * a) % c);
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        System.out.println(power(a, b, c));
    }
}
