/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.47%)
 * Likes:    574
 * Dislikes: 2234
 * Total Accepted:    352.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
       if(s.length()==0) {
         return 0;
       }
       if(s[s.length()-1]==' ') {
           // s.erase(s.begin()+s.find_last_not_of(' ')+1,s.end());
           s.erase(s.find_last_not_of(' ')+1);
       }
       std::size_t start = s.find_last_of(' ');
       if(start == std::string::npos) {
         return s.length();
       }
       std::size_t end = s.find_last_not_of(' ');
       if(end == std::string::npos) {
         return 0;
       }
       int len_of_lastword = end - start;
       return len_of_lastword;
    }
};
// @lc code=end

// 多种情况： " ", "  a  b   ", "a "
/*
class Solution {
public:
    int lengthOfLastWord(string s) { 
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};
*/