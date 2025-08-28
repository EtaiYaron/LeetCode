#include <iostream>
#include <initializer_list>


class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extranum = 0;
        int mul = 1;
        int base = 10;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int add = 0;
            if (l1 != nullptr) {
                add += l1->val; 
                l1 = l1->next;  
            }
            if (l2 != nullptr) {
                add += l2->val; 
                l2 = l2->next;  
            }
            int x = add + extranum;
            extranum = x / 10;
            add = x % 10;
            sum += (add * mul);
            mul *= base;
        }
        ListNode* l3 = nullptr;
        while (sum != 0) {
            l3 = new ListNode(sum % 10, l3);
            sum /= 10;
        }
        ListNode* l4 = nullptr;
        ListNode* l3_iter = l3;
        while (l3_iter != nullptr) {
            l4 = new ListNode(l3_iter->val, l4); 
            l3_iter = l3_iter->next;             
        }
        return l4;
    }

    Solution::ListNode* createList(std::initializer_list<int> vals) {
        Solution::ListNode* head = nullptr;
        Solution::ListNode* tail = nullptr;
        for (int v : vals) {
            if (!head) {
                head = tail = new Solution::ListNode(v);
            }
            else {
                tail->next = new Solution::ListNode(v);
                tail = tail->next;
            }
        }
        return head;
    }

    void printList(Solution::ListNode* node) {
        while (node) {
            std::cout << node->val;
            if (node->next) std::cout << " -> ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};



int main() {
    Solution sol;
    auto l1 = sol.createList({ 2,4,3 });
    auto l2 = sol.createList({ 5,6,4 });
    auto result = sol.addTwoNumbers(l1, l2);
	sol.printList(result); // Expected: 7 -> 0 -> 8
    return 0;
}

