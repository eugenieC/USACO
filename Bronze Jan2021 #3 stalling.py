#read n
n = input()
n = int(n)

#read height and limit
r1 = input()
r2 = input()

#convert the string data to array
def make_array(ary):
  s_x =""
  tmp_ary = list()
  for i in range(len(ary)):
    if ary[i] == " ":
      tmp_ary.append(int(s_x.strip()))
      s_x =""
    else:
      s_x += ary[i]
  tmp_ary.append(int(s_x.strip()))
  return tmp_ary

a = make_array(r1)
b = make_array(r2)


#descending sort height
#then count by height, by limit
a.sort(reverse=True)
b.sort(reverse=True)

def cnt_h(ary):
  cnt_d = {}
  for h in ary:
    cnt_d[h] = cnt_d.get(h,0) + 1

  return cnt_d

a_cnt = cnt_h(a)
b_cnt = cnt_h(b)


ok_cnt = 0
total = 1
# define factorial user-function
def factori(q):
  f_out = 1
  for fiter in range(1,q+1):
    f_out=f_out*fiter
  return f_out

#carry over left-over of limit 
carry_n = 0
prev_key_a = (list(b_cnt.keys())[0])
for key_a in a_cnt:
  r = a_cnt[key_a]
  n = carry_n
  for key_b in b_cnt:
      if key_a == (list(a_cnt.keys())[0]):
        if key_a <= key_b:
          n += b_cnt[key_b]
      else:
        if key_a <= key_b and key_b < prev_key_a:
          n += b_cnt[key_b]
  carry_n = n - r

  if (n-r) < 0:
    total = 0
  else:
    t=factori(n)/factori(n-r)
    total = total * t
  prev_key_a = key_a  

print(int(total)) 
