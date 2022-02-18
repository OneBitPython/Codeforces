time = int(input())
s = input()
hours = s[0:2]
minutes = s[3:5]

if(time == 24):
    # represent in 24 hour format
    # 0 to 23 minutes from 0 to 59
    ans = ""
    
    if int(hours) > 23:
        first = hours[0]
        second = hours[1]
        if(int(first) == 2):
            ans+=first
            if int(second)<4: ans+=second
            else: ans+="2"
        else:
            if(int(first) > 2):ans+="1"
            ans+=second
    else: ans+=hours
    ans+=":"
    if(int(minutes) > 59):
        first = minutes[0]
        second = minutes[1]
        
        
        ans+="2"
        ans+=second
    else: ans+=minutes
    print(ans)
else:
    ans = ""
    if(int(hours) > 12):
        first = hours[0]
        second = hours[1]
        if(int(first) == 1):
            ans+=first
            if int(second)<=1: ans+=second
            else: ans+="0"
        elif int(first) == 0 and int(second) == 0:
            ans+="01"
        else:
            if(int(second)!=0):
                ans+="0"
                ans+=second
            else:
                ans+="1"
                ans+=second
    else:
        if(int(hours)>0):ans+=hours;
    if(int(hours)==0):ans+="10"
    ans+=":"

    if(int(minutes) > 59):
        first = minutes[0]
        second = minutes[1]
        
        
        ans+="2"
        ans+=second
    else: ans+=minutes
    print(ans)