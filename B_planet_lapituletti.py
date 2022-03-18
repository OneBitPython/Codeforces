convert = {'0':'0', '1':'1', '2':'5', '5':'2', '8':'8'}
for q in range(int(input())):
    h, m = map(int,input().split());
    s = list(map(int,input().split(":")))
    curr_h = s[0];
    curr_m = s[1];
    # check all values including the values of the current minute
    valids = []
    for i in range(0, 100):
        for j in range(0, 100):
            
            if(i >= h or j >= m):continue
            if i<= 9:
                hour = "0"+str(i)
            else: hour = str(i);
            if j<=9:minute = "0"+str(j)
            else: minute = str(j)
            new_hour = "";
            new_minute = ""
            minute = minute[::-1]
            hour = hour[::-1]
            ok = 1
            for k in minute:
                if convert.get(k, 'no') == 'no':
                    ok = 0
                else:
                    new_hour+=(convert[k])
            for k in hour:
                if(convert.get(k, 'no') == 'no'):
                    ok = 0
                else:
                    new_minute+=(convert[k])
            if(not ok):continue
            if int(new_hour) < h and int(new_minute) < m:
                valids.append((hour[::-1], minute[::-1]))
    dist = []
    for valid in valids:
        hour = int(valid[0])
        minute = int(valid[1])
        ans = f"{valid[0]}:{valid[1]}";
        if(hour == curr_h and minute == curr_m):
            dist.append((0, ans));
        if(hour == curr_h and minute > curr_m):
            dist.append((minute - curr_m, ans))
        if(hour > curr_h):
            d = minute
            d+=(m-curr_m)
            d+=((hour - curr_h - 1) * m)
            dist.append((d, ans))
        if(hour <=curr_h):
            d = (m - curr_m)
            d+=minute
            d+=((h - (curr_h+1))*m)
            d+=((hour)*m)
            dist.append((d, ans))
    dist.sort(key = lambda x : x[0])
    print(dist[0][1]);
        
