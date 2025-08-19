arr = [4, 0, 1, 2, 0, 2, 0, 2, 0, 3, 0, 5]  # we want to maintain the order of original numbers
n = len(arr)

for i in range(n - 1):
    flag = True
    for x in range(n - 1 - i):
        if arr[x] == 0 and arr[x + 1] != 0:
            arr[x], arr[x + 1] = arr[x + 1], arr[x]  # one-line swap
            flag = False
    if flag:
        break

# Print sorted array
for num in arr:
    print(num, end=" ")
print()
