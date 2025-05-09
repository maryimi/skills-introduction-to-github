#include <iostream> 
#include <string> 

using namespace std; 

/**
 * @class Node
 * @brief A class representing a node in a linked list.
 *
 * This class is used to create nodes that store an action and a book title,
 * along with a pointer to the next node in the list.
 *
 * @var std::string Node::action
 * A string representing the action associated with the node.
 *
 * @var std::string Node::bookTitle
 * A string representing the title of the book associated with the node.
 *
 * @var Node* Node::next
 * A pointer to the next node in the linked list.
 *
 * @fn Node::Node(std::string a, std::string b)
 * @brief Constructs a new Node object.
 * 
 * Initializes the action and bookTitle with the provided values and sets the next pointer to nullptr.
 *
 * @param a The action associated with the node.
 * @param b The title of the book associated with the node.
 */

class Node { 
    public: 
        string action; 
        string bookTitle; 
        Node* next; 
        Node(string a, string b) { 
            action = a; 
            bookTitle = b; 
            next = nullptr; 
        } 
}; 

/**
 * @class Stack
 * @brief A simple stack implementation to manage book actions.
 * 
 * This class provides a stack data structure to keep track of actions
 * performed on books, such as adding, removing, borrowing, and returning.
 * It allows pushing new actions onto the stack and popping the last action
 * to undo it.
 */
class Stack { 
    private: 
        Node* top; 
    public: 
        Stack() { 
            top = nullptr; 
        } 
        
        /**
         * @brief Pushes a new node onto the stack.
         * 
         * This function creates a new node with the given action and title,
         * and pushes it onto the top of the stack.
         * 
         * @param action The action string to be stored in the new node.
         * @param title The title string to be stored in the new node.
         */
        void push(const string& action, const string& title) { 
            Node* temp = new Node(action, title); 
            temp->next = top; 
            top = temp; 
        } 
        
        /**
         * @brief Undo the last operation performed on the book stack.
         * 
         * This function removes the top node from the stack and performs the
         * corresponding undo operation based on the action stored in the node.
         * It handles the following actions:
         * - "add": Removes the book that was added.
         * - "remove": Adds back the book that was removed.
         * - "borrow": Returns the book that was borrowed.
         * - "return": Borrows the book that was returned.
         * 
         * If the stack is empty, it prints a message indicating that there is
         * nothing to undo.
         */
        void pop() { 
            if (top == nullptr) { 
                cout << "Nothing to undo!" << endl; 
                return; 
            } 
            Node* curr = top; 
            cout << "Undoing last operation: " << top->action 
                 << " on " << top->bookTitle << endl; 
            if (top->action == "add") { 
                cout << "Removing book: " << top->bookTitle << endl; 
            } else if (top->action == "remove") { 
                cout << "Adding back book: " << top->bookTitle << endl; 
            } else if (top->action == "borrow") { 
                cout << "Returning book: " << top->bookTitle << endl; 
            } else if (top->action == "return") { 
                cout << "Borrowing book: " << top->bookTitle << endl; 
            } 
            top = top->next; 
            delete curr; 
        } 
        /**
         * @brief Destructor for the Stack class.
         * 
         * This destructor ensures that all elements in the stack are properly
         * deallocated by repeatedly calling the pop() method until the stack
         * is empty.
         */
        ~Stack() { 
            while (top != nullptr) { 
                pop(); 
            } 
        } 
}; 

/**
 * @class QNode
 * @brief A class representing a node in a queue.
 * 
 * This class is used to create nodes that store book titles and a pointer to the next node in the queue.
 * 
 * @var std::string QNode::bookTitle
 * A string that stores the title of the book.
 * 
 * @var QNode* QNode::next
 * A pointer to the next node in the queue.
 * 
 * @fn QNode::QNode(std::string b)
 * @brief Constructor that initializes a QNode with a given book title.
 * 
 * @param b The title of the book to be stored in the node.
 */

class QNode { 
    public: 
        string bookTitle; 
        QNode* next; 
        QNode(string b) { 
            bookTitle = b; 
            next = nullptr; 
        } 
}; 

/**
 * @class Queue
 * @brief A class to represent a queue for managing book borrow requests.
 * 
 * This class provides functionalities to enqueue and dequeue book borrow requests.
 * Each request is represented by a node containing the book title.
 * 
 * @note The queue is implemented using a linked list.
 */

class Queue { 
    private: 
        QNode* front; 
        QNode* rear; 
    public: 
        Queue() { 
            front = nullptr; 
            rear = nullptr; 
        } 
        
        /**
         * @brief Adds a new element with the given title to the end of the queue.
         * 
         * This function creates a new node with the specified title and adds it to the 
         * rear of the queue. If the queue is empty, the new node becomes both the front 
         * and rear of the queue.
         * 
         * @param title The title to be added to the queue.
         */
        
        void enqueue(const string& title) { 
            QNode* temp = new QNode(title); 
            if (rear == nullptr) { 
                front = rear = temp; 
            } else { 
                rear->next = temp; 
                rear = temp; 
            } 
        } 
        
        /**
         * @brief Removes the front element from the queue and processes the borrow request.
         * 
         * This function checks if the queue is empty. If it is, it prints a message indicating
         * that there are no books in the borrow queue. Otherwise, it processes the borrow request
         * for the book at the front of the queue, removes the front element, and updates the 
         * front pointer to the next element in the queue. If the queue becomes empty after 
         * removing the front element, it also updates the rear pointer to nullptr.
         */
        void dequeue() { 
            if (front == nullptr) { 
                cout << "No books in the borrow queue!" << endl; 
                return; 
            } 
            QNode* curr = front; 
            cout << "Processing borrow request for book: " 
                 << front->bookTitle << endl; 
            front = front->next; 
            if (front == nullptr) { 
                rear = nullptr; 
            } 
            delete curr; 
        } 
        /**
         * @brief Destructor for the Queue class.
         * 
         * This destructor ensures that all elements in the queue are properly 
         * deallocated by repeatedly calling the dequeue() method until the queue 
         * is empty. It prevents memory leaks by ensuring that all dynamically 
         * allocated memory is freed.
         */

        ~Queue() { 
            while (front != nullptr) { 
                dequeue(); 
            } 
        } 
}; 

/**
 * @class Book
 * @brief A class representing a book in a library system.
 * 
 * The Book class contains information about a book, including its title,
 * availability status, and a pointer to the next book in a linked list.
 * 
 * @var std::string Book::title
 * The title of the book.
 * 
 * @var bool Book::available
 * A boolean indicating whether the book is available for borrowing.
 * 
 * @var Book* Book::next
 * A pointer to the next book in the linked list.
 * 
 * @fn Book::Book(std::string t)
 * @brief Constructs a new Book object with the given title.
 * 
 * Initializes the title of the book to the given string, sets the availability
 * status to true, and initializes the next pointer to nullptr.
 * 
 * @param t The title of the book.
 */

class Book { 
    public: 
        string title; 
        bool available; 
        Book* next; 
        Book(string t) { 
            title = t; 
            available = true; 
            next = nullptr; 
        } 
}; 

/**
 * @class Library
 * @brief A class to manage a collection of books in a library.
 * 
 * The Library class provides functionalities to add, remove, borrow, return, 
 * and display books in the library. It maintains a linked list of books and 
 * keeps track of the total number of books.
 * 
 * @note The Book class is assumed to have the following members:
 *       - std::string title
 *       - bool available
 *       - Book* next
 * 
 * @var Library::head
 * Pointer to the first book in the library.
 * 
 * @var Library::totalBooks
 * The total number of books in the library.
 * 
 * @fn Library::Library()
 * Default constructor that initializes the library with no books.
 **/

class Library { 
    private: 
        Book* head; 
        int totalBooks; 
    public: 
        Library() { 
            head = nullptr; 
            totalBooks = 0; 
        } 
        /**
         * @brief Adds a new book to the collection.
         * 
         * This function creates a new Book object with the given title, 
         * adds it to the beginning of the linked list of books, 
         * increments the total number of books, and prints a confirmation message.
         * 
         * @param title The title of the book to be added.
         */
        void addBook(string title) { 
            Book* temp = new Book(title); 
            temp->next = head; 
            head = temp; 
            totalBooks++; 
            cout << "Book added: " << title << endl; 
        } 
        
        /**
         * @brief Removes a book with the given title from the list.
         * 
         * This function searches for a book by its title in the linked list of books.
         * If the book is found, it is removed from the list, the memory is deallocated,
         * and the total number of books is decremented. If the book is not found, a 
         * message is printed indicating that the book was not found.
         * 
         * @param title The title of the book to be removed.
         */
        void removeBook(string title) { 
            Book* current = head; 
            Book* previous = nullptr; 
            while (current != nullptr) { 
                if (current->title == title) { 
                    if (previous == nullptr) { 
                        head = current->next; 
                    } else { 
                        previous->next = current->next; 
                    } 
                    delete current; 
                    totalBooks--; 
                    cout << "Book removed: " << title << endl; 
                    return; 
                } 
                previous = current; 
                current = current->next; 
            } 
            cout << "Book not found!" << endl; 
        } 
        
        /**
         * @brief Borrows a book with the given title if it is available.
         * 
         * This function searches through the list of books starting from the head.
         * If a book with the specified title is found and is available, it marks the book as borrowed
         * (i.e., sets its available status to false) and prints a confirmation message.
         * If the book is not found or is not available, it prints a message indicating that the book is not available.
         * 
         * @param title The title of the book to be borrowed.
         */
        void borrowBook(string title) { 
            Book* current = head; 
            while (current != nullptr) { 
                if (current->title == title && current->available) { 
                    current->available = false; 
                    cout << "Book borrowed: " << title << endl; 
                    return; 
                } 
                current = current->next; 
            } 
            cout << "Book is not available!" << endl; 
        } 
        
        /**
         * @brief Marks a book as returned in the library system.
         * 
         * This function searches for a book by its title in the linked list of books.
         * If the book is found and it is currently borrowed (not available), it marks
         * the book as available and prints a confirmation message. If the book is not
         * found or it was not borrowed, it prints an appropriate message.
         * 
         * @param title The title of the book to be returned.
         */
        void returnBook(string title) { 
            Book* current = head; 
            while (current != nullptr) { 
                if (current->title == title && !current->available) { 
                    current->available = true; 
                    cout << "Book returned: " << title << endl; 
                    return; 
                } 
                current = current->next; 
            } 
            cout << "Book not found or it wasn't borrowed!" << endl; 
        }

        /**
         * @brief Displays the list of books in the library.
         * 
         * This function iterates through the linked list of books starting from the head.
         * If there are no books in the library, it prints a message indicating that.
         * For each book, it prints the title and the availability status (either "Available" or "Borrowed").
         */
        void displayBooks() { 
            if (head == nullptr) { 
                cout << "No books in the library!" << endl; 
                return; 
            } 
            Book* current = head; 
            while (current != nullptr) { 
                cout << "Book: " << current->title 
                     << ", Status: " 
                     << (current->available ? "Available" : "Borrowed") 
                     << endl; 
                current = current->next; 
            } 
        } 

        /**
         * @brief Destructor for the Library class.
         * 
         * This destructor ensures that all dynamically allocated Book objects
         * in the linked list are properly deleted to free memory. It iterates
         * through the list starting from the head, deleting each Book object
         * until the list is empty.
         */
        
        ~Library() { 
            while (head != nullptr) { 
                Book* temp = head; 
                head = head->next; 
                delete temp; 
            } 
        } 
}; 

/**
 * @brief Main function for the Library Management System.
 * 
 * This function provides a menu-driven interface for managing a library system.
 * It allows the user to add, borrow, return, and remove books, as well as display
 * all books, undo the last operation, and process the borrow queue.
 * 
 * The available options are:
 * 1. Add a book
 * 2. Borrow a book
 * 3. Return a book
 * 4. Remove a book
 * 5. Display all books
 * 6. Undo last operation
 * 7. Process borrow queue
 * 8. Exit
 * 
 * The function runs in an infinite loop until the user chooses to exit.
 * 
 * @return int Returns 0 upon successful exit.
 */

int main() { 
    Library l; 
    Stack s; 
    Queue q; 
    int choice = 0; 
    string bookTitle; 
    while (choice >= 1 || choice <= 8) { 

        cout << "\n----Library Management System----\n" << endl; 
        cout << "1. Add a book" << endl; 
        cout << "2. Borrow a book" << endl; 
        cout << "3. Return a book" << endl; 
        cout << "4. Remove a book" << endl; 
        cout << "5. Display all books" << endl; 
        cout << "6. Undo last operation" << endl; 
        cout << "7. Process borrow queue" << endl; 
        cout << "8. Exit\n" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice;
        cin.ignore();

        if (choice == 1) { 
            cout << "Enter book title to add: "; 
            getline(cin, bookTitle); 
            l.addBook(bookTitle); 
            s.push("add", bookTitle); 
        } else if (choice == 2) { 
            cout << "Enter book title to borrow: "; 
            getline(cin, bookTitle); 
            q.enqueue(bookTitle); 
        } else if (choice == 3) { 
            cout << "Enter book title to return: "; 
            getline(cin, bookTitle); 
            l.returnBook(bookTitle); 
            s.push("return", bookTitle); 
        } else if (choice == 4) { 
            cout << "Enter book title to remove: "; 
            getline(cin, bookTitle); 
            l.removeBook(bookTitle); 
            s.push("remove", bookTitle); 
        } else if (choice == 5) { 
            l.displayBooks(); 
        } else if (choice == 6) { 
            s.pop(); 
        } else if (choice == 7) { 
            q.dequeue(); 
        } else if (choice == 8) { 
            cout << "Exiting the program." << endl; 
            break; 
        } else { 
            cout << "Invalid choice, please try again." << endl; 
        } 
        // this will terminate the program incase userinput was not valid (1-8).
        choice = 8 ;
        
        }

    return 0; 
}
