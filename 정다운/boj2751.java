import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

/*
 * 문제: N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * 입력: 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
 * 
 * 출력: 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 * 
 * 우선순위 큐 사용나 Collections.sort() 단일 사용 --> 시간 초과
 * stringbuilder 사용해 출력
 * 
 * 자바에서 String은 불변(immutable), 문자열끼리 + 연산 시 두 문자열이 복사되어 새로운 문자열 객체가 생성, 시간과 메모리 낭비 발생함. StringBuilder는 가변(mutable)으로 새로운 객체 생성이나 복사 과정이 없음.
 * 
 * 우선순위 큐 사용 --> 메모리 156640KB, 시간 1484ms
 * Collections.sort() 사용 --> 메모리 129616KB, 시간 1316ms
 */

public class boj2751 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        // PriorityQueue<Integer> pq = new PriorityQueue<>();
        // while (N-- > 0)
        // pq.add(Integer.parseInt(br.readLine()));

        // StringBuilder sb = new StringBuilder();

        // while (!pq.isEmpty())
        // sb.append(pq.poll()).append('\n');

        // System.out.print(sb);

        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(arr);

        StringBuilder sb = new StringBuilder();

        for (int value : arr) {
            sb.append(value).append('\n');
        }

        System.out.print(sb);
    }
}
