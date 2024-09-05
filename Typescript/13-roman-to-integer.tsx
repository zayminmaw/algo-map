// Explanation https://www.youtube.com/watch?v=JlVOzbOJiv0
// Question https://leetcode.com/problems/roman-to-integer/description/

function romanToInt(s: string): number {
  const romanNumberMap = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };
  let ans = 0;

  s.split("").forEach((i, ind) => {
    if (s[ind + 1] && romanNumberMap[s[ind]] < romanNumberMap[s[ind + 1]]) {
      ans -= romanNumberMap[s[ind]];
    } else {
      ans += romanNumberMap[s[ind]];
    }
  });

  return ans;
}
