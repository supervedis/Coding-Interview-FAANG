/* Given two string S and T, return if they are equal, when both are typed out.
Any '#' that appears in the string counts as a backspace. 

What happens when two #'s appear beside each other?
  Delete the two values before the first hash.
What happens to the # when there is no character to remove?
  It deletes nothing then, just like backspace would.
Are two empyt strings equal to each other?
  Yes consider two empty strings equal to each other.
Does case sensitivity matter?
  Yes it does, "a" does not equal "A".

  inputs : "ab#z", "ac#z"
  output : false
*/
const str1 = "ab#z";
const str2 = "ac#z";
const typedString = function is_same(word1, word2){
    let word1_seq = parseString(word1);
    let word2_seq = parseString(word2);

    if(word1_seq.length !== word2_seq.length) return false;

    let i = 0;
    while(i<word1_seq.length){
        if(word1_seq[i] !== word2_seq[i]) return false;
        ++i;
    }

    return true;

    function parseString(str) {
        let parsed_string = [];
        for (let index = 0; index < str.length; index++) {
            parsed_string.push(str[index]);
            if (str[index] === '#') parsed_string.pop();
        }
        return parsed_string;
    }
}

console.log(typedString(str1,str2));