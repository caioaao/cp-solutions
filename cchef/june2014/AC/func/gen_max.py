ans = ''
for i in range(1,100):
  m = int(2**(60./i))
  ans = ans + str(m) + ','
print ans
