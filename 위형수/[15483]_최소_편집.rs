use std::{io::{prelude::*, stdout, BufWriter}, vec};

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut writer = BufWriter::new(stdout().lock());

    let input = input.split("\n").collect::<Vec<&str>>();
    let (s1, s2) = (input[0].chars().collect::<Vec<char>>(), input[1].chars().collect::<Vec<char>>());
    let len_s1 = s1.len();
    let len_s2 = s2.len();
    let mut dp = vec![vec![0; len_s2 + 1]; len_s1 + 1];

    // DP
    for i in 0..=len_s1 {
        for j in 0..=len_s2 {
            if i == 0 {
                dp[i][j] = j;
            }
            else if j == 0 {
                dp[i][j] = i
            }
            else {   
                let cost = |x:char, y:char| {
                    if x==y {
                        0
                    }else {
                        1
                    }
                };
                let l_i1_j = dp[i-1][j];    // l(n-1, m  )
                let l_i_j1 = dp[i][j-1];    // l(n  , m-1)
                let l_i1_j1 = dp[i-1][j-1]; // l(n-1, m-1)
                
                dp[i][j] = (l_i1_j+1).min(l_i_j1+1).min(l_i1_j1+cost(s1[i-1], s2[j-1]))
            }
        }
    }

    writeln!(writer, "{}", dp[len_s1][len_s2]).unwrap();
}
