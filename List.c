#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	
	int id;
	struct node* next;
	
}node;

//节点创建
node* creatList(){
	
	//创建头节点
	node* head = (node*)malloc(sizeof(node));
	if(head == NULL){
		
		printf("创建头节点失败\n");
		
		return NULL;
	}
	//头节点赋值
	head->id = 0;
	head->next = NULL;
	//创建当前节点
	node* pCur = head;
	node* pNew = NULL;
	
	int data = 0;
	
	while(1){
		printf("请输入数据：");
		scanf("%d", &data);
		if(data == -1){
			printf("结束节点创建\n");
			break;
		}
		//申请堆区链表节点空间
		pNew = (node*)malloc(sizeof(node));
		pNew->id = data;
		pNew->next = NULL;
		//关联节点
		pCur->next = pNew;
		//重置当前节点
		pCur = pNew;
		
	}
	
	return head;
}
//节点遍历
void ListPrint(node* head){
	node* pCur = head->next;
	printf("打印链表数据：head->");
	while(pCur != NULL){
		printf("%d->", pCur->id);
		pCur = pCur->next;
	}
	printf("NULL\n");
	printf("链表遍历结束\n");
}

//节点插入(若x存在就在x前插入y，不存在就在链表尾部插入y)
int ListInsert(node* head, int x, int y){
	if(head == NULL){
		printf("插入失败\n");
		return -1;
	}
	node* pPre = head;
	node* pCur = head->next;
	while(pCur != NULL){
		if(pCur->id == x){
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
		
	}
	//创建插入节点
	node* pNew = (node*)malloc(sizeof(node));
	if(pNew == NULL){
		printf("创建插入节点失败\n");
		return -2;
	}
	pNew->id = y;
	pNew->next = NULL;
	//插入节点
	pPre->next = pNew;
	pNew->next = pCur;
	
	return 0;
}

//删除节点，删除所有x值的节点
int ListDelete(node* head, int x){
	if(head == NULL){
		return -1;
	}
	node* pPre = head;
	node* pCur = head->next;
	int flag = 0;
	while(pCur != NULL){
		if(pCur->id == x){//删除找到的节点
			pPre->next = pCur->next;
			free(pCur);
			pCur = pPre->next;
			flag = 1;
			continue;  //结束本次循环
		}
		pPre = pCur;
		pCur = pCur->next;	
	}
	
	if(flag == 0){
		printf("没有找到值为%d的节点\n",x);
		return -2;
	}
	
	return 0;
}
//释放堆区空间
int Listfree(node* head){
	node* tmp = NULL;
	int i = 0;
	if(head == NULL){
		return -1;
	}
	
	while(head != NULL){
		tmp = head->next;
		free(head);
		head = tmp;
		i++;
	}
	printf("一共释放%d节点\n",i);
	return 0;
	
}
//升序
int ListSort(node* head){
	node* pPre = NULL;
	node* pCur = NULL;
	node tmp;
	if((head == NULL) || (head->next == NULL)){
		return -1;
	}
	
	for(pPre=head->next; pPre != NULL; pPre=pPre->next){
		for(pCur=pPre->next; pCur != NULL; pCur=pCur->next){
			
			if(pPre->id > pCur->id){   //升序
				/*
				//1.交换数据域，下面还要单独指针域，不然指针指向交换了
				tmp = *pCur; 
				*pCur = *pPre;
				*pPre = tmp;
				
				tmp.next = pCur->next;
				pCur->next = pPre->next;
				pPre->next = tmp.next;*/
				
				tmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = tmp.id;
				
			}
		
		}
	}
	return 0;
}
//反转
int ListReverse(node* head){
	if((head == NULL) || (head->next == NULL)){
		return -1;
	}
	node* pPre = head->next;
	node* pCur = pPre->next;
	node* tmp = NULL;
	
	while(pCur != NULL){
		tmp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = tmp;
	}
	head->next->next = NULL;
	head->next = pPre;
	
	return 0;
}


int main(int argc, char* argv[]){
	
	node* head = creatList();
	
	//ListInsert(head, 5 , 100);
	
	//ListDelete(head, 4);
	
	//ListSort(head);
	
	ListReverse(head);
	
	printf("\n");
	printf("===========================================\n");
	printf("\n");
	ListPrint(head);
	Listfree(head);
	
	return 0;
}