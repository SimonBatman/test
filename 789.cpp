#include "stdafx.h"
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

//定义线性表List
template <class T>
class List {
	void clear();					//置表空
	bool create1(const int size);
	bool destroy1();
	bool isEmpty();					//判表空（返回true）	
	bool insert(const int p, const T value);	//插入表元
	bool delete1(const int p); 			//删除表元
	bool getPos(int &p, const T value);		//查表元（返回位置）
	bool getValue(const int p, T &value);	 	//读表元（返回值）
	bool setValue(const int p, const T value);	//置表元
	int length(T &value);                       	//求表长
	void display();                 		//显示表
	bool append(const T value);	                //追加表元
};


//定义顺序表arrList
template <class T>
class arrList : public List<T> {			//顺序表，向量
private:    						
	T    *aList;     		   		//顺序表的头指针
	int  maxSize;            			//顺序表的最大长度
	int  curLen; 					//顺序表实例的实际长度
	int  position;					//当前处理位置
public: 						
	arrList(const int size) {  			//创建一个新的顺序表，指定最大长度
		maxSize = size;  aList = new T[maxSize]; curLen = position = 0;
	}

	~arrList() {
		delete[] aList;				//析构函数，用于消除顺序表
	}
	bool create1(int size){
		if(size<1) cout<<"非法\n";
		if(aList==NULL){
			cout<<"顺序表为空，可以创建\n"; 
			maxSize = size;  aList = new T[maxSize]; curLen = position = 0;
			return true;
		}
		else{
			cout<<"已有顺序表，不能创建"<<endl;
			return false;
		}
	}
	bool destroy1(){
		if(aList==NULL){
			cout<<"顺序表不存在，不能删"<<endl;
			return false;
		}
		delete[] aList;
		aList=NULL;
		curLen = position = 0;
		return true;
	}
	void clear() { 					
		curLen = position = 0;
		cout << "顺序表已清除！" << endl;
	}
	
	void display() { 
		if(aList==NULL){cout << "顺序表不存在，不能展示，请先创建" <<endl;}
		if (curLen == 0) {
			cout << "空表！" << endl;
		}
		for (int i = 0; i < curLen; i++) 
			cout << aList[i] << "  ";
		cout << endl;
	}

	int  length() {               
		return curLen;
	}  
	
	bool isEmpty() {
		if (curLen > 0) {
			return false;
		}
		return true;
	}

	bool append(const T value) {
		if(aList==NULL) {
			cout << "顺序表不存在，不能添加，请先创建顺序表" << endl;
		}
		if (curLen >= maxSize) {
			cout << "表满！" << endl;
			return false;
		}
		aList[curLen++] = value;
		return true;
	}				
	
	bool insert(const int p, const T value) {   //在位置p上插入一个元素value，表的长度增1
		if(aList==NULL) {
			cout << "顺序表不存在，不能添加，请先创建顺序表" << endl;
		}
		if (p > curLen+1 || p < 1) {
			cout << "位置错误！" << endl;
			return false;
		}
		for (int i = curLen-1; i >= p-1; i--) {
			aList[i+1] = aList[i];
		}
		aList[p-1] = value;
		curLen++;
		return true;
	}
	
	bool delete1(const int p) {        //删除位置p上的元素，表的长度减 1
		if(aList==NULL) {
			cout << "顺序表不存在，不能删除，请先创建顺序表" << endl;
		}
		if(p < 1 || p > curLen){
			cout << "位置错误！" << endl;
			return false;
		}
		for (int i = p-1; i < curLen ; i++) {
			aList[i] = aList[i+1];
		}
		curLen--;
		return true;
	}					
	
	bool setValue(const int p, T& value) {       //用value修改位置p的元素值
		if(aList==NULL) {
			cout << "顺序表不存在，不能修改，请先创建顺序表" << endl;
		}
		if (p < 1 || p > curLen) {
			cout << "位置错误！" << endl;
			return false;
		}
		aList[p-1] = value;
		return true;
	}	

	bool getValue(const int p, T& value) {      //把位置p的元素值返回到变量value中 
		if(aList==NULL) {
			cout << "顺序表不存在，不能返回，请先创建顺序表" << endl;
		}
		if (p < 1 || p > curLen) {
			cout << "位置错误！" << endl;
			return false;
		}
		value = aList[p-1];
		return true;
	}		
	
	bool getPos(int &p, const T value) {    //查找值为value的元素，并返回第1次出现的位置
		if(aList==NULL) {
			cout << "顺序表不存在，不能返回，请先创建顺序表" << endl;
		}
		if (isEmpty()) {
			return false;
		}
		for (int i = 0; i < curLen; i++) {
			if (aList[i] == value) {
				p = i+1;
				break;
			}
		}
		if(i<curLen) return true;
		else return false;
	}		
};



void main()
{
	arrList<char> AL(100);			//定义及构造顺序表对象
	int choice;
	int p;
	char value;
	bool ok;
	do {
		printf("请选择(0退出, 1清除, 2显示, 3表长, 4插入, 5追加, 6删除, 7查找, 8修改, 9定位, 10创建 ,11销毁):");
		cout<<"选择:\n";  cin>>choice; 
		switch (choice) {
		case 0:
			printf("再见！\n");
			break;
		case 1:
			AL.clear();
			break;
		case 2:
			AL.display();
			break;
		case 3:
			cout << "表长:" << AL.length() << endl;
			break;
		case 4:
			printf("位置:"); scanf("%d",&p); getchar();
			printf("元素:"); scanf("%c",&value);
			ok=AL.insert(p,value );
			if(ok==true) printf("插入操作成功！\n");
			break;
		case 5:
			printf("元素:"); scanf("%c",&value);
			ok=AL.append(value );
			if(ok==true) printf("追加操作成功！\n");
			break;
		case 6:
			printf("位置:"); scanf("%d",&p); getchar();
			ok=AL.delete1(p);
			if(ok==true) printf("删除操作成功！\n");
			break;
		case 7:
			printf("位置:"); scanf("%d",&p); getchar();
			ok=AL.getValue(p,value );
			if(ok==true) printf("元素值为:%c\n",value);
			break;
		case 8:
			printf("位置:"); scanf("%d",&p); getchar();
			printf("元素:"); scanf("%c",&value);
			ok=AL.setValue(p,value );
			if(ok==true) printf("修改操作成功！\n");
			break;
		case 9:
			printf("元素:"); scanf("%c",&value);
			ok=AL.getPos(p,value );
			if(ok==true) printf("元素位置为:%d\n",p);
			else printf("元素不存在！\n");
			break;
		case 10:
			cout<<"输入:"<<endl;
			cin>>p;
			ok= AL.create1(p);
			if(ok==true) cout<<"创建成功"<<endl;
			else cout<<"失败"<<endl;
			break;
		case 11:
			ok= AL.destroy1();
			if(ok==true) cout<<"删除成功"<<endl;
			else cout<<"失败"<<endl;
			break;
		default: cout<<"选择错误！"<<endl;
		}
		system("pause");
		system("cls");
	} while (choice != 0);

	getchar();						//暂停
}

