fn read_i32() -> i32
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().parse::<i32>().unwrap();
}

fn read_string_vec() -> Vec<String>
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().split(" ").map(|x| x.to_string()).collect();
}

fn main()
{
    let t = read_i32();
    for _i in 0..t
    {
        let mut v = read_string_vec();
        let mut n = v[0].parse::<f64>().unwrap();
        for j in 1..v.len()
        {
            match v[j].as_ref()
            {
                "@" => n *= 3.0,
                "%" => n += 5.0,
                "#" => n -= 7.0,
                _ => n = n,
            }
        }
        println!("{:.2}",n);
    }
}
