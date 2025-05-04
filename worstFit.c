#include<stdio.h>
int main(){
	int n,m;
	printf("Enter the number of blocks:");
	scanf("%d",&n);
	int block[n],block_size[n];
	printf("Enter the number of files:");
	scanf("%d",&m);
	int file[m],allocated[m];
	printf("Enter the size of the blocks:-\n");
	for(int i=0;i<n;i++){
		printf("Block %d:",i+1);
		scanf("%d",&block[i]);
		allocated[i]=-1;
		block_size[i]=block[i];
	}
	printf("Enter the size of the files:\n");
	for(int i=0;i<m;i++){
		printf("File %d:",i+1);
		scanf("%d",&file[i]);
	}
	for(int i=0;i<m;i++){
		int worstfit=-1;
		for(int j=0;j<n;j++){
			if(block[j]>=file[i]){
				if(worstfit==-1){
					worstfit=j;
				}
				else if(block[worstfit]<block[j]){
					worstfit=j;
				}
			}
		}
		if(worstfit!=-1){
			allocated[i]=worstfit;
			block[worstfit]=-1;
		}
	}
	printf("File_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");
	for(int i=0;i<m;i++){
		if(allocated[i]!=-1){
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,file[i],allocated[i]+1,block_size[allocated[i]],block_size[allocated[i]]-file[i]);
		}else{
			printf("%d\t\t%d\t\tNot Allocated\n",i+1,file[i]);
		}
	}
	return 0;
}