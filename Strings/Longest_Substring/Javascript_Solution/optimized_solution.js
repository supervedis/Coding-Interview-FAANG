
/*Given a string, find the length of the longest substring without repeating characters*/

const longest_substring_array_impl=function find_longest(str){
    let longest_sub = 0;
    let left = 0;
    let len = str.length;
    let counter = 0;
    let substring = [];
    for (let right = 0; right < len; right++) {
        counter = 0;
        while(left < len && !substring.includes(str[left])){
            substring.push(str[left]);
            counter = substring.length;
            left++;
        }
        substring.shift();
        if(counter > longest_sub) longest_sub = counter;
    }
    return longest_sub;
}


const longest_substring_hashmap_impl = function find_longest(arr){
    let left = 0;
    let substring = {};
    let longest = 0;
    const len = arr.length
    for (let right = 0; right < len; right++) { 
        const curr_char = arr[right];
        const prev_char = substring[curr_char];
        if(prev_char >= left){
            left = prev_char + 1;
        }

        substring[curr_char] = right;
        longest = Math.max(longest, right - left+1);
    }
    return longest;
}

const smallest_subarray_with_sum = function smallest_subarray(arr, target){
    let min_length = Number.POSITIVE_INFINITY;
    let left = 0;
    let len = arr.length;
    let window_sum = 0;
    for (let right = 0; right < len; right++) {
        window_sum += arr[right];
        
        while(window_sum >= target){
            min_length = Math.min(min_length, right - left+1);
            window_sum -= arr[left];
            left += 1;
        }
    }
    min_length = min_length !== Math.MIN_VALUE ? min_length : 0;
    return min_length;
}

arr = [2, 1, 5, 2, 3, 2];
str = "abbcdea";
let alphabets = {'a':1};
console.log(alphabets['b'] === undefined ? "Not available":alphabets['b']);
//console.log(smallest_subarray_with_sum(arr,7))
//console.log(longest_substring_array_impl(str))
//console.log(longest_substring_array_impl("abcbdaac"))