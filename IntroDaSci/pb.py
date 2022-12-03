# import re
def palindrome(str):
    return str==str[::-1]
string = input()
# string = re.sub("\s+","", string)
string = string.lstrip()
print(palindrome(string))