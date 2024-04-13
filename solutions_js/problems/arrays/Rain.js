function trappedWater(heights) {
    const n = heights.length;
    // Store the nearest left max value
    const left = new Array(n).fill(0);
    // Store the nearest right max value
    const right = new Array(n).fill(0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    // Create data for lists
    for (let i = 1; i < n; i++) {
        left[i] = Math.max(left[i - 1], heights[i]);
        right[n-(i+1)]=Math.max(right[n-i] ,heights[n-(i+1)])
    }
    // for (let i = n - 2; i >= 0; i--) {
    //     right[i] = Math.max(right[i + 1], heights[i]);
    // }

    let rs = 0;
    for (let j = 0; j < n; j++) {
        rs += Math.min(left[j], right[j]) - heights[j];
    }

    return rs;
}

const water = [0, 1, 2, 5, 1, 3];
console.log(trappedWater(water));
