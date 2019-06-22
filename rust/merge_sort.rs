fn merge_sort(v : &mut Vec<i32>, s : usize, e : usize)
{
    let mut tv : Vec<i32> = vec![];
    inner_merge_sort(v, &mut tv, s, e);
}

fn inner_merge_sort(v : &mut Vec<i32>, tv : &mut Vec<i32>, s : usize, e : usize)
{
    let m : usize = (s + e) / 2;
    if s < e
    {
        inner_merge_sort(v, tv, s, m);
        inner_merge_sort(v, tv, m + 1, e);
        merge(v, tv, s, m, e);
    }
}

fn merge(v : &mut Vec<i32>, tv : &mut Vec<i32>, s : usize, m : usize, e : usize)
{
    let mut l : usize = s;
    let mut r : usize = m + 1;
    while l <= m && r <=e
    {
        if v[l] < v[r]
        {
            tv.push(v[l]);
            l += 1;
        }
        else
        {
            tv.push(v[r]);
            r += 1;
        }
    }
    while l <= m
    {
        tv.push(v[l]);
        l += 1;
    }
    while r <= e
    {
        tv.push(v[r]);
        r += 1;
    }
    l = s;
    for (i, x) in tv.iter().enumerate()
    {
        v[l + i] = *x;
    }
    tv.clear();
}
