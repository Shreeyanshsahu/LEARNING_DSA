s = "DYIFZHZFHXEOHXXYUZ"

# Step 1: filter out only chars >= 'X'
ans = "".join([ch for ch in s if ch >= 'X'])
print("Filtered:", ans)

# Step 2: bubble sort (ascending order)
ans_list = list(ans)   # convert string to list for swapping
n = len(ans_list)

for i in range(n):
    swapped = False
    for j in range(0, n - 1 - i):   # bubble pass
        if ans_list[j] > ans_list[j + 1]:  # ascending order
            ans_list[j], ans_list[j + 1] = ans_list[j + 1], ans_list[j]
            swapped = True
    if not swapped:
        break  # stop early if already sorted

sorted_ans = "".join(ans_list)
print("Sorted:", sorted_ans)
