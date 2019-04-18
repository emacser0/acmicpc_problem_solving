for i in range(3):
    n,s=int(input()),0
    for j in range(n):
        s+=int(input())
    print('0' if s==0 else '+' if s>0 else '-')
