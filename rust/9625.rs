fn fib(x : i64) -> i64
{
    let n = x as f64;
    if n == 0.0
    {
        return 0;
    }
    if n == 1.0
    {
        return 1;
    }
    let s5 = (5 as f64).sqrt();
    return ((1.0/s5) * (((1.0 + s5)/2.0).powf(n) - ((1.0 - s5)/2.0).powf(n))) as i64;
}
fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let k = input.trim().parse::<i64>().unwrap();
    println!("{} {}",fib(k - 1), fib(k));
}
