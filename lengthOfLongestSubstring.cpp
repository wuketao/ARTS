#include <string>
#include <iostream>
#include <deque>
#include <set>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::deque;
using std::set;
using std::vector;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		cout << __func__ << ": in: " << s << endl;

		for (auto letter : s) {
			if (substringSet.find(letter) == substringSet.end()) {
				pushBackValToSubstringAndSet(letter);
				cout << __func__ << ": add " << letter << ": " << substringToString() << endl;
			} else {
				updateSubstringAndSet(letter);
				cout << __func__ << ": update by " << letter << ": " << substringToString() << endl;
			}
			updateLongestSubstring();
		}

		return longestSubstring.size();
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
