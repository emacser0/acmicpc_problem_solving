fn read_usize() -> usize
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<usize>().unwrap();
}

fn read_vec() -> Vec<f64>
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().split(" ").map(|x| x.parse::<f64>().unwrap()).collect();
}

fn main()
{
    let pv : Vec<f64> = vec![350.34, 230.90, 190.55, 125.30, 180.90];
    for _ in 0..read_usize()
    {
        let v = read_vec();
        let mut sum : f64 = 0.0;
        for i in 0..5
        {
            sum += pv[i] * v[i];
        }
        println!("${:.2}", sum);
    }
}
