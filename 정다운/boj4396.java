import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/*
     * 문제:
     * 입력: 첫 번째 줄에는 10보다 작거나 같은 양의 정수 n이 입력된다. 다음 n개의 줄은 지뢰의 위치를 나타낸다. 각각의 줄은 n개의
     * 문자를 사용하여 한 행을 나타낸다. 온점(.)은 지뢰가 없는 지점이며 별표(*)는 지뢰가 있는 지점이다. 다음 n개의 줄에는 길이가 n인
     * 문자열이 입력된다. 이미 열린 칸은 영소문자 x로, 열리지 않은 칸은 온점(.)으로 표시된다. 예제 입력은 문제 설명에서의 가운데 그림과
     * 상응한다.
     * 
     * 출력: 출력은 각각의 위치가 정확하게 채워진 판을 표현해야 한다. 지뢰가 없으면서 열린 칸에는 0과 8 사이의 숫자가 있어야 한다. 지뢰가
     * 있는 칸이 열렸다면 지뢰가 있는 모든 칸이 별표(*)로 표시되어야 한다. 다른 모든 지점은 온점(.)이어야 한다.
     * 
     */

public class boj4396 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] tableResult = new int[n][n];
        boolean[][] tableMine = new boolean[n][n];
        boolean[][] tableOpended = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                if (input[j] == '*') {
                    tableMine[i][j] = true;
                }
            }

        }
        for (int i = 0; i < n; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                if (input[j] == 'x') {
                    tableOpended[i][j] = true;
                }
            }
        }

        int[] dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
        int[] dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!tableMine[i][j]) {
                    for (int k = 0; k < 8; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];

                        if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                            if (tableMine[ny][nx])
                                tableResult[i][j]++;
                        }
                    }
                }
            }
        }

        boolean mineHit = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tableOpended[i][j] && tableMine[i][j]) {
                    mineHit = true;
                    break; // 하나라도 찾으면 더 확인할 필요 없음
                }
            }
            if (mineHit)
                break;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mineHit) {
                    if (tableMine[i][j])
                        sb.append('*');
                    else if (tableOpended[i][j])
                        sb.append(tableResult[i][j]);
                    else
                        sb.append('.');
                } else {
                    if (tableOpended[i][j])
                        if (tableMine[i][j])
                            sb.append('*');
                        else
                            sb.append(tableResult[i][j]);
                    else
                        sb.append('.');
                }
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}
