class Solution {
    std::unordered_map<std::string, unsigned int> word_map;  // words 빈도 저장
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;
        if (words.empty() || s.empty()) return result;

        unsigned int word_length = words[0].size();    // 각 단어의 길이
        unsigned int word_count = words.size();        // words의 단어 개수
        unsigned int total_length = word_length * word_count; // 찾아야 할 총 길이

        // 단어 빈도 맵을 초기화
        word_map.clear();
        for (const std::string& word : words)
            word_map[word]++;

        // 단어 길이만큼 offset을 돌면서 탐색
        for (unsigned int offset = 0; offset < word_length; ++offset) {
            unsigned int left = offset;
            std::unordered_map<std::string, unsigned int> seen;
            int valid_count = 0;

            // offset부터 끝까지 탐색, word_length씩 이동
            for (unsigned int right = offset; right + word_length <= s.size(); right += word_length) {
                std::string sub = s.substr(right, word_length);

                if (word_map.find(sub) != word_map.end()) {  // words에 있는 단어인 경우
                    seen[sub]++;
                    valid_count++;

                    // 단어의 빈도가 초과되면 윈도우를 축소
                    while (seen[sub] > word_map[sub]) {
                        std::string left_word = s.substr(left, word_length);
                        seen[left_word]--;
                        valid_count--;
                        left += word_length;
                    }

                    // 유효한 단어들이 모두 일치하는 경우
                    if (valid_count == word_count) {
                        result.push_back(left);
                    }
                } else {  // words에 없는 단어인 경우
                    seen.clear();
                    valid_count = 0;
                    left = right + word_length;
                }
            }
        }

        return result;
    }
};