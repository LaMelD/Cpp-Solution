res = []
numbers = []
visit = []
maximum = 0

def printlist(stack):
    s = ''
    for i in stack:
        s += str(i) + ' '
    print(s)

def backtracking(count, stack):
    global res
    global visit
    if count == maximum:
        res.append(stack)
        printlist(stack)
        return
    
    for i in numbers:
        if not visit[i - 1]:
            visit[i - 1] = True
            stack.append(i)
            backtracking(count + 1, stack)
            stack.remove(i)
            visit[i - 1] = False
        
 
def solve(to, n):
    global maximum
    maximum = n
    for i in range(1, to + 1):
        numbers.append(i)
        visit.append(False)
    backtracking(0, [])

#get input
inputnum = input()
num = inputnum.split(' ')
solve(int(num[0]), int(num[1]))

#this is test case
#solve(4, 3)