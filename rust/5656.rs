use std::io::Write;
fn main()
{
    let mut input = String::new();
    // for fast print
    let stdout = std::io::stdout();
    let mut stdout = std::io::BufWriter::new(stdout.lock());
    for cnt in 1..
    {
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.trim().split(" ");
        let (x, o, y)
        = (s.next().unwrap().parse::<i32>().unwrap(),
           s.next().unwrap().to_string(),
           s.next().unwrap().parse::<i32>().unwrap());
        let result : bool
        = match o.as_ref()
        {
            ">" => x > y,
            ">=" => x >= y,
            "<" => x < y,
            "<=" => x <= y,
            "==" => x == y,
            "!=" => x != y,
            _ => break,
        };
        writeln!(stdout, "Case {}: {}", cnt, if result {"true"} else {"false"}).unwrap();
    }
}
