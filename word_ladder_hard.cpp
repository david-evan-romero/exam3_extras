#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) return steps;
                
                // Try changing every character
                for (int i = 0; i < word.length(); ++i) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word); // Mark visited
                        }
                    }
                    word[i] = original; // Restore
                }
            }
            steps++;
        }
        return 0;
    }
};
