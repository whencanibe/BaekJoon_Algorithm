use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).expect("입력 오류입니다");
    let money :i32 = input.trim().parse().expect("정수가 아닙니다");

    let mut change = 1000 - money;
    let coins = [500,100,50,10,5,1];
    let mut count = 0;

    let mut i= 0;
    while change >= 1 {
        count += change / coins[i];
        change %= coins[i];
        i+= 1;
    }

    println!("{}",count);
}
