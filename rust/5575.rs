fn read_vec() -> Vec<i32>
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
}

fn main()
{
    for _ in 0..3
    {
        let v = read_vec();
        let mut t = (v[3] - v[0], v[4] - v[1], v[5] - v[2]);
        if t.2 < 0
        {
            t.1 -= 1;
            t.2 += 60;
        }
        if t.1 < 0
        {
            t.0 -= 1;
            t.1 += 60;
        }
        println!("{} {} {}", t.0, t.1, t.2);
     }
}
