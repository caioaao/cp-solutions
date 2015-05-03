from math import factorial

n, m, c = 0l,0l,0l

colorCodes = {}
baloonsPrice = []
baloonsAmt = []
sBaloons = []

memo = []

def dp(id, cLeft):
	if id == c:
		if cLeft == 0:
			return [0,1]
		return [0,0]
	if memo[id][cLeft][1] != -1:
		return memo[id][cLeft]
		
	dp0 = dp(id+1, cLeft)
	dp1 = dp(id+1, max(cLeft-1, 0))
	
	#~ print "dp0(",id+1,cLeft, "):",dp0[0], dp0[1]
	#~ print "dp1(",id+1,max(cLeft-1, 0), "):",dp1[0], dp1[1]
	
	memo[id][cLeft][0] = dp0[0] + dp1[0] * sBaloons[id][1] + dp1[1] * sBaloons[id][0]
	memo[id][cLeft][1] = dp0[1] + dp1[1] * sBaloons[id][1] # ok
	
	return memo[id][cLeft]

memo_in = []

def dp_in(cId, id, bLeft): # OK
	if bLeft == 0: return [0,1]
	if id == baloonsAmt[cId]: return [0,0]
	
	if memo_in[id][bLeft][1] != -1:
		return memo_in[id][bLeft]
	
	dp0 = dp_in(cId, id+1, bLeft)
	dp1 = dp_in(cId, id+1, bLeft - 1)
	
	memo_in[id][bLeft][0] = dp0[0] + dp1[0] + dp1[1]*baloonsPrice[cId][id]
	memo_in[id][bLeft][1] = dp0[1] + dp1[1]
	return memo_in[id][bLeft]

t = int(raw_input())
for caso in range(0,t):
	n,m = map(int,raw_input().split())
	
	c = 0
	colorCodes.clear()
	baloonsPrice = []
	baloonsAmt = []
	
	for i in range(0,n):
		ci,pi = map(int,raw_input().split())
		if ci not in colorCodes:
			colorCodes[ci] = c
			c = c+1
			baloonsPrice.append([])
			baloonsAmt.append(0)
		baloonsAmt[colorCodes[ci]] = baloonsAmt[colorCodes[ci]] + 1
		baloonsPrice[colorCodes[ci]].append(pi)
	sBaloons = [[0,0] for x in range(0,c)]
	for i in range(0,c):
		memo_in = [[[0,-1] for y in range(0,baloonsAmt[i]+1)] for x in range(0, baloonsAmt[i])]
		for j in range(1, baloonsAmt[i]+1):
			ansX,ansY = dp_in(i, 0, j)
			sBaloons[i][0] = sBaloons[i][0] + ansX
			sBaloons[i][1] = sBaloons[i][1] + ansY
		#~ print sBaloons[i][0], sBaloons[i][1]
	
	memo = [[[0l,-1l] for y in range(0,m+1)] for x in range(0, c)]
	
	[ansN, ansD] = dp(0,m)
	#~ print ansN, ansD
	print("{0:.9f}".format(ansN/float(ansD)))
