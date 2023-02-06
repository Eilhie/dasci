/*
Location 1, string
Location 2, string
Price, long long int
Rooms, int
Bathrooms, int 
CarParks, int
Type, string
Area, long int
Furnish, string
*/

#include <stdio.h>
#include <string.h>
struct track{
    int count;
    int count2;
    int count3;
    int count4;
};

struct housing{
    char loc1[100];
    char loc2[100];
    long long int price;
    int rooms;
    int bathrooms;
    int carparks;
    char type[100];
    long long int area;
    char furnish[100];
    track tracks;
};



void readFile(housing datas[], int &size);
void merge(housing *datas, int l, int m, int r);
void mergeSortType(housing datas[], int l, int r);
void mergeType(housing *datas, int l, int m, int r);
void mergeSort(housing datas[], int l, int r);
void mergeSortFurnish(housing datas[], int l, int r);
void mergeFurnish(housing *datas, int l, int m, int r);
void countLoc1Frequency(housing words[], int n);
void countLoc2Frequency(housing words[], int n);
void countTypeFrequency(housing words[], int n);
void countFurnishFrequency(housing words[], int n);
void carsfreq(housing data[], int n);
void bathsfreq(housing data[], int n);
void roomsfreq(housing data[], int n);
void price(housing datas[], int size);
void area(housing datas[], int size);

void printFile(housing datas[], int size);

int main(){
    housing datas[5000];
    track location1[5000];
    int size = 0;
    int location1size = 0;
    readFile(datas, size);

    char input[100];
    int run = 1;
    printf("%d \n", size);
    mergeSort(datas, 0, size);

    // printFile(datas, size);

    do{
    printf("Input Column to describe : ");
    scanf("%[^\n]", input); getchar();

    if (strcmp(input, "loc1") == 0){
        countLoc1Frequency(datas, size);
    } else if (strcmp(input, "loc2") == 0) {
        countLoc2Frequency(datas, size);
    } else if (strcmp(input, "price") == 0) {
        price(datas, size);
    } else if (strcmp(input, "rooms") == 0) {
        roomsfreq(datas, size);
    } else if (strcmp(input, "bathrooms") == 0) {
        bathsfreq(datas, size);
    } else if (strcmp(input, "carparks") == 0) {
        carsfreq(datas, size);
    } else if (strcmp(input, "type") == 0) {
        countTypeFrequency(datas, size);
    } else if (strcmp(input, "area") == 0) {
        area(datas, size);
    } else if (strcmp(input, "furnish") == 0) {
        countFurnishFrequency(datas, size);
    } else {
        printf("no column after %s\n", input);
        run = 0;
    }
    

    } while(run);

    return 0;
}

void printFile(housing datas[], int size){
    for(int i = 0; i < size; i++){
        
       printf("%s,%s,%lld,%d,%d,%d,%s,%lld,%s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
       
    }   
}

void readFile(housing datas[], int &size){
    FILE *fp = fopen("fileAol.csv", "r");
    char buffer[1000];
    fscanf(fp, "%[^\n]\n", buffer);
    // printf("%s\n", buffer);
    while(!feof(fp)){
       fscanf(fp, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%lld,%[^\n]\n", datas[size].loc1, datas[size].loc2, &datas[size].price, &datas[size].rooms, &datas[size].bathrooms, &datas[size].carparks, datas[size].type, &datas[size].area, datas[size].furnish);
        datas[size].tracks.count = 1;
        datas[size].tracks.count2 = 1;
        datas[size].tracks.count3 = 1;
        datas[size].tracks.count4 = 1;
       size += 1;
    }
}

void countLoc1Frequency(housing words[], int n) {
    int i, j;
    housing min = words[5];
    housing max = words[0];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i].loc1, words[j].loc1) == 0) {
                words[i].tracks.count++;
                words[j].tracks.count = -1;
            }
        }
    }
    printf("Loc1 words: \n");
    for (i = 0; i < n; i++) {
        if (words[i].tracks.count != -1) {
            if(words[i].tracks.count > words[i-1].tracks.count){
                printf("%s: %d\n", words[i].loc1, words[i].tracks.count);
                if(words[i].tracks.count > max.tracks.count) max = words[i];
                if(words[i].tracks.count > 0){
                    if(words[i].tracks.count < min.tracks.count)
                    min = words[i];
                } 
            }
        }
    }
    printf("MAX VALUE : %s with freq of %d\n", max.loc1, max.tracks.count);
    printf("MIN VALUE : %s with freq of %d\n", min.loc1, min.tracks.count);
}

void countLoc2Frequency(housing words[], int n) {
    int i, j;
    housing min = words[5];
    housing max = words[0];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i].loc2, words[j].loc2) == 0) {
                words[i].tracks.count2++;
                words[j].tracks.count2 = -1;
            }
        }
    }
    printf("Loc1 words: \n");
    for (i = 0; i < n; i++) {
        if (words[i].tracks.count2 != -1) {
            if(words[i].tracks.count2 > words[i-1].tracks.count2){
                printf("%s: %d\n", words[i].loc2, words[i].tracks.count2);
                if(words[i].tracks.count2 > max.tracks.count2) max = words[i];
                if(words[i].tracks.count2 > 0){
                    if(words[i].tracks.count2 < min.tracks.count2)
                    min = words[i];
                } 
            }
        }
    }
    printf("MAX VALUE : %s with freq of %d\n", max.loc2, max.tracks.count2);
    printf("MIN VALUE : %s with freq of %d\n", min.loc2, min.tracks.count2);
}

void roomsfreq(housing data[], int n) {
    int minFrequency = 0;
    int maxFrequency = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (data[i].rooms == data[j].rooms) {
                count++;
                data[j].rooms = -1;
            }
        }
        if (data[i].rooms != -1) {
            printf("%d: %d\n", data[i].rooms, count);
            if (count < minFrequency && count > 0) minFrequency = count;
            if (count > maxFrequency) maxFrequency = count;
        }
    }
    printf("Minimum frequency: %d\n", minFrequency);
    printf("Maximum frequency: %d\n", maxFrequency);
}

void bathsfreq(housing data[], int n) {
    int minFrequency = 0;
    int maxFrequency = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (data[i].bathrooms == data[j].bathrooms) {
                count++;
                data[j].bathrooms = -1;
            }
        }
        if (data[i].bathrooms != -1) {
            printf("%d: %d\n", data[i].bathrooms, count);
            if (count < minFrequency && count > 0) minFrequency = count;
            if (count > maxFrequency) maxFrequency = count;
        }
    }
    printf("Minimum frequency: %d\n", minFrequency);
    printf("Maximum frequency: %d\n", maxFrequency);
}

void carsfreq(housing data[], int n) {
    int minFrequency = 0;
    int maxFrequency = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (data[i].carparks == data[j].carparks) {
                count++;
                data[j].carparks = -1;
            }
        }
        if (data[i].carparks != -1) {
            printf("%d: %d\n", data[i].carparks, count);
            if (count < minFrequency && count > 0) minFrequency = count;
            if (count > maxFrequency) maxFrequency = count;
        }
    }
    printf("Minimum frequency: %d\n", minFrequency);
    printf("Maximum frequency: %d\n", maxFrequency);
}

void countTypeFrequency(housing words[], int n) {
    mergeSortType(words,0,n);
    int i, j;
    housing min = words[5];
    housing max = words[0];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i].type, words[j].type) == 0) {
                words[i].tracks.count3++;
                words[j].tracks.count3 = -1;
            }
        }
    }
    printf("Loc1 words: \n");
    for (i = 0; i < n; i++) {
        if (words[i].tracks.count3 != -1) {
            if(words[i].tracks.count3 > words[i-1].tracks.count3){
                printf("%s: %d\n", words[i].type, words[i].tracks.count3);
                if(words[i].tracks.count3 > max.tracks.count3) max = words[i];
                if(words[i].tracks.count3 > 0){
                    if(words[i].tracks.count3 < min.tracks.count3)
                    min = words[i];
                } 
            }
        }
    }
    printf("MAX VALUE : %s with freq of %d\n", max.type, max.tracks.count3);
    printf("MIN VALUE : %s with freq of %d\n", min.type, min.tracks.count3);
}

void countFurnishFrequency(housing words[], int n) {
    mergeSortFurnish(words,0,n);
    
    int i, j;
    housing min = words[5];
    housing max = words[0];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            
            if (strcmp(words[i].furnish, words[j].furnish) == 0) {
                words[i].tracks.count4++;
                words[j].tracks.count4 = -1;
            }
        }
    }
    printf("furnish words: \n");
    for (i = 0; i < n; i++) {
        if (words[i].tracks.count4 != -1) {
            if(words[i].tracks.count4 > words[i-1].tracks.count4){
                printf("%d : %s\n", words[i].tracks.count4, words[i].furnish);
                if(words[i].tracks.count4 > max.tracks.count4) max = words[i];
                if(words[i].tracks.count4 > 0){
                    if(words[i].tracks.count4 < min.tracks.count4)
                    min = words[i];
                } 
            }
        }
    }
    printf("MAX VALUE : %d with freq of %s\n", max.tracks.count4, max.furnish);
    printf("MIN VALUE : %d with freq of %s\n", min.tracks.count4, min.furnish);
}

void area(housing datas[], int size){
    housing min = datas[0];
    housing max = datas[0];
    double avg = 0;
    for(int i = 0; i < size; i++){
        if(datas[i].area > max.area) max = datas[i];
        if(datas[i].area < min.area) min = datas[i];

        avg += datas[i].area;
    }

    avg = avg / size;
    printf("MAX AREA : %lld\nMIN AREA : %lld\nAVERAGE AREA : %.2f\n", max.area, min.area, avg);
}

void price(housing datas[], int size){
// 1.	Minimum value 
// 2.	Maximum value
// 3.	Average value
    housing min = datas[0];
    housing max = datas[0];
    double avg = 0;
    for(int i = 0; i < size; i++){
        if(datas[i].price > max.price) max = datas[i];
        if(datas[i].price < min.price) min = datas[i];

        avg += datas[i].price;
    }

    avg = avg / size;
    printf("MAX PRICE : %lld\nMIN PRICE : %lld\nAVERAGE PRICE : %.2f\n", max.price, min.price, avg);
}

void merge(housing *datas, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp datasays */
    housing L[n1], R[n2];
 
    /* Copy housing to temp datasays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = datas[l + i];
    for (j = 0; j < n2; j++)
        R[j] = datas[m + 1 + j];
 
    /* Merge the temp datasays back into datas[l..r]*/
    i = 0; // Initial index of first subdatasay
    j = 0; // Initial index of second subdatasay
    k = l; // Initial index of merged subdatasay
    while (i < n1 && j < n2) {
    	if(strcmp(L[i].loc1,R[j].loc1) < 0){
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

void mergeSort(housing datas[], int l, int r)
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

void mergeType(housing *datas, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp datasays */
    housing L[n1], R[n2];
 
    /* Copy housing to temp datasays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = datas[l + i];
    for (j = 0; j < n2; j++)
        R[j] = datas[m + 1 + j];
 
    /* Merge the temp datasays back into datas[l..r]*/
    i = 0; // Initial index of first subdatasay
    j = 0; // Initial index of second subdatasay
    k = l; // Initial index of merged subdatasay
    while (i < n1 && j < n2) {
    	if(strcmp(L[i].type,R[j].type) < 0){
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

void mergeSortType(housing datas[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSortType(datas, l, m);
        mergeSortType(datas, m + 1, r);
 
        mergeType(datas, l, m, r);
    }
}

void mergeFurnish(housing *datas, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp datasays */
    housing L[n1], R[n2];
 
    /* Copy housing to temp datasays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = datas[l + i];
    for (j = 0; j < n2; j++)
        R[j] = datas[m + 1 + j];
 
    /* Merge the temp datasays back into datas[l..r]*/
    i = 0; // Initial index of first subdatasay
    j = 0; // Initial index of second subdatasay
    k = l; // Initial index of merged subdatasay
    while (i < n1 && j < n2) {
    	if(strcmp(L[i].furnish,R[j].furnish) < 0){
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

void mergeSortFurnish(housing datas[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSortFurnish(datas, l, m);
        mergeSortFurnish(datas, m + 1, r);
 
        mergeFurnish(datas, l, m, r);
    }
}
