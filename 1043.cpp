#include <iostream>

#include <vector>

#include <cstdio>

const int MAX = 100014;

using namespace std;



struct Node{

  int data;

  Node* left;

  Node* right;

};



vector<int> preResult,preMirrorResult,inputSequence;

int number,key;



void preOrder(Node* root)

{

  if(root == NULL){

    return;

  }

  preResult.push_back(root->data);

  preOrder(root->left);

  preOrder(root->right);

}



void preMirrorOrder(Node* root)

{

  if(root == NULL){

    return;

  }

  preMirrorResult.push_back(root->data);

  preMirrorOrder(root->right);

  preMirrorOrder(root->left);

}



int postCount = 0;

int postCountMirror = 0;



void postOrder(Node* root)

{

  if(root == NULL){

    return;

  }

  postOrder(root->left);

  postOrder(root->right);

  if(postCount < number - 1){

    printf("%d ",root->data);

    postCount++;

  }else{

    printf("%d",root->data);

  }

}



void postMirrorOrder(Node* root)

{

  if(root == NULL){

    return;

  }

  postMirrorOrder(root->right);

  postMirrorOrder(root->left);

  if(postCountMirror < number - 1){

    printf("%d ",root->data);

    postCountMirror++;

  }else{

    printf("%d",root->data);

  }

}



bool isIdentical(vector<int> result,vector<int> input)

{

  int flag = 1;

  int i = 0;



  while(i < (int)input.size()){

    if(result[i] != input[i]){

      flag = 0;

      break;

    }else{

      i++;

    }

  }



  return flag;

}



Node* newNode(int key)

{

  Node* root = new Node;

  root->data = key;

  root->left = NULL;

  root->right = NULL;

  return root;

}



void search(Node* root,int x)

{

  if(root == NULL){

    printf("Search Failed\n");

    return;

  }

  if(x < root->data){

    search(root->left,x);

  }else if(x > root->data){

    search(root->right,x);

  }else{

    printf("data element be scouted:%d\n",root->data);

  }

}



void insert(Node* &root,int key)

{

  if(root == NULL)

  {

    root = newNode(key);

    return;

  }

  if(key < root->data){

    insert(root->left,key);

  }else if(key >= root->data){

    insert(root->right,key);

  }else{

    return;

  }

}



Node* create(vector<int> input)

{

  Node* root = NULL;

  for(int i = 0;i < (int)input.size();i++){

    insert(root,input[i]);

  }

  return root;

}



int main()

{

  scanf("%d",&number);

  for(int i = 0;i < number;i++){

    scanf("%d",&key);

    inputSequence.push_back(key);

  }



  Node* root = create(inputSequence);

  preOrder(root);

  preMirrorOrder(root);



  if(isIdentical(preResult,inputSequence)){

    printf("YES\n");

    postOrder(root);

  }

  else if(isIdentical(preMirrorResult,inputSequence)){

    printf("YES\n");

    postMirrorOrder(root);

  }else{

    printf("NO");

  }



  return 0;

}


