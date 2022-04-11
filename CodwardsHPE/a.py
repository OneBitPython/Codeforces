s = input()
st = []
for i in s:st.append(i)
st.sort()
repeat = st[0]
res = ""
for i in range(len(s)):
    res+=repeat
print(res)