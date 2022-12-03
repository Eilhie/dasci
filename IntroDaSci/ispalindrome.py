import re

def ispalindrome(str):
    # string = ''
    # for i in range(len(str)):
    #     if str[i] != " ":
    #         string += str[i]

    # for i in str:
    #     if i == ' ':
    #         str = str.replace(" ", "")

    #str = "".join(str.split())

    str = re.sub(" ", "", str)

    #str = str.lstrip() optional

    print(str)
    # print(string)
    return str == str[::-1]

string = input()
# ispalindrome = True
# for i in range(len(string)):
#     if(string[i] != string[len(string) - 1 - i]):
#         ispalindrome = False

# if(ispalindrome):
#     print("TRUE")
# else:
#     print("FALSE")

print(ispalindrome(string))