
arr = [0,1,2,1,2,2,1,2,1,2,0,1,0,0,0,1,2]
#[0 1 2 1 0 2]
lo = 0
hi = len(arr)-1
mid=0
while(mid<=hi):
    if(arr[mid]==1):
        mid+=1
    elif(arr[mid]==0):
        arr[mid],arr[lo]=arr[lo],arr[mid]
        mid+=1
        lo+=1
    elif(arr[mid]==2):
        arr[mid],arr[hi]=arr[hi],arr[mid]
        hi-=1


print(arr)
        