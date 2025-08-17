def majority_element(nums):
    # Step 1: Find candidate
    candidate = None
    count = 0

    for num in nums:
        if count == 0:
            candidate = num
        count += (1 if num == candidate else -1) # Increasing the count if the previous element is same as candidite
        #if not decreasing it zero 

    # Step 2: Verify candidate
    if nums.count(candidate) > len(nums) // 2: 
        return candidate
    else:
        return None  # No majority element


arr = [3, 2, 3, 1, 3, 4, 3]
print("majority element which occur more than n/2 of arr is ",majority_element(arr))
 