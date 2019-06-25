fn read_int() -> usize
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<usize>().unwrap();
}

fn read_pair(buffer : &mut String) -> (&str, &str)
{
    std::io::stdin().read_line(buffer).unwrap();
    let v : Vec<&str> = buffer.trim().split(" ").collect();
    return (v[0], v[1]);
}

fn main()
{
    let t = read_int();
    for _ in 0..t
    {
        let n = read_int();
        let (mut a, mut b) = (0, 0);
        for _ in 0..n
        {
            let mut buffer = String::new();
            let p = read_pair(&mut buffer);
            match p
            {
                ("R", "S") | ("P", "R") | ("S", "P") => a += 1,
                ("S", "R") | ("R", "P") | ("P", "S") => b += 1,
                _ => (),
            }
        }
        println!("{}",
        if a > b
        {
            "Player 1"
        }
        else if a == b
        {
            "TIE"
        }
        else
        {
            "Player 2"
        });
    }
}
