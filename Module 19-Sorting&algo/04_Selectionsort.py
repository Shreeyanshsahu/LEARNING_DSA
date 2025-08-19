arr = [23, 24, 12, 10, 22]
n = len(arr)

for i in range(n - 1):
    min_index = i
    for j in range(i + 1, n):
        if arr[j] < arr[min_index]:
            min_index = j
    if min_index != i:  # swap only if needed
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Print sorted array
for num in arr:
    print(num, end=" ")
print()
