

# import the module 
import sys 
def out_of_order(arr,idx):
    
    val = arr[idx]
    if idx==0 :
        return val>arr[1]
    if idx==len(arr)-1:
        return val <arr[len(arr)-2]
    return val > arr[idx+1] or val < arr[idx-1]
def sub_array_sort(arr):
    smallestVal = float('-inf')
    largestVal= float('inf')
    for i in range(len(arr)):
        if out_of_order(arr, i):
            largestVal= max(largestVal, arr[i])
            smallestVal= min(smallestVal, arr[i])
            
    if smallestVal==float('-inf'):
        print("-1, -1")
        return        
    leftIdx= 0
    rightIdx= len(arr)-1
    while arr[leftIdx]<=smallestVal:
        leftIdx +=1
    while arr[rightIdx]>=largestVal:
        rightIdx-=1
    print("-----LEFT IDX IS ",leftIdx, " RIGHT IDX IS", rightIdx  ) 
    
arr= [1, 2, 3, 4,5,6,7, 8 ,9, 10,11]
sub_array_sort(arr)           