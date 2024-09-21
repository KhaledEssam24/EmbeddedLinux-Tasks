#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <map>
#include <fstream>
#include <sstream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    static std::list<Contact> contacts;
public:
    Contact(std::string firstName,std::string lastName,std::string phoneNumber,std::string email)   :firstName(firstName),lastName(lastName),
                                                                                                    phoneNumber(phoneNumber),email(email){contacts.push_back(*this);}
    
    static void printContacts() {
        if (contacts.empty()) {
            std::cout << "No contacts found." << std::endl;
            return;
        }

        std::cout << "Contacts List:" << std::endl;
        for (const auto& contact : contacts) {
            std::cout << "First Name: " << contact.firstName << std::endl;
            std::cout << "Last Name: " << contact.lastName << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
    
    static void deleteContact(const std::string& firstName, const std::string& lastName) {
        for (auto it = contacts.begin(); it != contacts.end(); it++)
        {
            if(it->firstName==firstName && it->lastName==lastName) 
            {
                contacts.erase(it);
                return;
            }
        }
        
    }

    static void deleteAllContact() {
        contacts.clear();
        std::cout << "All contacts deleted." << std::endl;
    }

    static void searchContact(const std::string& firstName) {
        for (auto it = contacts.begin(); it != contacts.end(); it++)
        {
            if(it->firstName==firstName){
                std::cout << "First Name: " << it->firstName << std::endl;
                std::cout << "Last Name: " << it->lastName << std::endl;
                std::cout << "Phone Number: " << it->phoneNumber << std::endl;
                std::cout << "Email: " << it->email << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        }
    }

    static void searchContact(const std::string& firstName, const std::string& lastName) {
        for (auto it = contacts.begin(); it != contacts.end(); it++)
        {
            if(it->firstName==firstName && it->lastName==lastName){
                std::cout << "First Name: " << it->firstName << std::endl;
                std::cout << "Last Name: " << it->lastName << std::endl;
                std::cout << "Phone Number: " << it->phoneNumber << std::endl;
                std::cout << "Email: " << it->email << std::endl;
            std::cout << "-----------------------------" << std::endl;
            }
        }
    }
};

std::list<Contact> Contact::contacts;

void read_data() {
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        // Parse the full name (first and last names)
        std::stringstream ss(line);
        std::string temp,firstname="",lastname="",phonenumber="",email="";
        ss >> firstname >> lastname;

        // Read the optional fields (phone number and email)
        if (getline(file, line) && !line.empty()) {
            if (isdigit(line[0])) {
                phonenumber = line;
            } else if (line.find('@') != std::string::npos) {
                email = line;
            }
        }

        // Skip potential empty lines
        while (getline(file, line) && line.empty());

        Contact contact(firstname,lastname,phonenumber,email);
    }

    file.close();
}


// Function to convert a string to lowercase
std::string lower(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return result;
}

int main(){
    read_data();

    while (true)
    {
        std::cout<<"Welcome to your favourite address book!"<<std::endl;
        std::cout<<"What do you want?"<<std::endl;
        std::cout<<"|  List         "<<std::endl;
        std::cout<<"|  Add          "<<std::endl;
        std::cout<<"|  Delete       "<<std::endl;
        std::cout<<"|  Delete All   "<<std::endl;
        std::cout<<"|  Search       "<<std::endl;
        std::cout<<"|  Close        "<<std::endl;
        
        std::string input;
        std::cin>>input;
        
        if(lower(input) == "list")   
        {
            Contact::printContacts();
        }

        else if (lower(input) == "add") 
        {
            std::string firstname="",lastname="",phonenumber="",email="";
            while (1)
            {     
                std::cout<<"Enter firstname : ";
                std::cin>>firstname;
                if(firstname=="")
                {
                    std::cout<<"Invalid! Enter firstname : ";
                    continue;
                } 
                else break;
            }

            while (1)
            {     
                std::cout<<"Enter lastname : ";
                std::cin>>lastname;
                if(lastname=="")
                {
                    std::cout<<"Invalid! Enter lastname : ";
                    continue;
                } 
                else break;
            }   

            std::cout << "Enter phone number (or press Enter to skip): ";
            std::cin.ignore(); // Ignore leftover newline character from previous input
            std::getline(std::cin, phonenumber);

            std::cout << "Enter email (or press Enter to skip): ";
            std::getline(std::cin, email);
            
            Contact contact(firstname,lastname,phonenumber,email);
        }

        else if (lower(input) == "deleteall")
        {
            Contact::deleteAllContact();
        }

        else if (lower(input) == "delete") 
        {
            std::string firstname="",lastname="",phonenumber="",email="";
            while (1)
            {     
                std::cout<<"Enter firstname : ";
                std::cin>>firstname;
                if(firstname=="")
                {
                    std::cout<<"Invalid! Enter firstname : ";
                    continue;
                } 
                else break;
            }

            while (1)
            {     
                std::cout<<"Enter lastname : ";
                std::cin>>lastname;
                if(lastname=="")
                {
                    std::cout<<"Invalid! Enter lastname : ";
                    continue;
                } 
                else break;
            }   
            
            Contact::deleteContact(firstname,lastname);
        }

        else if (lower(input) == "search")
        {
            std::string firstname, lastname;

            std::cout << "Enter firstname: ";
            std::cin >> firstname;

            std::cout << "Enter lastname (optional): ";
            std::cin.ignore();
            std::getline(std::cin, lastname);

            if (lastname.empty())
            {
                Contact::searchContact(firstname);
            }
            else
            {
                Contact::searchContact(firstname, lastname);
            }        
        }

        else if (lower(input) == "close")
        {
            std::cout<<"Closing Bye!"<<std::endl;
            break;
        }
    }
    return 0;
}
