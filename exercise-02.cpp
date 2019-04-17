/*
Nama Program	: Doubly Linked List
Nama			: Bunga Azizha N
NPM				: 140810180016
Kelas			: B
Deskripsi		: Create Function Insert First, Insert Last, Delete First, Delete last and Traversal (print)
*/

#include<iostream>
using namespace std;

struct ElemtList { 
	char info; 
	ElemtList* next; 
	ElemtList* prev; 
};
typedef ElemtList* pointer; 
typedef pointer List;

void createList (List& First);
void createElement(pointer& pBaru);
void insertFirstDoubly(List& First, pointer pBaru);
void insertLastDoubly(List& First, pointer pBaru);
void deleteFirstDoubly (List& First, pointer& pHapus);
void deleteLastDoubly (List& First, pointer& pHapus);
void traversal (List First);

main (){
	pointer x;
	pointer pHapus;
	List coba;
	int n;
	
	cout<<"===== PROGRAM DOUBLY LINKED LIST ====="<<endl;
  	createList(coba);
	cout<<"\n\tInsert First Doubly"<<endl;
	cout << "Banyak Data Insert First : "; cin >> n;
    for (int i=0;i<n;i++){
    createElement (x);
	insertFirstDoubly (coba, x);
	traversal (coba);
    }
	cout<<endl;
	
	cout<<"\n\tInsert Last Doubly : "<<endl;
	cout << "Banyak Data Insert First : "; cin >> n;
    for (int i=0;i<n;i++){
	createElement (x);
	insertLastDoubly (coba, x);
	traversal (coba);
    }
    
	deleteFirstDoubly(coba, pHapus);
	traversal (coba);
	deleteLastDoubly(coba, pHapus);
	traversal (coba);	
}

void createList (List& First){
	First = NULL;
}

void createElement(pointer& pBaru) { 
	pBaru = new ElemtList; 
	cout<<"\nMasukkan Data : ";
	cin >> pBaru->info; 
	pBaru->next = NULL; 
	pBaru->prev = NULL; 
}
void insertFirstDoubly(List& First, pointer pBaru){ 
	if (First==NULL)
		First=pBaru; 
	else { 
		pBaru->next=First;
		First->prev = pBaru;
		First=pBaru;
	}
}

void insertLastDoubly(List& First, pointer pBaru){ 
	pointer last;
	if (First==NULL){
		First=pBaru; 
	} 
	else {
		last=First;                    
		while (last->next!=NULL){       
			last=last->next; 
		} 
		last->next=pBaru;
		pBaru->prev = last; 
	} 
}

void deleteFirstDoubly (List& First, pointer& pHapus){
	cout << "\nDelete First" << endl; 
	if (First == NULL){               
		pHapus = NULL; 
		cout << "List kosong, tidak ada yang dihapus" << endl; 
	}
	else if (First->next == NULL){   
		pHapus = First; 
		First = NULL;                  
	}
	else {								
		pHapus = First;					
		First = First->next;
		pHapus->next = NULL;
		First->prev = NULL;
	}
}

void deleteLastDoubly (List& First, pointer& pHapus){
	pointer last;
	cout << "\nDelete Last" << endl; 
	if (First == NULL){               
		pHapus = NULL; 
		cout << "List kosong, tidak ada yang dihapus" << endl; 
	}
	else if (First->next == NULL){   
		pHapus = First; 
		First = NULL;                  
	}
	else {								
		last = First;
		while (last->next != NULL){
			last = last->next;
		}
		pHapus = last;
		last->prev->next = NULL;
		pHapus->prev = NULL;
	}
}

void traversal (List First){
	pointer pBantu;
	if (First == NULL){
		cout << "List Kosong"<<endl;
	}
	else {
		pBantu = First;
		do {
			cout << pBantu->info;
			pBantu = pBantu->next; cout<<" <--> ";
		} while (pBantu != NULL);	
		cout << endl;
	}
}
