#include<iostream>
#include<windows.h>
using namespace std;
typedef struct LinkNode{
	int data;
	LinkNode * next;
}ListNode,*LinkList;

//ͷ�巨 ����������
LinkNode * createListHead(){
	ListNode *temp;
	int data = 0;
	//��ʼ��ͷ���,ͷ���Ϊ��
	LinkNode * head = (LinkList)malloc(sizeof(ListNode));
	head->next = NULL;
	//����ڵ�ֵ��
	while(cin>>data&&data!=-1){
		//�����½ڵ�
		temp = (ListNode *)malloc(sizeof(ListNode));
		temp->data = data;
		temp->next = head->next;
		head->next = temp;
	}
	return head;
}

//β�巨
LinkNode * createListRear(){
	//����ͷ�սڵ�
	LinkNode * head = (LinkNode *)malloc(sizeof(LinkNode));
	//������ʱ�ڵ�,��βָ��
	LinkNode * temp,* r=head;
	int data;
	while(cin>>data&&data!=-1){
		temp = (LinkNode *)malloc(sizeof(LinkNode));
		temp->data = data;
		temp->next = NULL;
		r->next = temp;
		r = temp;
	}
	return head;
}

//����������ȡ������
int printList(LinkList L){
	LinkNode * p = L->next;
	int length = 0;
	if(p==NULL){
		cout<<"LinkList is NULL"<<endl;
		return 0;
	}
	while(p!=NULL){
		cout<<p<<"::"<<p->data<<" ";
		p = p->next;
		length++;
	}
	cout<<endl;
	return length;
}

//����Ų���
LinkNode * getItemByIndex(LinkList L,int index){
	LinkNode * p = L->next; 
	int count = 1;
	while(p!=NULL && count<index){
		count++;
		p = p->next;
	}
	return p;
}

//��ֵ����
LinkNode * getItemByValue(LinkList L,int value){
	LinkNode * p = L->next;
	while(p!=NULL && p->data!=value)
		p = p->next;
	return p;
}

//����ڵ� O(n) ǰ��
LinkList insertFormer(LinkList &L,int index,int data){
	LinkNode * formerNode = getItemByIndex(L,index-1);
	LinkNode * insertNode = (LinkNode *)malloc(sizeof(LinkNode));
	insertNode->data = data;
	insertNode->next = formerNode->next;
	formerNode->next = insertNode;
	return L;
}
//����ڵ� O(n) ���
LinkList insertLater(LinkList &L,int index,int data){
	LinkNode * originalNode = getItemByIndex(L,index);
	LinkNode * insertNode = (LinkNode *)malloc(sizeof(LinkNode));
	insertNode->data = data;
	int temp = insertNode->data;
	insertNode->next = originalNode->next;
	originalNode->next = insertNode;
	insertNode->data = originalNode->data;
	originalNode->data = temp;
	return L;
}

//ɾ���ڵ� O(n) ����ǰ���ڵ�
LinkList deleteByFormer(LinkList &L,int index){
	LinkNode * formerNode = getItemByIndex(L,index-1);
	LinkNode * delNode = formerNode->next;
	formerNode->next = delNode->next;
	free(delNode);
	return L;
}

//ɾ���ڵ� O(n) ���ú����ڵ�
LinkList deleteByLater(LinkList &L,int index){
	LinkNode * delNode = getItemByIndex(L,index);
	LinkNode * laterNode = delNode->next;
	delNode->data = laterNode->data;
	delNode->next = laterNode->next;
	free(laterNode);
	return L;
}
//��ԭ��������
ListNode * reverse(ListNode * head){
	if(head==NULL||head->next==NULL)
		return head;
	ListNode * newHead = (ListNode *)malloc(sizeof(ListNode));
	newHead->data = head->data;
	newHead->next = NULL;
	ListNode * p = head->next;
	while(p){
		ListNode * temp = (ListNode *)malloc(sizeof(ListNode));
		temp->data = p->data;
		temp->next = newHead->next;
		newHead->next = temp;
		p = p->next;
	}
	free(head);
	return newHead;
}
//ԭ��������
ListNode * reverseList(ListNode * head){

}

int main(){
	//LinkList headL = createListHead();
	//int lengthHead = printList(headL);
	//cout<<"LinkList length = "<<lengthHead<<endl;
	////��������
	LinkList rearL = createListRear();
	//���������
	int lengthRear = printList(rearL);
	cout<<"LinkList length = "<<lengthRear<<endl;
	//��λ�ò��ҽڵ�
	//LinkNode * indexNode = getItemByIndex(rearL,4);
	//cout<<"the node data is "<<indexNode->data<<endl;
	////��ֵ���ҽڵ�
	//LinkNode * valueNode = getItemByValue(rearL,50);
	//if(valueNode)
	//	cout<<"the node data is "<<valueNode->data<<endl;
	//else
	//	cout<<"Not Found"<<endl;
	////ǰ��ڵ�
	//insertFormer(rearL,3,100);
	//printList(rearL);
	////���ڵ�
	//insertLater(rearL,4,200);
	//printList(rearL);
	////ɾ�� ����ǰ��
	//deleteByFormer(rearL,4);
	//printList(rearL);
	////ɾ�� ���ú���
	//deleteByLater(rearL,3);
	//printList(rearL);
	//LinkList reverseList = (LinkNode *)malloc(sizeof(LinkNode));
	//reverseByCreateList(rearL,reverseList);
	//printList(reverseList);
	
	LinkList list = reverse(rearL);
	printList(list);
	system("pause");
	return 0;
}

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if(head->next==NULL||head==NULL)
//            return head;
//        else{
//        ListNode * newHead = (ListNode *)malloc(sizeof(ListNode));
//	    newHead->next = NULL;
//	    ListNode * p;
//    	ListNode * temp = head->next;
//    	while(temp){
//		    p = (ListNode *)malloc(sizeof(ListNode));
//		    p->val = temp->val;
//	    	p->next = newHead->next;
//	    	newHead->next = p;
//	    	temp = temp->next;
//    	}
//	    free(head);
//	    return newHead;
//        }
//    }
//};
//ListNode* reverseList(ListNode* head) {
//        if(head==NULL||head->next==NULL)
//		return head;
//	ListNode * newHead = (ListNode *)malloc(sizeof(ListNode));
//	newHead->val = head->val;
//	newHead->next = NULL;
//	ListNode * p = head->next;
//	while(p){
//		ListNode * temp = (ListNode *)malloc(sizeof(ListNode));
//		temp->val = p->val;
//		temp->next = newHead->next;
//		newHead->next = temp;
//		p = p->next;
//	}
//	return newHead;
//    }