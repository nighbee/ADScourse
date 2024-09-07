def proc_string(s):
    stack = []
    for char in s:
        if char =="#" :
            if stack:
                stack.pop()
        else:
            stack.append(char)
    return "".join(stack)

s1,s2 = input().split()

finals1 = proc_string(s1)
finals2 = proc_string(s2)
if finals1 == finals2:
    print("YES")
else:
    print("NO")
