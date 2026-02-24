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


  Test Cases: ["abcd", "abcd"], ["",""],["a","a"],["ab","a"],["a#","a"],["a#","a#"],["a"]
*/
const str1 = "ab##";
const str2 = "ad#c";
const typedString = function is_same(S, T) {
  let i = S.length - 1;
  let j = T.length - 1;

  while (i >= 0 || j >= 0) {
    if (S[i] === "#" || T[j] === "#") {
      ({ i, j } = check_index(S, i, T, j));
    } else {
      if (S[i] !== T[j]) return false;
      else {
        i--;
        j--;
      }
    }
  }

  function check_index(S, i, T, j) {
    if (S[i] === "#") {
      let hash_count = 2;
      while (hash_count > 0) {
        i--;
        hash_count--;
        if (S[i] === "#") hash_count += 2;
      }
    }

    if (T[j] === "#") {
      let hash_count = 2;
      while (hash_count > 0) {
        j--;
        hash_count--;
        if (T[j] === "#") hash_count += 2;
      }
    }
    return { i, j };
  }
  return true;
};

console.log(typedString("ab##", "c#d#"));
console.log(typedString("a#c", "b"));
console.log(typedString("####", ""));
console.log(typedString("", "#"));
