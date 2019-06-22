fn main()
{
    let mut input = String::new();
    while std::io::stdin().read_line(&mut input).unwrap() > 0
    {
        let v : Vec<i32> = input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
        if (v[0], v[1]) == (0, 0)
        {
            break;
        }
        match v[0] > v[1]
        {
            true => println!("Yes"),
            false => println!("No"),
        }
        input.clear();
    }
}
