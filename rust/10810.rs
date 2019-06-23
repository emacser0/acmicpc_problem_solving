fn read_vec() -> Vec<usize>
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    return input.trim().split(" ").map(|x| x.parse::<usize>().unwrap()).collect();
}
fn read_pair() -> (usize, usize)
{
    let v = read_vec();
    return (v[0], v[1]);
}
fn read_tuple3() -> (usize, usize, usize)
{
    let v = read_vec();
    return (v[0], v[1], v[2]);
}
fn main()
{
    let (n, m) = read_pair();
    let mut v = vec![0; n];
    for _i in 0..m
    {
        let nv = read_tuple3();
        for i in nv.0..nv.1+1
        {
            v[i - 1] = nv.2;
        }
    }
    for i in v.iter()
    {
        print!("{} ", i);
    }
    println!("");
}
