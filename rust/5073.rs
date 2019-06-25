fn read_vec() -> Vec<u32>
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().split(" ").map(|x| x.parse::<u32>().unwrap()).collect();
}

fn classify_triangle(tv : &mut Vec<u32>) -> u32
{
    let mut max : (usize, u32) = (0, 0);
    for (i, x) in tv.iter().enumerate()
    {
        if *x > max.1
        {
            max = (i, *x);
        }
    }
    tv.remove(max.0);
    let t : (u32, u32, u32) = (max.1, tv[0], tv[1]);
    let r = t.0 ^ t.1 ^ t.2;
    if t == (0, 0, 0)
    {
        return 0;
    }
    else if t.0 >= t.1 + t.2
    {
        return 4;
    }
    else if t == (t.1, t.2, t.0)
    {
        return 3;
    }
    else if r == t.0 || r == t.1 || r == t.2
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

fn print_triangle_class() -> bool
{
    match classify_triangle(&mut read_vec())
    {
        4 => println!("{}", "Invalid"),
        3 => println!("{}", "Equilateral"),
        2 => println!("{}", "Isosceles"),
        1 => println!("{}", "Scalene"),
        _ => return false,
    }
    return true;
}

fn main()
{
    loop
    {
        if print_triangle_class() == false
        {
            break;
        }
    }
}
