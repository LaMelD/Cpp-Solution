res = []
numbers = []
maximum = 0

def printlist(stack):
    s = ''
    for i in stack:
        s += str(i) + ' '
    print(s)

def backtracking(count, stack, before):
    global res
    if count == maximum:
        res.append(stack)
        printlist(stack)
        return
    
    for i in range(before, len(numbers)):
        stack.append(numbers[i])
        backtracking(count + 1, stack, i)
        stack.pop()
 
def solve(to, n):
    global maximum
    maximum = n
    for i in range(1, to + 1):
        numbers.append(i)
    backtracking(0, [], 0)

#get input
inputnum = input()
num = inputnum.split(' ')
solve(int(num[0]), int(num[1]))

#this is test case
#solve(4, 3)