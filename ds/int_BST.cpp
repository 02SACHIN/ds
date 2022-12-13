#include <iostream>
#include "Queue.h"

class Node
{
    public:
    int data;
    int key;
    Node* lchild;
    Node* rchild;

    Node()
    {
        data = 0;
        key = 0;
        lchild = NULL;
        rchild = NULL;
    }

    Node(int a)
    {
        data = a;
        lchild = NULL;
        rchild = NULL;
    }

    friend class Binary_search_tree;

};

class Binary_search_tree
{
    public:

    Node* root;


    int insert_element(int);
    void preorder(Node*);
    void postorder(Node*);
    void inorder(Node*);
    void level_order();
    int height(Node*);
    bool search_element(int);
    Node* get_Successor(Node*);
    Node* delete_Node(Node* ,int);
};

int Binary_search_tree::insert_element(int x)
{
    Node* ele = new Node(x);
    if(root==NULL)
    {
        root = ele;
        return 1;
    }
        
    Node* curr = root;

    while(curr!=NULL)
    {
        if(x<curr->key)
        {
            if(curr->lchild==NULL)
            {
                curr->lchild = ele;
                return 1;
            }

            else
            {
                curr = curr->lchild;
            }
                
            }
            else if(x>curr->key)
            {
                if(curr->rchild==NULL)
                {
                    curr->rchild = ele;
                    return 1;
                }
                else
                {
                    curr = curr->rchild;
                }
                
            }

            else
            {
                return 0;
            }
        }
        return 1;

}

bool Binary_search_tree::search_element(int element)
{
    Node* temp = root;

    while(temp != NULL)
    {
        if(temp->data > element)
        {
            temp = temp -> lchild;
        }

        else if(temp->data < element)
        {
            temp = temp -> rchild;
        }

        else
        {
            return true;
        }
    }

    return false;
}

void Binary_search_tree::preorder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    std::cout<<node->data<<" ";
    preorder(node -> lchild);
    preorder(node -> rchild);
}

void Binary_search_tree::postorder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    postorder(node -> lchild);
    postorder(node -> rchild);
    std::cout<< node->data <<" ";
}

void Binary_search_tree::inorder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    preorder(node -> lchild);
    std::cout<<node->data<<" ";
    preorder(node -> rchild);
}

void Binary_search_tree::level_order()
{
    if(this->root == NULL)
    {
        return ;
    }

    Queue<Node*> q;

    q.enqueue(root);

    while (q.check_empty() == false) 
    {
        Node* n = q.front_element();
        cout << n->data << " ";
        q.dequeue();

        if( n->lchild != NULL)
        {
            q.enqueue(n->lchild);
        }

        if (n->rchild != NULL)
        {
            q.enqueue(n->rchild);
        }
    } 
    std::cout<<std::endl;   
}

int Binary_search_tree::height(Node* root)
{
    if(root==NULL)
        {
            return 0;
        }
    
        else
        {
            return std::max(height(root->lchild),height(root->rchild))+1;
        }
}

Node* Binary_search_tree::get_Successor(Node* curr)
{
    curr=curr->rchild;
        while(curr!=NULL && curr->lchild!=NULL)
        {
            curr=curr->lchild;
        }
        
        return curr;
}

Node* Binary_search_tree::delete_Node(Node* root, int x)
{
    if(root==NULL)
    {
        return 0;
    }
        
    if(root->key>x)
    {
        root->lchild=delete_Node(root->lchild,x);
    }
        
    else if(root->key<x)
    {
        root->rchild=delete_Node(root->rchild,x);
    }
        
    else{

        if(root->lchild==NULL)
        {
            Node* temp=root->rchild;
            delete root;
            return temp;
        }
        else if(root->rchild==NULL)
        {
            Node* temp=root->lchild;
            delete root;
            return temp;
        }
        else
        {
            Node*succ = get_Successor(root);
            root->key=succ->key;
            root->rchild=delete_Node(root->rchild,succ->key);
        }
    }
    return root;
}


int main()
{
    Binary_search_tree b;
    b.root = new Node(3);
    b.root->lchild = new Node(1);
    b.root->rchild = new Node(4);
    b.root->lchild->rchild = new Node(2);
    b.root->rchild->rchild = new Node(5);

    b.level_order();
}