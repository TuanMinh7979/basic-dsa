function countMinSwap(arr) {

    let pairList = []
    for (let i = 0; i < arr.length; i++) {
        pairList.push({
            val: arr[i],
            idx: i
        })
    }
    pairList.sort((a, b)=>a.val-b.val)
   
    let visited = [false, false, false]
    let ans = 0;
    for (let i = 0; i < pairList.length; i++) {


        let item = pairList[i]
        if (visited[i] || item.idx == i) {
            continue;
        }

        let curIdx = i;
        let  cnt = 0;
        while (!visited[curIdx]) {
            visited[curIdx] = true;
            curIdx = pairList[curIdx].idx;
            cnt++;
        }
        ans+=(cnt-1)


    }

    return ans;



}

let arr = [6,2, 1, 4, 3]
console.log(countMinSwap(arr))