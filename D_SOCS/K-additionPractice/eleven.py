tc = int(input())

for i in range(tc):
    bigint = int(input())
    quotient, remainder = divmod(bigint, 11)
    if remainder == 0:
        print("Case #{}: Yeah".format(i + 1))
    else:
        print("Case #{}: Nah".format(i + 1))
