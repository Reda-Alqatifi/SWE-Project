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

///////////////////////

//! Globa Variables / Objects:

int EMP_key_code = 999;
int MNG_key_code = 777;

GeneralFunctions general;

list<User> users;

list<Customer> customers;

list<Employee> employees;

list<Manager> managers;

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
        list<Books> B;
        list<BorrowedBooks> B_borrowed;
        list<PurchasedBooks> B_purchased;

    public:
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

        void menu()
        {
            cout<<endl;
            general.printLine(60 , '=');
            cout<<"|"<<general.centerText("Employee Menu", 58)<<"|"<<endl;
            general.printLine(60 , '-');

            cout<<"| "<<setw(57)<<left<<"1 - Browse Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"2 - Search Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"3 - Manage Books."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"4 - Veiw Customers Info."<<"|"<<endl;
            cout<<"| "<<setw(57)<<left<<"5 - Log out."<<"|"<<endl;

            general.printLine(60 , '=');

            /////////////////////////////////////

            cout<<"\n> Enter your choice : ";
        }
        void EMPMenuChoice() //! Every operations related to Employee
        {
            int choice = 0;

            do
            {
                menu();
                cin>>choice;

                general.handleErrors(choice);

                switch (choice)
                {
                    case 1: //! Browse Books
                        browseBooks();
                        break;
                    
                    case 2: //! Search Books
                        searchBooksMenuChoice();
                        break;
                    
                    case 3: //! Manage Books
                        manageBooksMenuChoice();
                        break;

                    case 4: //! Veiw Customers Info
                        browseCustomersData();
                        break;

                    case 5: //! Log out
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
        
        list<PurchasedBooks> purchasedList;
        list<BorrowedBooks> borrowedList;

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

        void returnBook(BorrowedBooks B)
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

                for (auto &u : users)
                {
                    if(TempEmail == u.email) // if the user email is already in the list
                    {
                        cout << "\nThis Email is already Exist!" << endl;
                        cout << "Pleaes, Try Again!" << endl;
                        exist = true;
                        break;
                    }
                }
            }
            
            if(!exist) //! if the input is uniqe 
            {
                this->email = TempEmail;
            }
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

            users.push_back(*this); //! to insert the entire object into the list
        } 

        void logout()
        {
            cout << "\n >>> You had logged out successfully! \n" << endl;
            return;
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

                for (auto &u : users)
                {
                    if(TempEmail == u.get_email()) // if the user email is already in the list
                        return TempEmail;
                }

                //! if not exist
                cout << "\nThis Email is not Exist!" << endl;
                cout << "Pleaes, Try Again!" << endl;
            }
            return "-1";
        }
        bool checkpasswrd(string tempEmail)
        {
            //! Password
            string TempPassword;
            for (auto &u : users)
            {
                if(u.get_email() == tempEmail)
                {
                    for (int attempt = 0 ; attempt < 3 ; attempt++)
                    {
                        cout << "> Enter Your Password (Enter '-1' to leave): ";
                        cin >> TempPassword;
                        
                        if (TempPassword == "-1")
                            return false;

                        //! if valid
                        if (TempPassword == u.get_password())
                        {
                            return true;
                        }

                        //! if not valid
                        cout << "\nThis Password is not correct!" << endl;
                        cout << "Pleaes, Try Again!" << endl;
                    }

                    return false;
                }
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
        
        list<PurchasedBooks> customerPurchasedBooks;
        list<BorrowedBooks> customerBorrowedBooks;

    public:
        //! add books to customers inventory
        void add_Purchased(PurchasedBooks book)
        {
            this->customerPurchasedBooks.push_back(book);
        }
        void add_Borrowed(BorrowedBooks book)
        {
            customerBorrowedBooks.push_back(book);
        }

        bool login() override
        {
            string tempEmail = check_getEmail();

            if (tempEmail != "-1" && checkpasswrd(tempEmail))
            {
                for (auto &u : users)
                {
                    if (tempEmail == u.get_email())
                    {
                        bool inList = false;
                        Customer tempC;
                        for (auto &c : customers)
                        {
                            if (c.get_email() == u.get_email())
                            {
                                tempC = c;
                                inList = true;
                                break;
                            }
                        }

                        this->set_name(u.get_name());
                        this->set_age(u.get_age());
                        this->set_email(u.get_email());
                        this->set_password(u.get_password());

                        if (inList)
                        {
                            this->customerPurchasedBooks = tempC.customerPurchasedBooks;
                            this->customerBorrowedBooks = tempC.customerBorrowedBooks;
                        }
                        if (!inList)
                            customers.push_back(*this);

                        return true;
                    }
                }
            }
            
            return false;
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
                        
                        break;
                    
                    case 2: //! Search Books
                        
                        break;
                    
                    case 3: //! Borrow a Book
                        
                        break;

                    case 4: //! Purchase a Book
                        
                        break;

                    case 5: //! return a Book
                        
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
        bool set_salary(double salary)
        {
            if (salary > 2000 && salary < 1000000)
            {
                this->salary = salary;
                return true;
            }

            return false;    
        }

        //! caller is employee or manager
        bool checkKey_Code(const string &caller)
        {
            int attempt;
            for (attempt = 0 ; attempt < 3 ; attempt++)
            {
                int tempCode;
                cout << "> Enter the Key_Code (Enter '-1' to leave): ";
                cin >> tempCode;

                general.handleErrors(tempCode);

                if (tempCode == -1)
                    return false;

                if (caller == "manager")
                {
                    if (tempCode == MNG_key_code)
                    {
                        cout << "\n >> You had Loged in successfully!\n" << endl;
                        return true;
                    }
                }
                else
                {
                    if (tempCode == EMP_key_code)
                    {
                        cout << "\n >> You had Loged in successfully!\n" << endl;
                        return true;
                    }
                }
                
                //! if not valid
                cout << "\nThis key_Code is not correct!" << endl;
                cout << "Pleaes, Try Again!" << endl;
            }

            return false;
        }
        
        bool login(const string &caller)
        {
            string tempEmail = check_getEmail();

            if (tempEmail != "-1" && checkpasswrd(tempEmail) && checkKey_Code(caller))
            {
                for (auto &u : users)
                {
                    if (tempEmail == u.get_email())
                    {
                        bool inList = false;
                        for (auto &e : employees)
                        {
                            if (e.get_email() == u.get_email())
                            {
                                inList = true;
                                break;
                            }
                        }

                        this->set_name(u.get_name());
                        this->set_age(u.get_age());
                        this->set_email(u.get_email());
                        this->set_password(u.get_password());

                        if (!inList)
                            employees.push_back(*this);

                        return true;
                    }
                }
            }
            
            return false;
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
        //! caller is employee or manager
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
        bool Mnglogin()
        {
            if (login("manager"))
            {
                bool inList = false;
                for (auto &m : managers)
                {
                    if (m.get_email() == this->get_email())
                    {
                        inList = true;
                        break;
                    }
                }

                if (!inList)
                    managers.push_back(*this);

                return true;
            }

            return false;
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
                        { 
                           customer.customerMenuChoice();
                        }
                        else
                        {
                            general.printLine(50 , '-');
                            return;
                        }
                        break;
                    
                    case 2: //! Employee
                        if (employee.login("employee"))
                        { 
                           employee.employeeMenuChoice();
                        }
                        else
                        {
                            general.printLine(50 , '-');
                            return;
                        } 
                        break;
                    
                    case 3: //! Manager
                        if (manager.Mnglogin())
                        { 
                           manager.managerMenuChoice();
                        }
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
        void mainMenuChoice() //! Every operations we gonna do in the program are here
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
    





    return 0;
}