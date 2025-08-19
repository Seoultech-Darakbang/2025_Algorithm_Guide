use std::{io::{prelude::*, stdout, BufWriter}, vec};

const DS:[(isize, isize);4] = [(0,-1), (1, 0), (0, 1), (-1, 0)];
const MAX_HEIGHT:usize = 10000;

// Sub problem
// 현재 위치에서 도착 지점까지의 경로 개수
// Dfs에서 도착지점에 도착한 후 escape할 때 경로 수를 memo
// 답이 아닐경우 경우 제거를 위한 표시

fn dfs(s:(usize, usize), e:(usize, usize), map:&mut Vec<Vec<usize>>, dp:&mut Vec<Vec<usize>>) -> usize{
    if s == e {
        dp[e.0][e.1] = 1;
        return dp[e.0][e.1];
    }

    let mut path_found = false;

    for ds in DS {
        let ny = s.0 as isize + ds.0;
        let nx = s.1 as isize + ds.1;

        if ny < 0 || ny >= map.len() as isize {
            continue;
        }
        if nx < 0 || nx >= map[0].len() as isize {
            continue;
        }
        let ny = ny as usize;
        let nx = nx as usize;

        if map[ny][nx] >= map[s.0][s.1] {
            continue;
        }
        // sub problem
        if dp[ny][nx] > 0 {
            dp[s.0][s.1] += dp[ny][nx];
            path_found = true;
        }
        else {
            dp[s.0][s.1] += dfs((ny, nx), e, map, dp);
            path_found = true;
        }
    }

    // 경우 제거: 시간 단축
    if !path_found {
        map[s.0][s.1] = MAX_HEIGHT;
    }
    dp[s.0][s.1]
}

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut writer = BufWriter::new(stdout().lock());

    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let m = input.next().unwrap();
    let n = input.next().unwrap();

    let mut map = (0..m)
        .map(|i| input.clone().skip(i*n).take(n).collect::<Vec<usize>>())
        .collect::<Vec<Vec<usize>>>();
    let mut dp = vec![vec![0; n]; m];
    let h = dfs((0, 0), (m-1, n-1), &mut map, &mut dp);

    writeln!(writer, "{h}").unwrap();
}
