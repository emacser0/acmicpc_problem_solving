fn read_line() -> String
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().to_string();
}
fn find_nemo(s : &String) -> bool
{
    for (i, x) in s.chars().enumerate()
    {
        if x == 'n' && &s[i..(i+4)] == "nemo"
        {
            return true;
        }
    }
    return false;
}
fn main()
{
    loop
    {
        let s = read_line();
        if s == "EOI"
        {
            break;
        }
        match find_nemo(&s.to_lowercase())
        {
            true => println!("Found"),
            false => println!("Missing"),
        };
    }
}
