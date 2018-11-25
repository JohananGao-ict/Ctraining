#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	
	int id;
	struct node* next;
	
}node;

//�ڵ㴴��
node* creatList(){
	
	//����ͷ�ڵ�
	node* head = (node*)malloc(sizeof(node));
	if(head == NULL){
		
		printf("����ͷ�ڵ�ʧ��\n");
		
		return NULL;
	}
	//ͷ�ڵ㸳ֵ
	head->id = 0;
	head->next = NULL;
	//������ǰ�ڵ�
	node* pCur = head;
	node* pNew = NULL;
	
	int data = 0;
	
	while(1){
		printf("���������ݣ�");
		scanf("%d", &data);
		if(data == -1){
			printf("�����ڵ㴴��\n");
			break;
		}
		//�����������ڵ�ռ�
		pNew = (node*)malloc(sizeof(node));
		pNew->id = data;
		pNew->next = NULL;
		//�����ڵ�
		pCur->next = pNew;
		//���õ�ǰ�ڵ�
		pCur = pNew;
		
	}
	
	return head;
}
//�ڵ����
void ListPrint(node* head){
	node* pCur = head->next;
	printf("��ӡ�������ݣ�head->");
	while(pCur != NULL){
		printf("%d->", pCur->id);
		pCur = pCur->next;
	}
	printf("NULL\n");
	printf("�����������\n");
}

//�ڵ����(��x���ھ���xǰ����y�������ھ�������β������y)
int ListInsert(node* head, int x, int y){
	if(head == NULL){
		printf("����ʧ��\n");
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
	//��������ڵ�
	node* pNew = (node*)malloc(sizeof(node));
	if(pNew == NULL){
		printf("��������ڵ�ʧ��\n");
		return -2;
	}
	pNew->id = y;
	pNew->next = NULL;
	//����ڵ�
	pPre->next = pNew;
	pNew->next = pCur;
	
	return 0;
}

//ɾ���ڵ㣬ɾ������xֵ�Ľڵ�
int ListDelete(node* head, int x){
	if(head == NULL){
		return -1;
	}
	node* pPre = head;
	node* pCur = head->next;
	int flag = 0;
	while(pCur != NULL){
		if(pCur->id == x){//ɾ���ҵ��Ľڵ�
			pPre->next = pCur->next;
			free(pCur);
			pCur = pPre->next;
			flag = 1;
			continue;  //��������ѭ��
		}
		pPre = pCur;
		pCur = pCur->next;	
	}
	
	if(flag == 0){
		printf("û���ҵ�ֵΪ%d�Ľڵ�\n",x);
		return -2;
	}
	
	return 0;
}
//�ͷŶ����ռ�
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
	printf("һ���ͷ�%d�ڵ�\n",i);
	return 0;
	
}
//����
int ListSort(node* head){
	node* pPre = NULL;
	node* pCur = NULL;
	node tmp;
	if((head == NULL) || (head->next == NULL)){
		return -1;
	}
	
	for(pPre=head->next; pPre != NULL; pPre=pPre->next){
		for(pCur=pPre->next; pCur != NULL; pCur=pCur->next){
			
			if(pPre->id > pCur->id){   //����
				/*
				//1.�������������滹Ҫ����ָ���򣬲�Ȼָ��ָ�򽻻���
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
//��ת
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