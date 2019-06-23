fn read_i32() -> i32
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().parse::<i32>().unwrap();
}
fn main()
{
    let n = read_i32();
    let mut sum : i32 = 0;
    for _i in 0..n
    {
        let mut x : i32 = read_i32();
        let m : i32 = x % 10;
        x /= 10;
        sum += x.pow(m as u32);
    }
    println!("{}", sum);
}
