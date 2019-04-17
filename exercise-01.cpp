/*
Nama Program	: Singly Linked List
Nama			: Bunga Azizha N
NPM				: 140810180016
Kelas			: B
Deskripsi		: Create Function Insert First, Insert Last, Delete First, Delete last and Traversal (print)
*/

#include<iostream>
using namespace std;

struct ElemtList{
	char info;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer pBaru;
    List first;
    int pilihan, n;

	cout<<"----- PROGRAM SINGLY LINKED LIST -----"<<endl;
  	createList(first);
	cout<<"\n\tInsert First"<<endl;
	    cout << "Banyak Data Insert First : "; cin >> n;
    for (int i=0;i<n;i++){
     	createElmt(pBaru);
     	insertFirst(first,pBaru);
     		traversal(first);
    }
	cout<<endl;
	
	cout<<"\n\tInsert Last : "<<endl;
	cout << "Banyak Data Insert First : "; cin >> n;
    for (int i=0;i<n;i++){
    createElmt(pBaru);
    insertLast(first,pBaru);
    traversal(first);
    }
	deleteFirst(first,pBaru); 
	traversal(first);
	deleteLast(first,pBaru); 
	traversal(first);
	cout<<endl;	
}

void createList(List& First){
	First = NULL;
}

void createElmt(pointer& pBaru){
	pBaru = new ElemtList;
	cout<<"\nMasukkan Data : ";
	cin>>pBaru->info;					
	pBaru->next = NULL;	
}

void insertFirst(List& First, pointer pBaru) {
	
	if (First==NULL) {
		First=pBaru;
	}
	else {
		pBaru->next=First;
		First=pBaru;
	}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	
	if(First==NULL) {
		First=pBaru;
	}
	else {
		last=First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void deleteFirst(List& First, pointer& pHapus){
	cout<<"\n\nDelete First"<<endl;
	if (First==NULL){
		pHapus=NULL;
		cout<<"List Kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else {							
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void deleteLast(List& First, pointer& pHapus){
	pointer last,preclast;
	cout<<"\nDelete Last"<<endl;
	if (First==NULL) {
		pHapus=NULL;
		cout<<"List Kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else {
		last=First;
		preclast=last;
		while (last->next!=NULL){
			preclast=last;
			last=last->next;
		}
		pHapus=last;
		preclast->next=NULL;
	}
}

void traversal(List First){
	pointer pBantu;
	if (First==NULL) {
		cout<<"List Kosong"<<endl;
	}
	else {
		pBantu=First;
		do{
			cout<< pBantu->info;
			pBantu = pBantu->next; cout<<" -> ";
		} while (pBantu != NULL);
	}	
}
