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

function two_sum(arr, target){
    for (let i = 0; i < arr.length; i++) {
        const element =target - arr[i];
        for (let j = i+1; j < arr.length; j++) {
            if(element == arr[j]) return [i,j];
        }
    }
    return null;
}

console.log(two_sum([1,3,7,9,2], 11));