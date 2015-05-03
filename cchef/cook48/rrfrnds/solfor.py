total=0
friends=int(raw_input())
adjmat=['' for i in range(friends)]
binreps=[[0 for j in range(friends/31 + 1)] for i in range(friends)]
for i in range(friends):
    # no need to turn it into integers, you can access the value
    # directly on the string
    adjmat[i] = raw_input()
    
    for j in range(friends):
      # the key here is that binreps should be an array of bitmasks with
      # size equal to friends/31. the relationships will be stored as
      # on/off bits inside those bitmasks
      if adjmat[i][j] == '1':
        binreps[i][j/31] = (binreps[i][j/31]|(1<<(j%31)))
    
    # you can do the checking loop here, as the bitmasks prior to line i
    # have been processed already
    for j in range(i):
      # test if they are already friends
      if adjmat[i][j]=='1':
          continue
      # if not, run through all the bitmasks (at most n/31) and check
      # if any of them has a common bit turned on. if it does, sum the
      # pair in the result and break the loop
      for k in range(friends/31+1):
        if binreps[i][k] & binreps[j][k] != 0:
          total = total+2
          break

print(total)
