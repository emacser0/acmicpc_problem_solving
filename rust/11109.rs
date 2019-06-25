fn read_int() -> usize
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<usize>().unwrap();
}

fn read_vec() -> Vec<i32>
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
}

fn main()
{
    let n = read_int();
    for _ in 0..n
    {
        let v = read_vec();
        let (s, p) : (i32, i32) = (v[1] * v[2], v[0] + v[1] * v[3]);
        println!("{}",
            if p < s {"parallelize"}
            else if p == s {"does not matter"}
            else {"do not parallelize"}
        );
    }
}
