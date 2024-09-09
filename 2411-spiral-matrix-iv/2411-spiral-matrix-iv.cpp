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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int> > ans(n, vector<int>(m, -1));


        int left = 0, right = m-1, top = 0, bottom = n-1;
        while(left<=right && top<=bottom && head!=NULL){
            int j=left;
            while(j<=right && head!=NULL){
                ans[top][j] = head->val;
                head = head->next;
                j++;
            }
            top++;
            // break;
            
            j = top;
            while(j<=bottom && head!=NULL){
                ans[j][right] = head->val;
                head = head->next;
                j++;
            }
            right--;

            j = right;
            while(j>=left && head!=NULL){
                ans[bottom][j] = head->val;
                head = head->next;
                j--;
            }
            bottom--;
            j = bottom;
            while(j>=top && head!=NULL){
                ans[j][left] = head->val;
                head = head->next;
                j--;
            }
            left++;
            // cout << left << " " << right << " " << top << " " << bottom << endl;
        }   

        return ans;
    }
};