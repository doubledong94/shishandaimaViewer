from collections import Counter
import sys
import os

def find_dup(p):
    print(p)
    f = open(p)
    c=Counter(c.strip() for c in f if c.strip()) #for case-insensitive search
    l = []
    for line in c:
        if c[line]>1:
            l.append([c[line], line])
    #l.sort(reverse=True,key=lambda e:e[0])
    for i in l:
        print(i[1]+": "+str(i[0]))
    f.close()

p = sys.argv[1]
if os.path.isdir(p):
    for f in os.listdir(p):
        find_dup(p+"/"+f)
else:
    find_dup(p)
