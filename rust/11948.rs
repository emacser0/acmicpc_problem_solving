fn read_int() -> i32
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<i32>().unwrap();
}

fn get_sum_except_min(cnt : usize) -> i32
{
    let mut sum : i32 = 0;
    let mut min : i32 = 100;
    for _ in 0..cnt
    {
        let n = read_int();
        sum += n;
        min = if min < n {min} else {n};
    }
    sum -= min;
    return sum;
}

fn main()
{
    println!("{}", get_sum_except_min(4) + get_sum_except_min(2));
}
