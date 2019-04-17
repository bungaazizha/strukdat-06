/*
Nama Program	: Circular Doubly Linked List
Nama			: Bunga Azizha N
NPM				: 140810180016
Kelas			: B
Deskripsi		: Create Function Insert First, Insert Last, Delete First, Delete last and Traversal (print)
*/

#include<iostream>
using namespace std;

struct elemlist
{
    char info;
    elemlist* next;
    elemlist* prev;
};

typedef elemlist* pointer;
typedef pointer list;

void createList (list& first){
    first = NULL;
}

void createElmt (list& first, pointer& pBaru)
{
    pBaru = new elemlist;
    cout << "Input element : "; cin >> pBaru->info;
    pBaru->next = pBaru;
    pBaru->prev = pBaru;
}

void insertFirstCircular (list& first, pointer pBaru)
{
    pointer last;
    if (first == NULL)
    {
        first = pBaru;
    }

    else
    {
        last = first;
        while(last->next != first)
        {
            last = last->next;
        }
        pBaru->next = first;
        pBaru->prev = last;
        first->prev = pBaru;
        last->next = pBaru;
        first = pBaru;
    }
    
}

void insertLastCircular (list& first, pointer pBaru)
{
    pointer last;
    if (first == NULL)
    {
        first = pBaru;
        last = first;
    }

    else
    {
        last = first;
        while(last->next != first)
        {
            last = last->next;
        }
        last->next = pBaru;
        pBaru->prev = last;
        pBaru->next = first;
        first->prev = pBaru;
        
    }
    
}

void deleteFirstCircular (list& first, pointer& pHapus)
{
    pointer last;
    if (first == NULL)
    {
        cout << "List kosong, tidak ada yang bisa dihapus" << endl;
    }

    else if (first->next == first)
    {
        pHapus = first;
        pHapus->next = NULL;
        pHapus->prev = NULL;
        first = NULL;
    }

    else
    {
        last = first;
        while(last->next != first)
        {
            last = last->next;
        }
        pHapus = first;
        first = pHapus->next;
        last->next = first;
        first->prev = last;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
    
}

void deleteLastCircular (list& first, pointer& pHapus)
{
    pointer last;
    if (first == NULL)
    {
        cout << "List kosong, tidak ada yang bisa dihapus" << endl;
    }

    else if (first->next == first)
    {
        pHapus = first;
        pHapus->next = NULL;
        pHapus->prev = NULL;
        first = NULL;
    }
    
    else
    {
        last = first;
        while(last->next != first)
        {
            last = last->next;
        }
        pHapus = last;
        first->prev = last->prev;
        last->prev->next = first;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
    
}

void traversal (list first)
{
    pointer pBantu, last;
    if (first == NULL)
    {
        cout << "List kosong" << endl;
    }

    else
    {
        int i = 1;
        pBantu = first;
        while(pBantu->next != first)
        {
            cout << "Element " << i << " : " << pBantu->info << endl;
            ++i;
            pBantu = pBantu->next;
        }
        cout << "Element " << i << " : " << pBantu->info << endl;   
    }  
}

main ()
{
    pointer p;
    list l;
    int menu;
    createList (l);
    do
    {
    	cout<<endl;
		cout<<">>> Program Circular Doubly Linked List <<<"<<endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete First" << endl;
        cout << "4. Delete Last" << endl;
        cout << "5. Traversal" << endl;
        cout << "6. Exit" << endl;
        
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
            case 1:
                createElmt (l,p);
                insertFirstCircular (l,p);
                traversal (l);
                break;

            case 2:
                createElmt (l,p);
                insertLastCircular (l,p);
                traversal (l);
                break;

            case 3:
                deleteFirstCircular (l,p);
                traversal (l);
                break;

            case 4:
                deleteLastCircular (l,p);
                traversal (l);
                break;

            case 5:
                traversal (l);
                break;

            default:
                cout << "Exit" << endl;
                break;
        }
    } while (menu >= 1 && menu <= 5);  
}
