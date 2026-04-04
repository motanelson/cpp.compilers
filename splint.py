import copy
print ("\033c\033[40;37m\n")

ss="""8086 x86
80186 x86
80286 x86
80386 x86
80486 x86
arm7 arm
arm8 arm"""

def splint(s,s1):
    i=0
    ss=copy.copy(s)
    l=[]
    while 1:
        a=ss.find(s1)
        if a>-1:
            aa=ss[:a]
            l.append(copy.copy(aa))
            aaa=a+len(s1)
            ss=ss[aaa:]
        else:
            l.append(copy.copy(ss))
            break
    return l
l=splint(ss,"\n")
print(l)