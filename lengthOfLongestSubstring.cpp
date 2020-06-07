#include <string>
#include <iostream>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::deque;
using std::set;
using std::vector;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<int> char_map(256, -1);
		int start = -1;
		int size = s.size();
		int maxl = 0;

		for (int i = 0; i < size; ++i) {
			auto c = s[i];

			/* start is begin of count length. Why -1, because string pos begin 0;
			 * All char in substring is unique. 
			 * If char repeated in substring, set start pos to lasted char pos. 
			 * Not char pos +1, like -1 and 0.
			 * If not repeated, current char pos is the end of count length.
			 * current substring length = end - start; 
			 * */
			if (char_map[c] > start) {
				start = char_map[c];
			}

			char_map[c] = i;
			maxl = max(maxl, i - start);
		}

		return maxl;
    }

	void updateLongestSubstring(void)
	{
		if (substring.size() > longestSubstring.size())
			longestSubstring = substringToString();
	}

	void updateSubstringAndSet(const char &key)
	{
		deleteSubstringAndSetToEndByKey(key);
		pushBackValToSubstringAndSet(key);
	}

	void deleteSubstringAndSetToEndByKey(const char &key)
	{
		//cout << __func__ << ": delete " << key << " front: " << substringToString() << endl;
		while (!substring.empty()) {
			auto cur = substring.front();

			substringSet.erase(cur);
			substring.pop_front();

			if (cur == key)
				break;
		}
		//cout << __func__ << ": end: " << substringToString() << endl;
	}

	void deleteKeyInSubstringSet(const char &key)
	{
		substringSet.erase(key);
	}

	void pushBackValToSubstringAndSet(const char val)
	{
		substring.push_back(val);
		substringSet.insert(val);
	}

	void reset(void)
	{
		substring.clear();
		substringSet.clear();
		longestSubstring.clear();
	}

	string substringToString(void)
	{
		string s;

		for (auto ch : substring)
			s += ch;

		return s;
	}

	void test_base(const string &s)
	{
		int length = lengthOfLongestSubstring(s);

		cout << length << ": " << longestSubstring << endl;

		reset();
	}

	void test(void)
	{
		vector<string> strvec = {"pwwkew", "tmmzuxt", "", "aaa", "aabcedfaxyzopq", "aabcae", "abaccc", "abacccab"};

		for (auto s : strvec)
			test_base(s);
	}


private:
	deque<char> substring;
	set<char> substringSet;
	string longestSubstring;
};

int main(void)
{
	Solution solution;

	solution.test();

	return 0;
}
