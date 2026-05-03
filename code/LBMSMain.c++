#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

//! to make the classes more clear to not be comfused
class Books;
class BorrowedBooks;
class PurchasedBooks;
class BooksPublicOperations;
class User;
class Customer;
class Employee;
class Manager;
class EmployeeOperations;
class CustomerOperations;
class ManagerOperations;

//////////////////////////////////

//TODO - >>>>>>>>>     Classes Implementation


//! GeneralFunctions struct, it is a struc that contains a very helpful functions
struct GeneralFunctions
{
    //! Handeling Errors function - (not same data type imput)
    void handleErrors(int &choice)
    {
        while (cin.fail())
        {
            cout<<"\n>>>>] This option doesn't exist"<<endl;
            cin.clear();
            cin.ignore(1000 , '\n');

            cout<<"> Enter another option please : ";
            cin>>choice;
        }
    }

    //! To change the input case int Lower (small letters), very important in Searching
    void lowerCase(string &word)//* changes the orginal value
    {
        //! to make it Lower
        for (size_t Lower = 0 ; Lower < word.length() ; Lower++) 
        {
            if (word[Lower] >= 'A' && word[Lower] <= 'Z') 
            {
                word[Lower] = word[Lower] + ('a' - 'A');
            }
        }
    }

    //! to print a line from char you want
    //* recommended : length = 50  ,  symbol = '-'
    void printLine(int length , char symbol)
    {
        cout<<string(length, symbol)<<endl;
    }
    
    //! to stop the screen till the user click 'Enter' , caller is:  getline  or anything
    void pause(const string & caller)
    {
        cout<<"\n> Press Enter to continue...";
        if (caller != "getline")
            cin.ignore();
        cin.get();

        cout<<endl;
        printLine(50 , '-');
    }

    //! to put a text in the miidle of a space
    string centerText(const string &text , int width)
    {
        int leftSpace = (width - text.length()) / 2;
        int rightSpace = width - text.length() - leftSpace;

        return string(leftSpace , ' ') + text + string(rightSpace , ' ');
    }
};

//! Pointers_Handling class, it is a class that contains a very helpful functions for poniters
class Pointers_Handling
{
    public:

        //! Search a pointer list for a User* by email.
        template<typename T>
        T* findByEmail(list<T*> &lst, const string &email)
        {
            for (T* ptr : lst)
            {
                if (ptr != nullptr && ptr->get_email() == email)
                    return ptr;
            }
            return nullptr;
        }

        //! Check whether a given email already exists in a pointer list.
        template<typename T>
        bool emailExists(list<T*> &lst, const string &email)
        {
            return findByEmail(lst, email) != nullptr;
        }

        //! Remove (and delete) an element from a pointer list by email.
        template<typename T>
        bool removeByEmail(list<T*> &lst, const string &email)
        {
            for (auto temp = lst.begin(); temp != lst.end(); ++temp)
            {
                if (*temp != nullptr && (*temp)->get_email() == email)
                {
                    delete temp;
                    lst.erase(temp);
                    return true;
                }
            }
            return false;
        }

        //! Add a pointer to a list only if no element with the same email exists.
        template<typename T>
        bool addUserInList(list<T*> &lst, T* newPtr)
        {
            if (newPtr == nullptr) 
                return false;
            if (emailExists(lst, newPtr->get_email()))
                return false;
            lst.push_back(newPtr);

            return true;
        }

        //! Free every pointer in a list and clear it.
        template<typename T>
        void freeList(list<T*> &lst)
        {
            for (T* ptr : lst)
                delete ptr;
            lst.clear();
        }

        //! Print all Users in a list

        template<typename T>
        void printUsers(list<T*> &lst)
        {
            if (lst.empty())
            {
                cout << "\n> No users found in this list.\n" << endl;
                return;
            }

            for (T* ptr : lst)
            {
                if (ptr == nullptr) 
                    continue;
                cout << left
                    << setw(20)  << (ptr->get_name().length() > 20 ? 
                    ptr->get_name().substr(0, 17) + "..." : ptr->get_name())
                    << setw(4) << ptr->get_age()
                    << setw(30) << (ptr->get_email().length() > 20 ? 
                    ptr->get_email().substr(0, 17) + "..." : ptr->get_email());

                    cout << endl;
            }
        }


        /////////////////////////////////


        //! Search a Books pointer list by code
        template<typename T>
        T* findByCode(list<T*> &lst, int code)
        {
            for (T* ptr : lst)
            {
                if (ptr != nullptr && ptr->get_code() == code)
                    return ptr;
            }
            return nullptr;
        }
    
        //! Search a Books pointer list by title
        template<typename T>
        T* findByTitle(list<T*> &lst, const string &title)
        {
            for (T* ptr : lst)
            {
                if (ptr != nullptr && ptr->get_title() == title)
                    return ptr;
            }
            return nullptr;
        }
    
        //! Check whether a book with the given code already exists in the list.
        template<typename T>
        bool codeExists(list<T*> &lst, int code)
        {
            return findByCode(lst, code) != nullptr;
        }
    
        //! Add a Books* to a list only if no book with the same code exists.
        template<typename T>
        bool addBookInList(list<T*> &lst, T* newPtr)
        {
            if (newPtr == nullptr) 
                return false;
            if (codeExists(lst, newPtr->get_code()))
                return false;
            lst.push_back(newPtr);

            return true;
        }
    
        //! Remove a book from a pointer list by code.
        template<typename T>
        bool removeByCode(list<T*> &lst, int code)
        {
            for (auto temp = lst.begin(); temp != lst.end(); ++temp)
            {
                if (*temp != nullptr && (*temp)->get_code() == code)
                {
                    delete *temp;
                    lst.erase(temp);
                    return true;
                }
            }
            return false;
        }

        //! Print all books in a list
        template<typename T>
        void printBooks(list<T*> &lst)
        {
            if (lst.empty())
            {
                cout << "\n> No books found in this list.\n" << endl;
                return;
            }

            for (T* ptr : lst)
            {
                if (ptr == nullptr) 
                    continue;
                cout << left
                    << setw(10)  << ptr->get_code()
                    << setw(20) << (ptr->get_title().length() > 20 ? 
                    ptr->get_title().substr(0, 17) + "..." : ptr->get_title())
                    << setw(20) << (ptr->get_author().length() > 20 ? 
                    ptr->get_author().substr(0, 17) + "..." : ptr->get_author())
                    << setw(15) << ptr->get_section()
                    << setw(10) << fixed << setprecision(2) << ptr->get_price() << endl;
            }
        }
};

///////////////////////

//! Globa Variables / Objects:

int EMP_key_code = 999;
int MNG_key_code = 777;

GeneralFunctions general;
Pointers_Handling pointers;

list<User*> users;

list<Customer*> customers;

list<Employee*> employees;

list<Manager*> managers;

///////////////////////

//TODO - >>>>>>>>>>>>   Books' Classes


//! Books

class Books 
{
    private:
        string title;
        int code;
        string author;
        string section;
        double price;
    
    public:
        //! Virtual destructor
        virtual ~Books()
        {

        }

        //! Setters:
        void set_title(string title)
        {
            this->title = title;
        }
        void set_code(int code)
        {
            this->code = code;
        }
        void set_author(string author)
        {
            this->author = author;
        }
        void set_section(string section)
        {
            this->section = section;
        }
        void set_price(double price)
        {
            this->price = price;
        }

        //! Getters:
        string get_title()
        {
            return this->title;
        }
        int get_code()
        {
            return this->code;
        }
        string get_author()
        {
            return this->author;
        }
        string get_section()
        {
            return this->section;
        }
        double get_price()
        {
            return this->price;
        }
};

//! Purchased Books

class PurchasedBooks : public Books 
{
    
};


//! Borrowed Books

class BorrowedBooks : public Books 
{
    public:
        string returnDate;
};

////////////////////////

//TODO - >>>>>>>>>>>>   Operations Classes


//! Books Public Operations ===>  ____  Basim  ____

class BooksPublicOperations 
{
    protected:
        list<Books*> B;
        list<BorrowedBooks*> B_borrowed;
        list<PurchasedBooks*> B_purchased;

    public:
        //! virtual Destructor to destroy all books
        virtual ~BooksPublicOperations()
        {
            pointers.freeList(B_borrowed);
            pointers.freeList(B_purchased);
            pointers.freeList(B);
        }

        void browseBooks()
        {

        }

        //! to chose by whitch way you want to search , caller is:  name  or code
        void searchBooks(const string &caller)
        {

        }

        //! to chose who is the user , caller is:  customer  or employee
        void browseBorrowedBooks(const string &caller)
        {

        }

        //! to chose who is the user , caller is:  customer  or employee
        void browsePurchasedBooks(const string &caller)
        {

        }

        //////////////////////

        //TODO - Menus

        //! to chose who is the user , caller is:  customer  or employee
        void browseBooksMenu(const string &caller)
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Browse Books Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Browse All Books."<<"|"<<endl;
            if (caller == "customer")
            {
                cout<<"| "<<setw(57)<<left<<"2 - Browse My Purchased Books."<<"|"<<endl;
                cout<<"| "<<setw(57)<<left<<"3 - Browse My Borrowed Books."<<"|"<<endl;
            }
            else
            {
                cout<<"| "<<setw(57)<<left<<"2 - Browse All Purchased Books."<<"|"<<endl;
                cout<<"| "<<setw(57)<<left<<"3 - Browse All Borrowed Books."<<"|"<<endl;
            }
            
            cout<<"| "<<setw(57)<<left<<"4 - Back to The Main Menu."<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }

        //! to chose who is the user , caller is:  customer  or employee
        void browseBooksMenuChoice(const string &caller)
        {
            int choice = 0;

            do
            {
                browseBooksMenu(caller);
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! All Books
                        browseBooks();
                        break;
                    
                    case 2: //! Purchased Books
                        browsePurchasedBooks(caller);
                        break;

                    case 3: //! Borrowed Books
                        browseBorrowedBooks(caller);
                        break;

                    case 4: //! Back to main menu
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 4);
        }

        //////////////////////
        
        void searchBooksMenu()
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Search Books Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Search by Code."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Search by Name."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Back to The Main Menu."<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void searchBooksMenuChoice()
        {
            int choice = 0;

            do
            {
                searchBooksMenu();
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! search by code
                        searchBooks("code");
                        break;
                    
                    case 2: //! search by name
                        searchBooks("name");
                        break;

                    case 3: //! Back to main menu
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 3);
        }
};

////////////////////////

//! Employee Operations ===?  ____  Hussain  ____

class EmployeeOperations : public BooksPublicOperations 
{
    public:
        void AddBooks()
        {

        }

        void DeleteBooks()
        {

        }

        void UpdateBooks()
        {

        }

        void browseCustomersData()
        {

        }

        ///////////////////////

        //TODO - Menus

        void manageBooksMenu()
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Manage Books Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Add Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Delete Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Update Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"4 - Back to The Main Menu."<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void manageBooksMenuChoice()
        {
            int choice = 0;

            do
            {
                manageBooksMenu();
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Add Books
                        AddBooks();
                        break;
                    
                    case 2: //! Delete Books
                        DeleteBooks();
                        break;
                    
                    case 3: //! Update Books
                        UpdateBooks();
                        break;

                    case 4: //! Back to main menu
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 3);
        }
};

////////////////////////

//! Customer Operations ===>  ____  Basim  ____

class CustomerOperations : public BooksPublicOperations 
{
    private:
        string returnDate;

    public:
        void assignDate(string returndate)
        {

        }

        void borrow()
        {

        }

        void purchase()
        {

        }

        void printReceipt()
        {

        }

        void returnBook()
        {

        }
};

////////////////////////

//! Manager Operations  ===>  ____  Yazan  ____

class ManagerOperations 
{
    public:
        void deleteEmployee(Employee* emp); 
        void editSalary();
        void changeKey_Code();
        void viewEmployeesData();
        void browseFinancialReports();
};

////////////////////////

//TODO - >>>>>>>>>>>>   Actors Classes


//! User ===>  ____  Reda  ____

class User {
    private:
        string name;
        int age;
        string email;
        string password;

    public:
        //! Virtual destructor
        virtual ~User()
        {

        }

        //! setters
        void set_name(string name)
        {
            this->name = name;
        }
        void set_age(int age)
        {
            this->age = age;
        }
        void set_email(string email)
        {
            this->email = email;
        }
        void set_password(string password)
        {
            this->password = password;
        }
        
        //! getters
        string get_name()
        {
            return this->name;
        }
        int get_age()
        {
            return this->age;
        }
        string get_email()
        {
            return this->email;
        }
        string get_password()
        {
            return this->password;
        }

        //! registration
        void register_name()
        {
            cout << "\n> Enter Your name: ";
            cin.ignore();
            getline(cin , this->name);
        }
        void register_age()
        {
            cout << "> Enter Your Age: ";
            cin >> this->age;
            general.handleErrors(this->age);
        }
        void register_email()
        {
            string TempEmail;
            bool exist = true; // to check if the typed value ame as another value of the list
            while (exist)
            {
                cout << "> Enter Your Email: ";
                cin >> TempEmail;
                exist = false;


                if(pointers.emailExists(users, TempEmail)) // if the user email is already in the list
                {
                    cout << "\nThis Email is already Exist!" << endl;
                    cout << "Pleaes, Try Again!" << endl;
                    exist = true;
                }

            }
            
            //! if the input is uniqe 
            this->email = TempEmail;
        }
        void register_password()
        {
            bool correct = false;
            while (!correct)
            {
                cout << "> Enter Your Password: ";
                cin >> this->password;
                correct = true;
                if (this->password == "-1")
                {
                    cout << "\nThis password isn't allowed!" << endl;
                    cout << "Pleaes, Try Again!" << endl;
                    correct = false;
                }
            }
        }
        
        void registerUser()
        {
            register_name();
            register_age();
            register_email();
            register_password();

            User* newUser = new User(*this);
            users.push_back(newUser); //! to insert the entire object(pointer) into the list
        } 

        bool logout()
        {
            cout << "\n >>> You had logged out successfully! \n" << endl;
            return true;
        }

    protected:
        string check_getEmail()
        {
            //! Email
            string TempEmail;
            bool exist = false; // to check if the typed value ame as another value of the list
            while (!exist)
            {
                cout << "> Enter Your Email (Enter '-1' to leave): ";
                cin>>TempEmail;

                if (TempEmail == "-1") //! to leave
                    return "-1";

                // if the user email is already in the list
                if(pointers.findByEmail(users, TempEmail) != nullptr) 
                    return TempEmail;

                //! if not exist
                cout << "\nThis Email is not Exist!" << endl;
                cout << "Pleaes, Try Again!" << endl;
            }
            return "-1";
        }
        bool checkpasswrd(string tempEmail)
        {
            //! Password
            User* foundUser = pointers.findByEmail(users, tempEmail);
            if (foundUser == nullptr) 
                return false;

            string TempPassword;
            for (int attempt = 0 ; attempt < 3 ; attempt++)
            {
                cout << "> Enter Your Password (Enter '-1' to leave): ";
                cin >> TempPassword;
                
                if (TempPassword == "-1")
                    return false;

                if (TempPassword == foundUser->get_password())
                    return true;

                //! if not valid
                cout << "\nThis Password is not correct!" << endl;
                cout << "Please, Try Again!" << endl;
            }
            return false;
        }

        virtual bool login()
        {

        }
};

////////////////////////

//! Customer ===>  ____  Reda  ____

class Customer : public User {
    private:
        CustomerOperations CustomerOp;
        
        list<PurchasedBooks*> customerPurchasedBooks;
        list<BorrowedBooks*> customerBorrowedBooks;

    public:
        //! add books to customers inventory
        void add_Purchased(PurchasedBooks* book)
        {
            pointers.addBookInList(customerPurchasedBooks, book);
        }
        void add_Borrowed(BorrowedBooks* book)
        {
            pointers.addBookInList(customerBorrowedBooks, book);
        }

        //! Remove books from customer's inventory
        void remove_Purchased(int code)
        {
            pointers.removeByCode(customerPurchasedBooks, code);
        }
        void remove_Borrowed(int code)
        {
            pointers.removeByCode(customerBorrowedBooks, code);
        }

        //! virual destructor to destroy the customer with his books
        virtual ~Customer()
        {
            pointers.freeList(customerPurchasedBooks);
            pointers.freeList(customerBorrowedBooks);
        }

        bool login() override
        {
            string tempEmail = check_getEmail();
            if (tempEmail == "-1") 
                return false;
            if (!checkpasswrd(tempEmail)) 
                return false;

            //! Find the User in the list
            User* foundUser = pointers.findByEmail(users, tempEmail);
            if (foundUser == nullptr) 
                return false;

            this->set_name(foundUser->get_name());
            this->set_age(foundUser->get_age());
            this->set_email(foundUser->get_email());
            this->set_password(foundUser->get_password());

            //! Check if this customer is already in the list
            Customer* exist = pointers.findByEmail(customers, tempEmail);
            if (exist != nullptr)
            {
                //! Restore his saved book lists
                this->customerPurchasedBooks = exist->customerPurchasedBooks;
                this->customerBorrowedBooks  = exist->customerBorrowedBooks;
            }
            else
            {
                //! if he is not in the list
                Customer* newCustomer = new Customer(*this);
                customers.push_back(newCustomer);
            }

            return true;
        }

        ////////////////////

        //TODO - Customer Menu

        void customerMenu()
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Main Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Browse Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Search Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Borrow a Book."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"4 - Purchase a Book."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"5 - return a Book."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"6 - Log out. "<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void customerMenuChoice()
        {
            int choice = 0;

            do
            {
                customerMenu();
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Browse Books
                        CustomerOp.browseBooksMenuChoice("customer");
                        break;
                    
                    case 2: //! Search Books
                        CustomerOp.searchBooksMenuChoice();
                        break;
                    
                    case 3: //! Borrow a Book
                        CustomerOp.borrow();
                        break;

                    case 4: //! Purchase a Book
                        CustomerOp.purchase();
                        break;

                    case 5: //! return a Book
                        CustomerOp.returnBook();
                        break;

                    case 6: //! Log out
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 6);
        }  
};

////////////////////////

//! Employee ===>  ____  Reda  ____

class Employee : public User {
    private:
        EmployeeOperations employeeOp;
        double salary = 2500;

    public:
        //! virtual destructor
        virtual ~Employee()
        {
            
        }

        bool set_salary(double salary)
        {
            if (salary > 2000 && salary < 1000000)
            {
                this->salary = salary;
                return true;
            }

            return false;    
        }
        double get_salary()
        {
            return this->salary;
        }

        //! caller is employee or manager
        bool checkKey_Code(const string &caller)
        {
            for (int attempt = 0 ; attempt < 3 ; attempt++)
            {
                int tempCode;
                cout << "> Enter the Key_Code (Enter '-1' to leave): ";
                cin >> tempCode;
                general.handleErrors(tempCode);

                if (tempCode == -1) 
                    return false;

                if (caller == "manager" && tempCode == MNG_key_code)
                {
                    cout << "\n >> You had Logged in successfully!\n" << endl;
                    return true;
                }
                else if (caller != "manager" && tempCode == EMP_key_code)
                {
                    cout << "\n >> You had Logged in successfully!\n" << endl;
                    return true;
                }

                cout << "\nThis Key_Code is not correct!" << endl;
                cout << "Please, Try Again!" << endl;
            }
            return false;
        }
        
        bool login(const string &caller)
        {
            string tempEmail = check_getEmail();
            if (tempEmail == "-1") 
                return false;
            if (!checkpasswrd(tempEmail)) 
                return false;
            if (!checkKey_Code(caller)) 
                return false;

            //! Find the User in the list
            User* foundUser = pointers.findByEmail(users, tempEmail);
            if (foundUser == nullptr) 
                return false;

            this->set_name(foundUser->get_name());
            this->set_age(foundUser->get_age());
            this->set_email(foundUser->get_email());
            this->set_password(foundUser->get_password());

            //! if he is not already in the list
            if (pointers.findByEmail(employees, tempEmail) == nullptr)
            {
                Employee* newEmployee = new Employee(*this);
                employees.push_back(newEmployee);
            }

            return true;
        }

        ////////////////////

        //TODO - Employee and Manager Menu

        //! caller is employee or manager
        void employeeMenu(const string &caller)
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Main Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Browse Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Search Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Manage Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"4 - Veiw Customers Info."<<"|"<<endl;
            if (caller == "manager")
            {
                cout<<"| "<<setw(57)<<left<<"5 - Employees. "<<"|"<<endl;
                cout<<"| "<<setw(57)<<left<<"6 - Veiw Financial Transaction Reports. "<<"|"<<endl;
                cout<<"| "<<setw(57)<<left<<"7 - Log out. "<<"|"<<endl;
            }
            else
                cout<<"| "<<setw(57)<<left<<"5 - Log out. "<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void employeeMenuChoice()
        {
            int choice = 0;

            do
            {
                employeeMenu("employee");
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Browse Books
                        
                        break;
                    
                    case 2: //! Search Books
                        
                        break;
                    
                    case 3: //! Manage Books
                        
                        break;

                    case 4: //! Veiw Customers Info
                        
                        break;

                    case 5: //! Log out
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 5);
        }
};

////////////////////////

//! Manager ===>  ____  Reda  ____

class Manager : public Employee {
    private:
        ManagerOperations managerOp;

    public:
        //! virtual destructor
        virtual ~Manager()
        {

        }

        bool Mnglogin()
        {
            if (!login("manager")) 
                return false;

            //! if he is not already in the list
            if (pointers.findByEmail(managers, this->get_email()) == nullptr)
            {
                Manager* newManager = new Manager(*this);
                newManager->set_salary(30000);
                managers.push_back(newManager);
            }

            return true;
        }
        void managerMenuChoice()
        {
            int choice = 0;

            do
            {
                employeeMenu("manager");
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Browse Books
                        
                        break;
                    
                    case 2: //! Search Books
                        
                        break;
                    
                    case 3: //! Manage Books
                        
                        break;

                    case 4: //! Veiw Customers Info
                        
                        break;

                    case 5: //! Employees
                        
                        break;

                    case 6: //! Veiw Financial Reports
                        
                        break;

                    case 7: //! Log out
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 7);
        }
};

////////////////////////

//TODO - >>>>>>>>>>   Main Menu

//! Menu ===>  ____  Reda  ____
class MainMenu
{
    private:
        User user;
        Employee employee;
        Manager manager;
        Customer customer;

        void RolesMenu()
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Select a Role", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Customer."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Employee."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Manager."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"4 - Back to The Registration Menu. "<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void RolesMenuChoice()
        {
            int choice = 0;

            do
            {
                RolesMenu();
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Customer
                        if (customer.login())
                            customer.customerMenuChoice();
                        else
                        {
                            general.printLine(50 , '-');
                            return;
                        }
                        break;
                    
                    case 2: //! Employee
                        if (employee.login("employee"))
                            employee.employeeMenuChoice();
                        else
                        {
                            general.printLine(50 , '-');
                            return;
                        } 
                        break;
                    
                    case 3: //! Manager
                        if (manager.Mnglogin())
                            manager.managerMenuChoice();
                        else
                        {
                            general.printLine(50 , '-');
                            return;
                        } 
                        break;

                    case 4: //! Back to The Registration Menu
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 4);
        }

    public:
        void menu()
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Registration Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Log in."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Create an Account."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Exit. "<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void mainMenuChoice()
        {
            int choice = 0;

            do
            {
                menu();
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Log in
                        RolesMenuChoice();
                        break;
                    
                    case 2: //! Register
                        user.registerUser();
                        break;

                    case 3: //! Exit
                        general.printLine(50 , '-');
                        return;

                    default:
                        cout<<"\n* Wrong Entry! please try again!\n"<<endl;
                        break;
                }

                general.printLine(50 , '-'); //! print a Line between each option

            } while (choice != 3);
            
        }
};


/////////////////////////////////////////////////

//! <<<<<<<<<<<<<<[   M A I N   ]>>>>>>>>>>>>>>>>

/////////////////////////////////////////////////

int main()
{
    MainMenu menu;

    //////////////////////////////////////

    //! Greeting sentence
    cout << "\n\n" << general.centerText(string(46 , '-') , 64) << endl;
    cout << "<<<<<<<<[   Welcome to our Library Management System   ]>>>>>>>>" << endl;
    cout << general.centerText(string(46 , '-') , 64) << endl << endl;

    ///////////////////

    //! The Main Menu

    menu.mainMenuChoice(); //! Every operations will be here

    ///////////////////

    //! Concluding sentence
    cout << endl << endl;
    general.printLine(79 , '=');
    cout << "|             T h e  _  P r o g r a m  _  i s  _  F i n i s h e d             |"
        << endl;
    general.printLine(79 , '=');
    cout << endl << endl;

    ///////////////////
    

    //! Free all Pointers
    pointers.freeList(managers);
    pointers.freeList(employees);
    pointers.freeList(customers);
    pointers.freeList(users);



    return 0;
}