#include<iostream>
#include<queue>
#include<map>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree() {
    int data;
    cout << "Enter a data: " << endl;
    cin >> data;

    if(data==-1) return NULL;
    
    Node* root = new Node(data);
    cout << "Enter data for left part: " << data << " node" << endl;
    root->left = buildTree();
    cout << "Enter data for right part: " << data << " node" << endl;
    root->right = buildTree();
    
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

void inOrder(Node* root) {
    if(root==NULL) return;
    Node* temp = root;
    inOrder(temp->left);
    cout << temp->data << " ";
    inOrder(temp->right);
}

void preOrder(Node* root) {
    if(root==NULL) return;
    Node* temp = root;
    cout << temp->data << " ";
    preOrder(temp->left);
    preOrder(temp->right);
}

void postOrder(Node* root) {
    if(root==NULL) return;
    Node* temp = root;
    postOrder(temp->left);
    postOrder(temp->right);
    cout << temp->data << " ";
}

int height(Node* root) {
    if(root==NULL) return 0;
    int rootLeftHeight = height(root->left);
    int rootRightHeight = height(root->right);
    return 1+max(rootLeftHeight,rootRightHeight);
}

void printTopView(Node* root) {
    if(root==NULL) return;

    //horizontal node se top node ka difference
    map<int, int> topNode;

    //level order
    // we will store a pair consisting of node and horizontal distance;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //jo bhi horizontal dist aya hai check already it exist or not
        if(topNode.find(hd)==topNode.end()) {
            //create entry
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }  
    //ab answer map me store hai
    cout << "Printing the answer: " << endl;
    for(auto i: topNode) {
        cout << i.first << " -> " << i.second << endl;
    }
}



int main() {
    Node* root = NULL;
    root = buildTree();

    levelOrderTraversal(root);
    cout << "Preorder traversal: ";
    preOrder(root);
    cout << "Inorder traversal: ";
    inOrder(root);
    cout << "Postorder traversal: ";
    postOrder(root);
    
    cout << "Height of the tree is: " << height(root) << endl;

    cout << "Top view of the tree is: " << endl;
    printTopView(root);
    return 0;
}