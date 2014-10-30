//
//  Header.h
//  BinaryTree
//
//  Created by Hank on 10/27/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef BinaryTree_Header_h
#define BinaryTree_Header_h
template<typename T>class BinaryTree;
template<typename T>class Node {
    Node<T> *lchild,*rchild;
    T info;
public:
    Node(){
        lchild=NULL;
        rchild=NULL;
    }
    Node(T data,Node<T> *left=NULL,Node<T> *right=NULL){
        info=data;
        lchild=left;
        rchild=right;
    }
    T Getinfo(){return info;} //取得结点数据
    void setinfo(const T &data){info=data;}
    //修改结点数据
    Node<T> *Getleft(){return lchild;} //取得左子树
    Node<T> *Getright(){return rchild;} //取得右子树
    void setleft(Node<T> *left){lchild=left;}
    //设置左指针
    void setright(Node<T> *right){rchild=right;}
    //设置右指针
    friend class BinaryTree<T>; //二叉树类说明为友元类
};
template<typename T>class BinaryTree{
    Node<T> *root;                  //二叉树的根指针
    void InOrder(Node<T> *Current);                //中序遍历
    void PreOrder(Node<T> *Current);				//前序遍历
    void PostOrder(Node<T> *Current);				//后序遍历
    void Insert(const T &data,Node<T> * &b); //插入结点，参数为引用！
    void Destory(Node<T> * Current);        //删除树
public:
    BinaryTree(){root=NULL;}						//空树构造函数
    ~BinaryTree(){Destory(root);}						//析构函数
    void Creat(T* data,int n);                    //建立（排序）二叉树
    void InOrder(){InOrder(root);}                //中序遍历，共有函数为接口
    void PreOrder(){PreOrder(root);}		      //前序遍历，共有函数为接口
    void PostOrder(){PostOrder(root);}			  //后序遍历，共有函数为接口
};
#endif
