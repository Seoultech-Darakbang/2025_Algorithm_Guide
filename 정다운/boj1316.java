import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * 문제: https://www.acmicpc.net/problem/1316
 * 그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
 * 입력: 첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
 * 
 * 출력: 첫째 줄에 그룹 단어의 개수를 출력한다.
 */

public class boj1316 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int groupWordCount = 0;

        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            if (isGroupword(word))
                groupWordCount++;
        }

        System.out.println(groupWordCount);
    }

    public static boolean isGroupword(String word) {
        boolean[] check = new boolean[26];
        char prevChar = ' ';

        for (int i = 0; i < word.length(); i++) {
            char currentChar = word.charAt(i);
            if (prevChar != currentChar) {
                if (check[currentChar - 'a'] == true)
                    return false;
                else {
                    check[currentChar - 'a'] = true;
                    prevChar = currentChar;
                }
            }
        }

        return true;
    }
}