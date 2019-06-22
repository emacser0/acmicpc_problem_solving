fn read(input : &mut String)
{
    std::io::stdin().read_line(input).unwrap();
}
fn main()
{
    let mut input = String::new();
    read(&mut input);
    let _n = input.trim().parse::<i32>().unwrap();
    input.clear();
    read(&mut input);
    let l : Vec<i32> = input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
    input.clear();
    read(&mut input);
    let v = input.trim().parse::<i32>().unwrap();
    let mut cnt : i32 = 0;
    for i in &l
    {
        if *i == v
        {
            cnt += 1;
        }
    }
    println!("{}",cnt);
}
