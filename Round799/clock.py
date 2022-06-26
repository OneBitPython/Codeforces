

for ghj in range(int(input())):
    w = input().split();
    s = w[0]
    x = int(w[1]);
    hour = s.split(":")[0];
    minute = s.split(":")[1];
    curr = int(hour)*60 + (int(minute));
    times = []
    for i in range(2000):
        hours = (curr//60)%24;
        minutes = (curr%60)%60
        hours = str(hours)
        minutes = str(minutes)
        time = ""
        if len(hours) == 1:
            time = "0"
        time+=str(hours)
        if len(minutes) == 1:
            time+="0"
        time+=str(minutes)
        times.append(time)
        curr+=x
    res = 0
    st = set()

    for val in times:
        if val == val[::-1]:
            st.add(val)
    print(len(st))