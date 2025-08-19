arr = [23, 24, 12, 10, 22]
ans = [-1] * len(arr)
n = len(arr)

for i in range(n):
    min_val = float("inf")
    temp = 0

    for j in range(n):
        if ans[j] > -1:
            continue
        if arr[j] < min_val:
            min_val = arr[j]
            temp = j

    ans[temp] = i

# Print sorted array
for num in ans:
    print(num, end=" ")
print()
