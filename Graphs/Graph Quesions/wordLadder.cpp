#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // unordered set is used as we want unique words in wordList.
    // If isPresent becomes true than it means endWord is present
    // in unordered set.
    // Also pushing every element of wordList to unordered set.
    unordered_set<string> myset;
    bool isPresent = false;

    for (auto word : wordList)
    {
        if (endWord.compare(word) == 0)
        {
            isPresent = true;
        }
        myset.insert(word);
    }

    // if not present than it will return 0 as we cannot reach endword
    // without it being in wordlist.
    if (isPresent == false)
    {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);
    int depth = 0;
    while (!q.empty())
    {
        // increase depth by one.
        // and initiallise lsize by current queue size.
        depth += 1;
        int lsize = q.size();
        while (lsize--)
        {
            string curr = q.front();
            q.pop();

            // check by changing every element of a particular word.
            // like in dog -> check by changing d,o,g.
            for (int i = 0; i < curr.length(); i++)
            {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;

                    // if curr == temp -> then continue as on changing d
                    //  by d in dog -> it will still remains dog.
                    // Hence,makes no sense on changing d
                    if (curr.compare(temp) == 0)
                    {
                        continue;
                    }

                    // if on changing it(temp) becomes = to endword
                    // then we got our ans and hence return depth + 1.
                    if (temp.compare(endWord) == 0)
                    {
                        return depth + 1;
                    }

                    // otherwise if temp is found in set then push that
                    // word in queue and also remove it from set.
                    // As we can use a word only once in graph.
                    if (myset.find(temp) != myset.end())
                    {
                        q.push(temp);
                        myset.erase(temp);
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int ans = ladderLength(beginWord, endWord, wordList);
    cout << ans << endl;
    return 0;
}

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord
// does not need to be in wordList.
// sk == endWord
//
// Given two words, beginWord and endWord, and a dictionary wordList,
// return the number of words in the shortest transformation sequence
// from beginWord to endWord, or 0 if no such sequence exists.

// Input: beginWord = "hit", endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" ->
// "dot" -> "dog" -> cog", which is 5 words long.