#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int findPosition(int arr[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i]==element) {
            return i;
        }
    }
    return -1;
}

//build tree using inorder and preorder traversal
Node* buildTreeFormPreorderInorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd) {
    //base case
    if(preIndex>=size || inorderStart>inorderEnd) {
        return NULL;
    }

    // StepA:
    int element = preorder[preIndex++];
    Node* root = new Node(element);

    int pos = findPosition(inorder, size, element);
    // StepB:
    root->left = buildTreeFormPreorderInorder(inorder, preorder, size, preIndex, inorderStart, pos-1);
    root->right = buildTreeFormPreorderInorder(inorder, preorder, size, preIndex, pos+1, inorderEnd);
    return root;
}

Node* buildTreeFormPostorderInorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd) {
    if(postIndex<0 || inorderStart>inorderEnd) {
        return NULL;
    }

    // StepA:
    int element = postorder[postIndex--];
    Node* root = new Node(element);
    int pos = findPosition(inorder, size, element);
    root->right = buildTreeFormPostorderInorder(inorder, postorder, size, postIndex, pos+1, inorderEnd);
    root->left = buildTreeFormPreorderInorder(inorder, postorder, size, postIndex, inorderStart, pos-1);

    return root;
}


void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        //A
        Node* temp = q.front();
        //B
        q.pop();
        //C
        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            //D
            if(temp->left) {
                q.push(temp->left);
            }
            //E
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;
    cout << "Building tree: " << endl;
    Node* root = buildTreeFormPreorderInorder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    cout << "\nPrinting level order traversal: " << endl;
    levelOrderTraversal(root);
    return 0;
}