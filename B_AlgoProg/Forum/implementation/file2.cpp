#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct score{
	int tm;
	int uts;
	int uas;
};

struct data{
	char name[100];
	char nim[10];
	score scores;
};

void readFile(data datas[], int& size);
void printData(data datas[],int size);

void viewData(data datas[],int size);
void bubbleSort(data datas[],int size);
void mergeSort(data datas[], int l, int r);

void insertData(data datas[],int& size);

void searchData(data datas[],int size);

int main(){
	data datas[100];
	int size=0;
	
	readFile(datas,size);
	
	int input;
	
	do{
		puts("1. view data");
		puts("2. insert data");
		puts("3. search data");
		
		do{
			printf("input(0 to exit) :");
			scanf("%d",&input);getchar();
		}while(input < 0 || input > 3);
		
		switch(input){
			case 1: viewData(datas,size);break;
			case 2: insertData(datas,size);break;
			case 3: searchData(datas,size);break;
		}
	}while(input != 0);
	
}

void readFile(data datas[], int& size){
	
	FILE *fp;
	fp=fopen("data.in","r");
	if(fp == NULL){
      perror("Error ");
	}
	else{
		while(!feof(fp)){
			
			fscanf(fp,"%[^,],%[^,],%d,%d,%d\n",&datas[size].name,&datas[size].nim,&datas[size].scores.tm,&datas[size].scores.uts,&datas[size].scores.uas);
			size+=1;
		}
			
	}
	
	fclose(fp);
}

void viewData(data datas[],int size){
	int input;
	
	do{
		printData(datas,size);
		puts("");
		
		puts("1. order by name [bubble]");
		puts("2. order by name [merge]");
		
		do{
			printf("input (0 to go back) :");
			scanf("%d",&input);getchar();
		}while(input < 0 || input > 2);
		if(input == 0) continue;
		
		switch(input){
			case 1 : bubbleSort(datas,size);break;
			case 2 : mergeSort(datas,0,size-1); break;
		}
	}while(input != 0);
}

void bubbleSort(data datas[],int size){
	for(int i=0;i<size;i++){
		for(int j=0; j < size-i-1;j++){
			if(strcmp(datas[j].name,datas[j+1].name) > 0){
				data temp = datas[j];
				datas[j] = datas[j+1];
				datas[j+1] = temp; 
			}
		}
	}
};

void merge(data *datas, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    data L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = datas[l + i];
    for (j = 0; j < n2; j++)
        R[j] = datas[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
    	if(strcmp(L[i].name,R[j].name) > 0){
            datas[k] = L[i];
            i++;
        }
        else {
            datas[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        datas[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        datas[k] = R[j];
        j++;
        k++; 
    }
}

void mergeSort(data datas[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(datas, l, m);
        mergeSort(datas, m + 1, r);
 
        merge(datas, l, m, r);
    }
}

void printData(data datas[],int size){
	if(size >0){
		for(int i=0;i< size;i++){
			printf("%s %s %d %d %d\n",datas[i].name ,datas[i].nim,datas[i].scores.tm,datas[i].scores.uts,datas[i].scores.uas);
		}
	}
}

void printSingleData(data datas[],int n){
	puts("data found!");
	printf("%s %s %d %d %d\n",datas[n].name ,datas[n].nim,datas[n].scores.tm,datas[n].scores.uts,datas[n].scores.uas);
	puts("");
}

void insertData(data datas[],int& size){
	
	if(size==100){
		puts("student limit reach");
	}else
	{
		FILE *fp;
		srand(time(NULL));
		
		printf("student name :");
		scanf("%[^\n]",datas[size].name);getchar();
		
		printf("student nim :");
		scanf("%[^\n]",datas[size].nim);getchar();
		
		datas[size].scores.tm = rand()%100 + 1;
		datas[size].scores.uts = rand()%100 + 1;
		datas[size].scores.uas = rand()%100 + 1;
		
		fp=fopen("data.in","w");
		puts("processing to data insertion. . .");
		for(int i=0;i< size+1;i++){
			printf(" inserting -> %s,%s,%d,%d,%d\n",datas[i].name,datas[i].nim,datas[i].scores.tm,datas[i].scores.uts,datas[i].scores.uas);
		
			fprintf(fp,"%s,%s,%d,%d,%d\n",datas[i].name,datas[i].nim,datas[i].scores.tm,datas[i].scores.uts,datas[i].scores.uas);
		}
		fclose(fp);
	}
}

int BinarySearch(data *datas, int l, int r, char *nim)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        
        if (strcmp(datas[mid].nim , nim)==0){
			printSingleData(datas,mid); 	
            return 0;	
		}
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (strcmp(datas[mid].nim , nim)>0)
            return BinarySearch(datas, l, mid - 1, nim);
  
        // Else the element can only be present
        // in right subarray
        return BinarySearch(datas, mid + 1, r, nim);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}

void searchData(data datas[],int size){
	int input;
	char nim[100];
	do{
		printData(datas,size);
		puts("");
		printf("search by nim :");
		scanf("%s",nim);getchar();
		
		puts("1. linear search");
		puts("2. interpolation search");
		do{
			printf("input (0 to go back) :");
			scanf("%d",&input);getchar();
		}while(input < 0 || input > 2);
		if(input == 0) continue;
		
		switch(input){
			case 1 : 
			{
				for(int i=0;i < size;i++){
					if(strcmp(nim,datas[i].nim) == 0){
						printSingleData(datas,i);
						break;
					}
				}
			}; break;
			case 2 : 
			{
				BinarySearch(datas, 0,size-1, nim);
			}; 
		}
	}while(input != 0);
}

