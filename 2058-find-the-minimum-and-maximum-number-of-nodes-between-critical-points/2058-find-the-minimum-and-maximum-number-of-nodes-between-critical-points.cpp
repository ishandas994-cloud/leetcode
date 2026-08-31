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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {
            int nextVal = curr->next->val;

            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > nextVal) ||
                (curr->val < prev->val && curr->val < nextVal)) {

                if (first == -1) {
                    // First critical point
                    first = index;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Need at least two critical points
        if (first == -1 || first == last)
            return ans;

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};