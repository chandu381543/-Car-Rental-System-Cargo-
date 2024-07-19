#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <windows.h>

using namespace std;

void menu();
void adminpass();
void admin();
void newadmin();
void showcardata();
void addcar();
void delcar();
void resetcar();
void user();
void existinguser();
void newuser();
void tnc();
/***/
void invoice();
void userdata();
void availablecar();
void displayavilablecar();
void displaycar();
void cardata();
int countuser();
int countcar();
int countavailable();
int custcount();
int rate(int hour, int j);

struct car
{
	char plate_num[10];
	char brand[20];
	char model[20];
	int capacity;
	char colour[20];
	float rate_per_hour;
	float rate_per_half;
	float rate_per_day;
	char transmission[20];
   
};

struct customer
{
	int id;
	char name[100];
	char phone[15];
	char license[15];
	char address[1500];
};

struct pass
{
	int ID;
	char passWord[20];
	
};

	pass userPass[100];
	car rent[100];
	customer cust[100];
	car avail[100];

int rate(int hour, int j)
{
	int hour_24, hour_12, hour_1;
	int total, total_24, total_12, total_1;
	
	hour_24=hour/24;
	hour_12=(hour - hour_24*24)/12;
	hour_1=(hour - hour_24*24 - hour_12*12)/1;
	
	total_24 = hour_24 * rent[j].rate_per_day;
	total_12 = hour_12 * rent[j].rate_per_half;
	total_1 = hour_1 * rent[j].rate_per_hour;
	
	total = total_24 + total_12 + total_1;
	return total;
}

void menu()
    {
        int x;
	
	
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. ADMIN";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. USER";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. EXIT";
    cout<<"\n\t  \t\t\t\t\t\t\t  4. MENU"<<endl<<"\n";
	cout<<"\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	
	
	system("cls");
	
	if (x==2)
	{
		user();
	}
	
	else if (x==1)
	{
		adminpass();
	}
	
	else if (x==3)
	{
		cout << "\n\n\n\n";
		
		Sleep(1000);
		exit(0);
	}
		
	else if (x==4)
	{
		
		menu();
	}		
		
    }
    
void tnc()
{
	cout<<endl;
	cout<<"\n\t  \t\t\t1. MINIMUM TIME TO RENT A CAR IS 3 HOURS ";
	cout<<"\n\t  \t\t\t2. ANY PENALTIES LEVIED SHOULD BE PAID BY THE CUSTOMER";
	cout<<"\n\t  \t\t\t3. INCASE OF ACCIDENT,INCURRED LOSSES SHOULD BE PAID BY THE CUSTOMER";
	cout<<"\n\t  \t\t\t4. LISTED DOCUMENTS ARE MANDATORY";
	cout<<"\n\t  \t\t\t     \3COPY OF LICENSE";
	cout<<"\n\t  \t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
	cout<<"\n\t  \t\t\t5. ADDITIONAL CHAGES SHALL BE LAID  IN CASE OF LATE RETURNING";
	cout<<"\n\t  \t\t\t6. WEAR SEATBELT & DRIVE SAFE";
	cout<<"\n\n\n\n\t  \t\t\t                             PRESS ANY KEY TO CONTINUE :)";
	cout<<"\n\t  \t\t\t                                                            ";
	
	getch();
	system("cls");
	menu();

}

void adminpass()
{
    countuser();
   string password;
   char c;
   
   cout << "\n\n\n\n\t  \t\t\tPASSWORD: ";

	while(c != '\r') //Loop until 'Enter' is pressed
         {
         c = getch();
         if(c == 0)
            {
            switch(getch())
               {
               default:
                  break;            
               };
            }
         else if(c == '\b')   //If the 'Backspace' key is pressed
            {
            if(password.size() != 0)  //If the password string contains data, erase last character
               {
               cout << "\b \b";
               password.erase(password.size() - 1, 1);
               }
            continue;
            }
         else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
            {
            password += c;
            cout << "*";
            }
         else
            continue;
         }
         
         for(int i=0; i<countuser();i++)
         {
         	if(password.compare(userPass[i].passWord)==0)
         	{
         		system("cls");
          		admin();
			 }
		 }
         
		 
          if(password == "Thomas")
          	{
          system("cls");
          admin();
      		}
      		
		  else
          cout<<"\n\t  \t\t\tWrong Password.. Call Administrator";
          cout<<"\n\t  \t\t\tReturning to Main Menu.."<<endl;
          cout<<"\n\t  \t\t\t";
		  Sleep(1000);
          cout<<"\n\t  \t\t\tPress Enter to Continue.";
          cout<<"\n\t  \t\t\t";
          getch();
          menu();
}

void admin()
{
	int x;
	cout<<"\n\n\n\n";
	
	cout << endl;
	
	cout<<"\n\t  \t\t\t\t\t\t\t  1. ADD ADMIN";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. SHOW DATA";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. ADD CAR";
	cout<<"\n\t  \t\t\t\t\t\t\t  4. DELETE CAR";
	cout<<"\n\t  \t\t\t\t\t\t\t  5. RESET AVAILABLE CAR";
	cout<<"\n\t  \t\t\t\t\t\t\t  6. LOG OUT"<<endl<<"\n";
	cout<<"\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	
	
	system("cls");
	
	if (x==6)
	{
		
		menu();
	}
	
	else if (x==2)
	{
		showcardata();
	}
	
	else if (x==3)
	{
		addcar();
	}
	
	else if (x==4)
	{
		delcar();
	}
	else if (x==1)
	{
		newadmin();
	}
	else if(x==5)
	system("cls");
		resetcar();
}

void newadmin()
{
	
	ofstream ofs;
	ofs.open("UserPass.txt", fstream::app);
	
	userPass[countuser()].ID = countuser()+1;
	
	
	string password;
	char c;
	
	cout << "\n\n\n\n\t  \t\t\tID(DEFAULT): "<<userPass[countuser()].ID;
	cout << "\n\t  \t\t\tADD PASSWORD: ";

	while(c != '\r') //Loop until 'Enter' is pressed
         {
         c = getch();
         if(c == 0)
            {
            switch(getch())
               {
               default:
                  break;            
               };
            }
         else if(c == '\b')   
            {
            if(password.size() != 0)  
               {
               cout << "\b \b";
               password.erase(password.size() - 1, 1);
               }
            continue;
            }
         else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
            {
            password += c;
            cout << "*";
            }
         else
            continue;
         }
	
	
	strcpy(userPass[countuser()].passWord,password.c_str());
	
	ofs<<userPass[countuser()].ID;
	ofs<<";";
	ofs<<userPass[countuser()].passWord;
	ofs<<endl;	
	
	system("cls");
	admin();

}

void showcardata()
{
	
	
	int x;
	cout<<"\n\n";

	cout << endl;
	
	cout << "\t    Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t    =======================================================================================================================" << endl;
	for (int i = 0; i < countcar(); i++)
	{
		cout << "\t\t " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t " << rent[i].model << "\t   " << rent[i].capacity << "\t     "
			 << rent[i].colour << "\t  " <<rent[i].rate_per_hour << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day 
			 << "\t\t       " << rent[i].transmission << endl;
	}
	cout << "\n\n";
	cout<<"\n\t  \t\t\t\t\t  1. BACK";
	cout<<"\n\t  \t\t\t\t\t  2. MAIN MENU"<<endl<<"\n\n";
	cout<<"\t  \t\t\t\t\tINPUT :";
	cin >> x;
	
	system("cls");
	
	if (x==1)
	{
		admin();
	}
	
	if (x==2)
	{
		menu();
	}
	
}

void addcar()
{
	cout<<"\n\n";

	cout << endl;
	
	ofstream ofs;
	ofs.open("car rental.csp" , fstream::app);
	ofs<<endl;
	
	int newCar = countcar() + 1;
	cout << "\n\n";
	cout << "\n\t  \t\t\t\t\t  Please enter the car data below : " << endl;
	
	cout << "\n\t  \t\t\t\t\t  Plate Number : ";
	cin >> ws;
	cin.getline(rent[newCar].plate_num,10);
	ofs << rent[newCar].plate_num;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Brand : ";
	cin.getline(rent[newCar].brand,20);
	ofs << rent[newCar].brand;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Model : ";
	cin.getline(rent[newCar].model,20);
	ofs << rent[newCar].model;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Capacity : ";
	cin >> rent[newCar].capacity;
	ofs << rent[newCar].capacity;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Colour : ";
	cin >> ws;
	cin.getline(rent[newCar].colour,20);
	ofs << rent[newCar].colour;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Rate Per Hour : ";
	cin >> rent[newCar].rate_per_hour;
	ofs << rent[newCar].rate_per_hour;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Rate Per 12 Hour : ";
	cin >> rent[newCar].rate_per_half;
	ofs << rent[newCar].rate_per_half;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Rate Per 24 Hour : ";
	cin >> rent[newCar].rate_per_day;
	ofs << rent[newCar].rate_per_day;
	ofs << " ";

	cout << "\t  \t\t\t\t\t  Tranmission (Auto/Manual/SemiAuto) : ";
	cin >> ws;
	cin.getline(rent[newCar].transmission,20);
	ofs << rent[newCar].transmission;
	
	
	ofs.close();
	system("cls");
	
	cardata();
	admin();
}

void delcar()
{
	char plate[10];
	
	ofstream ofs;
	ofs.open("temp.csp");
	
	cout<<"\n\n\n\n";
	
	cout << endl;
	displaycar();
	
	cout << "\n\n";
	cout << "\t   \t\tEnter the car plate number that are going to be deleted (CAPITAL LETTER W/OUT SPACE): "<<endl;
	cout<< "\t    \t\t\t\t\t\t\t";
	cin >> ws;
	cin.getline(plate,10);
	int x=countcar();
	for(int i = 0; i < countcar(); i++)
	{
		if (strcmp(plate,rent[i].plate_num) != 0)
		{
			ofs << rent[i].plate_num;
			ofs << " ";
			ofs << rent[i].brand;
			ofs << " ";
			ofs << rent[i].model;
			ofs << " ";
			ofs << rent[i].capacity;
			ofs << " ";
			ofs << rent[i].colour;
			ofs << " ";
			ofs << rent[i].rate_per_hour;
			ofs << " ";
			ofs << rent[i].rate_per_half;
			ofs << " ";
			ofs << rent[i].rate_per_day;
			ofs << " ";
			ofs << rent[i].transmission;
			if(i != countcar())
			{
				ofs<<endl;
			}
			
			
		}
	}
	
	ofs.close();
	
	remove("car rental.csp");
	rename("temp.csp","car rental.csp");
	
	
	system("cls");
	
	cardata();
	admin();
}

void resetcar()
{

	ofstream ofs;
	ofs.open("temp2.csp");
	
	for(int i = 0; i < countcar(); i++)
	{
			ofs << rent[i].plate_num;
			ofs << " ";
			ofs << rent[i].brand;
			ofs << " ";
			ofs << rent[i].model;
			ofs << " ";
			ofs << rent[i].capacity;
			ofs << " ";
			ofs << rent[i].colour;
			ofs << " ";
			ofs << rent[i].rate_per_hour;
			ofs << " ";
			ofs << rent[i].rate_per_half;
			ofs << " ";
			ofs << rent[i].rate_per_day;
			ofs << " ";
			ofs << rent[i].transmission;
			if(i != countcar())
			{
				ofs<<endl;
			}
			
			
		}
	
	
	
	
	ofs.close();
	remove("available.csp");
	rename("temp2.csp","available.csp");
	
	admin();
	
}

void user()
{
	
	int x;
	

	cout << endl;
	

	cout<<"\n\t  \t\t\t\t\t\t\t  1. NEW";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. EXISTING";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. MAIN MENU"<<endl;
	cout<<"\n\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;

	system("cls");
	if (x==1)
	{
		newuser();
	}
	
	else if (x==2)
	{
		system("cls");
		
		existinguser();
	}
	
	else if (x==3)
	{
		menu();
	}
	
	
}

void newuser ()
{
	cout<<"\n\n";
	
	cout << endl;
	
	availablecar();
	ofstream ofs,log;
	ofs.open("Customer.txt", fstream::app);
	log.open("Log.txt", fstream::app);
	ofs << endl;
	ofstream availTemp;
	availTemp.open("availtemp.csp");
	cout<<"\n\n\n\n";
	cout << endl;
	
	
	cust[custcount()].id = custcount() + 1001;
	ofs << cust[custcount()].id;
	ofs << ";";
	
	
	cout << "\n\n";
	cout << "\n\t  \t\t\t\t\t  Please enter the data below : " << endl;
	
	cout << "\n\t  \t\t\t\t\t  Name : ";
	cin >> ws;
	cin.getline(cust[custcount()].name,100);
	ofs << cust[custcount()].name<<";";
	log <<"\nNAME: "<< cust[custcount()].name;
	
	cout << "\t  \t\t\t\t\t  Phone Number : ";
	cin.getline(cust[custcount()].phone,15);
	ofs << cust[custcount()].phone;
	ofs << ";";
	log <<"\nPHONE: "<< cust[custcount()].phone;
	
	
	cout << "\t  \t\t\t\t\t  license : ";
	cin.getline(cust[custcount()].license,15);
	ofs << cust[custcount()].license;
	ofs << ";";
	log <<"\nIC: "<< cust[custcount()].license;
	
	cout << "\t  \t\t\t\t\t  Address : ";
	cin.getline(cust[custcount()].address,1500);
	ofs << cust[custcount()].address;
	
	ofs.close();
	
	
	system("cls");
	
	int tempCust, hour;
	char carSelect[10];
	tempCust = custcount() - 1;
	
	cout<<"\n\n\n\n";
	
	cout << endl;
	
	cout<<"\n\t  \t\t\tWELCOME ";
	cout << cust[tempCust].name;
	cout<<"\t  \tID ";
	cout << cust[tempCust].id;
	cout << "\n\n";
	
	displayavilablecar();
	
	cout<<"\n\n\t  \tPlease select car";
	cout<<"\n\t  \tPlate Number : ";
	cin >> ws;
	cin.getline(carSelect,10);
	
	int x=countavailable();
	
	for(int i = 0; i < countavailable(); i++)
	{
		if (strcmp(carSelect,avail[i].plate_num) != 0)
		{
			availTemp << avail[i].plate_num;
			availTemp << " ";
			availTemp << avail[i].brand;
			availTemp << " ";
			availTemp << avail[i].model;
			availTemp << " ";
			availTemp << avail[i].capacity;
			availTemp << " ";
			availTemp << avail[i].colour;
			availTemp << " ";
			availTemp << avail[i].rate_per_hour;
			availTemp << " ";
			availTemp << avail[i].rate_per_half;
			availTemp << " ";
			availTemp << avail[i].rate_per_day;
			availTemp << " ";
			availTemp << avail[i].transmission;
			if(i != countavailable())
			{
				availTemp<<endl;
			}
			
			
		}
	}
	
	ofs.close();
	
	remove("available.csp");
	rename("availtemp.csp","available.csp");
	
	cout << "\t  \tHours of rent : ";
	cin >> hour;
	int j;
	for(int i = 0; i < countcar(); i++)
	{
		if (strcmp(carSelect,rent[i].plate_num) == 0)
		{
			j = i;
			rate(hour,j);
			log<<"\nCAR: "<<rent[i].plate_num;
			log<<"\nBRAND: "<<rent[i].brand;
			log<<"\nMODEL: "<<rent[i].model;
			log <<"\nHOUR: "<< hour;
			log <<"\nPAYMENT: "<< rate(hour,j);
			
		}
	}
		
			
			
	cout << "\n\t  \tPrice for " << hour << " hours of rent : RM ";
	cout << rate(hour,j);
	
	log<<"\n==========================================================";
	log.close();
	availTemp.close();
	availablecar();
	
	Sleep(5000);
	system("cls");
	menu();
}

void existinguser()
{
	
	
	int tempCust, hour, userID;
	char carSelect[10];
	tempCust = custcount() - 1;
	ofstream log;
	log.open("Log.txt", fstream::app);
	ofstream ofs;
	ofs.open("temp.csp");
	cout<<"\n\n\n\n";
	cout << endl;
	
	cout<<"\n\n";
	
	cout << endl;
	
	cout << "\n\t  \t\t\t\tPlease enter user ID : ";
	cin >> userID;
	
	for (int i = 0 ; i < custcount() ; i++)
	{
		if (userID == cust[i].id)
		{
			cout<<"\n\t  \t\t\t\t\tWELCOME ";
			cout << cust[i].name;
			log <<"\nNAME: "<< cust[i].name;
			cout<<"\t  \tID ";
			cout << cust[i].id;
			cout << "\n\n";
			log<<"\nPHONE: "<<cust[i].phone;
			log<<"\nIC: "<<cust[i].license;
		}
	}
	
	
	displayavilablecar();
	
	cout<<"\n\n\t  \t\t\t\t\tPlease select car";
	cout<<"\n\t  \t\t\t\t\tPlate Number : ";
	cin >> ws;
	cin.getline(carSelect,10);
	int x=countavailable();
	for(int i = 0; i < countavailable(); i++)
	{
		if (strcmp(carSelect,avail[i].plate_num) != 0)
		{
			ofs << avail[i].plate_num;
			ofs << " ";
			ofs << avail[i].brand;
			ofs << " ";
			ofs << avail[i].model;
			ofs << " ";
			ofs << avail[i].capacity;
			ofs << " ";
			ofs << avail[i].colour;
			ofs << " ";
			ofs << avail[i].rate_per_hour;
			ofs << " ";
			ofs << avail[i].rate_per_half;
			ofs << " ";
			ofs << avail[i].rate_per_day;
			ofs << " ";
			ofs << avail[i].transmission;
			if(i != countavailable())
			{
				ofs<<endl;
			}
			
			
		}
	}
	
	ofs.close();
	
	remove("available.csp");
	rename("temp.csp","available.csp");
	cout << "\t  \t\t\t\t\tHours of rent : ";
	cin >> hour;
	int j;
	for(int i = 0; i < countcar(); i++)
	{
		if (strcmp(carSelect,rent[i].plate_num) == 0)
		{
			j = i;

			log<<"\nCAR: "<<rent[i].plate_num;
			log<<"\nBRAND: "<<rent[i].brand;
			log<<"\nMODEL: "<<rent[i].model;
			log <<"\nHOUR: "<< hour;
			log <<"\nPAYMENT: "<< rate(hour,j);
		}
	}
	
	cout << "\t  \t\t\t\tPrice for " << hour << " hours of rent : RM ";
	cout << rate(hour,j);
	
	log<<"\n==========================================================";
	log.close();

	Sleep(5000);
	system("cls");
	menu();
}

void cardata()
{
	ifstream ifs;
	ifs.open("car rental.csp");
	int carNum = 0;
	
	while(!ifs.eof())
	{
		ifs.getline(rent[carNum].plate_num,10,' ');
		ifs.getline(rent[carNum].brand,20,' ');
		ifs.getline(rent[carNum].model,20,' ');
		ifs >> rent[carNum].capacity;
		ifs.ignore();
		ifs.getline(rent[carNum].colour,20,' ');
		ifs >> rent[carNum].rate_per_hour;
		ifs.ignore();
		ifs >> rent[carNum].rate_per_half;
		ifs.ignore();
		ifs >> rent[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(rent[carNum].transmission,6);
		carNum++;
		ifs>>ws;
	}
	
	ifs.close();
}

void availablecar()
{
	ifstream ifs;
	ifs.open("available.csp");
	int carNum = 0;
	
	while(!ifs.eof())
	{
		ifs.getline(avail[carNum].plate_num,10,' ');
		ifs.getline(avail[carNum].brand,20,' ');
		ifs.getline(avail[carNum].model,20,' ');
		ifs >> avail[carNum].capacity;
		ifs.ignore();
		ifs.getline(avail[carNum].colour,20,' ');
		ifs >> avail[carNum].rate_per_hour;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_half;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(avail[carNum].transmission,6);
		carNum++;
		ifs>>ws;
	}
	
	ifs.close();
}

void displayavilablecar()
{
	cout << "\t    Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t    =======================================================================================================================" << endl;
	for (int i = 0; i < countavailable(); i++)
	{
		cout << "\t     " << avail[i].plate_num << "\t\t" << avail[i].brand << "\t " << avail[i].model << "\t   " << avail[i].capacity << "\t     "
			 << avail[i].colour << "\t  " <<avail[i].rate_per_hour << "\t\t    " << avail[i].rate_per_half << "\t\t    " << avail[i].rate_per_day 
			 << "\t\t       " << avail[i].transmission << endl;
	}
}

int countcar()
{
	int numOfCar = 0;
	ifstream ifs("car rental.csp"); 

	string word;
	while (getline(ifs, word))
	{
    	if (!word.empty())
        	numOfCar++;
	}
	
	ifs.close();

	return numOfCar;
}

int custcount()
{
	int numOfCust = 0;
	ifstream ifs("Customer.txt"); 

	string word;
	while (getline(ifs, word))
	{
    	if (!word.empty())
        	numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

int countuser()
{
	int numOfCust = 0;
	ifstream ifs("UserPass.txt"); 

	string word;
	while (getline(ifs, word))
	{
    	if (!word.empty())
        	numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

int countavailable()
{
	int numOfCust = 0;
	ifstream ifs("available.csp"); 

	string word;
	while (getline(ifs, word))
	{
    	if (!word.empty())
        	numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

void userdata()
{
	ifstream ifs;
	ifs.open("Customer.txt");
	int custNum = 0;
	
	while (!ifs.eof())
	{
		ifs >> cust[custNum].id;
		ifs.ignore();
		ifs.getline(cust[custNum].name,100,';');
		ifs.getline(cust[custNum].phone,15,';');
		ifs.getline(cust[custNum].license,15,';');
		ifs.getline(cust[custNum].address,1500);
		custNum++;
	}
	
	ifs.close();
}

void displaycar()
{
	cout << "\t    Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t    =======================================================================================================================" << endl;
	for (int i = 0; i < countcar(); i++)
	{
		cout << "\t     " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t " << rent[i].model << "\t   " << rent[i].capacity << "\t     "
			 << rent[i].colour << "\t  " <<rent[i].rate_per_hour << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day 
			 << "\t\t       " << rent[i].transmission << endl;
	}
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