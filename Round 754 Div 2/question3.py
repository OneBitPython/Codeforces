for q in range(int(input())):
    n = int(input())
    string = input()
    output = []
    tmp = ""
    for i in string:
        if tmp:
            tmp += i
            if tmp.count("a") > tmp.count("b") and tmp.count("a")>tmp.count("c"):
                output.append(tmp)
        if i == "a":
            if tmp == "":
                tmp += i
    if output == []:
        print(-1)
    else:
        print(output)
        print(len(output[0]))