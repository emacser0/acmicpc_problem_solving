fn read_tuple3() -> (i32, i32, i32)
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let v : Vec<i32> = input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
    return (v[0], v[1], v[2]);
}
fn main()
{
    loop
    {
        let t = read_tuple3();
        if t == (0, 0, 0)
        {
            break;
        }
        if t.1 - t.0 == t.2 - t.1
        {
            println!("AP {}", t.2 + (t.1 - t.0));
        }
        else
        {
            println!("GP {}", t.2 * t.1 / t.0);
        }
     }
}
