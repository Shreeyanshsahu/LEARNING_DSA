from math import gcd

def juggling(nums, d):
    n = len(nums)
    d %= n  # handle d > n
    g = gcd(n, d)
    
    for i in range(g):
        temp = nums[i]
        j = i
        while True:
            k = (j + d) % n
            if k == i:
                break
            nums[j] = nums[k]
            j = k
        nums[j] = temp

nums = [1, 2, 3, 4, 5]
print(gcd(5,3))
juggling(nums, 3)
print(nums)  # Output: [4, 5, 1, 2, 3]
