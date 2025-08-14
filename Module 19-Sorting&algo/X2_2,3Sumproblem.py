def twoSum(nums, target):
        d = {}  # create empty hashmap

        for i, num in enumerate(nums):
            need = target - num

            if need in d:
                return [d[need], i]  # we found the answer!

            d[num] = i  # store this number with its index

def threeSum(nums):
        nums.sort()  
        ans=set()
        for i in range (len(nums)-1):
            y = len(nums)-1
            x = i + 1
            #[-4,-1,-1,0,1,2]
            while(x<y):
                if nums[x]+nums[y]+nums[i]==0:
                    ans.add((nums[x],nums[y],nums[i]))
                if nums[x]+nums[y]+nums[i]>0:
                    y-=1
                else:
                    x+=1
        return [list(b) for b in ans]

print(twoSum([2,7,11,15],9))
print(threeSum([-1,0,1,2,-1,-4]))#get the array of 0s sum