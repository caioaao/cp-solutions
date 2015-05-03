t=int(raw_input())
child = []
visited = []
def cyc_len(u):
  visited[u] = True
  s = 1
  v = child[u]
  while v != u:
    s = s + 1
    visited[v] = True
    v = child[v]
  return s
  
def gcd(a, b):
  if b == 0:
    return a
  return gcd(b, a % b)

def lcm(a, b):
  return a*(b/gcd(a,b))

for cnt in range(0,t):
  n=int(raw_input())
  child = [int(x)-1 for x in raw_input().split(" ")]
  visited = [False for x in child]
  ans = cyc_len(0)
  for i in range(1,n):
    if not visited[i]:
      ans = lcm(cyc_len(i),ans)
  print ans%1000000007
  
  

