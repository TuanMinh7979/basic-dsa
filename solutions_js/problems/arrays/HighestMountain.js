function heighestMountain(arr) {


    let maxMtLen = 0;
    // [5, 1, 2, 3,4, 3, 2, 5] max len is 6 
    for (let i = 1; i < arr.length; i++) {
        let cnt = 1;
      
        
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            let temp = i;
            while (arr[temp - 1] < arr[temp] && temp>=0) {
                cnt++;
                temp--;
            }
            temp = i;
            while (arr[temp] > arr[temp + 1] && temp<arr.length) {
                cnt++;
                temp++;

            }
        }
        maxMtLen= Math.max(cnt, maxMtLen)

    }

    return maxMtLen

}

let arr = [5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4];
// let arr = [5, 1, 2, 3,4, 3, 1,9, 5,1];
console.log(heighestMountain(arr))