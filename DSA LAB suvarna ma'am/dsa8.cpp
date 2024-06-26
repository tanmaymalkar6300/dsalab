// Implement all the functions of dictionary(ADT) using hashing and handle collision using chaining with/ without replacement .

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public :
    int chain;
    string mean, word;

}obj[10];

int hash_func(string wd){
    int key=0;
    for(int i=0; i<wd.size(); i++){
        key +=wd[i];
    }
    return key%10;
}

void collsion(int key, string wd, string mn){
    int i=1;
    while(((key%i)%10)<10){
        if(obj[(key+i)%10].word==wd){
            obj[(key+i)%10].word=wd;
            obj[(key+i)%10].mean=mn;
            obj[(key+i-1)%10].chain=(key+1)%10;
            break;
        }
        else{
            i++;
        }
    }
}

void hash_ini(){
    for(int i=0; i<10; i++){
        obj[i].word="-";
        obj[i].mean="-";
        obj[i].chain=-1;

    }
}

void hash_table(){
    string wd, mn;
    cout << "\n Enter a word = ";
    cin >>wd;
    cout <<"\n enter meaning =";
    cin >>mn;
    cout <<"\n";
    int hash_key=hash_func(wd);
    if(obj[hash_key].word=="-"){
         obj[hash_key].word=wd;
         obj[hash_key].mean=mn;
    }
    else{
        collsion(hash_key, wd, mn);
    }
}

void display(){
    cout << "Index \t Word \t Meaning \t Chain \n ";
    for(int i=0; i<10; i++){
        cout << i << "\t"<<obj[i].word<<"\t"<<obj[i].mean << "\t\t"<<obj[i].chain <<endl;
    }
}

void del_key(string word){
    int key= hash_func(word);
    if(obj[key].word==word){
        obj[key].word="-";
        obj[key].mean="-";
        obj[key].chain=-1;

    }
    else if(obj[key].word!=word){
        int target=obj[key].chain;
        while (true){
            if(obj[target-1].chain=obj[target].chain);
            obj[target].word="-";
            obj[target].mean="-";
            obj[target].chain=-1;
            cout<<"Deletion is sucessfull " <<endl;
            break;
        }
        target=obj[target].chain;

    }
    else{
    cout << " Word not found ! "<<endl;
  }
}

void find(string word){
    int key=hash_func(word);
    if(obj[key].word==word){
        cout << " Found the word !! "<<endl;
        cout <<obj[key].word<<"\t"<<obj[key].mean<<endl;

    }

    else if(obj[key].chain!=-1){
        int target=obj[key].chain;
        while(true){
            if(obj[target].word==word){
                cout << "found the word "<<endl;
                cout << obj[target].word <<"\t"<<obj[target].mean<<endl;
                break;
            }
            target=obj[target].chain;
        }
    }
    else{
        cout << "Not found !!"<<endl;

    }
}



int main(){
    int ch;
    string delwd;
    string src;
    hash_ini();
    do{
        cout << " Enter the choice = "<<endl;
        cout<< "1.insert\n2.Display\n3.Delete\n4.Find\n5.Exit\n";
        cout <<"Enter your choice :";
        cin>>ch;
        cout<<"\n";

        switch(ch){
            case 1 :
            cout <<"Enter the no of entires you want to make = ";
            int n;
            cin >>n;
            for(int i=0; i<n; i++){
                hash_table();

            }
            break;

            case 2 :
            display();
            break;

            case 3 :
            cout << "Enter the word you want to delete = ";
            cin>>delwd;
            del_key(delwd);
            break;

            case 4 :
            cout <<"Enter the number you want to find =";
            cin >>src;
            find(src);
            break;

            case 5 :
            exit(0);

        }
    }while(ch<=5);


}