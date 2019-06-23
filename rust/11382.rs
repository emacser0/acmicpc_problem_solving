fn read_triple() -> (i64, i64, i64)
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let v : Vec<i64> = input.trim().split(" ").map(|x| x.parse::<i64>().unwrap()).collect();
    return (v[0], v[1], v[2]);
}

fn main()
{
    let r = read_triple();
    println!("{}",r.0 + r.1 + r.2);
}
