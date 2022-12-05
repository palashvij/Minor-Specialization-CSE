#include<iostream>
using namespace std;
typedef struct node
{
    int value;
    node * pLeft;
    node * pRight;
    node(int val = 0)
    {
        value = val;
        pRight = NULL;
        pLeft = NULL;
    }
}node;

void insert(node ** pRoot, int val)
{
    if(*pRoot == NULL)
        *pRoot = new node(val);
    else if((*pRoot)->value <= val)
        insert(&((*pRoot)->pRight), val);
    else if((*pRoot)->value > val)
        insert(&((*pRoot)->pLeft), val);
}

node * getBST(int * arr, int size)
{
    node * pRoot = NULL;
    for(int i = 0; i < size; i++)
        insert(&pRoot, arr[i]);
    return pRoot;
}

void inOrderTraversal(node * pRoot)
{
    if(pRoot && pRoot->pLeft)
        inOrderTraversal(pRoot->pLeft);
    if(pRoot)
        std::cout<<pRoot->value<<" , ";
    if(pRoot && pRoot->pRight)
        inOrderTraversal(pRoot->pRight);

}
node* minValueNode(node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->pLeft != NULL)
        current = current->pLeft;
 
    return current;
}
node* deleteNode(node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->value)
        root->pLeft = deleteNode(root->pLeft, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->value)
        root->pRight = deleteNode(root->pRight, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->pLeft == NULL and root->pRight == NULL)
            return NULL;
 
        // node with only one child or no child
        else if (root->pLeft == NULL) {
            struct node* temp = root->pRight;
            free(root);
            return temp;
        }
        else if (root->pRight == NULL) {
            struct node* temp = root->pLeft;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->pRight);
 
        // Copy the inorder successor's content to this node
        root->value = temp->value;
 
        // Delete the inorder successor
        root->pRight = deleteNode(root->pRight, temp->value);
    }
    return root;
}
int main()
{
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    cout<<endl;
    cout<<"Enter the elements of array"<<endl;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int arr[] = {10,5,15,5,6,7,8,89};
    node * pRoot = getBST(arr, n);
    // inOrderTraversal(pRoot);
    // std::cout<<std::endl;
    while(true){
        cout<<"press 1 for inserting" <<endl;
        cout<<"press 2 for deleting"<<endl;
        cout<<"Press 3 to print"<<endl;
        cout<<"Press 4 to exit"<<endl;
        int x;
        cin>>x;
        if(x==1){
            cout<<"Enter the number to insert:"<<endl;
            int a;
            cin>>a;
            insert(&pRoot,a);
        }
        else if(x==2){
            cout<<"Enter the number to delete:"<<endl;
            int a;
            cin>>a;
            pRoot=deleteNode(pRoot,a);
            
        }
        else if(x==3){
            inOrderTraversal(pRoot);
            std::cout<<std::endl;
        }
        else{
            break;
        }
    }
    
    
    return 0;
}