#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#define LENGTH 10

long getSystemTime(){   //��ȡϵͳʱ�䣬���غ���
	struct timeb tb;
	ftime(&tb);
	return tb.time*1000+tb.millitm;    //time���룬millitm����
}


void insert_sort(int p[],int length){  //��������
	int tmp = 0;
	int j = 0;
	for(int i=1; i<length; i++){
		if(p[i-1] > p[i]){
			tmp = p[i];
			for(j=i-1; j>=0&&tmp<p[j]; j--){
				p[j+1] = p[j];
			}
			p[j+1] = tmp;
		}
	}
} 

void shellsort(int arr[], int length){    //ϣ������
	int increasement = length;
	int i,j,k;
	int tmp = 0;
	do{
		//ȷ�����������
		increasement = increasement/3+1;
		for(i=0; i<increasement; i++){
			for(j=i+increasement; j<length; j+=increasement){
				if(arr[j]<arr[j-increasement]){
					tmp = arr[j];
					for(k=j-increasement; k>=0&&tmp<arr[k]; k-=increasement){
						arr[k+increasement] = arr[k];
					}
					arr[k+increasement] = tmp;
				}
			}
		}
		
	}while(increasement>1);
}

void Quicksort(int arr[],int start, int end){ //��������

	int i = start;
	int j = end;
	int tmp = arr[start];  //��׼��
	
	if(i<j){
		while(i<j){
			//��������ȥ�ұȻ�׼��С��
			while(i<j&&arr[j]>=tmp){
				j--;
			}
			//���
			if(i<j){
				arr[i] = arr[j];
				i++;
			}
			//��������ȥ�ұȻ�׼�����
			while(i<j&&arr[i]<=tmp){
				i++;
			}
			//���
			if(i<j){
				arr[j] = arr[i];
				j--;
			}
		}
		//�ѻ�׼���ŵ�iλ��
		arr[i] = tmp;
		//�ݹ飬����벿�ֽ��п�������
		Quicksort(arr,start,i-1);
		//����벿�ֽ��п�������
		Quicksort(arr,i+1,end);
	}
		
	
}


int main(){
	
	srand((unsigned int)time(NULL));
	
	int a[LENGTH]={0};
	
	for(int i=0 ; i<LENGTH; i++){
		a[i] = rand()%100;
	}
	
	
	//shellsort(a, LENGTH);
	Quicksort(a,0,LENGTH-1);
	
	for(int i=0 ; i<LENGTH; i++){
		printf("%d ",a[i]);
	}
	
	printf("\n");
	
	
	return 0;
}