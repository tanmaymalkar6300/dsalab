//  Consider telephone book database of N consider Telephone make use of hash function table implementation to quickly look up clients telephone number.


#include<bits/stdc++.h>

using namespace std;

class telephone
{

    int x;
    int hash_add;
    long long int key;
    int mob[10];
    string name[10];

public:
    telephone()
    {
        for (int i = 0; i < 10; i++)
        {

            mob[i] = -1;
        }
    }

    void insertrecord_Lp()
    {
        cout << "enter no of record: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {

            cout << "Enter the Telephone no(key):";
            cin >> key;

            hash_add = key % 10;
            if (mob[hash_add] == -1)
            {
                mob[hash_add] = key;
                cout << "Enter the name: ";
                cin >> name[hash_add];
            }

            else
            {
                int i = 1;
                while (mob[hash_add + i] < 10)
                {
                    if (mob[hash_add + i] == -1)
                    {
                        mob[hash_add + i] = key;
                        cout << "Enter the name: ";
                        cin >> name[hash_add + i];
                        break;
                    }
                    else if (mob[hash_add + i] != -1)
                    {
                        i++;
                    }
                }
            }
        }
    }

    void insertrecord_Qp()
    {
        cout << "enter no of record: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {

            cout << "Enter the Telephone no(key):";
            cin >> key;

            hash_add = key % 10;
            if (mob[hash_add] == -1)
            {
                mob[hash_add] = key;
                cout << "Enter the name: ";
                cin >> name[hash_add];
            }

            else
            {
                int i = 1;

                hash_add = hash_add + (i * i);
                while (mob[hash_add] < 10)
                {

                    if (mob[hash_add] == -1)
                    {
                        mob[hash_add] = key;
                        cout << "Enter the name";
                        cin >> name[hash_add];
                        break;
                    }
                    else if (mob[hash_add] != -1)
                    {
                        i++;
                        hash_add = hash_add + (i * i);
                    }
                }
            }
        }
    }

    void Display()
    {
        cout<<endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << " " << mob[i] << " " << name[i] << endl;
        }
        cout<<endl;
    }
};

int main()
{

    telephone t;
    int choice;

    do
    {
        cout << "\n1. Insert Record(Linear Probing)" << endl;
        cout << "2. Insert Record(Quadratic Probing)" << endl;
        cout << "3. Display" << endl;
        cout << "4. exit" << endl;
        cout << "\nEnter your choice : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.insertrecord_Lp();
            break;

        case 2:
            t.insertrecord_Qp();
            break;

        case 3:
            t.Display();
            break;

        case 4:
            cout<<"\nExiting...";
            break;

        default:
            cout << "\nselect appropiate choice" << endl;
            break;
        }
    } while (choice != 4);
}