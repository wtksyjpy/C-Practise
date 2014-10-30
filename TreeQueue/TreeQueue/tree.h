//
//  tree.h
//  TreeQueue
//
//  Created by Hank on 10/27/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef __TreeQueue__tree__
#define __TreeQueue__tree__

#include "queue.h"
#include "stack.h"
template<typename T>class BinaryTree;
template<typename T>class TNode {
    TNode<T> *lchild,*rchild;
    T info;
public:
    TNode(){
        lchild=NULL;
        rchild=NULL;
    }
    TNode(T data,TNode<T> *left=NULL,TNode<T> *right=NULL){
        info=data;
        lchild=left;
        rchild=right;
    }
    T Getinfo(){return info;} //取得结点数据
    void setinfo(const T &data){info=data;}
    //修改结点数据
    TNode<T> *Getleft(){return lchild;} //取得左子树
    TNode<T> *Getright(){return rchild;} //取得右子树
    void setleft(TNode<T> *left){lchild=left;}
    //设置左指针
    void setright(TNode<T> *right){rchild=right;}
    //设置右指针
    friend class BinaryTree<T>; //二叉树类说明为友元类
};
template<typename T>class BinaryTree{
    TNode<T> *root;                  //二叉树的根指针
    void InOrder(TNode<T> *Current);                //中序遍历
    void PreOrder(TNode<T> *Current);				//前序遍历
    void PostOrder(TNode<T> *Current);				//后序遍历
    void WidthOrder(TNode<T> *Current);
    void StackOrder(TNode<T> *Current);

    void Insert(const T &data,TNode<T> * &b); //插入结点，参数为引用！
    void Destory(TNode<T> * Current);        //删除树
public:
    BinaryTree(){root=NULL;}						//空树构造函数
    ~BinaryTree(){Destory(root);}						//析构函数
    void Creat(T* data,int n);                    //建立（排序）二叉树
    void InOrder(){InOrder(root);}                //中序遍历，共有函数为接口
    void PreOrder(){PreOrder(root);}		      //前序遍历，共有函数为接口
    void PostOrder(){PostOrder(root);}			  //后序遍历，共有函数为接口
    void WidthOrder(){WidthOrder(root);}
    void StackOrder(){StackOrder(root);}

    friend class Queue<T>;
    friend class Stack<T>;

};

#endif /* defined(__TreeQueue__tree__) */
