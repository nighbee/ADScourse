def is_balanced(s):
    # your code here
    stack =[]
    for char in s:
        if stack and stack[-1] == char:
                stack.pop()
        else:
            stack.append(char)
    return  len(stack)

s =input()
if is_balanced(s):
    print("NO")
else:
    print("YES")
