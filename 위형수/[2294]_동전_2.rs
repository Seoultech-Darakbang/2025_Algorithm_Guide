use std::{collections::HashMap, io::{prelude::*, stdout, BufWriter}};

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut writer = BufWriter::new(stdout().lock());

    let _ = input.next().unwrap(); // n: unused
    let k = input.next().unwrap();
    let coins = input.collect::<Vec<usize>>(); 
    let mut memo: HashMap<usize, isize> = HashMap::new();

    // DP(bottom-up)
    memo.insert(0, 0);
    for i in 1..=k {
        for coin in coins.iter() {
            let sub_problem = i.checked_sub(*coin);
            if sub_problem.is_none(){
                continue;
            }
            let sub_problem = sub_problem.unwrap();

            if let Some(cur) = memo.get(&i) {
                if let Some(sub_problem) = memo.get(&sub_problem) {
                    memo.insert(i, (*cur).min(*sub_problem + 1));
                }
            }
            else {
                if let Some(sub_problem) = memo.get(&sub_problem) {
                    memo.insert(i, *sub_problem + 1);
                }
            }
        }
    }
    writeln!(writer, "{}", memo.get(&k).unwrap_or(&-1)).unwrap();
}
