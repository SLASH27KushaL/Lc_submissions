// Last updated: 6/26/2025, 7:56:13 PM
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        std::vector<std::string> result;
        std::array<int, 26> merge;
        merge.fill(0);
        for (auto& subword : words2) {
            std::array<int, 26> letters;
            letters.fill(0);
            for (char ch : subword) {
                ++letters[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                merge[i] = std::max(merge[i], letters[i]);
            }
        }
        for (auto& word : words1) {
            if (checkWords(word, merge)) result.push_back(std::move(word));
        }
        return result;
    }

    bool checkWords(std::string& word, std::array<int, 26>& lettersSubword) {
        std::array<int, 26> lettersWord;
        lettersWord.fill(0);
        for (char ch : word) {
            ++lettersWord[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (lettersWord[i] < lettersSubword[i]) return false;
        }
        return true;
    }
};