//
//  main.cpp
//  SeqList
//
//  Created by Hank on 8/14/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

//【例6.3】顺序表类模板。
#include<iostream>
using namespace std;
template <typename T,int size>class seqlist{
	T slist[size];                                     //存放顺序表的数组
	int Maxsize;                                       //最大可容纳项数
	int last;                                          //已存表项的最后位置
public:
	seqlist(){last=-1;Maxsize=size;}                   //初始化为空表
	int Length() const{return last+1;}                 //计算表长度
	int Find(T & x)const;                              //寻找x在表中位置（下标）
	bool IsIn(T & x);                                  //判断x是否在表中
	bool Insert(T & x,int i);                          //x插入到列表中第i个位置处（下标）
	bool Remove(T & x);                                //删除x
	int Next(T & x);                                   //寻找x的后继位置
	int Prior(T & x);                                  //寻找x的前驱位置
	bool IsEmpty(){return last==-1;}                   //判断表是否空
	bool IsFull(){return last==Maxsize -1;}            //判断表是否满
	T Get(int i){return i<0||i>last?NULL:slist[i];}    //取第i个元素之值
	T& operator[](int i);                              //重载下标运算符[]
};
template <typename T,int size> int seqlist<T,size>::Find(T & x)const{
    //注意格式，const表示该函数的this指针为const，即被访问对象的数据不能被修改。
    //如被修改，编译器会警告，防止编程时失误。
	int i=0;
	while(i<=last && slist[i]!=x) i++;  //顺序查找是否有x
	if (i>last) return -1;              //未找到，返回-1
	else return i;                      //找到，返回下标
}
template <typename T,int size> bool seqlist<T,size>::IsIn(T & x){
	int i=0;
	bool found=0;
	while(i<=last && !found)            //换了一种方法来查找
		if (slist[i]!=x) i++;
		else found=1;                       //找到
    return found;
}
template <typename T,int size> bool seqlist<T,size>::Insert(T & x, int i){
	int j;
	if (i<0||i>last+1||last==Maxsize -1) return false;  //插入位置不合理，不能插入（健壮性）
	else{
		last++;
		for(j=last;j>i;j--) slist[j]=slist[j-1];    //从表最后位置向前依次后移，空出指定位置
		slist[i]=x;
		return true;
	}
}
template <typename T,int size> bool seqlist<T,size>::Remove(T & x){
	int i=Find(x),j;                                        //先去找x在哪个位置
	if(i>=0){
		last--;
		for(j=i;j<=last;j++) slist[j]=slist[j+1];         //依次前移，保证表连续
		return true;
	}
	return false;                                         //表中不存在x
}
template <typename T,int size> int seqlist<T,size>::Next(T & x){
	int i=Find(x);
	if(i>=0 && i<last) return i+1;                        //x后继位置
	else return -1;                                       //x不在表中，或在表末尾
}
template <typename T,int size> int seqlist<T,size>::Prior(T & x){
	int i=Find(x);
	if(i>0 && i<=last)  return i-1;                       //x前驱的位置
	else return -1;
}
template <typename T,int size> T& seqlist<T,size>::operator[](int i){
	if(i>last+1||i<0||i>=Maxsize){
		cout<<"下标出界！"<<endl;
		exit(1);
	}
	if(i>last) last++;  //下标运算符[]，只能增加表的元素，不能减少
	return slist[i];
}

int main(){
	seqlist <int,100> seqlisti;                         //顺序表对象seqlisti的元素为整型
	int i,j,k,a[10]={2,3,5,7,11,13,17,19,23,29};
	for(j=0;j<10;j++)
		if (!seqlisti.Insert(a[j],j)){                      //把素数写入
			cout<<"表太大放不下了!"<<endl;
			break;
		}
	j=seqlisti.Length();
	for(i=0;i<j;i++) cout<<seqlisti.Get(i)<<' ';        //打印出seqlisti.slist[]-素数表
	cout<<endl ;
	for(j=0;j<10;j++) seqlisti[j]=0;                    //采用下标运算符运算
	for(j=0;j<10;j++) cout<<seqlisti[j]<<' ';
	cout<<endl;
	for(j=0;j<10;j++) seqlisti[j]=a[j];
	seqlisti[10]=31;                                    //实验能否增加元素
	for(j=0;j<11;j++) cout<<seqlisti[j]<<' ';
	cout<<endl;
    
	k=7;
	if (seqlisti.IsIn(k)) cout<<"素数7在顺序表中"<< endl;
	//因形参为引用，所以实参不可用整数常量7
	else cout <<"素数7不在顺序表中"<<endl;
	k=17;
	if (seqlisti.Remove (k)) cout<<"删除素数17"<<endl;  //删除素数17
	else cout<<"找不到素数17，无法删除";
	j=seqlisti.Length( ) ;
	for (i=0;i<j;i++) cout<<seqlisti.Get(i)<<' ';      //打印剩下的素数
	cout<<endl;
	if (seqlisti.Insert(k,j-1)){                       // 把素数17装回去,成功则打印
		j=seqlisti.Length ( );
		for (i=0;i<j;i++)  cout<<seqlisti.Get(i)<<' ';
		cout<<endl;
	}
	cout<<"打印17后一个素数："<<seqlisti.Get(seqlisti.Next(k)) <<endl;
	cout<<"打印17前一个素数："<<seqlisti.Get(seqlisti.Prior(k))<<endl;
	cout<<"素数17在表中位置（下标）为："<<seqlisti.Find(k)<<endl;
	if(seqlisti.IsEmpty( ))  cout<<"表是空的"<<endl;
	else cout<<"表不空"<<endl;
	if (seqlisti.IsFull())  cout<<"表是满的"<<endl;
	else cout<<"表也不满"<<endl;
	if (seqlisti.IsIn(k))  cout<<"素数17在表中"<<endl;
	return 0;
}
