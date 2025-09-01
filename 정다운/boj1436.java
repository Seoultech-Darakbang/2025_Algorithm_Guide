import java.util.*;
import java.io.*;

/*
 * 665부터 시작, 브루트포스 num을 string으로 변환해 666이 포함되어 있는지 확인 Integer.toString(num) -> String.valueOf(num)
 * Integer.toString() 메서드는 static 메서드(인스턴스X, 클래스 메서드)이고 null일 경우 NullPointerException 에러 발생시킴.
 * String.valueOf() 메서드는 오버로드된 static 메서드, null 체크 로직 포함됨.
 */

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int num = 665;
        int count = 0;
        while (count != n) {
            num++;
            if (String.valueOf(num).contains("666")) {
                count++;
            }
        }
        System.out.println(num);
    }
}
