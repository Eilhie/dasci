/*
Financial Planner

data set = 
    1. name
    2. age
    3. monthly income
    4. starting value
    5. risk profile
    6. monthly expense
    7. saving target in nominal

what this app can do?   
    1. aplikasi bisa login dan register investor // DONE
    2. aplikasi bisa menunjukan data investor & ubah // DONE
    3. aplikasi bisa menentukan jenis instrument investasi berdasarkan profil resiko // DONE
        aplikasi bisa memperkirakan berapa lama waktu investasi // DONE
    4. aplikasi bisa memberikan list dari jenis instrument berdasar profil resiko, list instrument berisi nama dan interestnya // DONE
    5. aplikasi bisa memberikan informasi tentang instrument aplikasi dengan searching algo // DONE


file handling 
    data investor akan di simpan dalam file, dan data rekomendasi akan disimpan dalam file juga.
    dipisah.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// struct for data set
struct investor{
    char name[100]; // investor name
    char password[100]; // investor password
    long long int income; // investor monthly income
    long long int startingValue; // investor saving starting value
    char riskProfile[100]; // investor risk profile = conservative,moderate,aggresive
    long long int expense; // investor monthly expense
    long long int saveTarget; // investor saving target
};

struct interest{
    char fundManager[100]; // fund manager
    double Cinterest; // conservative interest
    double Minterest; // moderate interest
    double Ainterest; // aggresive interest
};

// helper function
int filecheck(const char *filename); // DONE // cek file kosong ato ga
void printInfo(investor datas[], int pos); // DONE  // print info user saat ini
void savingFile(investor datas[], int size); // DONE // save data user ke file investordata
void recommendList(interest datas[], int &insize); // DONE  // masukan rekomendasi ke dalam struct
void swap(interest *a, interest *b); // DONE // swap struct
int partition(interest datas[], int low, int high, int query, int order, investor data[], int pos); // DONE // partition quicksort
void quickSort(interest datas[], int low, int high, int query, int order, investor data[], int pos); // DONE // quicksort
void printAllRecomList(interest interests[], int &insize, investor datas[], int pos); // DONE // print semua yang ada di rekomendasi
double average(investor datas[], int pos, interest interests[], int &insize); // DONE // bikin average dari file rekomendasi berdasarkan riskprofile
void printlist(interest interests[], int &insize); // DONE // print isi dari struck interest
void best(investor datas[], int pos, interest interests[], int &insize); // DONE // mencari best fund manager
void containsSearch(char* key, interest interests[], int insize); // DONE 
void startsSearch(char* key, interest interests[], int insize); // DONE
void endsSearch(char* key, interest interests[], int insize); // DONE

// important function
int login(investor datas[], int &size); // DONE
void readFile(investor datas[],int &size); // DONE
int regis(investor datas[], int size); // DONE
void recommendInvest(investor datas[], int pos, interest interests[], int &insize); // DONE
int investmentPredictionRecursive(investor datas[], int pos, int t, double A, interest interests[], int &insize); // DONE
void moreInfoInstrument(interest interests[], int insize); // DONE
void changeInfo(investor datas[], int pos, int size); // DONE

// driver code
int main(){
	investor datas[100];
    interest interests[100];

    int insize = 0;
	int size=0;
    
    readFile(datas, size);
	int pos = 9999;
	int input;
    
    recommendList(interests, insize);
    if(size == 0) {
        puts("No Account Detected!");
        puts("Please Register!!!!");
        puts("");
        puts("");
        pos = regis(datas, size);
    }
    else {
        do{
            puts("");
            puts("1. Login");
            puts("2. Register");
            
            do{
                printf("input(0 to exit) :");
                scanf("%d", &input); getchar();
            } while(input < 0 || input > 2);

            switch (input){
                case 1: pos = login(datas, size); break;
                case 2: pos = regis(datas, size); break;
            }
        } while(input != 0 && pos == 9999);
    }
    size = 0;
    readFile(datas, size);
    do{
        puts("");
        
        puts("1. view user data");
        puts("2. Recommended Instrument");
        puts("3. Investment Duration Prediction");
        puts("4. More Information on Investment Instrument");
        
        do{
            printf("input(0 to exit) :");
            scanf("%d",&input); getchar();
        }while(input < 0 || input > 4);
        
        switch(input){
            case 1: printInfo(datas, pos); changeInfo(datas, pos, size); break;
            case 2: recommendInvest(datas,pos, interests, insize);break;
            case 3: printf("We Predict that your investment will reach target by %d month(s).\n", investmentPredictionRecursive(datas, pos, 1, 0, interests, insize)); break;
            case 4: moreInfoInstrument(interests, insize);break;
        }
    }while(input != 0);
    puts("~~~ Thanks for Using Sproutvest ~~~");
}


// helper function
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

void printInfo(investor datas[], int pos){
        
    printf("\nName\t\t: %15s\nPassword\t: %15s\nIncome\t\t: %15lld\nStarting value\t: %15lld\nrisk Profile\t: %15s\nExpense\t\t: %15lld\nSaving Target\t: %15lld\n", datas[pos].name, datas[pos].password, datas[pos].income, datas[pos].startingValue, datas[pos].riskProfile, datas[pos].expense, datas[pos].saveTarget);
        
    puts("");
    printf("Press any key to continue\n");
    getchar();
}

void savingFile(investor datas[], int size){

    FILE *fp = fopen("InvestorData.ivr", "w");

    for(int i = 0; i < size; i++){
        fprintf(fp, "%s#%s#%lld#%lld#%s#%lld#%lld\n", datas[i].name, datas[i].password, datas[i].income, datas[i].startingValue, datas[i].riskProfile, datas[i].expense, datas[i].saveTarget);
    }
    printf("\nRegister Complete!\n");
    fclose(fp);
}

void recommendList(interest datas[], int &insize){
    FILE *fp = fopen("recommendation.ivr", "r");

    while(!feof(fp)){
        fscanf(fp, "%[^#]#%lf#%lf#%lf\n", datas[insize].fundManager, &datas[insize].Cinterest, &datas[insize].Minterest, &datas[insize].Ainterest);
        insize += 1;
    }
}

void printAllRecomList(interest interests[], int &insize, investor datas[], int pos){

    if(strcmp(datas[pos].riskProfile, "conservative") == 0){
        puts("\nConservative List of Interest Rate");
        for(int i = 0; i < insize; i++) printf("Fund Manager : %s Interest Rate : %.3f\n", interests[i].fundManager, interests[i].Cinterest);
        puts("");
    } else if(strcmp(datas[pos].riskProfile, "moderate") == 0){
        puts("\nModerate List of Interest Rate");
        for(int i = 0; i < insize; i++) printf("Fund Manager : %s Interest Rate : %.3f\n", interests[i].fundManager, interests[i].Minterest);
        puts("");
    } else if(strcmp(datas[pos].riskProfile, "aggresive") == 0){
        puts("\nAggresive List of Interest Rate");
        for(int i = 0; i < insize; i++) printf("Fund Manager : %s Interest Rate : %.3f\n", interests[i].fundManager, interests[i].Ainterest);
        puts("");
    }
}

void printlist(interest interests[], int &insize){
    for(int i = 0; i < insize; i++){
        printf("%s %lf %lf %lf\n", interests[i].fundManager, interests[i].Cinterest, interests[i].Minterest, interests[i].Ainterest);
    }
}

void swap(interest *a, interest *b){
    interest t = *a;
    *a = *b;
    *b = t;
}
  
int partition(interest datas[], int low, int high, int query, int order, investor data[], int pos)
{
    interest pivot = datas[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
   
        if (query == 1) {
            if(order == 1 ? strcmp(datas[j].fundManager, pivot.fundManager) > 0 : strcmp(datas[j].fundManager, pivot.fundManager) < 0){
                i++; 
                swap(&datas[i], &datas[j]);
                // printAllRecomList(datas, high, data, pos);
            }  
        } else if (query == 2 && strcmp(data[pos].riskProfile, "conservative") == 0) {
            if(order == 1 ? datas[j].Cinterest >= pivot.Cinterest : datas[j].Cinterest <= pivot.Cinterest){
                i++; 
                swap(&datas[i], &datas[j]);
            }
        } else if (query == 2 && strcmp(data[pos].riskProfile, "moderate") == 0) {
            if(order == 1 ? datas[j].Minterest >= pivot.Minterest : datas[j].Minterest <= pivot.Minterest){
                i++; 
                swap(&datas[i], &datas[j]);
            }
        } else if (query == 2 && strcmp(data[pos].riskProfile, "aggresive") == 0) {
            if(order == 1 ? datas[j].Ainterest >= pivot.Ainterest : datas[j].Ainterest <= pivot.Ainterest){
                i++; 
                swap(&datas[i], &datas[j]);
            }
        }
    }
    swap(&datas[i + 1], &datas[high]);
    return (i + 1);
}

void quickSort(interest datas[], int low, int high, int query, int order, investor data[], int pos)
{
    if (low < high) {
  
        int pi = partition(datas, low, high, query, order, data, pos);
 
        quickSort(datas, low, pi - 1, query, order, data, pos);
        quickSort(datas, pi + 1, high, query, order, data, pos);
    }
}

double average(investor datas[], int pos, interest interests[], int &insize){
    double average = 0;
    for(int i = 0; i < insize; i++){
        if(strcmp(datas[pos].riskProfile, "conservative") == 0){
            average = average + interests[i].Cinterest;
        } else if(strcmp(datas[pos].riskProfile, "moderate") == 0){
            average = average + interests[i].Minterest;
        } else if(strcmp(datas[pos].riskProfile, "aggresive") == 0){
            average = average + interests[i].Ainterest;
        }
    }
    return (average / insize);
}

void best(investor datas[], int pos, interest interests[], int &insize){
    interest best = interests[0];
    for(int i = 0; i < insize; i++){
        if(strcmp(datas[pos].riskProfile, "conservative") == 0){
            if(interests[i].Cinterest > best.Cinterest) best = interests[i];
        } else if(strcmp(datas[pos].riskProfile, "moderate") == 0){
            if(interests[i].Minterest > best.Minterest) best = interests[i];
        } else if(strcmp(datas[pos].riskProfile, "aggresive") == 0){
            if(interests[i].Ainterest > best.Ainterest) best = interests[i];
        }
    }
    if(strcmp(datas[pos].riskProfile, "conservative") == 0){
        printf("We Recommend %s as the best fund Mananger to invest with interest %.3f rate\n", best.fundManager, best.Cinterest);
    } else if(strcmp(datas[pos].riskProfile, "moderate") == 0){
        printf("We Recommend %s as the best fund Mananger to invest with interest %.3f rate\n", best.fundManager, best.Minterest);
    } else if(strcmp(datas[pos].riskProfile, "aggresive") == 0){
        printf("We Recommend %s as the best fund Mananger to invest with interest %.3f rate\n", best.fundManager, best.Ainterest);
    }
    
}

void printSingleList(interest interests[], int pos){
    printf("Fund Manager : %s\nConservative Interest rate : %.3f\nModerate Interest rate : %.3f\nAggresive Interest rate : %.3f\n\n", interests[pos].fundManager, interests[pos].Cinterest, interests[pos].Minterest, interests[pos].Ainterest);
}

void containsSearch(char* key, interest interests[], int insize) {
    printf("Results for contains search <%s>: \n", key);
    for (int i = 0; i < insize; i++) {
        if (strstr(interests[i].fundManager, key) != NULL) {
            printSingleList(interests, i);
        }
    }
    printf("\n");
}

void startsSearch(char* key, interest interests[], int insize) {
    printf("Results for contains start <%s>: \n", key);
    for (int i = 0; i < insize; i++) {
        if (strncmp(interests[i].fundManager, key, strlen(key)) == 0) {
            printSingleList(interests, i);
        }
    }
    printf("\n");
}

void endsSearch(char* key, interest interests[], int insize) {
    printf("Results for contains end <%s>: \n", key);
    for (int i = 0; i < insize; i++) {
        int keyLen = strlen(key);
        int dataLen = strlen(interests[i].fundManager);
        if (strncmp(interests[i].fundManager + dataLen - keyLen, key, keyLen) == 0) {
            printSingleList(interests, i);
        }
    }
    printf("\n");
}

// important function
int login(investor datas[], int &size){
        char name[100];
        char password[100];

        printf("Login\nname >> ");
        scanf("%s",name); getchar();
        printf("password >> ");
        scanf("%s",password); getchar();

        for(int i = 0; i < size; i++){
            //printf("%s\n%s\n%s\n%s\n", name, datas[i].name, password, datas[i].password);
            if(strcmp(name, datas[i].name) == 0 && strcmp(password, datas[i].password) == 0){
                puts("Login Passed\nPress any key to continue");
                getchar();
                return i;
            }  
        }

        puts("Login failed\n");
        exit(0);
}

void readFile(investor datas[],int &size){
    FILE *fp = fopen("InvestorData.ivr", "a+");
    if(!filecheck("InvestorData.ivr")){
        if(fp == NULL){
        perror("Error ");
        }
        else{
            while(!feof(fp)){
                fscanf(fp, "%[^#]#%[^#]#%lld#%lld#%[^#]#%lld#%lld\n", datas[size].name, datas[size].password, &datas[size].income, &datas[size].startingValue, datas[size].riskProfile, &datas[size].expense, &datas[size].saveTarget);
                size+=1;
            }
                
        }
    }
	fclose(fp);
}

int regis(investor datas[], int size){
    printf("name :");
    scanf("%[^\n]",datas[size].name); getchar();
    
    printf("password :");
    scanf("%[^\n]",datas[size].password); getchar();
    
    do{
        printf("income :");
        scanf("%lld",&datas[size].income); getchar();
    } while(datas[size].income < 0 || datas[size].income > 1000000000000); 
    

    do{
        printf("starting value :");
        scanf("%lld",&datas[size].startingValue); getchar();
    } while (datas[size].startingValue < 0 || datas[size].startingValue > 1000000000000);
    
    do{
        printf("risk profile [conservative || moderate || aggresive] :");
        scanf("%[^\n]",datas[size].riskProfile); getchar();
    } while (strcmp("conservative", datas[size].riskProfile) != 0 && strcmp("moderate", datas[size].riskProfile) != 0 && strcmp("aggresive", datas[size].riskProfile) != 0);

    do{
        printf("expense [monthly] :");
        scanf("%lld",&datas[size].expense);getchar();
    } while (datas[size].expense < 0 || datas[size].expense > 1000000000000);
    
    do{
        printf("saving target :");
        scanf("%lld",&datas[size].saveTarget);getchar();
    } while (datas[size].saveTarget < 0 || datas[size].saveTarget > 1000000000000);
    
    int pos = size;
    size += 1;
    
    savingFile(datas, size);

    return pos;
}

void recommendInvest(investor datas[], int pos, interest interests[], int &insize){
    int input;
    
    puts("");
    puts("1. Show Recommended [Ascending]");
    puts("2. Show Recommended [Descending]");
    
    do {
        scanf("%d", &input); getchar();
    } while(input < 0 || input > 2);

    int choice;

    puts("");
    puts("1. sort by name");
    puts("2. sort by interest rate");

    do {
        scanf("%d", &choice); getchar();
    } while(choice < 0 || choice > 2);
    
    quickSort(interests, 0, insize - 1, choice, input - 1, datas, pos);
    printAllRecomList(interests, insize, datas, pos);

    best(datas, pos, interests, insize);
}
    
int investmentPredictionRecursive(investor datas[], int pos, int t, double A, interest interests[], int &insize) {
    double r = average(datas, pos, interests, insize);
    A = (datas[pos].startingValue + (datas[pos].income - datas[pos].expense) * 30  * t) * pow((1 + r / 12), (12 * t));
    if(A < datas[pos].saveTarget)
        return investmentPredictionRecursive(datas, pos, t+1, A, interests, insize);
    else 
        return t + 1;
}

void moreInfoInstrument(interest interests[], int insize){
    char searchkey[30];
    puts("To get More Information About The Instrument Please Input Search Key");
    puts("");
    printf("Input Search Key :");
    scanf("%s", searchkey);
    containsSearch(searchkey, interests, insize);

    printf("Input Search start Key :");
    scanf("%s", searchkey);
    startsSearch(searchkey, interests, insize);

    printf("Input Search end Key :");
    scanf("%s", searchkey);
    endsSearch(searchkey,interests, insize);
}

void changeInfo(investor datas[], int pos, int size){
    int input;

    printf("do yo want to change your info?\n1. yes\n2. no\n");
    do {
        scanf("%d", &input); getchar();
    } while (input < 1 || input > 2);
    
    if(input == 1){
        printf("name :");
        scanf("%[^\n]",datas[pos].name); getchar();
        
        printf("password :");
        scanf("%[^\n]",datas[pos].password); getchar();
        
        do{
            printf("income :");
            scanf("%lld",&datas[pos].income); getchar();
        } while(datas[pos].income < 0 || datas[pos].income > 1000000000000); 
        

        do{
            printf("starting value :");
            scanf("%lld",&datas[pos].startingValue); getchar();
        } while (datas[pos].startingValue < 0 || datas[pos].startingValue > 1000000000000);
        
        do{
            printf("risk profile [conservative || moderate || aggresive] :");
            scanf("%[^\n]",datas[pos].riskProfile); getchar();
        } while (strcmp("conservative", datas[pos].riskProfile) != 0 && strcmp("moderate", datas[pos].riskProfile) != 0 && strcmp("aggresive", datas[pos].riskProfile) != 0);

        do{
            printf("expense [monthly] :");
            scanf("%lld",&datas[pos].expense);getchar();
        } while (datas[pos].expense < 0 || datas[pos].expense > 1000000000000);
        
        do{
            printf("saving target :");
            scanf("%lld",&datas[pos].saveTarget);getchar();
        } while (datas[pos].saveTarget < 0 || datas[pos].saveTarget > 1000000000000);

        savingFile(datas, size);
    }
}

