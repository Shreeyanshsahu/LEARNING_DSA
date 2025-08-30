def mergesort(arr):
    if(len(arr)<=1):
        return arr
    arr1 = arr[0:len(arr)//2]
    arr2 = arr[len(arr)//2:len(arr)]
    mergesort(arr1)
    mergesort(arr2)

    mergearray(arr1,arr2,arr)
    return arr


def mergearray(arr1,arr2,arr):
    i,j,k=0,0,0
    while(k<len(arr1)+len(arr2)):
        if(i>=len(arr1)):
            arr[k]=arr2[j]
            k+=1
            j+=1
        elif(j>=len(arr2)):
            arr[k]=arr1[i]
            i+=1
            k+=1
        else:
            if(arr1[i]>=arr2[j]):
                arr[k]=arr2[j]
                k+=1
                j+=1

            else:
                arr[k]=arr1[i]
                i+=1
                k+=1
    return arr


        

        


arr=[2, 1, 23, 9, 5, 8, 7]
mergesort(arr)
print(arr)