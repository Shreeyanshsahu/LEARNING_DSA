def countcheck(piles, mid):
    return sum((i + mid - 1) // mid for i in piles)

def minEatingSpeed(piles, h):
    low, high = 1, max(piles)
    ans = high
    while low <= high:
        mid = (low + high) // 2
        count = countcheck(piles, mid)
        if count <= h:
            ans = mid     
            high = mid - 1
        else:
            low = mid + 1 
    return ans

piles = [3, 6, 7, 11]
h = 8
print(minEatingSpeed(piles, h))  # 4
