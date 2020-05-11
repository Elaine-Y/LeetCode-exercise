/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (42.85%)
 * Likes:    1566
 * Dislikes: 260
 * Total Accepted:    419.1K
 * Total Submissions: 971K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
 string addBinary(string a, string b) { 
    int asize = a.size();
    int bsize = b.size();
    // 1 位数不同 需先补位 方便计算
    while(asize<bsize) {
      a = '0' + a;
      asize++;
    }
    while(bsize < asize) {
      b = '0' + b;
      bsize++;
    }
    // 2 carry存放进位  a作为结果返回
    int carry = 0;
    for (int i = asize - 1; i >= 0;i--) {
      int sum = a[i] - '0' + b[i]-'0' + carry;
      a[i] = sum % 2 + '0';
      carry = sum / 2; 
    }
    // 3 有溢出 需补位
    if(carry > 0) {
      a = '1' + a;
    }
    return a;
 }
};
// @lc code=end

