a = [9, 5, 7, 6, 3, 2, 1, 4, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]

max1 = a[0]
max2 = a[0]
max3 = a[0]
for num in a:
    if num > max1:
        max3 = max2
        max2 = max1
        max1 = num
    elif num > max2:
        max3 = max2
        max2 = num
    elif num > max3:
        max3 = num
print(max1, max2, max3)



# 9 9
# 5 5
# 3 5
# 
# -3 -1 -10 -6
# -3 -1 -1
# -3 -3 -3
# -3 -3 -3
