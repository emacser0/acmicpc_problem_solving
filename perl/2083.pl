while(1) {
  @a=split ' ',<>;
  if(@a[0] eq "#"){last}
  printf "%s %s\n",@a[0],(@a[1]>17 or @a[2]>79)?"Senior":"Junior"
}
