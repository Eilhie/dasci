#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

struct score{
    int tm;
    int uts;
    int uas;
};

struct data{
    char name[100];
    char nim[10];
    score scores;
	// point 10 : add your own additional struct (with min.2  attributes) to the existing data (dont forget to add it on insert and save it)
	int semester;
	char grade[20];
};

void readFile(data datas[], int& size);
void printData(data datas[],int size);

void viewData(data datas[],int size);
void bubbleSort(data datas[],int size);
void mergeSort(data datas[], int l, int r);
void quickSortAsc(data datas[], int l, int r);
void quickSortDesc(data datas[], int l, int r);

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

void grading(data datas[], int &size){
	int culmulative = (datas[size].scores.tm * 25 / 100) + (datas[size].scores.uts * 35 / 100) + (datas[size].scores.uas * 40 / 100);
	if(culmulative > 89 && culmulative <= 100)
		strcpy(datas[size].grade, "A");
	else if(culmulative > 85 && culmulative <= 89)
		strcpy(datas[size].grade, "A-");
	else if(culmulative > 79 && culmulative <= 84)
		strcpy(datas[size].grade, "B+");
	else if(culmulative > 75 && culmulative <= 79)
		strcpy(datas[size].grade, "B");
	else if(culmulative > 70 && culmulative <= 74)
		strcpy(datas[size].grade, "B-");
	else if(culmulative > 65 && culmulative <= 69)
		strcpy(datas[size].grade, "C");
	else if(culmulative > 50 && culmulative <= 64)
		strcpy(datas[size].grade, "D");
	else if(culmulative > 0 && culmulative <= 49)
		strcpy(datas[size].grade, "E");
	else
		strcpy(datas[size].grade, "F");
}

void readFile(data datas[], int& size){
	
	FILE *fp;
	// point 10 : instead of static data, make the user input the file name, and read the additional field called GRADE ( which the calculation from scores, details on Insert method)
	char filename[101];
	printf("input file name :");
	scanf("%[^\n]", filename); getchar();
	fp=fopen(filename,"r");

	// this gonna make user input filename and pass to the function to open the file

	if(fp == NULL){
      perror("Error ");
	}
	else{
		while(!feof(fp)){
			
			fscanf(fp,"%[^,],%[^,],%d,%d,%d,%d,%s\n",&datas[size].name,&datas[size].nim,&datas[size].scores.tm,&datas[size].scores.uts,&datas[size].scores.uas,&datas[size].semester,datas[size].grade);
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
		// POINT 20 : order by NIM both asc and desc using quick sort
		puts("3. order by nim Ascending [quick]");
		puts("3. order by nim Descending [quick]");
		do{
			printf("input (0 to go back) :");
			scanf("%d",&input);getchar();
		}while(input < 0 || input > 4);
		if(input == 0) continue;
		
		switch(input){
			case 1 : bubbleSort(datas,size);break;
			case 2 : mergeSort(datas,0,size-1); break;
			case 3 : quickSortAsc(datas,0,size-1); break;
			case 4 : quickSortDesc(datas,0,size-1); break;
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
 
    /* create temp datasays */
    data L[n1], R[n2];
 
    /* Copy data to temp datasays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = datas[l + i];
    for (j = 0; j < n2; j++)
        R[j] = datas[m + 1 + j];
 
    /* Merge the temp datasays back into datas[l..r]*/
    i = 0; // Initial index of first subdatasay
    j = 0; // Initial index of second subdatasay
    k = l; // Initial index of merged subdatasay
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


void swap(data *a, data *b){
    data t = *a;
    *a = *b;
    *b = t;
}
  
int partitionAsc(data datas[], int low, int high)
{
    data pivot = datas[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
   
        if (strcmp(datas[j].nim, pivot.nim) < 0) {
            i++; 
            swap(&datas[i], &datas[j]);
        }
    }
    swap(&datas[i + 1], &datas[high]);
    return (i + 1);
}
  
void quickSortAsc(data datas[], int low, int high)
{
    if (low < high) {
  
        int pi = partitionAsc(datas, low, high);
 
        quickSortAsc(datas, low, pi - 1);
        quickSortAsc(datas, pi + 1, high);
    }
}

int partitionDesc(data datas[], int low, int high)
{
    data pivot = datas[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
   
        if (strcmp(datas[j].nim, pivot.nim) > 0) {
            i++; 
            swap(&datas[i], &datas[j]);
        }
    }
    swap(&datas[i + 1], &datas[high]);
    return (i + 1);
}
  
void quickSortDesc(data datas[], int low, int high)
{
    if (low < high) {
  
        int pi = partitionDesc(datas, low, high);
 
        quickSortDesc(datas, low, pi - 1);
        quickSortDesc(datas, pi + 1, high);
    }
}

void printData(data datas[],int size){
	if(size >0){
		for(int i=0;i< size;i++){
			printf("%s %s %d %d %d %d %s\n",datas[i].name ,datas[i].nim,datas[i].scores.tm,datas[i].scores.uts,datas[i].scores.uas,datas[i].semester,datas[i].grade);
		}
	}
}

void printSingleData(data datas[],int n){
	puts("data found!");
	printf("%s %s %d %d %d %d %s\n",datas[n].name ,datas[n].nim,datas[n].scores.tm,datas[n].scores.uts,datas[n].scores.uas,datas[n].semester,datas[n].grade);
	puts("");
}

int nimCheck(data datas){
	if(strlen(datas.nim) != 10) return 0;
	for(int i = 0; i < strlen(datas.nim); i++){
		if(!isdigit(datas.nim[i])){
			return 0;
		}
	}
	return 1;
}

void insertData(data datas[],int& size){
	if(size==100){
		puts("student limit reach");
	}else
	{
		FILE *fp;
		srand(time(NULL));
		/*
			POINT 20 : give simple validation to input student and nim using binus standard and change the scores input from random to user input between 0-100

			POINT 10 : after inputing the scores get the score grade using the formula,  25% TM + 35% UTS + 40% UAS , then classified the grade using binus standard letter grade( D - A+) and save it.

		*/
		printf("student name :");
		scanf("%[^\n]",datas[size].name);getchar();
		int run;
		do{
			printf("student nim :");
			scanf("%[^\n]",datas[size].nim); getchar();
		} while(nimCheck(datas[size]) == 0); // nim harus berisi 10 karakter
		
        do{
			printf("student semester :");
			scanf("%d",&datas[size].semester); getchar();
		} while(datas[size].semester < 1 || datas[size].semester > 8); // nim harus berisi 10 karakter
		

		do{
			printf("student tm score :");
			scanf("%d",&datas[size].scores.tm);getchar();
		} while (datas[size].scores.tm < 0 || datas[size].scores.tm > 100);
		
		do{
			printf("student uts score :");
			scanf("%d",&datas[size].scores.uts);getchar();
		} while (datas[size].scores.uts < 0 || datas[size].scores.uts > 100);

		do{
			printf("student uas score :");
			scanf("%d",&datas[size].scores.uas);getchar();
		} while (datas[size].scores.uas < 0 || datas[size].scores.uas > 100);
		
		// 25% TM + 35% UTS + 40% UAS , then classified the grade using binus standard letter grade( D - A+) and save it.
		size += 1;
		fp=fopen("data.in","w");
		puts("processing to data insertion. . .");
		for(int i=0;i< size;i++){
            grading(datas,i);
			printf(" inserting -> %s,%s,%d,%d,%d,%d,%s\n",datas[i].name,datas[i].nim,datas[i].scores.tm,datas[i].scores.uts,datas[i].scores.uas,datas[i].semester,datas[i].grade);
		
			fprintf(fp,"%s,%s,%d,%d,%d,%d,%s\n",datas[i].name,datas[i].nim,datas[i].scores.tm,datas[i].scores.uts,datas[i].scores.uas,datas[i].semester,datas[i].grade);
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

int interpolationSearch(data arr[], int n, char x[]) {
    int lo = 0;
    int hi = (n - 1);

    while (lo <= hi && strcmp(x, arr[lo].nim) >= 0 && strcmp(x, arr[hi].nim) <= 0) {
        int pos = lo + (((double)(hi-lo) / (strcmp(arr[hi].nim,arr[lo].nim)))*(strcmp(x, arr[lo].nim)));

        if (strcmp(arr[pos].nim,x) == 0)
            printSingleData(arr, pos); 
            return 0;

        if (strcmp(arr[pos].nim,x) < 0)
            lo = pos + 1;

        else
            hi = pos - 1;
    }
    return -1;
}

int gradeSearch(data data[], char grade[], int size){
	int found = 0;
    for(int i=0;i < size;i++){
        if(strcmp(data[i].grade, grade) == 0){
            printSingleData(data,i);
            found = 1;
        }
    }
    if(found == 0) 
		return 0;
	return 1;
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
		puts("2. binary search");
		//POINT 10 : create interpolation search
        puts("3. interpolation search");
		//POINT 20 : create a search logic that show all data matched using letter Grade as key 
        puts("4. grade search");
		do{
			printf("input (0 to go back) :");
			scanf("%d",&input);getchar();
		}while(input < 0 || input > 4);
		if(input == 0) continue;
		
		switch(input){
			case 1 : 
				for(int i=0;i < size;i++){
					if(strcmp(nim,datas[i].nim) == 0){
						printSingleData(datas,i);
						break;
					}
				}
		        break;
			case 2 : 
				BinarySearch(datas, 0,size-1, nim);
			    break;
            case 3 :
                quickSortAsc(datas,0,size-1);
                interpolationSearch(datas, size, nim);
                break;
            case 4 :
                int res;
                do{
                    char grade[20];
                    printf("List data by grade :");
                    scanf("%[^\n]", grade); getchar();
                    res = gradeSearch(datas, grade, size);
                    if(res == 0) printf("Data Not Found!\n");
                } while(res == 0);
                break;
		}
	}while(input != 0);
}

