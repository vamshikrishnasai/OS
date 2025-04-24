#include<stdio.h>
#define MAX 50
int main(){
	int page[MAX],i,n,f,ps,off,pno;
	printf("Enter the no. of pages in memory:");
	scanf("%d",&n);
	printf("Enter page size:");
	scanf("%d",&ps);
	printf("Enter no. of frames:");
	scanf("%d",&f);
	for(i=0;i<n;i++){
		page[i]=-1;
	}
	printf("Enter the page table\n");
	printf("(Enter frame no as -1 if the page is not present in any frame)\n");
	printf("Page no\tFrame no\n--------\t--------");
	for(i=0;i<n;i++){
		printf("\n%d\t\t",i);
		scanf("%d",&page[i]);
	}
	printf("\nEnter the logical address(i.e., page no & offset):");
	scanf("%d%d",&pno,&off);
	if(page[pno]==-1){
		printf("The required page is not available in any of frames\n");
	}
	else{
		printf("Physical address(i.e., frame no & offset): %d %d",page[pno],off);
	}
	return 0;
}
