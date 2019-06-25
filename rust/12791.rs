fn read_int() -> u32
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    return buffer.trim().parse::<u32>().unwrap();
}

fn read_pair() -> (u32, u32)
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    let v : Vec<u32> = buffer.trim().split(" ").map(|x| x.parse::<u32>().unwrap()).collect();
    return (v[0], v[1]);
}
fn main()
{
    let albums : Vec<(u32, &str)> = vec!
    [
        (1967, "DavidBowie"),
        (1969, "SpaceOddity"),
        (1970, "TheManWhoSoldTheWorld"),
        (1971, "HunkyDory"),
        (1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"),
        (1973, "AladdinSane"),
        (1973, "PinUps"),
        (1974, "DiamondDogs"),
        (1975, "YoungAmericans"),
        (1976, "StationToStation"),
        (1977, "Low"),
        (1977, "Heroes"),
        (1979, "Lodger"),
        (1980, "ScaryMonstersAndSuperCreeps"),
        (1983, "LetsDance"),
        (1984, "Tonight"),
        (1987, "NeverLetMeDown"),
        (1993, "BlackTieWhiteNoise"),
        (1995, "1.Outside"),
        (1997, "Earthling"),
        (1999, "Hours"),
        (2002, "Heathen"),
        (2003, "Reality"),
        (2013, "TheNextDay"),
        (2016, "BlackStar")
    ];
    let q = read_int();
    for _ in 0..q
    {
        let (s, e) = read_pair();
        let mut results : Vec<(u32, &str)> = vec![];
        for i in albums.iter()
        {
            if i.0 >= s && i.0 <=e
            {
                results.push(*i);
            }
            if i.0 > e
            {
                break;
            }
        }
        println!("{}", results.len());
        for i in results.iter()
        {
            println!("{} {}", i.0, i.1);
        }
    }
}
