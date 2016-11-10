/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

 // http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *root = head;
        if(!root)
            return NULL;
        //create copy of the n'th node and insert it after the n'th node
        while(head){
            RandomListNode *newnode = (RandomListNode *) malloc(sizeof(RandomListNode));
            newnode->label = head->label;
            newnode->next = head->next;
            head->next = newnode;
            head = head->next->next;
        }
        //set the random pointers of the new created nodes
        // This works because original->next is nothing but copy of 
        // original and Original->arbitrary->next is nothing but copy of arbitrary.
        head = root;
        while(head){
            head->next->random = (head->random) ? (head->random->next) : NULL;
            head = head->next->next;
        }
        //restore the original and the copy lists
        head = root;
        root = head->next;
        RandomListNode *ans = root;
        while(head && root){
            head->next = head->next->next;
            root->next = (root->next) ? (root->next->next) : NULL;
            head = head->next;
            root = root->next;
        }
        return ans;
    }
};