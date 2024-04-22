use std::io;

fn main(){
    let mut a0 = String::new();
    io::stdin().read_line(&mut a0).expect("a0 reading error");
    let a:Vec<usize> = a0.split_whitespace()
                            .map(|s| s.trim().parse().expect("a0 parsing error"))
                            .collect::<Vec<_>>();
    println!("{:?}",(a[0]+1)*(a[1]+1)/(a[2]+1)-1)
}