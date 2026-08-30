/* Given an array of integers, return the indices of two numbers 
that add up to a given integer.

Constraints:
- all the numbers are positive
- No duplicates in the array
- Return null if no solution available
- There will always be a solution available
- Can there be multiple pairs that add to the target value
  . Only 1 pair of numbers add up to the target solution

Test cases:
1. Solution available
   input =>[1,3,7,9,2], target=11 output => [3,4] 
2. No solution available
   input =>[1,3,7,9,2], target=29 output => null
3. Empty array with a target
   input =>[], target=11 output => null
5. Single element array with a target
   input =>[1], target=11 output => null 
6. input =>[1,3], target=4 output => [0,1] 
*/

const two_sum = function(nums, target){
    const compliments = {};
    let diff;
    for (let i = 0; i < nums.length; i++) {
        diff = target - nums[i];
        compliments[diff] = i;
        let value = nums[i];
        if(compliments[value] >= 0){
            return [compliments[value], i];
        }
    }
    return null;
}

console.log(two_sum([1,3,7,9,2],4))