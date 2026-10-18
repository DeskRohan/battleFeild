#include<bits/stdc++.h>
using namespace std;

void printLine(int n){
    for(int i = 0 ; i < n ; i++){
        cout<<"*";
    }
}

void printSquare(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void printRowNumberSquare(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<i + 1<<" ";
        }
        cout<<endl;
    }
}

void printColNumberSquare(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void printColNumbersSquareDesc(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = n ; j > 0 ;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void printNumbersSquare(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<(j+1)*(j+1)<<" ";
        }
        cout<<endl;
    }
}

void printAlphaSquare1(int n){
    for(char ch = 'a' ; ch < n + 'a' ;ch++){
        for(int j = 0 ; j < n ; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printAlphaSquare2(int n){
    for(int i = 0 ; i < n ; i++){
        for(char ch = 'a' ; ch < n + 'a' ;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printNumberSeriesASC(int n){
    int cnt = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            cout<<cnt++<<" ";
        }
        cout<<endl;
    }
}

void printRAT(int n){
    int cnt = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout<<cnt++<<" ";
        }
        cout<<endl;
    }
}

void printSpacedRAT(int n){
    for(int i = 0 ; i < n ; i++){
        //printing of the spaces
        for(int j = 0 ; j < n - i -1 ; j++){
            cout<<"  ";
        }

        //printing of the stars
        for(int k = 0 ; k <= i ; k++){
            cout<<" *";
        }
        cout<<endl;
    }
}

void printReverseSpacesRAT(int n){
    for(int row = 0 ; row < n ; row++){
        static int cnt = 1;
        //printing of the spaces
        for(int spaces = 0 ; spaces < row ; spaces++){
            cout<<"  ";
        }

        //printing of the stars
        for(int stars = 0 ; stars < n - row ; stars++){
            cout<<" *";
        }
        cout<<endl;
    }
}
int main(){
    cout<<"Printing n stars in line"<<endl;
    printLine(5);
    cout<<endl;
    cout<<endl;
    
    cout<<"Printing n stars square"<<endl;
    printSquare(5);
    cout<<endl;

    cout<<"Printing n numbered square"<<endl;
    printRowNumberSquare(5);
    cout<<endl;

    cout<<"Printing n numbers in n square"<<endl;
    printColNumberSquare(5);
    cout<<endl;

    cout<<"Printing n numbers in n square (DESCENDING)"<<endl;
    printColNumbersSquareDesc(5);
    cout<<endl;

    cout<<"Printing number's square"<<endl;
    printNumbersSquare(5);
    cout<<endl;

    cout<<"Printing alphabets in square"<<endl;
    printAlphaSquare1(5);
    cout<<endl;

    cout<<"Printing alphabets in square"<<endl;
    printAlphaSquare2(5);
    cout<<endl;

    cout<<"Printing number in series (ASC)"<<endl;
    printNumberSeriesASC(3);
    cout<<endl;

    cout<<"Printing right angled triangle"<<endl;
    printRAT(5);
    cout<<endl;

    cout<<"Printing right sided RAT"<<endl;
    printSpacedRAT(5);
    cout<<endl;

    cout<<"Printing reversed right sided RAT"<<endl;
    printReverseSpacesRAT(5);
    cout<<endl;

}