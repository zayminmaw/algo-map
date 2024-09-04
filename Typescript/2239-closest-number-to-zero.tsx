// Explanation https://www.youtube.com/watch?v=dLlKA5DQKYs
// Question https://leetcode.com/problems/find-closest-number-to-zero/description/

function findClosestNumber(nums: number[]): number {
  let closestNum = nums[0];
  nums.forEach((num) => {
    if (Math.abs(num) < Math.abs(closestNum)) {
      closestNum = num;
    }
  });
  return closestNum < 0
    ? nums.find((n) => n === Math.abs(closestNum))
      ? Math.abs(closestNum)
      : closestNum
    : closestNum;
}
