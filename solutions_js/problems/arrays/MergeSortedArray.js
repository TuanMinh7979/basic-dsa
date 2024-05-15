function mergeSortedArray(arrA, arrB) {

    let minLen = arrA.length > arrB.length ? arrB.length : arrA.length;

    let rs = []
    let i = 0;
    let aI=i;
    let bI=i;
    for (; i < minLen*2; i++) {
        if (arrA[aI] < arrB[bI]) {
            rs.push(arrA[aI]);
            aI++;
        }
        else if (arrA[aI] > arrB[bI]) {
            rs.push(arrB[bI]);
            bI++;
        } 
    
    }
    console.log(i)

    while ( aI < arrA.length) {
        rs.push("---"+arrA[aI])
        aI++;
    }
    while (bI < arrB.length) {
        rs.push("***", arrB[bI])
        bI++;
    }

    return rs;

}

console.log(mergeSortedArray([1, 3, 5, 7, 10], [2, 4, 6, 8]))