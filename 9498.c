#include <stdio.h>
int a;

int
main() {
  scanf("%d",&a);
  a=a>89?65:a>79?66:a>69?67:a>59?68:70;
  putchar(a);
}
