s = list(input()) # [(Na23C3)6((NaF4)7)2)3
n = int(len(s))
for i in range(n):
    if s[i] == '[': s[i] = '('
    elif s[i] == ']': s[i] = ')'
res = dict()
for i in range(n):
    if not s[i].isupper():continue
    st = []
    # figure out which element this is and subscript
    k = i+1
    ele = s[i]
    while k < n and s[k].islower():ele+=s[k];k+=1;
    coeff = ""
    while k < n and s[k].isnumeric():coeff+=s[k];k+=1
    if len(coeff)==0: coeff = "1"
    coeff = int(coeff)
    for j in range(n):
        if s[j] == '(': st.append(j)
        elif s[j]==')':
            if len(st) == 0: raise "brackets not symmetrical"
            idx = st.pop()
            if not (j > i and idx < i):continue
            val = ""; k = j+1;
            while k < n and s[k].isnumeric():val+=s[k];k+=1;
            if(len(val)==0):continue
            coeff *= int(val)
    if ele not in res:res[ele] = 0
    res[ele] += coeff;
print(res)