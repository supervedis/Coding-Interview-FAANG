/* [0,1,0,2,1,0,3,1,0,1,2] */
const trap_rainwater = function trap_water(heights){
    let total = 0;
    for (let i = 0; i < heights.length; i++) {
        let maxL = 0;
        let maxR = 0;
        let leftIndex = i;
        let rightIndex = i;
        while(leftIndex >=0 )
            maxL = Math.max(maxL, heights[leftIndex--]);
        while(rightIndex < heights.length)
            maxR = Math.max(maxR, heights[rightIndex++]);
        const current_area = Math.min(maxL, maxR) - heights[i] < 0 ? 0 : Math.min(maxL, maxR) - heights[i];
        total += current_area;
    }
    return total;
}

console.log(trap_rainwater([0,1,0,2,1,0,3,1,0,1,2]));
console.log(trap_rainwater([3,0,3]));