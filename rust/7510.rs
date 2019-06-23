fn read_vec() -> Vec<u32>
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().split(" ").map(|x| x.parse::<u32>().unwrap()).collect();
}
fn main()
{
    let n = read_vec()[0];
    for i in 0..n
    {
        let mut t = read_vec();
        t.sort();
        println!("Scenario #{}:", i + 1);
        match t[0]*t[0] + t[1]*t[1] == t[2]*t[2]
        {
            true => println!("yes\n"),
            false => println!("no\n"),
        }
    }
}
