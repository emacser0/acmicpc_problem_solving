fn ccw(a : (i32, i32), b : (i32, i32), c : (i32, i32)) -> i32
{
    let s = (b.0 - a.0) * (c.1 - a.1) - (b.1 - a.1) * (c.0 - a.0);
    match s
    {
        s if s > 0 => return 1,
        s if s < 0 => return -1,
        _ => return 0,
    }
}

fn read_pair() -> (i32, i32)
{
    let mut input = String::new();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let v : Vec<i32> = input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
    return (v[0], v[1]);
}

fn main()
{
    let (p1, p2, p3) = (read_pair(), read_pair(), read_pair());
    println!("{}",ccw(p1, p2, p3));
}
