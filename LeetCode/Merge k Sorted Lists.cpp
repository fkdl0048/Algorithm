/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// using namespace std;

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* result = new ListNode();
//         ListNode* dummy = result;

//         while (true) {
//             int minIndex = -1;
//             int minValue = INT_MAX;

//             for (int i = 0; i < lists.size(); i++) {
//                 if (lists[i] != nullptr && lists[i]->val < minValue) {
//                     minValue = lists[i]->val;
//                     minIndex = i;
//                 }
//             }

//             if (minIndex == -1) break;

//             dummy->next = lists[minIndex];
//             dummy = dummy->next;

//             lists[minIndex] = lists[minIndex]->next;
//         }

//         return result->next;
//     }
// };

struct Compare {
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (auto list : lists){
            if (list){
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(!minHeap.empty()){
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();

            current->next = smallestNode;
            current = current->next;

            if (smallestNode->next){
                minHeap.push(smallestNode->next);
            }
        }

        return dummy->next;
    }
};