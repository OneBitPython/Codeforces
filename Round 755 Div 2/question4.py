s1 = "codeforces"
s2 = "technocup"

substr = []
poses = []
for i, letter in enumerate(s1):
        
    pos = s2.find(letter)
    print(letter, pos)
    if pos != -1:
        poses.append(pos)
        if len(poses)>1:
            if poses[-1]>poses[-2]:
                substr.append(letter)
        else:
            substr.append(letter)
print(substr)
