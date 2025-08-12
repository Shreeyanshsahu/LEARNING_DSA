arr=[1,2,9,10]

a = 16 
count={}
for i in range(len(arr)):
    count[arr[i]]=sum(abs(x-arr[i]) for x in arr)

key = [key for key,value in count.items() if value==a]
print(key)