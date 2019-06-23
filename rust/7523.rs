fn read_i64() -> i64
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<i64>().unwrap();
}
fn read_pair() -> (i64, i64)
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    let v : Vec<i64> = buffer.trim().split(" ").map(|x| x.parse::<i64>().unwrap()).collect();
    return (v[0], v[1]);
}
fn main()
{
    let t = read_i64();
    for i in 1..t+1
    {
        let (n, m) = read_pair();
        println!("Scenario #{}:\n{}\n", i, (m * (m + 1) - (n - 1) * n) / 2);
    }
}
