#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person{
	string Email;
	string Password;
};

void lib(){
	fstream File2;
	
	File2.open("Books.txt", ios::in);
	
		if(File2.is_open()){
			string line;
			while(getline(File2, line)){
				cout << line << endl;
			}
			File2.close();

		}
}

void buyABook(){
	fstream File2;
	
	File2.open("Books.txt", ios::in);
	if(File2.is_open()){
		string bookNumber;
		cout << "Choose one book by a number (1, 2, 3, ...): ";
		cin >> bookNumber;
		
		string line, name;
		while(getline(File2, line)){
			char dot = '.';
		    size_t pos = line.find(dot);
		    if (pos!=string::npos){
		    name = line;
		    line = line.substr(0, pos);
		}
		    if(line == bookNumber){
		    	cout << "Your choose: " << name << endl;
			}
				
		}
		File2.close();
	}
	
}

void sellBookToLib(){
	fstream File3;
	string nameOfTheBook;
	string writer;
	File3.open("Books.txt", ios::app);
	if(File3.is_open()){
		cout << "Name of the book: ";
		cin >> nameOfTheBook;
		cout << "Writer: ";
		cin >> writer;
		string line;
		int i = 0;
		while(getline(File3, line)){
			
		}
		
		
	}
}

string line2;

int main() {
	fstream File;
	
	
	
	Person p;
	int option;
	begin:
	cout << "Press 1 for sign in, or 2 for sign up:" << endl;
	cin >> option;
	switch(option){
		case 1:
			File.open("Users.txt", ios::in);
			if(File.is_open()){
				string line;
				cout << "E-mail: ";
				cin >> p.Email;
				cout << "Password: ";
				cin >> p.Password;
				while(getline(File, line)){
					string person = p.Email + ", " + p.Password;
					if (line == person){
						cout << "Sign in was successfully\n\n" << endl;
						lib();
						buyABook();
						
						bool des;
						cout << "Do you want to sell a books to lib.? Yes(1)/No(0): ";
						cin >> des;
						if(des){
							sellBookToLib();
						} 
					}
				}
				
				while(getline(File, line)){
					string person = p.Email + ", " + p.Password;
					if (line != person){
						cout << "Sign in was not successfully\n" << endl;
						goto begin;
					}	
				}
				
				File.close();
			}
			
		
			break;
		case 2:
				cout << "Email: ";
				cin >> p.Email;
				cout << "Password: ";
				cin >> p.Password;
				
				File.open("Users.txt", ios::in);
				if(File.is_open()){
				string line;
				
				while(getline(File, line)){
					//////////
					char c = ',';
					size_t pos = line.find(c);
					if (pos!=string::npos){
						line = line.substr(0, pos);
					////////// Deleting all char. after ','
						line2 = line;
				    }
				}
				File.close();
				}
				File.open("Users.txt", ios::app);
				if(File.is_open()){
					if(line2 == p.Email){
						cout << "Email already exists.";
						}else{
						
						cout << "Sign up was successfully\n" << endl;
						File << p.Email + ", " + p.Password + "\n";
					}
					File.close();
				}
				goto begin;
				break;
			
			default:
				cout << "Try again!" << endl;
}

	return 0;
}
