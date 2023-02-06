#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mapList{
    char filename[100];
    int minstep;
    int minpospath;
};

void readFile(mapList list[], int& size);
int filecheck(const char *filename);
void printAllMapInfo(mapList list[], int &size);
void bubleSortMs(mapList list[], int size);

void viewMapList(mapList list[], int size);
void discoverNewMap(mapList list[], int &size);
int saveAndExit(mapList list[], int &size);

int main(){

    mapList list[100];

    int input;
    int size = 0;

    readFile(list, size);
    do{
        puts("");
		puts("1. view discovered map");
		puts("2. discover new map");
		puts("3. save and exit");
		
		do{
			printf("input(0 to exit) :");
			scanf("%d",&input); getchar();
		}while(input < 0 || input > 3);
		
		switch(input){ 
			case 1: printf("discovered map\n"); viewMapList(list, size); break;

			case 2: printf("new map discovered\n"); discoverNewMap(list, size); break;
			case 3: printf("save and exit\n"); input = saveAndExit(list, size); break;
		}
	}while(input != 0);

    return 0;
}

int filecheck(const char *filename){
    FILE *fp = fopen(filename, "r");
    long pos;
    if (fp == NULL)
        return 1;
    
    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);
    if (pos == 0)
        return 1;
    else 
        return 0;
    
    fclose(fp);
}

void readFile(mapList list[], int& size){
	
	FILE *fp;
	fp=fopen("maplist.in","a+");
    if(!filecheck("maplist.in")){
        if(fp == NULL){
            perror("Error ");
        }
        else{
            while(!feof(fp)){
                fscanf(fp,"%[^;];%d;%d\n", list[size].filename, &list[size].minstep, &list[size].minpospath);
                size+=1;
            }
                
        }
    }
	
	
	fclose(fp);
}

void printAllMapInfo(mapList list[], int &size){
    if(size > 0){
        for(int i = 0; i < size; i++){
            printf("\nMap Name : %s\nMinimum Step : %d\nMinimum Possible Path : %d\n", list[i].filename, list[i].minstep, list[i].minpospath);
        }
    }
}

void bubleSortMs(mapList list[], int size, int order){
    //mapList temporary;
    //printf("bubble sort\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            
            if(order == 1 ? list[j].minstep < list[j + 1].minstep : list[j].minstep > list[j + 1].minstep){
                //printf("^ %d %d\n", list[j].minstep, list[j + 1].minstep);
                mapList temporary = list[j];
                //printf("# %d %d\n", list[j].minstep, list[j + 1].minstep);
                list[j] = list[j + 1];
                //printf(". %d %d\n", list[j].minstep, list[j + 1].minstep);
                list[j + 1] = temporary;
            }

        }
    }    
}

void bubleSortMpp(mapList list[], int size, int order){
    //mapList temporary;
    //printf("bubble sort\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            
            if(order == 1 ? list[j].minpospath < list[j + 1].minpospath : list[j].minpospath > list[j + 1].minpospath){
                //printf("^ %d %d\n", list[j].minstep, list[j + 1].minstep);
                mapList temporary = list[j];
                //printf("# %d %d\n", list[j].minstep, list[j + 1].minstep);
                list[j] = list[j + 1];
                //printf(". %d %d\n", list[j].minstep, list[j + 1].minstep);
                list[j + 1] = temporary;
            }

        }
    } 
    
}

void viewMapList(mapList list[], int size){
    int choice;
    char input[20];
    FILE *fp = fopen("maplist.in", "a+");
    if(filecheck("maplist.in")){
        printf("No map founded!\n");
        size = 0;
    } else {
        printAllMapInfo(list, size);
        do {
            printf("sort map by (min step[ms] / min possible path[mpp]) :");
            scanf("%[^\n]", input); getchar();
        } while ((strcmp(input, "ms") != 0) && (strcmp(input, "mpp") != 0));
        
        do {
            puts("");
            printf("1. sort ascending\n");
            printf("2. sort descending\n");
            do{
                printf("input(0 to back) :");
                scanf("%d", &choice); getchar();
            } while(choice < 0 || choice > 2);

            if(strcmp(input, "ms") == 0) bubleSortMs(list, size, choice - 1);
            if(strcmp(input, "mpp") == 0) bubleSortMpp(list, size, choice - 1); 
            //printf("size = %d\n", size);
            printAllMapInfo(list, size);
            
        } while(choice != 0);
    }
    // printf("%d\n", size);

    fclose(fp);
}

int newMap(char *mapname, mapList list[], int size){
    if(size > 0){
        for(int i = 0; i < size; i++){
            // printf("%s %s\n",mapname, list[i].filename);
            if(strcmp(mapname, list[i].filename) == 0){
                return 0;
            }
        }
    }
    return 1;
}

void minstep(int step, int xpos, int ypos, int xdes, int ydes, char **grid, int **visited, int horlimit, int verlimit){
    if(xpos < 0 || ypos < 0 || xpos > horlimit|| ypos > verlimit || visited[ypos][xpos] <= step || grid[ypos][xpos] == '#'){
        return;
    }
    visited[ypos][xpos] = step;
    int x[] = {1, -1, 0, 0};
    int y[] = {0, 0, 1, -1};
    for(int i=0; i<4; i++){
        minstep(step+1, xpos+x[i], ypos+y[i], xdes, ydes, grid, visited, horlimit, verlimit);
    }
}

int minpospath(int **visited, int xdes, int ydes){
    int x[] = {1, -1, 0, 0};
    int y[] = {0, 0, 1, -1};
    int steps[4];
    int min = 100000;
    int count = 0;
    for(int i = 0; i < 4; i++){
        steps[i] = visited[ydes + y[i]][xdes + x[i]];
        if(steps[i] < min) min = steps[i];
    }
    for(int i = 0; i < 4; i++){
        if(steps[i] == min) count += 1;
    }
    return count;
}

void discoverNewMap(mapList list[], int &size){
    char mapname[100];
    char extension[100] = ".dig";
    
    int checknew;
    int cmptemp;
    do{
        char exttemp[100] = "";
        puts("");
        printf("Map Name (must .dig) :");  
        scanf("%[^\n]", mapname); getchar();
        for(int i = strlen(mapname) - 4; i < strlen(mapname); i++){
            strncat(exttemp, &mapname[i], 1);
        }
        if(strcmp(exttemp, extension) == 0) cmptemp = 1;
        else cmptemp = 0;
        checknew = (newMap(mapname, list, size) && cmptemp);
        if(checknew == 0) printf("Map Already Exist or Extension not correct\n");
    } while (!checknew);

    

    FILE *fp = fopen(mapname, "r");
    int endX, endY, startX, startY;
    int heightlim = 0;
    int widthlim = 0;
    char **grid;
    int **visited;

    grid = (char**)malloc(1000000*sizeof(*grid));         
    visited = (int**)malloc(1000000*sizeof *visited);          
    while(!feof(fp)){
        grid[heightlim]= (char*)malloc(10*sizeof(*grid[heightlim]));
        visited[heightlim]= (int*)malloc(7*sizeof(*visited[heightlim]));
        fscanf(fp,"%[^\n]\n", grid[heightlim]);    
        printf("%s\n", grid[heightlim]);
        for(int j = 0; j < strlen(grid[heightlim]); j++){
            visited[heightlim][j] = 104;
            if(grid[heightlim][j] == 'X'){
                endY = heightlim;
                endX = j;
            } else if(grid[heightlim][j] == '0') {
                startY = heightlim;
                startX = j;
            }
            widthlim = strlen(grid[heightlim]);
        }
		heightlim+=1;
        
    }
    // printf("SIZE = %d\n", size);

    minstep(0, startX, startY, endX, endY, grid, visited, widthlim, heightlim);
    printf("min steps: %d\n", visited[endY][endX]);
    printf("min pos path: %d\n\n", minpospath(visited,endX, endY));
    strcpy(list[size].filename, mapname);
    list[size].minstep = visited[endY][endX];
    list[size].minpospath = minpospath(visited, endX, endY);
    size += 1;
}

int saveAndExit(mapList list[], int &size){
    printf("file saved\n");
    FILE *fp;
    
    fp = fopen("maplist.in","w");
    puts("processing to data insertion. . .");
    
    //printf("SIZE = %d\n", size);

    for(int i=0;i< size;i++){
        printf(" Saving -> %s,%d,%d\n", list[i].filename, list[i].minstep, list[i].minpospath);
    
        fprintf(fp,"%s;%d;%d\n", list[i].filename, list[i].minstep, list[i].minpospath);
    }

    puts("Map Saved and Exit. . . \n");
    fclose(fp);

    return 0;
}