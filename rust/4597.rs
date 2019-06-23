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
        let mut s = read_string(&mut input);
        let mut sum : i32 = 0;
        let mut p : char = '0';
        for x in s.chars()
        {
            match x
            {
                '1' => sum += 1,
                '0' => sum += 0,
                'e' | 'o' =>
                {
                    p = x;
                    break;
                }
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
            s.pop();
            s.push(if (p == 'e' && sum % 2 != 0) || (p == 'o' && sum % 2 == 0) {'1'}
                   else {'0'});
            println!("{}", s);
        }
    }
}
