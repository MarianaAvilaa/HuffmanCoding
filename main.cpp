#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

    struct Node{
        char character;
        int freq;
        Node *left;
        Node*right;

    };
vector<Node> insertionSortNodes(vector<Node>lisOfNodes){
    int j;
    Node treeNode;
    for(int i=1; i<lisOfNodes.size();i++){
        treeNode=lisOfNodes[i];
        j=i-1;
        while(j>=0 && treeNode.freq<lisOfNodes[j].freq){
            lisOfNodes[j+1]=lisOfNodes[j];
            j=j-1;
        }
        lisOfNodes[j+1]=treeNode;
    }
    return lisOfNodes;
}
vector<Node> NodeList(char characters[]){
    vector<Node> nodeList;
    Node newNode;

    if(nodeList.empty()){
        newNode={characters[0],1};
        nodeList.push_back(newNode);
    }
    for(int i = 1; i <= sizeof(characters); i++){ // string
        bool inList=false;
        for(int y=0;y<=nodeList.size();y++) {  // vector

            if (nodeList[y].character==characters[i]) {
                nodeList[y].freq=nodeList[y].freq+1;
                inList=true;
            }
        }
        if(!inList){
            newNode={characters[i],1};
            nodeList.push_back(newNode);
        }


    }
    /* cout<< "List of nodes"<<endl;
    for(int r=0;r<nodeList.size();r++){
        cout<<nodeList[r].character<<" "<<nodeList[r].freq<<endl;
    }*/
  //  insertionSortNodes(nodeList);
    return nodeList;
}


    class huffmanTree{
    private:
        Node *root;
    public:

        huffmanTree(){
            root=NULL;
        }
        huffmanTree(Node l, Node r){
            root= new Node;
            root->character='0';
            root->freq=l.freq+r.freq;

            Node* leftnode = new Node;
            leftnode->character=l.character;
            leftnode->freq=l.freq;
            leftnode->left=l.left;
            leftnode->right=l.right;

            Node *rightNode= new Node;
            rightNode->character=r.character;
            rightNode->freq=r.freq;
            rightNode->left=r.left;
            rightNode->right=r.right;

            root->left=leftnode;
            root->right=rightNode;

        }
        Node * addNodes(Node *x, Node *y){ //Adds two nodes
            int total=x->freq+y->freq;
            Node *sum= new Node;
           sum->character='\0';
           sum->freq=total;
           sum->left=x;
           sum->right=y;
            return sum;
        }
       Node *getLeftNode(Node *n){
           return n->left;
        }
        Node *rightNode(Node *n){
            return n->right;
        }

        vector<Node>buildTree(vector<Node> vectorList,huffmanTree &root);


        Node *getRoot(){
            return root;
      }

    };



vector<Node>huffmanTree::buildTree(vector<Node> vectorList, huffmanTree & root) {
  //  Node m;
      // insertionSortNodes(vectorList);
      vector<Node>sortedNodes;
      sortedNodes= insertionSortNodes(vectorList);
      //  vector<Node>::iterator iter = vectorList.begin();
        while (sortedNodes.begin() != sortedNodes.end()-1 ) {
           sortedNodes= insertionSortNodes(sortedNodes);
            huffmanTree tree(sortedNodes[0],sortedNodes[1]);
            sortedNodes[0]=*tree.getRoot();
            sortedNodes.erase(sortedNodes.begin()+1);
            root=tree;

        }
  
    cout << "List of SUM Nodes" << endl;
    for (int r = 0; r < vectorList.size(); r++) {
        cout << vectorList[r].character << " " << vectorList[r].freq<<endl;
    }
    return sortedNodes;
}
    int main() {
//char str[100];
/* cout<< "Enter a string: ";
cin>> str;*/
        vector<Node> list;
        char str[] = {'M', 'a', 'r', 'i', 'a', 'n', 'a', 'b'};
//M,R,I,n,b,a
        list = NodeList(str);
vector<Node>sortedList;
sortedList= insertionSortNodes(list);

        cout<<"Sorted List"<<endl;
      for(int z=0;z<sortedList.size();z++) {
          cout << sortedList[z].character << " " << sortedList[z].freq << endl;
      }
cout<< "Building tree"<<endl;
        huffmanTree t;
        t.buildTree(sortedList,t);


        return 0;

    }


