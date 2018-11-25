#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#define LENGTH 10

long getSystemTime(){   //获取系统时间，返回毫秒
	struct timeb tb;
	ftime(&tb);
	return tb.time*1000+tb.millitm;    //time是秒，millitm毫秒
}


void insert_sort(int p[],int length){  //插入排序
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

void shellsort(int arr[], int length){    //希尔排序
	int increasement = length;
	int i,j,k;
	int tmp = 0;
	do{
		//确定分组的增量
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

void Quicksort(int arr[],int start, int end){ //快速排序

	int i = start;
	int j = end;
	int tmp = arr[start];  //基准数
	
	if(i<j){
		while(i<j){
			//从右向左去找比基准数小的
			while(i<j&&arr[j]>=tmp){
				j--;
			}
			//填坑
			if(i<j){
				arr[i] = arr[j];
				i++;
			}
			//从左向右去找比基准数大的
			while(i<j&&arr[i]<=tmp){
				i++;
			}
			//填坑
			if(i<j){
				arr[j] = arr[i];
				j--;
			}
		}
		//把基准数放到i位置
		arr[i] = tmp;
		//递归，对左半部分进行快速排序
		Quicksort(arr,start,i-1);
		//对左半部分进行快速排序
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