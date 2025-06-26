// Last updated: 6/26/2025, 10:51:02 PM
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int cur_len = 0;
        vector<string> tempo;      
        vector<string> lineWords;  

        for (int i = 0; i < n; ++i) {
            int wlen = words[i].size();
           
            if (lineWords.empty() ? cur_len + wlen <= maxWidth
                                  : cur_len + 1 + wlen <= maxWidth) {
                if (!lineWords.empty()) cur_len += 1;  
                cur_len += wlen;
                lineWords.push_back(words[i]);
            }
            else {
                string t;
                int totalWordLen = cur_len - (int)lineWords.size() + 1;  
              
                int slots = lineWords.size() - 1;
                if (slots == 0) {
                    t = lineWords[0] + string(maxWidth - totalWordLen, ' ');
                } else {
                    int totalSpaces = maxWidth - totalWordLen;
                    int spacePer = totalSpaces / slots;
                    int extra     = totalSpaces % slots;
                    for (int j = 0; j < lineWords.size(); ++j) {
                        t += lineWords[j];
                        if (j < slots) {
                            t += string(spacePer + (j < extra ? 1 : 0), ' ');
                        }
                    }
                }
                tempo.push_back(t);

                lineWords.clear();
                lineWords.push_back(words[i]);
                cur_len = wlen; 
            }
        }

        if (!lineWords.empty()) {
            string t = lineWords[0];
            for (int i = 1; i < lineWords.size(); ++i) {
                t += " " + lineWords[i];
            }
            if (t.size() < maxWidth)
                t += string(maxWidth - t.size(), ' ');
            tempo.push_back(t);
        }

        return tempo;
    }
};
