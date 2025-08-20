import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        String[] numbers = input.split("[+-]");

        List<Character> ops = new ArrayList<>();
        for (char c : input.toCharArray()) {
            if (c == '+' || c == '-')
                ops.add(c);
        }

        int result = Integer.parseInt(numbers[0]);
        int idx = 1;
        boolean minus = false;

        for (char op : ops) {
            int num = Integer.parseInt(numbers[idx++]);
            if (op == '-')
                minus = true;
            if (minus)
                result -= num;
            else
                result += num;
        }
        System.out.println(result);
    }
}
