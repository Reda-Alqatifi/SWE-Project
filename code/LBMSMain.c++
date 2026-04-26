#include <iostream>
#include <string>
#include <list>

using namespace std;

//! to make the classes more clear to not be cmfused
class Books;
class BorrowedBooks;
class PurchasedBooks;
class BooksPublicOperations;
class Employee;
class EmployeeOperations;
class CustomerOperations;
class ManagerOperations;

//! Globa Variables:
int EMP_key_code = 999;
int MNG_key_code = 777;

//////////////////////////////////

//TODO - >>>>>>>>>     Classes Implementation


//TODO - Books' Classes


//! Books

class Books {
private:
    string title;
    int code;
    string author;
    string section;
    double price;
};

//! Purchased Books

class PurchasedBooks : public Books {
    
};


//! Borrowed Books

class BorrowedBooks : public Books {
public:
    string returnDate;
};


//TODO - Operations Classes


//! Books Public Operations

class BooksPublicOperations {
protected:
    list<Books*> B;
    list<BorrowedBooks*> B_borrowed;
    list<PurchasedBooks*> B_purchased;

public:
    virtual void browseBooks() = 0;
    virtual void searchBooks() = 0;
    virtual void browseBorrowedBooks() = 0;
    virtual void browsePurchasedBooks() = 0;
    
    virtual ~BooksPublicOperations() {}
};


//! Employee Operations 

class EmployeeOperations : public BooksPublicOperations {
public:
    void UpdateBooks();
    void DeleteBooks();
    void AddBooks();
    void browseCustomersData();
};


//! Customer Operations

class CustomerOperations : public BooksPublicOperations {
private:
    string returnDate;
    
    list<PurchasedBooks*> purchasedList;
    list<BorrowedBooks*> borrowedList;

public:
    void assignDate(string r);
    void borrow();
    void purchase();
    void printReceipt();
    void returnBook(BorrowedBooks* B);
};


//! Manager Operations

class ManagerOperations {
public:
    // Dependency: "Manages" Employee. 
    // Using an Employee pointer parameter to represent the dependency.
    void deleteEmployee(Employee* emp); 
    void editSalary();
    void changeKey_Code();
    void viewEmployeesData();
    void browseFinancialReports();
};


//TODO - Actors Classes


//! User

class User {
private:
    string name;
    int age;
    string email;
    string password;

public:
    virtual void registerUser(); 
    virtual void login();
    virtual void logout();
    
    virtual ~User() {}
};


//! Customer 

class Customer : public User {
private:
    CustomerOperations* CustomerOp;
    
    list<PurchasedBooks*> customerPurchasedBooks;
    list<BorrowedBooks*> customerBorrowedBooks;

public:
    void browse(BooksPublicOperations* operations);
};


//! Employee

class Employee : public User {
private:
    EmployeeOperations* employeeOp;

public:
    void login() override; 
};


//! Manager

class Manager : public Employee {
private:
    // "Uses" ManagerOperations
    ManagerOperations* managerOp;
};


/////////////////////////////////////////////////

//! <<<<<<<<<<<<<<[   M A I N   ]>>>>>>>>>>>>>>>>

/////////////////////////////////////////////////

int main()
{






    return 0;
}