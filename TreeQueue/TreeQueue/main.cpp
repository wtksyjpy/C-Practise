//
//  main.cpp
//  TreeQueue
//
//  Created by Hank on 10/27/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include "tree.h"
#include "stack.h"

using namespace std;

//Stack
template<typename T> Stack<T>::Stack(int maxs){
    maxSize=maxs;
    top=-1;
    elements=new T [maxSize];                     //建立栈空间
    assert(elements!=0);                           //分配不成功结束程序
}
template<typename T> void Stack<T>::PrintStack(){
    for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
    cout<<endl;
}
template<typename T> void Stack<T>::Push(const T &data){
    assert(!IsFull());                             //栈满则退出程序
    elements[++top]=data;                //栈顶指针先加1，元素再进栈，top是指向栈顶元素
}
template<typename T> T Stack<T>::Pop(){
    assert(!IsEmpty());                           //栈已空则不能退栈，退出程序
    return elements[top--];                        //返回栈顶元素，同时栈顶指针退1
}
template<typename T> T Stack<T>::GetElem(int i){
    assert(i<=top&&i>=0);                        //超出栈有效数据则错，退出程序
    return elements[i];                            //返回指定元素，top不变
}

//Queue
template<typename T>void Queue<T>::MakeEmpty(){
    Node<T> *temp;
    while(front!=NULL){
        temp=front;front=front->link;delete temp;
    }
}
template<typename T>Queue<T>::~Queue(){MakeEmpty();}

template<typename T>void Queue<T>::EnQue(const T &data){
    if(front==NULL) front=rear=new Node<T>(data,NULL);
    else rear=rear->link=new Node<T>(data,NULL);
}
template<typename T>T Queue<T>::DeQue(){
    assert(!IsEmpty());
    Node<T> *temp=front;
    T data=temp->info;                       //取队头结点中的数据
    front=front->link;                       //队头出队
    delete temp;                             //释放内存空间
    return data;
}
template<typename T>T Queue<T>::GetFront(){
    assert(!IsEmpty());
    return front->info;
}

//Binary Tree
template<typename T> void BinaryTree<T>::Destory(TNode<T> *Current){
    if(Current!=NULL){
        Destory(Current->lchild);
        Destory(Current->rchild);
        delete Current;  						//后序释放根结点
    }
}
template<typename T>void BinaryTree<T>::Insert(const T &data,TNode<T> * &b){
    if(b==NULL){								//已到空树,插入
        b=new TNode<T>(data);
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
template<typename T>void BinaryTree<T>::InOrder(TNode<T> *Current){
    if(Current!=NULL){							//递归终止条件
        InOrder(Current->lchild);					//中序遍历左子树
        cout<<Current->info<<'\t';					//访问根结点，注意所放位置
        InOrder(Current->rchild);					//中序遍历右子树
    }
}
template<typename T>void BinaryTree<T>::PreOrder(TNode<T> *Current){
    if(Current!=NULL){
        cout<<Current->info<<'\t';						//注意前序访问语句所放位置
        PreOrder(Current->lchild);
        PreOrder(Current->rchild);
    }
}
template<typename T>void BinaryTree<T>::PostOrder(TNode<T> *Current){
    if(Current!=NULL){
        PostOrder(Current->lchild);
        PostOrder(Current->rchild);
        cout<<Current->info<<'\t';  						//后序访问根结点
    }
}
template<typename T>void BinaryTree<T>::WidthOrder(TNode<T> *Current){
    if(Current!=NULL){
        Queue<TNode<T>*> q;      // 队列
        q.EnQue(Current);
        TNode<T> * p;
        while(!q.IsEmpty()) {
            p = q.DeQue();   // 队首元素出队列
            cout<<p->info<<'\t';	          // 访问p结点
            if(p->lchild)
                q.EnQue(p->lchild);
            if(p->rchild)
                q.EnQue(p->rchild);
        }  						//后序访问根结点
    }
}
template<typename T>void BinaryTree<T>::StackOrder(TNode<T> *Current){
    if(Current!=NULL){
        
        Stack<TNode<T> *> stack;   // 栈
        stack.Push(Current);
        TNode<T>* p;
        while(!stack.IsEmpty()) {  // 栈非空
            p = stack.Pop();
            cout<<p->info<<'\t';	          // 访问p结点
            if(p->rchild)
                stack.Push(p->rchild);
            if(p->lchild)
                stack.Push(p->lchild);
        }
    }
}

int main(int argc, const char * argv[]) {
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
    cout<<endl<<"广度(queue)："<<endl;
    btree.WidthOrder();
    cout<<endl<<"先序(stack)："<<endl;
    btree.StackOrder();

    cout<<endl;
    //    int i;
    //    Queue<char> que;                          //构造一个空链队
    //    char str1[]="abcdefghijklmnop";           //17个元素，包括串结束符
    //    for(i=0;i<17;i++) que.EnQue(str1[i]);
    //    for(i=0;i<17;i++) cout<<que.DeQue();           //先进先出
    //    cout<<endl;
    //    if(que.IsEmpty()) cout<<"队空"<<endl;
    return 0;
}
