// Explanation https://www.youtube.com/watch?v=qq-AqEPKsI8
// Question https://leetcode.com/problems/merge-strings-alternately/description/

function mergeAlternately(word1: string, word2: string): string {
  let longerWord = word1.length > word2.length ? word1 : word2;
  let ans = "";

  for (let i = 0; i < longerWord.length; i++) {
    ans += word1[i] ? word1[i] : "";
    ans += word2[i] ? word2[i] : "";
  }

  return ans;
}
