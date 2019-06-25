fn read_int() -> i64
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<i64>().unwrap();
}

fn get_diff(x : i64) -> i64
{
    return x % 10 - (x / 10) % 10;
}

fn is_cute(x : i64) -> bool
{
    let mut n = x;
    let mut diff = get_diff(n);
    while n > 9
    {
        if diff != get_diff(n)
        {
            return false;
        }
        diff = get_diff(n);
        n /= 10;
    }
    return true;
}

fn main()
{
    let n = read_int();
    println!("{}", if is_cute(n) {"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!"} else {"흥칫뿡!! <(￣ ﹌ ￣)>"});
}
