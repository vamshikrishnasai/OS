#include<stdio.h>
#define MAX_BLOCKS 100
#define MAX_FILES 100

int main(){
	int memoryBlocks[MAX_BLOCKS],files[MAX_FILES];
	int numBlocks,numFiles;
	
	printf("Enter number of memory blocks: ");
	scanf("%d",&numBlocks);
	
	printf("Enter sizes of each memory block:\n");
	for(int i=0;i<numBlocks;i++){
		printf("Block %d: ",i+1);
		scanf("%d",&memoryBlocks[i]);
	}
	printf("Enter number of processes: ");
	scanf("%d",&numFiles);
	printf("Enter sizes of each process:\n");
	for(int i=0;i<numFiles;i++){
		printf("Process %d: ",i+1);
		scanf("%d",&files[i]);
	}
	printf("Process No.\tProcess Size\tBlock no.\n");
	for (int i=0;i<numFiles;i++){
		int allocated=-1;
		for(int j=0;j<numBlocks;j++){
			if(memoryBlocks[j]>=files[i]){
				allocated=j+1;
				memoryBlocks[j]-=files[i];
				break;
			}
		}
		if(allocated!=-1){
			printf("%d\t\t%d\t\t\t\t%d\n",i+1,files[i],allocated);
		}
		else{
			printf("%d\t\t%d\t\t\t\tNot Allocated\n",i+1,files[i]);
		}
	}
	
}