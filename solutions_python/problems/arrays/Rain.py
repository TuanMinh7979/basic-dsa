def trapped_water(heights):
    n = len(heights)
    # Store the nearest left max value
    left = [0] * n
    # Store the nearest right max value
    right = [0] * n
    left[0] = heights[0]
    right[n-1] = heights[n-1]

    # Create data for lists
    for i in range(1, n):
        left[i]= max(left[i-1], heights[i])
        right[n-(i+1)]= max(right[n-i], heights[n-(i+1)])
    
    rs= 0
    for j in range(n):
         rs+=(min(left[j], right[j])-heights[j])
    return rs
water = [0, 1, 2, 5, 1, 3]
print(trapped_water(water))
