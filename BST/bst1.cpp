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

Node* insertIntoBST(Node* &root, int data) {
    if(root==NULL) {
        //this is the first node we have to create
        root = new Node(data);
        return root;
    }
    if(root->data > data) {
        //insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
	}
}

void inorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}

	//LNR
	inorderTraversal(root->left);
	cout << root -> data << " ";
	inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}

	//NLR
	cout << root -> data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
	if(root == NULL)
		return;

	//LRN
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root -> data << " ";
}

bool findinBST(Node* root, int target) {
    if(root==NULL) return false;
    if(root->data == target) {
        return true;
    }

    bool leftAns = false;
    bool rightAns = false;

    if(root->data > target) {
        //left subtree me check kar k lao
        leftAns = findinBST(root->left, target);
    }
    else {
        rightAns = findinBST(root->right, target);
    }
    return leftAns||rightAns;
}

int findMin(Node* root) {
    Node* temp = root;
    if(temp==NULL) return -1;

    while(temp->left) {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node* root) {
    Node* temp = root;
    if(temp==NULL) return -1;

    while(temp->right) {
        temp = temp->right;
    }
    return temp->data;
}

Node* findNodeInBST(Node* root, int target) {
    if(root==NULL) return NULL;
    if(root->data == target) {
        return root;
    }

    if(root->data > target) {
        //left subtree me check kar k lao
        findNodeInBST(root->left, target);
    }
    else {
        findNodeInBST(root->right, target);
    }
    return root;
}

Node* deleteNodeInBST(Node* root, int target) {
    //base case
    if(root==NULL)
        return root;
    
    // Step1:
    Node* temp = findNodeInBST(root, target);

    // Step2:
    if(root->data==target) {
        // I want to delete temp
        if(temp->left==NULL && temp->right==NULL) {
            // It's a leaf node
            delete temp;
            return NULL;
        }
        else if(temp->left==NULL && temp->right!=NULL) {
            // when left subtree is empty and right subtree is not empty
            Node* child = temp->right;
            delete temp;
            return child;
        }
        else if(temp->left!=NULL && temp->right==NULL) {
            // when left subtree is not empty and right subtree is empty
            Node* child = temp->left;
            delete temp;
            return child;
        }
        else {
            // Both child exists 
            // Inorder predicissor of left subtree -> left subtree me max value 
            int inorderPre = maxVal(temp->left);
            temp->data = inorderPre;
            temp->left = deleteNodeInBST(temp->left, inorderPre);
            return root;
        }
    }
    else if(root->data > target){
        root->left = deleteNodeInBST(root->left, target);
    }
    else {
        root->right = deleteNodeInBST(root->right, target);
    }
    return root;
}

Node* bstUsingInorder(int inorder[], int s, int e) {
    // base case 
    if(s>e) return NULL;

    int mid = s+ (e-s)/2;
    int element = inorder[mid];
    Node* root= new Node(element);

    root->left = bstUsingInorder(inorder, s, mid-1);
    root->right = bstUsingInorder(inorder, mid+1, e);

    return root;
}

void convertIntoSortedDLL(Node* root, Node* &head) {
    //base case
    if(root==NULL) return;

    //right subtree into LL
    convertIntoSortedDLL(root->right, head);
    //attach root node
    root->right = head;

    if(head != NULL) {
        head -> left = root;
    }
    //update head node
    head = root;

    //left subtree link list
    convertIntoSortedDLL(root->left, head);
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}
int main() {
    Node* root = NULL;
    cout << "Enter the data for Node" << endl;
    takeInput(root); 
    cout << "Printing the level order traversal of the BST" << endl;
    levelOrderTraversal(root);

    cout << endl;
    // cout << "Printing Inorder: " << endl;
    // inorderTraversal(root);

    // cout << endl;
    // cout << "Printing preorder: " << endl;
    // preorderTraversal(root);

    // cout << endl;
    // cout << "Printing postorder: " << endl;
    // postorderTraversal(root);

    cout << endl;
    if(findinBST(root, 11)) {
        cout << "Found!";
    }
    else {
        cout << "Not found!";
    }

    cout << "Minimum element of the BST is: " << findMin(root) << endl;

    root = deleteNodeInBST(root, 100);
    cout << "Printing the level order traversal of the BST" << endl;
    levelOrderTraversal(root);

    cout << endl;
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;
    Node* root1 = bstUsingInorder(inorder, s, e);
    levelOrderTraversal(root1);

    cout << "\nLinked list: ";
    Node* head = NULL;
    convertIntoSortedDLL(root1, head);
    printLL(head);
    return 0;
}