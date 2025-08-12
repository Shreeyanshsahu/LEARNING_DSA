arr = [23,24,12,10,22]

for i in range(len(arr)-1):
    for x in range(len(arr)-1-i):
        if(arr[x]>arr[x+1]):
            arr[x],arr[x+1]=arr[x+1],arr[x]
print(arr)