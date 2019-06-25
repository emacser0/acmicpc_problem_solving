fn read_int() -> usize
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<usize>().unwrap();
}
fn read_string() -> String
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().to_string();
}
fn main()
{
    let n = read_int();
    for _ in 0..n
    {
        let (a, b) = (read_string(), read_string());
        let mut cnt = 0;
        for i in 0..a.len()
        {
            if a.chars().nth(i).unwrap() != b.chars().nth(i).unwrap()
            {
                cnt += 1;
            }
        }
        println!("Hamming distance is {}.", cnt);
    }
}
