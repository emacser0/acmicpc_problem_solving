fn read_int() -> u32
{
    let mut buffer =  String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<u32>().unwrap();
}
fn main()
{
    let n = read_int();
    println!("{}", n * (n - 1) * (n - 2) * (n - 3) / 24);
    // a square have one intersection point.
    // so select 4 vertexes of polygon and make a square.
    // then count every polygons.
}
