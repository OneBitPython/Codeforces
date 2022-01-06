for q in range(int(input())):
    w, h = map(int,input().split())
    x_coords = list(map(int,input().split()))[1:]
    x_coords2 = list(map(int, input().split()))[1:]
    y_coords = list(map(int, input().split()))[1:]
    y_coords2 = list(map(int, input().split()))[1:]

    ans= []

    base1 = x_coords[-1] - x_coords[0]
    height1 = h
    ans.append(base1*height1)
    base1 = x_coords2[-1] - x_coords2[0]
    ans.append(base1*height1)

    base2 = y_coords[-1] - y_coords[0]
    height2 = w
    ans.append(base2*height2)
    base2 = y_coords2[-1] - y_coords2[0]
    ans.append(base2*height2)
    print(max(ans))