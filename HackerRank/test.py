def make_list(number):
    names = []
    for item in range(number):
        names.append(input("enter name "))
    print(names)

number = int(input("number of name"))
names = make_list(number)

for name in names:
    if name[1] == "A":
        print("name", name, " start with A")

