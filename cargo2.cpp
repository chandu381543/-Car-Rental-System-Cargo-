#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <sstream>
#include <ctime>

using namespace std;

void menu();
void adminpass();
void admin();
void newadmin();
void showcardata();
void addcar();
void delcar();
void resetcar();
void employeelogin();
void newemployee(); 
void employee();
void user();
void existinguser();
void newuser();
void tnc();
void availablecar();
void displayavailablecar();
void displaycar();
int rate();
int countcar();
int  countadmin();
int  usercount();
int countavailable();
string date();
void welcome();

void welcome()
{

}

int countadmin()
{
	int numOfCust = 0;
	ifstream ifs("adminpass.txt"); 

	string word;
	while (getline(ifs, word))
	{
    	if (!word.empty())
        	numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

string date()
    {
        time_t now = time(0);

  

   tm *ltm = localtime(&now);

  
   cout << "Date:" <<  ltm->tm_mday <<"-" << 1 + ltm->tm_mon <<"-"<<1900 + ltm->tm_year<< endl;
   cout << "Time: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
   
    }

void tnc()
{
    cout << endl;
    cout << endl;
   date();

	cout << endl;
	cout << "\n\t  \t\t\t1. MINIMUM TIME TO RENT A CAR IS 3 HOURS ";
	cout << "\n\t  \t\t\t2. ANY PENALTIES LEVIED SHOULD BE PAID BY THE CUSTOMER";
	cout << "\n\t  \t\t\t3. INCASE OF ACCIDENT,INCURRED LOSSES SHOULD BE PAID BY THE CUSTOMER";
	cout << "\n\t  \t\t\t4. LISTED DOCUMENTS ARE MANDATORY";
	cout << "\n\t  \t\t\t     \3COPY OF LICENSE";
	cout << "\n\t  \t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
	cout << "\n\t  \t\t\t5. ADDITIONAL CHAGES SHALL BE LAID  IN CASE OF LATE RETURNING";
	cout << "\n\t  \t\t\t6. WEAR SEATBELT & DRIVE SAFE";
	cout << "\n\n\n\n\t  \t\t\t                             PRESS ANY KEY TO CONTINUE :)";
	cout << "\n\t  \t\t\t                                                            ";

	getch();
	system("cls");
	menu();
}

void menu()
{
    cout << endl;
    cout << endl;
    date();

	int x;

	cout << endl;
	cout << "\n\t  \t\t\t\t\t\t\t  1. ADMIN";
	cout << "\n\t  \t\t\t\t\t\t\t  2. EMPLOYEE";
	cout << "\n\t  \t\t\t\t\t\t\t  3. USER";
	cout << "\n\t  \t\t\t\t\t\t\t  4. T&C";
	cout<<  "\n\t  \t\t\t\t\t\t\t  5.EXIT" << endl
		 << "\n";
	cout << "\n\t  \t\t\t\t\t\t\tINPUT :";
	cin >> x;

	system("cls");

	if (x == 3)
	{
		user();
	}

	else if (x == 1)
	{
		adminpass();
	}

	else if (x == 4)
	{
		tnc();
		
	}
	else if(x==2)
	{
       employeelogin();
	}

	else if (x == 5)
	{
        cout << "\n\n\n\n";
        cout<<"\t\t\tThank You :)\n";
		Sleep(1000);
		exit(0);
	}
}

void adminpass()
{

	string password, x;
	char c;
	
	cout << "\n\n\n\n\t  \t\t\tPASSWORD: ";

	while (c != '\r') //Loop until 'Enter' is pressed
	{
		c = getch();
		if (c == 0)
		{
			switch (getch())
			{
			default:
				break;
			};
		}
		else if (c == '\b') //If the 'Backspace' key is pressed
		{
			if (password.size() != 0) //If the password string contains data, erase last character
			{
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
		{
			password += c;
			cout << "*";
		}
		else
			continue;
	}

	std::ifstream file;

	if (password == "Thomas")
	{
		system("cls");
		admin();
	}
	else if (password != "Thomas")

	{
		ifstream read("adminpass.txt");
		while (getline(read, x, '\n'))
		{
			if (password == x)
			{
				system("cls");
				admin();
			}
		}
	}

	else
		cout << "\n\t  \t\t\tWrong Password.. Call Administrator";
	cout << "\n\t  \t\t\tReturning to Main Menu.." << endl;
	cout << "\n\t  \t\t\t";
	Sleep(1000);
	cout << "\n\t  \t\t\tPress Enter to Continue.";
	cout << "\n\t  \t\t\t";
	getch();
	menu();
}

void admin()
{

cout << endl;
cout << endl;
   date();

	int x;
	cout << "\n\n\n\n";

	cout << endl;

	cout << "\n\t  \t\t\t\t\t\t\t  1. ADD ADMIN";
	cout << "\n\t  \t\t\t\t\t\t\t  2. REGISTER EMPLOYEE";
	cout << "\n\t  \t\t\t\t\t\t\t  3. SHOW DATA";
	cout << "\n\t  \t\t\t\t\t\t\t  4. ADD CAR";
	cout << "\n\t  \t\t\t\t\t\t\t  5. DELETE CAR";
	cout << "\n\t  \t\t\t\t\t\t\t  6. RESET AVAILABLE CAR";
	cout << "\n\t  \t\t\t\t\t\t\t  7. LOG OUT" << endl
		 << "\n";
	cout << "\t \t\t\t\t\t\t\tINPUT :";
	cin >> x;
	system("cls");

	if (x == 1)
	{
		newadmin();
	}

	else if (x == 2)
	{
		newemployee();
	}


	else if (x == 3)
	{
		showcardata();
	}

	else if (x == 4)
	{
		addcar();
	}

	else if (x == 5)
	{
		delcar();
	}
	else if (x == 6)
	{
		system("cls");
		resetcar();
	}
	else if (x == 7)
		menu();
}

void newadmin()
{
    cout << endl;
    cout << endl;
    date();
    cout<<endl<<endl;
	string password;
	char c;

	ofstream ofs;
	ofs.open("adminpass.txt", ios::app | ios::app);

	cout << "\n\n\n\n\t  \t\t\tID(DEFAULT): "<<countadmin()+1;
	cout << "\n\t  \t\t\tADD PASSWORD: ";

	while (c != '\r') //Loop until 'Enter' is pressed
	{
		c = getch();
		if (c == 0)
		{
			switch (getch())
			{
			default:
				break;
			};
		}
		else if (c == '\b')
		{
			if (password.size() != 0)
			{
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
		{
			password += c;
			cout << "*";
		}
		else
			continue;
	}

	ofs << password << endl;
	ofs.close();
	system("cls");
	admin();
}

void employeelogin()
{
string password, x;
	char c;
	
	cout << "\n\n\n\n\t  \t\t\tPASSWORD: ";

	while (c != '\r') //Loop until 'Enter' is pressed
	{
		c = getch();
		if (c == 0)
		{
			switch (getch())
			{
			default:
				break;
			};
		}
		else if (c == '\b') //If the 'Backspace' key is pressed
		{
			if (password.size() != 0) //If the password string contains data, erase last character
			{
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
		{
			password += c;
			cout << "*";
		}
		else
			continue;
	}

	std::ifstream file;

	if (password == "Thomas")
	{
		system("cls");
		employee();
	}
	else if (password != "Thomas")

	{
		ifstream read("employeepass.txt");
		while (getline(read, x, '\n'))
		{
			if (password == x)
			{
				system("cls");
				employee();
			}
		}
	}

	else
		cout << "\n\t  \t\t\tWrong Password.. Call Administrator";
	cout << "\n\t  \t\t\tReturning to Main Menu.." << endl;
	cout << "\n\t  \t\t\t";
	Sleep(1000);
	cout << "\n\t  \t\t\tPress Enter to Continue.";
	cout << "\n\t  \t\t\t";
	getch();
	menu();
}

void employee()
{
	int x;
	cout << "\n\t  \t\t\t\t\t\t\t  1. SHOW DATA";
	cout << "\n\t  \t\t\t\t\t\t\t  2. ADD CAR";
	cout << "\n\t  \t\t\t\t\t\t\t  3. DELETE CAR";
	cout << "\n\t  \t\t\t\t\t\t\t  4. RESET AVAILABLE CAR";
	cout << "\n\t  \t\t\t\t\t\t\t  5. LOG OUT" << endl
		 << "\n";
    cout << "\t \t\t\t\t\t\t\tINPUT :";
    cin>>x;


		  if (x == 1)
	{
		showcardata();
	}

	else if (x ==2)
	{
		addcar();
	}

	else if (x == 3)
	{
		delcar();
	}
	else if (x == 4)
	{
		system("cls");
		resetcar();
	}
	else if (x == 5)
		menu();
}

void newemployee()
{
cout << endl;
    cout << endl;
    date();
    cout<<endl<<endl;
	string password;
	char c;

	ofstream ofs;
	ofs.open("employeepass.txt", ios::app | ios::app);

	//cout << "\n\n\n\n\t  \t\t\tID(DEFAULT): "<<countadmin()+1;
	cout << "\n\t  \t\t\tADD PASSWORD: ";

	while (c != '\r') //Loop until 'Enter' is pressed
	{
		c = getch();
		if (c == 0)
		{
			switch (getch())
			{
			default:
				break;
			};
		}
		else if (c == '\b')
		{
			if (password.size() != 0)
			{
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
		{
			password += c;
			cout << "*";
		}
		else
			continue;
	}

	ofs << password << endl;
	ofs.close();
	system("cls");
	employee();


}

void showcardata()
{
    cout << endl;
    cout << endl;
    date();
	string plate_num, brand, variant, eng_capacity, colour, price, transmission, seating_capacity, mileage;

	ifstream ifs;

	ifs.open("car rental.csv");

	cout << "\t    Plate Number\tBrand\t     Model\t    Capacity\t    Colour\t Rate Per Hour    Transmission     seating_capacity    mileage " << endl;
	cout << "\t    ===========================================================================================================================================" << endl;

	cout << endl
	
		 << endl
		 << endl;

	while (getline(ifs, plate_num, ','))
	{
		
		getline(ifs, brand, ',');
		getline(ifs, variant, ',');
		getline(ifs, eng_capacity, ',');
		getline(ifs, colour, ',');
		getline(ifs, price, ',');
		getline(ifs, transmission, ',');
		getline(ifs, seating_capacity, ',');
		getline(ifs, mileage, '\n');
        
		
	
		cout << "\t    " << plate_num << "\t     " << brand << "\t      " << variant << "\t  " << eng_capacity << "\t   "
			 << colour << "\t      " << price << "\t      " << transmission << "\t         " << seating_capacity
			 << "\t       " << mileage << endl;

	
		cout << "\n\n";
	}

	ifs.close();

	cout << "\n\t  \t\t\t\t\t  1. BACK";
	cout << "\n\t  \t\t\t\t\t  2. MAIN MENU" << endl
		 << "\n\n";
	cout << "\t  \t\t\t\t\tINPUT :";
	int x;
	cin >> x;

	system("cls");

	if (x == 1)
	{
		admin();
	}

	if (x == 2)
	{
		menu();
	}
}

void addcar()
{
    cout << endl;
    cout << endl;
    date();
	string brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	char plate_num[20];
	cout << "\n\n";

	cout << endl;

	fstream ifs, f;
	ofstream ofs;
	ofs.open("car rental.csv", fstream::app);
	ifs.open("available.csv", ios::out | ios::app);
	f.open("availTemp.csv",ios::out);

	cout << "\n\n";
	cout << "\n\t  \t\t\t\t\t  Please enter the car data below : " << endl;

	cout << "Plate number :: ";
	cin >> plate_num;
	ofs << plate_num;
	ofs << ",";
	ifs << plate_num;
	ifs << ",";
	f << plate_num;
	f << ",";

	cout << "Brand :: " << brand;
	cin >> brand;
	ofs << brand;
	ofs << ",";
	ifs << brand;
	ifs << ",";
	f << brand;
	f << ",";

	cout << "variant :: " << variant;
	cin >> variant;
	ofs << variant;
	ofs << ",";
	ifs << variant;
	ifs << ",";
	f << variant;
	f << ",";

	cout << "engine capacity :: " << eng_capacity;
	cin >> eng_capacity;
	ofs << eng_capacity;
	ofs << ",";
	ifs << eng_capacity;
	ifs << ",";
	f << eng_capacity;
	f << ",";

	cout << "colour  :: " << colour;
	cin >> colour,
		ofs << colour;
	ofs << ",";
	ifs << colour;
	ifs << ",";
	f << colour;
	f << ",";

	cout << "rate :: " << price;
	cin >> price;
	ofs << price;
	ofs << ",";
	ifs << price;
	ifs << ",";
	f << price;
	f << ",";

	cout << "transmission :: " << transmission;
	cin >> transmission;
	ofs << transmission;
	ofs << ",";
	ifs << transmission;
	ifs << ",";
	f << transmission;
	f << ",";

	cout << "seating capacity :: " << seating_capacity;
	cin >> seating_capacity;
	ofs << seating_capacity;
	ofs << ",";
	ifs << seating_capacity;
	ifs << ",";
	f << seating_capacity;
	f << ",";

	cout << "mileage :: ";
	cin >> mileage;
	ofs << mileage;
	ofs << "\n";
	ifs << mileage;
	ifs << "\n";
	f << mileage;
	f << "\n";

	ofs.close();
	ifs.close();
	f.close();
	system("cls");

	admin();
}

void delcar()
{
    cout << endl;
    cout << endl;
date();
	string brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	string plate, plate_num;

	fstream ofs, f;
	ofs.open("available.csv");
	f.open("temp.csv", ios::out);
	displayavailablecar();
	cout << "\n\n\n\n";

	cout << endl;
	cout << "\n\n";
	cout << "\t   \t\tEnter the car plate number that are going to be deleted (CAPITAL LETTER W/OUT SPACE): " << endl;
	cout << "\t    \t\t\t\t\t\t\t";
	cin >> plate;

	while (getline(ofs, plate_num, ','))
	{
		getline(ofs, brand, ',');
		getline(ofs, variant, ',');
		getline(ofs, eng_capacity, ',');
		getline(ofs, colour, ',');
		getline(ofs, price, ',');
		getline(ofs, transmission, ',');
		getline(ofs, seating_capacity, ',');
		getline(ofs, mileage, '\n');

		if (plate != plate_num)
		{
			f << plate_num << ',' << brand << ',' << variant << ',' << eng_capacity << ',';
			f << colour << ',' << price << ',' << transmission << ',' << seating_capacity << ',';
			f << mileage << endl;
		}
		
	}

	ofs.close();
	f.close();

	remove("available.csv");
	rename("temp.csv", "available.csv");

	system("cls");

	admin();
}

void resetcar()
{
	string plate_num, brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	fstream ofs, f;
	f.open("available.csv");
	ofs.open("temp2.csv");

	ofs << plate_num;
	ofs << " ";
	ofs << brand;
	ofs << " ";
	ofs << variant;
	ofs << " ";
	ofs << colour;
	ofs << " ";
	ofs << transmission;
	ofs << " ";
	ofs << eng_capacity;
	ofs << " ";
	ofs << price;
	ofs << " ";
	ofs << seating_capacity;
	ofs << " ";
	ofs << mileage;

	ofs.close();
	f.close();
	remove("available.csv");
	rename("temp2.csv", "available.csv");

	admin();
}

void user()
{
    cout << endl;
    cout << endl;
    date();
    cout<<endl<<endl;

	int x;

	cout << endl;

	cout << "\n\t  \t\t\t\t\t\t\t  1. NEW";
	cout << "\n\t  \t\t\t\t\t\t\t  2. EXISTING";
	cout << "\n\t  \t\t\t\t\t\t\t  3. MAIN MENU" << endl;
	cout << "\n\n\t  \t\t\t\t\t\t\tINPUT :";
	cin >> x;

	system("cls");
	if (x == 1)
	{
		newuser();
	}

	else if (x == 2)
	{
		system("cls");

		existinguser();
	}

	else if (x == 3)
	{
		menu();
	}
}

void newuser()
{
	string name, phone_num, license, address, id;
	string brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	string plate_num,id_proof;
    
	cout << "\n\n";
	cout << endl;

	

	ofstream ofs, log;
	ofs.open("Customer.txt", fstream::app);
	log.open("Log.txt", fstream::app);
	ofs << endl;
	fstream availTemp;
	availTemp.open("availtemp.csv");
	cout << "\n\n\n\n";
	cout << endl;
	

	cout << "\n\n";
	cout << "\n\t  \t\t\t\t\t  Please enter the data below : " << endl;

	cout << "\n\t  \t\t\t\t\t  Name : ";
	cin >> ws;
	cin >> name;
	ofs << name << ",";
	log << "\nNAME: " << name;

	cout << "\t  \t\t\t\t\t  Phone Number : ";
	cin >> phone_num;
	ofs << phone_num;
	ofs << ",";
	log << "\nPHONE: " << phone_num;

	cout << "\t  \t\t\t\t\t  license ID : ";
	cin >> license;
	ofs << license;
	ofs << ",";
	log << "\nLICENSE ID: " << license;

    cout << "\t  \t\t\t\t\t  ID Proof(Aadhar/Passport) : ";
	cin >> id_proof;
	ofs << id_proof;
	ofs << ",";
	log << "\n ID Proof(Aadhar/Passport) : " << id_proof;


	cout << "\t  \t\t\t\t\t  Address : ";
	cin >> address;
	ofs << address;
	ofs<<",";

	cout << "\t  \t\t\t\t\t  ID : ";
	cin >> id;
	ofs << id;
	ofs<<"\n";
	log << "\nID " << id;

	ofs.close();

	system("cls");

	int tempCust, hour;
	string carSelect;

    
	cout << "\n\n\n\n";

	cout << endl;

	cout << "\n\t  \t\t\tWELCOME ";
	cout << name;
	cout << "\t  \tID ";
	cout << id;
	cout << "\n\n";

	displayavailablecar();

	cout << "\n\n\t  \tPlease select car";
	cout << "\n\t  \tPlate Number : ";

	cin >> carSelect;
	cout << endl;
		
	int j = 0;
	while (getline(availTemp, plate_num, ','))
	{
		
		getline(availTemp, brand, ',');
		getline(availTemp, variant, ',');
		getline(availTemp, eng_capacity, ',');
		getline(availTemp, colour, ',');
		getline(availTemp, price, ',');
		getline(availTemp, transmission, ',');
		getline(availTemp, seating_capacity, ',');
		getline(availTemp, mileage, '\n');
		cout << endl
			 << endl
			 << endl
			 << endl
			 << endl;

		if (carSelect == plate_num)
		{
			cout << "\t  \tHours of rent : ";
			cin >> hour;

			
				j = stoi(price);

				log << "\nCAR: " << plate_num;
				log << "\nBRAND: " << brand;
				log << "\nMODEL: " << variant;
				log << "\nHOUR: " << hour;
				log << "\nPAYMENT: " << hour * j;
				
			


			cout << "\n\t  \tPrice for " << price << " hours of rent : " << hour * j;

			log << "\n==========================================================";
		}
	}

	
	
	log.close();
	availTemp.close();
	

	Sleep(5);

	cout << "\n\n\n\n\t  \t\t\t                             PRESS ANY KEY TO CONTINUE :)";
	getch();
	system("cls");
	menu();
}

void existinguser()
{
    cout << endl;
    cout << endl;
	string name, phone_num, license, address;
	string brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	string plate_num,id_proof;


cout<<"\n\n\n";
	int tempCust, hour, userID, id;
	string carSelect;
	ofstream log;
	log.open("Log.txt", fstream::app);
	fstream ofs,f;
	ofs.open("availTemp.csv");
	cout << "\n\n\n\n";
	cout << endl;
	cout << "\n\n";
	cout << endl;
	f.open("customer.txt");

	while (getline(f, name ,','))
	{
		getline(f,phone_num,','); 
		getline(f,license,',');
        getline(f,id_proof,','); 
		getline(f, address,',');
		f<<id;
		f<<'\n';
        
	}	

	cout << "\n\t  \t\t\t\tPlease enter user ID : ";
	cin >> userID;

	if (userID == id)
	{
		cout << "\n\t  \t\t\t\t\tWELCOME ";
		cout << name;
		log << "\nNAME: " << name;
		log << "\nPHONE: " << phone_num;
		log << "\n License: " << license;
		log << "\n ID Proof(Aadhar/Passport) : " << id_proof;
		cout << "\t  \tID ";
		cout << id;
		log <<id;
		cout << "\n\n";
		
		
	}


	displayavailablecar();

	cout << "\n\n\t  \t\t\t\t\tPlease select car";
	cout << "\n\t  \t\t\t\t\tPlate Number : ";
	cin >> ws;
	cin >> carSelect;
    int j = 0;
	while (getline(ofs, plate_num, ','))
	{
		
		getline(ofs, brand, ',');
		getline(ofs, variant, ',');
		getline(ofs, eng_capacity, ',');
		getline(ofs, colour, ',');
		getline(ofs, price, ',');
		getline(ofs, transmission, ',');
		getline(ofs, seating_capacity, ',');
		getline(ofs, mileage, '\n');
		cout << endl
			 << endl
			 << endl
			 << endl
			 << endl;

		if (carSelect == plate_num)
		{
			cout << "\t  \tHours of rent : ";
			cin >> hour;

			if (carSelect == plate_num)
			{
				j = stoi(price);

				log << "\nCAR: " << plate_num;
				log << "\nBRAND: " << brand;
				log << "\nMODEL: " << variant;
				log << "\nHOUR: " << hour;
				log << "\nPAYMENT: " << hour * j;
				cout << "\t  \t\t\t\tPrice for " << hour << " hours of rent :  ";
	            cout << hour ;

	log << "\n==========================================================";
	
			}
			
        }
    }

	
	log.close();
	ofs.close();

	Sleep(5);

	cout << "\n\n\n\n\t  \t\t\t                             PRESS ANY KEY TO CONTINUE :)";

	getch();
	system("cls");
	menu();
}

void availablecar()
{
    
	string plate_num, brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	fstream ifs, f;
	
	ifs.open("available.csv");

	int carNum = 0;

	while (getline(ifs, plate_num, ','))
	{
		
		getline(ifs, brand, ',');
		getline(ifs, variant, ',');
		getline(ifs, eng_capacity, ',');
		getline(ifs, colour, ',');
		getline(ifs, price, ',');
		getline(ifs, seating_capacity, ',');
		getline(ifs, mileage, '\n');
		carNum++;

		ifs << plate_num << ',' << brand << ',' << variant << ',' << eng_capacity << ',' << colour << ',' << price << ','
			<< seating_capacity << ',' << mileage << endl;
	}
	ifs.close();
	
}

void displayavailablecar()
{
cout << endl;
cout << endl;
    date();
    cout<<"\n\n\n";
	string plate_num, brand, variant, colour, transmission, eng_capacity, price, seating_capacity, mileage;
	fstream ifs, f;
	ifs.open("available.csv");

	int carNum = 0;

cout << "\t    Plate Number\tBrand\t     Model\t    Capacity\t    Colour\t Rate Per Hour    Transmission     seating_capacity    mileage " << endl;
	cout << "\t    ===========================================================================================================================================" << endl;

	while (getline(ifs, plate_num, ','))
	{
		
		getline(ifs, brand, ',');
		getline(ifs, variant, ',');
		getline(ifs, eng_capacity, ',');
		getline(ifs, colour, ',');
		getline(ifs, transmission, ',');
		getline(ifs, price, ',');
		getline(ifs, seating_capacity, ',');
		getline(ifs, mileage, '\n');

		


		cout << "\t    " << plate_num << "\t" << brand << "\t " << variant << "\t       " << eng_capacity << "\t     "
			 << colour << "\t      " << price << "\t      " << transmission << "\t\t  " << seating_capacity
			 << "\t\t  " << mileage << endl;

	}
	
	ifs.close();

	

}

void userdata()
{
	string name, phone_num, license, address, id;
	ifstream ifs;
	ifs.open("Customer.txt");
	int custNum = 0;

	while (!ifs.eof())
	{
		ifs >> id;
		ifs.ignore();
		ifs >> name;
		ifs.ignore();
		ifs >> phone_num;
		ifs.ignore();
		ifs >> license;
		ifs.ignore();
		ifs >> address;
		custNum++;
	}

	ifs.close();
}

void cardata()
{

	string plate_num, brand, variant, colour, transmission, eng_capacity, rate, seating_capacity, mileage;
	ifstream ifs;
	ifs.open("car rental.csv");
	int carNum = 0;

	while (!ifs.eof())
	{
		ifs >> plate_num;
		ifs.ignore();
		ifs >> brand;
		ifs.ignore();
		ifs >> variant;
		ifs.ignore();
		ifs >> colour;
		ifs.ignore();
		ifs >> transmission;
		ifs.ignore();
		ifs >> eng_capacity;
		ifs.ignore();
		ifs >> rate;
		ifs.ignore();
		ifs >> seating_capacity;
		ifs.ignore();
		ifs >> mileage;
		ifs.ignore();
		carNum++;
		ifs >> ws;
	}

	ifs.close();
}

 int main()
{
	tnc();
	menu();
	adminpass();
	userdata();
	cardata();
	availablecar();
	return 0;
} 
