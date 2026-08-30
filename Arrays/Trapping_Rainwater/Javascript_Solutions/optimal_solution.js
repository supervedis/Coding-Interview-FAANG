/* [0,1,0,2,1,0,3,1,0,1,2] */
const trap_rainwater = function trap_water(heights) {
  let total = 0;
  let leftPointer = heights[0];
  let rightPointer = heights[heights.length - 1];
  let maxL = 0;
  let maxR = heights[rightPointer];
  const processSide = (currentHeight, maxHeight) => {
    if (maxHeight > currentHeight) {
      total += maxHeight - currentHeight;
    } else {
      maxHeight = currentHeight;
    }
    return maxHeight;
  };

  while (leftPointer <= rightPointer) {
    if (heights[leftPointer] <= heights[rightPointer]) {
      maxL = processSide(heights[leftPointer], maxL);
      ++leftPointer;
    } else {
      maxR = processSide(heights[rightPointer], maxR);
      --rightPointer;
    }
  }
  return total;
};

console.log(trap_rainwater([0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2]));
console.log(trap_rainwater([3, 0, 3]));
