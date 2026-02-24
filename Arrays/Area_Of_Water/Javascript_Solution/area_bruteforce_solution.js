/*
You are given an array of positive integers where each integer represents the height of a vertica line on a 
chart. Find two lines which together with the x-axis forms a container that would hold the greatest amount of water.
Return the area of water it would hold.

Constraints:
------------
1. Heights are all positive integers.
2. Return null when an empty array is passed.
3. Does the thickness of the lines affect the area?
   No, assume they take up no space.
4. Do the left and right sides of the graph count as walls?
   No, the sides cannot be used to form a container.
5. Can we pick two values if one value is higher in the middle?
   yes, the value in the middle won't affect the container.

   HashMap in JS.
*/

const area_between_lines = function(nums){
    let max_area = 0;
    for(let i = 0; i < nums.length; i++){
        for (let j = i+1; j < nums.length; j++) {
            const length = Math.min(nums[i],nums[j]);
            const width = j-i;
            const area = length * width;
            max_area = Math.max(max_area, area);
        }
    }
    return max_area;

    function min(a,b){
        return a > b ? b : a;
    }
}

console.log(area_between_lines([7,1,2,3,4,9]))