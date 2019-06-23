fn read_vec() -> Vec<i32>
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
}

fn read_pair() -> (i32, i32)
{
    let v = read_vec();
    return (v[0], v[1]);
}

fn main()
{
    let (s1, s2) = read_pair();
    let mut sample : bool = true;
    for _ in 0..s1
    {
        let (a, b) = read_pair();
        if a != b
        {
            sample = false;
        }
    }
    let mut system : bool = true;
    for _ in 0..s2
    {
        let (a, b) = read_pair();
        if a != b
        {
            system = false;
        }
    }
    println!("{}",
    if sample == false
    {
        "Wrong Answer"
    }
    else if sample == true && system == true
    {
        "Accepted"
    }
    else
    {
        "Why Wrong!!!"
    });
}
