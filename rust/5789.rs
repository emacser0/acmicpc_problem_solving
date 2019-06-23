fn read_i32() -> i32
{
    let mut input = String::new();
    return read_string(&mut input).parse::<i32>().unwrap();
}
fn read_string(buffer : &mut String) -> &str
{
    std::io::stdin().read_line(buffer).unwrap();
    return buffer.trim();
}
fn main()
{
    let n = read_i32();
    for _i in 0..n
    {
        let mut s = String::new();
        read_string(&mut s);
        let len = s.len();
        println!("Do-it{}",
                 match s.chars().nth(len / 2 - 1).unwrap() == s.chars().nth(len / 2).unwrap()
                 {
                     true => "",
                     false => "-Not"
                 });
    }
}
