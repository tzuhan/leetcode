#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
    int n=0;
    char buffer[100];
    char *ptr[20];
    cin >> n;
    cin.get(); //get rid of \n
    for(int i=0; i<n; i++){
        cin.getline(buffer,100);
        int words = 0;
        char *temp = strtok(buffer, " ");
        while(temp != NULL && words<20){
            ptr[words++] = temp;
            temp = strtok(NULL, " ");
        }
        for(int j=words-1; j>=0; j--){
            printf("%s ", ptr[j]);
        }
        printf("\n");
    }
    return 0;
}

