from math import factorial
t = int(raw_input())
n = 0
a = []
memo = [[[0 for x in range(0,101)] for y in range(0,101)] for z in range(0,101)]
memoized = []

facs = [1 for x in range(0,101)]
for i in range(1,101):
	facs[i] = facs[i-1]*i

def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def dp(id, g, size):
	if g == 1:
		if size%2 == 0:
			return facs[size-1] # player 1 perdeu na passada
		else:
			return 0 # player 0 perdeu na passada
	if id == n:
		if size == n:
			if size%2 == 0:
				return 0
			else:
				return facs[size]
		else:
			return 0
	if memoized[id][g][size] == True:
		return memo[id][g][size]
	
	memoized[id][g][size] = True
	
	ans1 = dp(id+1, g, size)
	ans2 = dp(id+1, gcd(max(g,a[id]),min(g,a[id])), size+1)
	memo[id][g][size] = ans1 + ans2
	
	return memo[id][g][size]

for caso in range(0,t):
	n = int(raw_input())
	a = map(int, raw_input().split())
	
	memoized = [[[False for x in range(0,101)] for y in range(0,101)] for z in range(0,n+1)]
	
	ans = dp(0,0,0)
	print 0,float(ans)/facs[n]
