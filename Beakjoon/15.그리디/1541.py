def split_by_minus(string):
    ret = []
    temp = ''
    for i in string:
        if i == '-':
            ret.append(temp)
            temp = ''
        else:
            temp += i
    ret.append(temp)
    return ret

def split_by_plus(string):
    ret = []
    temp = ''
    for i in string:
        if i == '+':
            ret.append(temp)
            temp = ''
        else:
            temp += i
    ret.append(temp)
    return ret

#get input
poly = input()
#this is test case
#poly = '55-50+40'

numset = split_by_minus(poly)

sum = 0

for idx in range(len(numset)):
    temp = split_by_plus(numset[idx])
    sumset = 0
    for i in temp:
        sumset += int(i)

    if idx == 0:
        sum += sumset
    else:
        sum -= sumset

print(sum)