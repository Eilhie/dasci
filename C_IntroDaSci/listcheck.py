def is_sorted(check):
    asc = desc = True
    i, L = 0, len(check)
    while (i < (L-1)) and (asc or desc):
        if check[i] < check[i+1]:
            desc = False
        elif check[i] > check[i+1]:
            asc = False
        if not (asc or desc):
            break
        i += 1
    if asc and desc:
        return "Ascending and Descending"
    elif asc:
        return "Ascending"
    elif desc:
        return "Descending"
    else:
        return "Not ascending and not descending"

number = list(map(int,input().split()))

print(is_sorted(number))