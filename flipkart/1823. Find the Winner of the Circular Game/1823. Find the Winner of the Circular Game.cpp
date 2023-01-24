// class Solution {
// private:
//     int helper(ListNode* head, int k){
//         ListNode* temp = head;
//         while(head->next != head){

//             ListNode* pre = NULL;
//             for(int i=1;i<k;i++){
//                 pre = temp;
//                 temp = temp->next;
//             }

//             // deleting kth node 
//             if(head == temp){
//                 head = head->next;
//             }
//             pre->next = temp->next;
//             delete(temp);
//             temp = pre->next;
//         }
//         return head->val;
//     }
// public:
//     int findTheWinner(int n, int k) {
//         if(k==1)
//             return n;
//         // making linked List
//         ListNode * head = NULL, *tail = NULL;
//         for(int i=1;i<=n;i++){
//             ListNode* node = new ListNode(i);
//             if(head == NULL){
//                 head = tail = node;
//             }else{
//                 tail->next = node;
//                 tail = node;
//             }
//             tail->next = head; // making circular
//         }
//         return helper(head, k);
        
//     }
// };


// Recursive 
// class Solution{
// private:
//     int helper(int n, int k){
//         if(n==1) return 0;
//          int res =   (helper(n-1,  k) + k)%n;
//          cout<<res<<" ";
//          return res;
//     }
// public:
//   int findTheWinner(int n, int k) {
//       return helper(n,k)+1;
//   }   
// };


// Iterative 
class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for conterting 0-based indexing to 1-based indexing
    }
};



