#include<iostream>

/*berfungsi untuk memberitahu program untuk menggunakan fitur dalam namespace yang bernama std.
contoh perintanya seperti cin, cout, dan endl*/
using namespace std;

/*mendeklarasi structur Node*/
struct Node {
    int val; //deklarasi variabel integer 
    Node* next; //Membuat Node baru melalui operator new dan mengalokasikan memorinya pada ptr
};

/*mendeklarasi variabel pointer Node head dengan nilai awal NULL*/
Node* head = NULL;

/*fungsi push(mengisi)*/
void push() {
    int val; //val mendeklarasi variabel integer untuk pointer Node ptr
    Node* ptr = new Node; //bikin Node new (baru) dan membagi data memori ke ptr
    
	/*kalau ptr kosong(NULL) atau tidak di isi,
	maka tidak dapat mengisi stack*/
	if (ptr == NULL) {
        cout << "Not able to push the element.\n";
        return;
    } 
	
	//Isi data/value
	else {
        cout << "Enter the value: ";
        cin >> val;
        
        //kalau head kosong(NULL)
        if (head == NULL) {
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
            
        //kalau head tidak bernilai NULL 
        } else {
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
        cout << "Item pushed.\n";
    }
}

/*fungsi pop(menghapus)*/
void pop() {
	//mendeklarasi variabel integer item dan pointer Node ptr
    int item; 
    Node* ptr;
    
    /*kalau head kosong(NULL),
    maka tidak ada data yang dapat dihapus*/
    if (head == NULL) {
        cout << "Underflow.\n";
        return;
        
    /*head tidak bernilai null, 
	maka isi paling atas dihilangkan*/
    } else {
        item = head->val;
        ptr = head;
        head = head->next;
        delete ptr;
        cout << "Item popped.\n";
    }
}

/*fungsi display(menampilkan)*/
void display() {
    Node* ptr; //deklarasi variabel pointer Node ptr
    ptr = head; //set ptr menjadi head
    
    /*jika stack kosong(NULL),
    maka tidak dapat menampilkan apapun*/
    if (ptr == NULL) {
        cout << "Stack is empty.\n";
        return;
        
    /*ptr tidak kosong(NULL),
	menampilkan semua isi data yang ada dalam stack*/
    } else {
        cout << "Printing Stack elements:\n";
        /*loop while mencetak semua nilai dari ptr->val
        dan ubah ptr jadi ptr->next sebagai template nya*/
		while (ptr != NULL) {
            cout << ptr->val << endl;
            ptr = ptr->next;
        }
    }
}

//menampilkan menu
int main() 
{
    int choice = 0;//mendeklarasi choise integer 
    
    cout << "*********Stack operations using linked list*********\n";
    while (choice != 4) {
        cout << "\nChose one from the below options...\n";
        cout << "1. Push\n2. Pop\n3. Show\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        	/*mengaktifkan 'push' atau dapat mengisi stack,
			jika memilih nomor 1*/
            case 1: {
                push();
                break;
            }
            
            /*mengaktifkan 'pop' atau menghapus isi stack,
			jika memilih nomor 2*/
            case 2: {
                pop();
                break;
            }
            
            /*mengaktifkan 'display' atau menampilkan semua isi stack,
			jika memilih nomor 3*/
            case 3: {
                display();
                break;
            }
            
            /*mengaktifkan 'exit' yaitu jika anda ingin selesai,
			jika memilih nomor 4*/
            case 4: {
                cout << "Exiting...\n";
                break;
            }
                        
            /*akan menampilkan "Please Enter valid choice.",
			jika tidak memilih option apapun yang di menu*/ 
            default: {
                cout << "Please Enter valid choice.\n";
            }
        }
    }
    return 0;
}
