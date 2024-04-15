function outOfOrder(arr, idx){
    let val =arr[idx];
    if(idx==0){
        return val > arr[idx+1];
    }
    if(idx==arr.length-1){
        return val < arr[idx-1];
    }

    return val > arr[idx+1] || val <arr[idx-1];


}


function subArraySort(){

    let smallestVal= Number.MAX_VALUE
    let largestVal= Number.MIN_VALUE


    for(let i=0; i<arr.length; i++){
        if(outOfOrder(arr ,i)){
            largestVal= Math.max(largestVal , arr[i])
            smallestVal= Math.min(smallestVal , arr[i])
        }

    }

    if(smallestVal==Number.MAX_VALUE){
        console.log("-1 ,-1")
        return
    }

   
    leftIdx= 0;
    rightIdx= arr.length-1;



    while(largestVal<=arr[rightIdx]){

        rightIdx--;
    }

    while(smallestVal>=arr[leftIdx]){

        leftIdx++;
    }

    console.log("LEFT IDX IS ",leftIdx ," RIGHT IDX IS ",rightIdx )

}


let arr= [1, 2, 3, 4,5, 8,6,7, 9, 10,11];
subArraySort(arr)