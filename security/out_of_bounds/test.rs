use std::env;
use std::str::FromStr;

fn main() {
    let test = [1,3,4];
    let args: Vec<String> = env::args().collect();
    let i: usize = usize::from_str(&args[1]).unwrap_or(0);

    println!("Hello World! {}", test[i]);
}
