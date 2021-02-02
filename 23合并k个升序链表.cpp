 //merge sort，分成k/2...个链表进行合并
class Solution {
public:
    ListNode* mergetwoLists(ListNode* l1,ListNode* l2){
        ListNode* head,*p,*p_l1 = l1,*p_l2= l2;
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        if(l1->val <= l2->val){
            head = l1;p_l1 = l1->next;p = head;
        }
        else{
            head = l2;p_l2 = l2->next;p = head;
        }
        while(p_l1 && p_l2){
            if(p_l1-> val <= p_l2->val){
                p->next = p_l1;p_l1 = p_l1->next;
            }
            else{
                p->next = p_l2;p_l2 = p_l2->next;
            }
            p = p->next;
        }
        if(p_l1 == nullptr)
            p->next = p_l2;
        else 
            p->next = p_l1;
        return head;
    }
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l == r)
            return lists[l];
        if(l > r)
            return nullptr;
        int mid = (l + r) / 2;
        return mergetwoLists(merge(lists,l,mid),merge(lists,mid+1,r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        /*for(int i = 0;i < lists.size();i++){
            ans = mergetwoLists(ans,lists[i]);
        }*/
        ans = merge(lists,0,lists.size()-1);
        return ans;
    }
};
