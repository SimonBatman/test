#include "stdafx.h"
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

//�������Ա�List
template <class T>
class List {
	void clear();					//�ñ��
	bool create1(const int size);
	bool destroy1();
	bool isEmpty();					//�б�գ�����true��	
	bool insert(const int p, const T value);	//�����Ԫ
	bool delete1(const int p); 			//ɾ����Ԫ
	bool getPos(int &p, const T value);		//���Ԫ������λ�ã�
	bool getValue(const int p, T &value);	 	//����Ԫ������ֵ��
	bool setValue(const int p, const T value);	//�ñ�Ԫ
	int length(T &value);                       	//���
	void display();                 		//��ʾ��
	bool append(const T value);	                //׷�ӱ�Ԫ
};


//����˳���arrList
template <class T>
class arrList : public List<T> {			//˳�������
private:    						
	T    *aList;     		   		//˳����ͷָ��
	int  maxSize;            			//˳������󳤶�
	int  curLen; 					//˳���ʵ����ʵ�ʳ���
	int  position;					//��ǰ����λ��
public: 						
	arrList(const int size) {  			//����һ���µ�˳���ָ����󳤶�
		maxSize = size;  aList = new T[maxSize]; curLen = position = 0;
	}

	~arrList() {
		delete[] aList;				//������������������˳���
	}
	bool create1(int size){
		if(size<1) cout<<"�Ƿ�\n";
		if(aList==NULL){
			cout<<"˳���Ϊ�գ����Դ���\n"; 
			maxSize = size;  aList = new T[maxSize]; curLen = position = 0;
			return true;
		}
		else{
			cout<<"����˳������ܴ���"<<endl;
			return false;
		}
	}
	bool destroy1(){
		if(aList==NULL){
			cout<<"˳������ڣ�����ɾ"<<endl;
			return false;
		}
		delete[] aList;
		aList=NULL;
		curLen = position = 0;
		return true;
	}
	void clear() { 					
		curLen = position = 0;
		cout << "˳����������" << endl;
	}
	
	void display() { 
		if(aList==NULL){cout << "˳������ڣ�����չʾ�����ȴ���" <<endl;}
		if (curLen == 0) {
			cout << "�ձ�" << endl;
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
			cout << "˳������ڣ�������ӣ����ȴ���˳���" << endl;
		}
		if (curLen >= maxSize) {
			cout << "������" << endl;
			return false;
		}
		aList[curLen++] = value;
		return true;
	}				
	
	bool insert(const int p, const T value) {   //��λ��p�ϲ���һ��Ԫ��value����ĳ�����1
		if(aList==NULL) {
			cout << "˳������ڣ�������ӣ����ȴ���˳���" << endl;
		}
		if (p > curLen+1 || p < 1) {
			cout << "λ�ô���" << endl;
			return false;
		}
		for (int i = curLen-1; i >= p-1; i--) {
			aList[i+1] = aList[i];
		}
		aList[p-1] = value;
		curLen++;
		return true;
	}
	
	bool delete1(const int p) {        //ɾ��λ��p�ϵ�Ԫ�أ���ĳ��ȼ� 1
		if(aList==NULL) {
			cout << "˳������ڣ�����ɾ�������ȴ���˳���" << endl;
		}
		if(p < 1 || p > curLen){
			cout << "λ�ô���" << endl;
			return false;
		}
		for (int i = p-1; i < curLen ; i++) {
			aList[i] = aList[i+1];
		}
		curLen--;
		return true;
	}					
	
	bool setValue(const int p, T& value) {       //��value�޸�λ��p��Ԫ��ֵ
		if(aList==NULL) {
			cout << "˳������ڣ������޸ģ����ȴ���˳���" << endl;
		}
		if (p < 1 || p > curLen) {
			cout << "λ�ô���" << endl;
			return false;
		}
		aList[p-1] = value;
		return true;
	}	

	bool getValue(const int p, T& value) {      //��λ��p��Ԫ��ֵ���ص�����value�� 
		if(aList==NULL) {
			cout << "˳������ڣ����ܷ��أ����ȴ���˳���" << endl;
		}
		if (p < 1 || p > curLen) {
			cout << "λ�ô���" << endl;
			return false;
		}
		value = aList[p-1];
		return true;
	}		
	
	bool getPos(int &p, const T value) {    //����ֵΪvalue��Ԫ�أ������ص�1�γ��ֵ�λ��
		if(aList==NULL) {
			cout << "˳������ڣ����ܷ��أ����ȴ���˳���" << endl;
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
	arrList<char> AL(100);			//���弰����˳������
	int choice;
	int p;
	char value;
	bool ok;
	do {
		printf("��ѡ��(0�˳�, 1���, 2��ʾ, 3��, 4����, 5׷��, 6ɾ��, 7����, 8�޸�, 9��λ, 10���� ,11����):");
		cout<<"ѡ��:\n";  cin>>choice; 
		switch (choice) {
		case 0:
			printf("�ټ���\n");
			break;
		case 1:
			AL.clear();
			break;
		case 2:
			AL.display();
			break;
		case 3:
			cout << "��:" << AL.length() << endl;
			break;
		case 4:
			printf("λ��:"); scanf("%d",&p); getchar();
			printf("Ԫ��:"); scanf("%c",&value);
			ok=AL.insert(p,value );
			if(ok==true) printf("��������ɹ���\n");
			break;
		case 5:
			printf("Ԫ��:"); scanf("%c",&value);
			ok=AL.append(value );
			if(ok==true) printf("׷�Ӳ����ɹ���\n");
			break;
		case 6:
			printf("λ��:"); scanf("%d",&p); getchar();
			ok=AL.delete1(p);
			if(ok==true) printf("ɾ�������ɹ���\n");
			break;
		case 7:
			printf("λ��:"); scanf("%d",&p); getchar();
			ok=AL.getValue(p,value );
			if(ok==true) printf("Ԫ��ֵΪ:%c\n",value);
			break;
		case 8:
			printf("λ��:"); scanf("%d",&p); getchar();
			printf("Ԫ��:"); scanf("%c",&value);
			ok=AL.setValue(p,value );
			if(ok==true) printf("�޸Ĳ����ɹ���\n");
			break;
		case 9:
			printf("Ԫ��:"); scanf("%c",&value);
			ok=AL.getPos(p,value );
			if(ok==true) printf("Ԫ��λ��Ϊ:%d\n",p);
			else printf("Ԫ�ز����ڣ�\n");
			break;
		case 10:
			cout<<"����:"<<endl;
			cin>>p;
			ok= AL.create1(p);
			if(ok==true) cout<<"�����ɹ�"<<endl;
			else cout<<"ʧ��"<<endl;
			break;
		case 11:
			ok= AL.destroy1();
			if(ok==true) cout<<"ɾ���ɹ�"<<endl;
			else cout<<"ʧ��"<<endl;
			break;
		default: cout<<"ѡ�����"<<endl;
		}
		system("pause");
		system("cls");
	} while (choice != 0);

	getchar();						//��ͣ
}

