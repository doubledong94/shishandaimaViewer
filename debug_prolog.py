import sys

file_path = sys.argv[1]
f = open(file_path,'r')
line_count = 0
lineStack = []
jump = 0
prefix = ''
while True:
    l1 = next(f)
    l2 = next(f)
    searched = l1[0] == '-'
    if searched:
        # search is done
        prefix = '| '
    else:
        # push stack or pop stack
        prefix = 'x '
        c = int(l2)
        for i in range(c,len(lineStack)):
            lineStack.pop()
        lineStack.append(l1)
    for l in lineStack:
        print(prefix+l[0:-1])
    print("------------------------------------------------------------------------------------------------------------")
    if jump > 0:
        jump-=1
        continue
    if jump < 0:
        if searched:
            jump = 0
        else:
            continue
    jumpStr = input("")
    if len(jumpStr) > 0:
        jump  = int(jumpStr)
    else:
        jump = 0
