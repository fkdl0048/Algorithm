class TrieNode {
public:
    // 자식 노드들
    TrieNode* children[26];
    // 단어의 끝 여부
    bool isEnd;

    TrieNode() {
        // 모든 자식 노드를 nullptr로 초기화
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    /** 생성자 */
    Trie() {
        root = new TrieNode();
    }
    
    /** 단어 삽입 */
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            // 해당 문자의 노드가 없으면 생성
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            // 다음 노드로 이동
            node = node->children[index];
        }
        // 단어의 끝 표시
        node->isEnd = true;
    }
    
    /** 단어 검색 */
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            // 해당 문자가 없으면 false
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        // 단어의 끝까지 도달했고, isEnd가 true인지 확인
        return node->isEnd;
    }
    
    /** 접두사 검색 */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            // 해당 문자가 없으면 false
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        // 접두사의 마지막 문자까지 도달하면 true
        return true;
    }
};
