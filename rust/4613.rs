fn read_string(input : &mut String) -> String
{
    input.clear();
    std::io::stdin().read_line(input).unwrap();
    return input.trim().to_string();
}
fn main()
{
    let mut input = String::new();
    let mut flag : bool = true;
    while flag
    {
        let s = read_string(&mut input);
        let mut sum : i32 = 0;
        for (i, x) in s.chars().enumerate()
        {
            match x
            {
                ' ' => sum += 0,
                x if x >= 'A' && x <= 'Z' => sum += (i as i32 + 1) * ((x as i32) - ('A' as i32) + 1),
                '#' =>
                {
                    flag = false;
                    break;
                }
                _ => panic!(),
            };
        }
        if flag
        {
            println!("{}", sum);
        }
    }
}
