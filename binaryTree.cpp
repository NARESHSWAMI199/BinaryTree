#include<iostream>
#include<bits/stdc++.h> 
#include<queue>
using namespace std;



struct  node 
{
    int data;
    node* left;
    node* right;
};


class BinaryTree{

    public:
        node* createNewNode(int data){
            node* tmp = new node();
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;
            return tmp;
        }

        void  insert(node* temp, int data){
            if (temp == NULL){
                temp = createNewNode(data);
                return; 
            }
            queue<node*> q;
            q.push(temp);


            while (q.size())
            {
                node* tmp = q.front();
                // in queue the pop remove first item
                q.pop();

                // check left
                if (tmp->left != NULL ){
                    q.push(temp->left);
                }
                else
                {
                    tmp->left = createNewNode(data);
                    break;

                }
                // check right
                if (tmp->right != NULL){
                    q.push(tmp->right);
                }
                else
                {
                    tmp->right = createNewNode(data);
                    break;

                }

            }
            
        }

        void inorder(struct node *root) 
        { 
            stack<node *> s; 
            node *curr = root; 
        
            while (curr != NULL || s.empty() == false) 
            { 
                while (curr !=  NULL) 
                { 
                    s.push(curr); 
                    curr = curr->left; 
                }  
                
                curr = s.top(); 
                s.pop(); 
                cout << curr->data << " "<<endl; 
                
                curr = curr->right; 
            } 
        } 

    
    
        void preorder(node *root)
    {
        if (root == NULL)
            return;

        stack<node *> s;
        s.push(root);

        while (!s.empty())
        {
            node *curr = s.top();
            cout << " " << curr->data << endl;
            s.pop();

            if (curr->right)
                s.push(curr->right);

            if (curr->left)
                s.push(curr->left);
        }
    }

    void postorder(node * temp){
        if(temp == NULL)
            return;
        cout<<"  " <<temp->data <<endl;
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(node *root)
    {
        if (root == NULL)
            return;

        node *temp = root;
        unordered_set<node *> visited;
        while (temp && visited.find(temp) == visited.end())
        {
            if (temp->left && visited.find(temp->left) == visited.end())
                temp = temp->left;
            else if (temp->right && visited.find(temp->right) == visited.end())
                temp = temp->right;
            else
            {
                cout << " " << temp->data;
                visited.insert(temp);
                temp = root;
            }
        }
    }


//     YOU CAN USE THESE METHOD ALSO MAY BE IT'S EASSY FOR YOU
    
        // void inorder(node* temp){
        //     if(temp == NULL)
        //         return;
            
        //     inorder(temp->left);
        //     cout<<"  " <<temp->data <<endl;
        //     inorder(temp->right);
        // }


//         void preorder(node * temp){
//             if(temp == NULL)
//                 return;
//             cout<<"  " <<temp->data <<endl;
//             preorder(temp->left);
//             preorder(temp->right);
//         }   

    
//         void postorder(node * temp){
//             if(temp == NULL)
//                 return;
//             postorder(temp->left);
//             postorder(temp->right);
//             cout<<"  " <<temp->data <<endl;

//         }   



};



int main(){

    BinaryTree binaryTree;
    node* root;
    root = binaryTree.createNewNode(10);
    root->left = binaryTree.createNewNode(12);
    root->left->right = binaryTree.createNewNode(100);
    root->right = binaryTree.createNewNode(16);


    binaryTree.insert(root,17);
    
    cout<<"this is a inorder traverse : "<<endl; 
    binaryTree.inorder(root);

    cout<<"this is a preorder traverse : "<<endl; 
    binaryTree.preorder(root);

    cout<<"this is a postorder traverse : "<<endl; 
    binaryTree.postorder(root);

    return 0;
}
