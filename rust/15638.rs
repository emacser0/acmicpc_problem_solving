fn is_prime(n : i64) -> bool
{
    if n == 2
    {
        return true;
    }
    for i in 2..n/2 + 1
    {
        if n % i == 0
        {
            return false;
        }
    }
    return true;
}

fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut n = input.trim().parse::<i64>().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    if n < 0
    {
        n = -n;
    }
    match is_prime(n)
    {
        true => println!("Yes"),
        false => println!("No")
    }
}
