A,B,C,D=eval('int(input()),'*4)
a="Fish "
print(["No Fish",a+"Diving",a+"Rising",a+"At Constant Depth"][(A>B>C>D)+(A<B<C<D)*2+(A==B==C==D)*3])