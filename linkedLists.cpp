#include <iostream>
using namespace std;

// Node
typedef struct node {
    int data;
    struct node *next;
}node;

// Class
class listClass {
    private:
        node *start;
    public:
        // Constructor
        listClass(){
          start = nullptr;
        }
        // Re-initializing
        void reinitialize() {
          start = nullptr;
        }
        // Adding a number to the list
        void add(int num){
          node *space = new node;
          space -> data = num;
          if(start == nullptr){
            space -> next = nullptr;
            start = space;
            return;
          }
          node *bef, *cur = start;
          if(cur -> data > num){
            space -> next = start;
            start = space;
            return;
          }
          while(cur != NULL && cur -> data < num){
            bef = cur;
            cur = cur -> next;
          }
          // Check if num is in the list
          if(cur != NULL && cur -> data == num){
            cout << "The value is already present";
            return;
          }
          space -> next = cur;
          bef -> next = space;
        }
        // Removing a number from the list
        void remove(int num){
            node *cur, *bef;
            cur = start;
            // Deleting value
            if(cur -> data == num){
                start = cur -> next;
                cur -> next = nullptr;
                delete cur;
                return;
            }
            while(cur != nullptr && cur->data != num){
                bef = cur;
                cur = cur -> next;
            }
            if(cur == nullptr) {
                return;
            }
            bef -> next = cur -> next;
            cur -> next = nullptr;
            delete cur;
        }
        // Check if the list is empty or not
        void empty(){
            if(start == nullptr){
                cout << "The list is empty" << endl;
            }else{
                cout << "The list is NOT empty" << endl;
            }
        }
        // Getting the length of the list
        int len(){
            node *cur = start;
            int num = 0;
            while(cur != nullptr){
                cur = cur -> next;
                num++;
            }
            return num;
        }
        // Checking if a certain number is in the list
        void checkNum(int num){
            node *cur = start;
            while(cur != nullptr && cur->data != num){
              cur = cur -> next;
            }
            if(cur != nullptr && cur -> data == num){
                cout << "The value " << num << " is present in the list" << endl;
            }else {
                cout << "The value " << num << " is NOT present in the list" << endl;
            }
        }
        // Returning the kth element of the list
        int find(int num){
            node *cur = start;
            for(int i = 1; cur != nullptr && i < num; i++){
                cur = cur -> next;
            }
            if(cur == nullptr)
                return -1;
                return cur -> data;
        }
        // Displaying the list
        void display(){
            node *cur = start;
            if(cur == nullptr){
                cout << "EMPTY LIST";
                return;
            }else {
                cout << "LIST: < " << cur -> data;
                cur = cur -> next;
            }
            while(cur != nullptr){
                cout << ", " << cur -> data;
                cur = cur -> next;
            }
            cout << " >" << endl;
        }
};

// Displaying the menu
void displayMenu(){
    cout << "This program responds to commands the user enters to " << endl;
    cout << "manipulate an ordered list of integers which is initially " << endl;
    cout << "empty. In the following commands k is a " << endl;
    cout << "position in the list, and v is an integer. " << endl << endl;
    cout << "e -- Re-initialize the list to be empty." << endl;
    cout << "i v -- Insert the value v into the list." << endl;
    cout << "r v -- Remove the value v from the list." << endl;
    cout << "m -- Is the list empty?" << endl;
    cout << "l -- Report the length of the list." << endl;
    cout << "p v -- Is the value v present in the list?" << endl;
    cout << "k k1 -- Report the k1th value in the list." << endl;
    cout << "w -- Write out the list." << endl;
    cout << "h -- See this menu." << endl;
    cout << "q -- Quit." << endl;
}

int main(){
    // Taking entry from user
    char entry;
    listClass list;
    int num, n;
    // Displaying the menu
    displayMenu();
    // Displaying the -->
    while(1){
        cout << "--> ";
        cin >> entry;
        // Switch statement to call each function
        switch(entry){
            case 'e':
                list.reinitialize();
                cout << endl;
                break;
            case 'i':
                cin >> num;
                list.add(num);
                break;
            case 'r':
                cin >> num;
                list.remove(num);
                break;
            case 'm':
                list.empty();
                break;
            case 'l':
                num = list.len();
                cout << "The length of the list is " << num << endl;
                break;
            case 'p':
                cin >> num;
                list.checkNum(num);
                break;
            case 'k':
                cin >> n;
                num = list.find(n);
                if(num == -1){
                    cout << "The list does not contain " << n << " values." << endl;
                }else{
                    cout << "The " << n << "th element of the list is " << num << endl;
                }
                break;
            case 'w':
                list.display();
                break;
            case 'h':
                displayMenu();
                break;
            case 'q':
                exit(0);
                break;
            default:
                cout << "Invalid Entry!" << endl;
        }
    }
    return 0;
}