fn read_usize() -> usize
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<usize>().unwrap();
}
fn read_string_lowercase() -> String
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().to_lowercase().to_string();
}
fn main()
{
    let n = read_usize();
    for _ in 0..n
    {
        println!("{}", read_string_lowercase());
    }
}
