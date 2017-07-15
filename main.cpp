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
        ListNode *res = l1, *mid = l1;
        int c = 0;
        while(l1 && l2){
            int tmp = l1->val + l2->val + c;
            l1->val = tmp % 10;
            c = tmp / 10;
            mid = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2){
            l2->val += c;
            mid->next = l2;
        } else{
            l1->val += c;
        }
        return res;
    }
};




int main(){
    //int n[] = {};
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution = Solution();
    vector<int> result = solution.twoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}