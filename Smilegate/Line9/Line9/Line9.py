#-*- coding: utf-8 -*-

l = []

with open('9.csv', 'r', encoding='UTF-8') as f:    
    for line in f.readlines():
       tokens = line.split(',')
       if len(tokens) == 3:
           l.append(tokens)

with open('9.csv', 'w', encoding='UTF-8') as f:
    for i, tokens in enumerate(l):
        f.write("{},9,{},2:00,{},{}".format(268 + i, tokens[0], tokens[1], tokens[2]))