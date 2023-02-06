def snowflake(n):
    for i in range(n*2-1):
        if i < n:
            for j in range(n-i-1):
                print(" ", end="")
            for j in range(2*i+1):
                print("*", end="")
        else:
            for j in range(i-n+1):
                print(" ", end="")
            for j in range(2*(n-i-1)-1):
                print("*", end="")
        print("")

#example usage
snowflake(2)
