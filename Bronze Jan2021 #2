
#read n
n = input()
n = int(n)
# print(n)

#read breed id
s = input() 
a = list()

#convert breed id string to list
n_s =""
for i in range(len(s)):
  if s[i] == " ":
      a.append(int(n_s.strip()))
      n_s =""
      # print(a)
  else:
    n_s += s[i]
    # print(n_s)

a.append(int(n_s.strip()))

n_even = 0
n_odd = 0
for i in range(n):
  if ((a[i]%2) == 0):
    n_even += 1
  else:
    n_odd += 1

cnt = 0
for i in range(1,n+1):
  if (i%2) == 1:
    if n_even > 0:
      if n_odd==0:
        cnt = i
        break
      else:
        n_even -= 1
    else:
      n_odd -= 2
  else:
    if n_even == 0:
      if (n_odd%3)==0:
        cnt = i-1 + int(n_odd/3)*2
        break
      else:
        if (n_odd%3)==2:
          cnt = i - 1 + int(n_odd/3)*2
          break
        else:
          n_odd -=1
          if n_odd == 0:
            cnt = i
            break
    else:
      n_odd -=1

print(cnt)
