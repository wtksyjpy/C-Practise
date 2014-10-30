//
//  stack.h
//  TreeQueue
//
//  Created by Hank on 10/27/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef TreeQueue_stack_h
#define TreeQueue_stack_h

template<typename T>class Stack{
    int top;                                    //栈顶指针（下标）
    T *elements;                               //动态建立的栈
    int maxSize;                               //栈最大容纳的元素个数
public:
    Stack(int=20);                              //栈如不指定大小，设为20元素
    ~Stack(){delete[] elements;}
    void Push(const T &data);                    //压栈
    T Pop();                            //弹出，top--
    T GetElem(int i);                   //取数据，top不变
    void MakeEmpty(){top= -1;}                  //清空栈
    bool IsEmpty() const{return top== -1;}          //判栈空
    bool IsFull() const{return top==maxSize-1;}      //判栈满
    void PrintStack();                            //输出栈内所有数据
};

#endif
