/*Given a string, find the length of the longest substring without repeating characters*/

const longest_substring=function find_longest(str){
    let longest_sub = 0;
    for (let index = 0; index < str.length; index++) {
        let substring = [];
        for (let j = index; j < str.length; j++) {
            if(!substring.includes(str[j])){
                substring.push(str[j]);
            }else{
                break;
            }
        }

        if(substring.length > longest_sub) longest_sub = substring.length;
    }
    return longest_sub;
}

//console.log(longest_substring(""))
console.log(longest_substring("abcd"))
/*console.log(longest_substring("as"))
console.log(longest_substring("aas"))
console.log(longest_substring("Abracadaaaaaaabra"))*/