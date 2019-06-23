fn read_vec() -> Vec<i32>
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
}
fn main()
{
    let v = read_vec();
    let (_n, t) = (v[0], v[1]);
    let v = read_vec();
    let (mut cnt, mut sum) = (0, 0);
    for x in v.iter()
    {
        sum += x;
        if sum > t
        {
            break;
        }
        cnt += 1;
    }
    println!("{}", cnt);
}
