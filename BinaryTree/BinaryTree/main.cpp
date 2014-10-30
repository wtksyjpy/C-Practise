//
//  main.cpp
//  BinaryTree
//
//  Created by Hank on 10/27/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include "Header.h"

using namespace std;


template<typename T> void BinaryTree<T>::Destory(Node<T> *Current){
    if(Current!=NULL){
        Destory(Current->lchild);
        Destory(Current->rchild);
        delete Current;  						//后序释放根结点
    }
}
template<typename T>void BinaryTree<T>::Insert(const T &data,Node<T> * &b){
    if(b==NULL){								//已到空树,插入
        b=new Node<T>(data);
        if(b==NULL){
            cout<<"空间不足"<<endl;
            exit(1);
        }
    }
    else if(data<b->info) Insert(data,b->lchild);			//小于,向左子树去查
    else Insert(data,b->rchild);	//大于等于,向右子树去查
}
template<typename T>void BinaryTree<T>::Creat(T* data,int n){		//建立一棵二叉排序树
    for(int i=0;i<n;i++) Insert(data[i],root);
}
template<typename T>void BinaryTree<T>::InOrder(Node<T> *Current){
    if(Current!=NULL){							//递归终止条件
        InOrder(Current->lchild);					//中序遍历左子树
        cout<<Current->info<<'\t';					//访问根结点，注意所放位置
        InOrder(Current->rchild);					//中序遍历右子树
    }
}
template<typename T>void BinaryTree<T>::PreOrder(Node<T> *Current){
    if(Current!=NULL){
        cout<<Current->info<<'\t';						//注意前序访问语句所放位置
        PreOrder(Current->lchild);
        PreOrder(Current->rchild);
    }
}
template<typename T>void BinaryTree<T>::PostOrder(Node<T> *Current){
    if(Current!=NULL){
        PostOrder(Current->lchild);
        PostOrder(Current->rchild);
        cout<<Current->info<<'\t';  						//后序访问根结点
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    const int n=15;
    int i,a[n]={10,5,15,8,3,18,13,12,14,16,20,1,4,6,9};
    BinaryTree<int> btree;
    btree.Creat(a,n);
    cout<<"输入数据："<<endl;
    for(i=0;i<n;i++) cout<<a[i]<<'\t';
    cout<<endl<<"中序："<<endl;
    btree.InOrder();    //中序遍历输出升序
    cout<<endl<<"前序："<<endl;
    btree.PreOrder();
    cout<<endl<<"后序："<<endl;
    btree.PostOrder();
    cout<<endl;
    return 0;
}
