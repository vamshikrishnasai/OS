#include<stdio.h>
int main(){
	int n,m;
	printf("Enter the number of blocks: ");
	scanf("%d",&n);
	printf("Enter the number of files: ");
	scanf("%d",&m);
	int block[n],fragment[n];
	int allocated[m],process[m],processno[n];
	printf("Enter the size of the blocks:\n");
	for(int i=0;i<n;i++){
		printf("Block %d: ",i+1);
		scanf("%d",&block[i]);
		fragment[i]=block[i];
	}
	printf("Enter the size of the files:\n");
	for(int i=0;i<m;i++){
		processno[i]=1+1;
		allocated[i]=-1;
		printf("File %d: ",i+1);
		scanf("%d",&process[i]);
	}
	for(int i=0;i<m;i++){
		int bestfit=-1;
		for(int j=0;j<n;j++){
			if(block[j]>=process[i]){
				if(bestfit==-1){
					bestfit=j;
				}
				else if(block[bestfit]>block[j]){
					bestfit=j;
				}
			}
		}
		if(bestfit!=-1){
			allocated[i]=bestfit;
			block[bestfit]-=process[i];
		}
	}
	printf("File No\tFile Size\tBlock No\tBlock Size\tFragment\n");
	for(int i=0;i<m;i++){
		if(allocated[i]!=-1){
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],allocated[i]+1,fragment[allocated[i]],block[allocated[i]]);
		}
	}


	
	return 0;
}