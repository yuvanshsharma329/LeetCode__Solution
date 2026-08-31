class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int firstIndex = -1;
        int lastIndex = -1;
        int prevCriticalIndex = -1;
        int minDistance = INT_MAX;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;

            bool isMaxima =
                (curr->val > prev->val) && (curr->val > nextNode->val);
            bool isMinima =
                (curr->val < prev->val) && (curr->val < nextNode->val);

            if (isMaxima || isMinima) {
                if (firstIndex == -1) {
                    firstIndex = index;
                } else {
                    minDistance = min(minDistance, index - prevCriticalIndex);
                }
                lastIndex = index;
                prevCriticalIndex = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (firstIndex == lastIndex) {
            return {-1, -1};
        }

        int maxDistance = lastIndex - firstIndex;
        return {minDistance, maxDistance};
    }
};
