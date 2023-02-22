#include <iostream>
using namespace std;

int main(){
    cout << "Lista de num. con variable i empleando while normal\n";
    int i = 0;
    while(i < 5){
        cout << i << "\n";
        i++;
    }

    cout << "Lista de num. con variable j empleando do{}while() \n";
    int j = 0;
    do{
        cout << j << endl;
        j++;
    }while(j < 5);

    return 0;
}

//Para compilar mediante terminal, emplear el comando "g++ FileName.cpp -o OutputFilePathAndName.exe"