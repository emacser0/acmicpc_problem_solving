@c=();
for(1..100){push @c, 0;}
$a=<STDIN>;
@b=split ' ',<STDIN>;
$r=0;
foreach $i (@b) {
  if(@c[$i-1]>0) {
    $r+=1;
  }
  @c[$i-1]=1;
}
print $r;
