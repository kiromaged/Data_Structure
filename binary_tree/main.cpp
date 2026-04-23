#include <bits/stdc++.h>
using namespace std;
class bstnode{
public:
    int value;
    bstnode* left;
    bstnode* right;
    bstnode(){
        left=right=NULL;
    }
};
class bst{
private:
    bstnode* root;
public:
    bst(){root=0;}
    void clear(){root=0;}
    bool isempty(){
        return root==0;
    }
    int* search(int el){
        bstnode* temp=root;
        while (temp!=NULL) {
            if (el == temp->value)
                return &(temp->value);
            else if (el > temp->value)
                temp=temp->right;

            else if (el<temp->value)
                temp=temp->left;
        }
        return 0;
    }
    void insert(int el){
        bstnode*temp=root;
        bstnode*prev=0;
        while (temp!=NULL) {
            prev=temp;
            if (el > temp->value) {
                temp = temp->right;
            } else if (el <= temp->value) {
                temp = temp->left;
            }
        }
        if(root==0){
            root= new bstnode;
            root->value=el;
        }
        else if(prev->value<el){
            prev->right=new bstnode;
            prev->right->value=el;
        }
        else{
            prev->left=new bstnode;
            prev->left->value=el;
        }
    }
//    void inorderdisplay(bstnode* node){
//        inorderdisplay(node->left);
//        cout<<node->value;
//        inorderdisplay(node->right);
//    }
//    void preodrderdisplay(bstnode* node){
//        cout<<node;
//        preodrderdisplay(node->left);
//        preodrderdisplay(node->right);
//    }
//    void deletebycopying(bstnode*& node){
//       bstnode*prev;
//       bstnode*temp=node;
//       if(node->left==0)
//           node=node->right;
//       else if(node->right==0)
//           node=node->left;
//     else {
//           temp=node->left;
//           prev=node;
//           while (temp->r ight!=NULL){
//               prev=temp;
//               temp=temp->right;
//           }
//           node->value=temp->value;
//           if(prev==node)
//               prev->left=temp->left;
//           else
//               prev->right=temp->left;
//
//       }
//     delete temp;
//    }
//};
//class bstnode{
//public:
//    int data;
//    bstnode*left;
//    bstnode*right;
//    bstnode(){
//        left=right=NULL;
//    }};
//    class bst{
//        bstnode*root;
//        bst(){root=NULL;}
//        int*min(){
//            bstnode*temp=root;
//            if(temp==NULL){
//                cout<<"empty tree\n";
//                return 0;
//            }
//            else
//                while (temp->left!=NULL){
//                    temp=temp->left;
//                }
//            return & (temp->data);
//        }
//        void deseinding(bstnode* node){
//            deseinding(node->right);
//            cout<<node->data;
//            deseinding(node->left);
//        }
//        int findlevel(int value){
//            if (root ==NULL){
//                cout<<"no elements in the tree\n";
//                return 0;
//            }
//            bstnode* temp=root;
//            int counter=0;
//            while (temp!=NULL){
//                if(temp->data==value)
//                    return counter;
//                else if(value>temp->data)
//                    temp=temp->right;
//                else
//                    temp=temp->left;
//                counter++;
//            }
////            return 0;
//        }
};

int main() {
}