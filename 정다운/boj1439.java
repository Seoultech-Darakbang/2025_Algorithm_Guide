import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = new String(br.readLine());

        char[] chars = str.toCharArray();
        int[] count = new int[2];
        if (chars[0] == '0')
            count[0]++;
        else
            count[1]++;

        for (int i = 1; i < chars.length; i++) {
            if (chars[i] != chars[i - 1]) {
                if (chars[i] == '0')
                    count[0]++;
                else
                    count[1]++;
            }
        }

        System.out.println(Math.min(count[0], count[1]));
    }
}
