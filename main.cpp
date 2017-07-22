#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.count(target - nums[i])){
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = l1, *cur_node = l1;
        int c = 0;
        ListNode *tmp;
        int tmp1, tmp2;
        while (l1 != NULL || l2 !=NULL) {
            if(l1 == NULL){
                cur_node->next = l2;
                l2 = l1;
                l1 = cur_node->next;
            }
            if(l2 == NULL){
                tmp1 = l1->val + c;
                l1->val = tmp1 % 10;
                c = tmp1 / 10;
                cur_node = l1;
                l1 = l1->next;
            } else{
                tmp2 = l1->val + l2->val + c;
                l1->val = tmp2 % 10;
                c = tmp2 / 10;
                cur_node = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(c==1){
            cur_node->next = new ListNode(1);
        }
        l1 = res;
        return l1;
    }
public:
    int hammingDistance(int x, int y) {

        int res = 0;
        while(x || y){
            if((x&1) != (y&1)){
                res += 1;
            }
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};




int main(){
    //int n[] = {};
    /*
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution = Solution();
    vector<int> result = solution.twoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    */
    ListNode *listNode1 = new ListNode(5);
    ListNode *listNode2 = new ListNode(9);
    ListNode *listNode3 = new ListNode(5);
    listNode1->next = listNode2;

    Solution solution = Solution();
    ListNode *res = solution.addTwoNumbers(listNode3, listNode1);

    cout << solution.hammingDistance(4, 4);


    return 0;
}