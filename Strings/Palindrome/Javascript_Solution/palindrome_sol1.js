/*A man, a plan, a canal: Panama */
const is_palindrome = function is_valid_palindrome(s){
    if(s.length <= 1) return true;

    const lowercase_s = s.toLowerCase();
    const len = s.length;
    let i = 0;
    let j = len -1;
    while(i <= j){
        const code_i = lowercase_s.charCodeAt(i);
        const code_j = lowercase_s.charCodeAt(j);
        if(!is_alphanumeric(code_i)){
            i++;
            continue;
        }

        if(!is_alphanumeric(code_j)){
            j--;
            continue;
        }

        if(lowercase_s[i] !== lowercase_s[j]) return false;
        i++;
        j--;
    }

    function is_alphanumeric(code) {
        return ((code >= 48 && code <= 57) || (code >= 97 && code <= 122));
    }

    return true;
}

const is_almost_palindrome = function(s){
    s = s.replace(/[^A-Za-z0-9]/g,"").toLowerCase();
    let len = s.length;
    let left = 0;
    let right = len;

    while(left <= right){
        if(s[left] !== s[right]){
            if(s[++left] === s[right]){
                continue;
            }else{
                --left;
            }
            
            if(s[left] === s[--right]){
                continue;
            }else{
                ++right;
            }
             return false;
        }
        ++left;
        --right;
    }

    return true;
}
console.log(is_palindrome("abb, a"))
console.log(is_palindrome("A man, a plan, a canal: Panama "))
console.log(is_almost_palindrome("abccdba"))
console.log(is_almost_palindrome("A man, a plan, a canal: Panama "))