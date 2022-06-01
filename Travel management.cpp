#include<fstream>
#include<iomanip>
#include<windows.h>
#include<iostream>

using namespace std;

void menu();
class ManageMenu
{
protected:
    string userName; //hide admin name

public:

    //virtual void menu(){}

    ManageMenu()
    {
        system("color 03"); //change terminal color
        cout<< "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin>> userName;
        system("CLS");
        menu(); //call to main function to load after executing the constructr
    }

    ~ManageMenu(){} //de
};


class Customer
{
	private:
		string name, age, gender;
		int phoneNumber;
    	static int cusID;//save and keep last value of cusID if not in new funtion, will initialize new object and value of cusID also re-initialize 
    	char all[999];
	public:
		
    	void getDetails()
    	{
        	ofstream out("old-customers.txt", ios::app); //open file using append mode to write customer details
        	{
            	cout<< "\nEnter Customer ID: ";
            	cin>> cusID;
            	cout<< "Enter Name: ";
            	cin>> name;
            	cout<< "Enter Age: ";
            	cin>> age;
            	cout<< "Enter Mobile Number: ";
            	cin>> phoneNumber;
            	cout<< "Gender: ";
            	cin>> gender;
        	}
        	out<< "\nCustomer ID: "<< cusID<< "\nName: "<< name<< "\nAge: "<< age<< "\nPhone Number: "<< phoneNumber<< "\nGender: "<< gender << endl;
        	out.close();
        	cout<< "\nSaved \nNOTE: We save your details record for future purposes.\n"<< endl;
    	}
    	void showDetails() //function to show old customer records
    	{
        	ifstream in("old-customers.txt");
        	{
            	if(!in)
            	{
                	cout<< "File Error!"<< endl;
            	}
            	while(!(in.eof()))
            	{
                	in.getline(all, 999);
                	cout<< all<< endl;
            	}
            	in.close();
        	}
    	}
    	static int get_cusID()
    	{
    		return cusID;
		}
};
int Customer::cusID;

class Cabs
{
	private:
    	int cabChoice;
    	int kilometers;
    	float cabCost;
    	static float lastCabCost;//save and keep last value of lastCabCost if not in new funtion, will initialize new object and value of lastCabCost also re-initialize
	public:
    	void cabDetails()
    	{
        	cout<< "We collaborated with fastest, safest, and smartest cab service arround the country"<< endl;
        	cout<< "-----------Vuong Cabs-----------\n"<< endl;
        	cout<< "1. Rent a Standard Cab - 50.000VND per 1KM"<< endl;
        	cout<< "2. Rent a Luxury Cab - 150.000VND per 1KM"<< endl;
			cout<< "3. Back"<< endl;

        	cout << "\nCalculate the cost for your journey.." << endl;
        	cout << "Enter which kind of cab you need: ";
        	cin >> cabChoice;
        	if(cabChoice == 3)
        	{
        		system("CLS");
        		menu();
			}
        	cout<< "Enter Kilometers you have to travel: ";
        	cin>> kilometers;

        	int hireCab;

        	if(cabChoice == 1)
			{
            	cabCost = kilometers * 50000;
            	cout<< "\nYour tour will cost "<< cabCost<< " VND for a standard cab"<< endl;
            	cout<< "Press 1 to hire this cab: or ";
            	cout<< "Press 2 to select another cab: ";
            	cin>> hireCab;
            	system("CLS");
            	if (hireCab == 1)
				{
                	lastCabCost = cabCost;
                	cout<< "\nYou have successfully hired standard cab"<< endl;
                	cout<< "Goto Menu to take the receipt"<< endl;
            	}
            	else if(hireCab == 2)
				{
                	cabDetails();
            	}
            	else
				{
                	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
                	Sleep(1100);
                	system("CLS");
                	cabDetails();
            	}
        	}
        	else if(cabChoice == 2)
			{
            	cabCost = kilometers * 150000;
            	cout<< "\nYour tour will cost "<< cabCost<< " VND for a luxury cab"<< endl;
            	cout<< "Press 1 to hire this cab: or ";
            	cout<< "Press 2 to select another cab: ";
            	cin>> hireCab;
            	system("CLS");
            	if (hireCab == 1)
				{
                	lastCabCost = cabCost;
                	cout<< "\nYou have successfully hired luxury cab"<< endl;
                	cout<< "Goto Menu to take the receipt"<< endl;
            	}
            	else if(hireCab == 2)
				{
                	cabDetails();
            	}
            	else
				{
                	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
                	Sleep(1100);
                	system("CLS");
                	cabDetails();
            	}
        	}
        	else
			{
            	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
            	Sleep(1100);
           	    system("CLS");
            	menu();
        	}

        	cout<< "\nPress 1 to Redirect Main Menu: ";
        	cin>> hireCab;
        	system("CLS");
        	if(hireCab == 1)
			{
            	menu();
        	}
        	else
			{
            	menu();
        	}
    	}
    	static float get_lastCabCost()
    	{
    		return lastCabCost;
		}
};

float Cabs::lastCabCost;

class Booking
{
	private:
    	int choiceHotel;
    	int packChoice1;
    	int gotoMenu;
    	static float hotelCost;//save and keep last value of hotelCost if not in new funtion, will initialize new object and value of hotelCost also re-initialize
	public:
    	void hotels()
    	{
        	string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        	for(int i = 0; i < 3; i++)
        	{
            	cout<< (i + 1)<< ". Hotel "<< hotelNo[i]<< endl;
       		}
       		cout<< "4. Back"<< endl;

        	cout<< "\nCurrently we collaborated with above hotels!"<< endl;

        	cout<< "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        	cin>> choiceHotel;
        	if(choiceHotel == 4)
        	{
        		system("CLS");
        		menu();
        	}

        	system("CLS");

        	if(choiceHotel == 1)
			{
            	cout<< "-------WELCOME TO HOTEL Avendra-------\n"<< endl;

            	cout<< "The Garden, food and beverage. Enjoy all you can drink, stay cool and get chilled in the summer sun."<< endl;

            	cout<< "Packages offered by Avendra:\n"<< endl;

            	cout<< "1. Standard Pack"<< endl;
            	cout<< "\tAll basic facilities you need just for: 500.000VND"<< endl;
            	cout<< "2. Premium Pack" << endl;
            	cout<< "\tEnjoy Premium: 1.000.000VND"<< endl;
            	cout<< "3. Luxury Pack"<< endl;
            	cout<< "\tLive a Luxury at Avendra: 1.500.000VND"<< endl;


            	cout<< "\nPress another key to back or\nEnter Package number you want to book: ";
           		cin>> packChoice1;

            	if (packChoice1 == 1)
				{
                	hotelCost = 500000;
                	cout<< "\nYou have successfully booked Standard Pack at Avendra"<< endl;
                	cout<< "Goto Menu and take the receipt"<< endl;
            	}
            	else if (packChoice1 == 2){
                	hotelCost = 1000000;
                	cout<< "\nYou have successfully booked Premium Pack at Avendra"<< endl;
                	cout<< "Goto Menu and take the receipt"<< endl;
            	}
            	else if (packChoice1 == 3)
				{
                	hotelCost = 1500000;
                	cout<< "\nYou have successfully booked Luxury Pack at Avendra"<< endl;
                	cout<< "Goto Menu to take the receipt"<< endl;
            	}
            	else
				{
                	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
                	Sleep(1100);
                	system("CLS");
                	hotels();

            	}

            	cout<< "\nPress 1 to Redirect Main Menu: ";
            	cin>> gotoMenu;
            	system("CLS");
            	if(gotoMenu == 1)
				{
                	menu();
            	}
            	else
				{
                	menu();
            	}
        	}
        	else if(choiceHotel == 2)
			{
            	cout<< "-------WELCOME TO HOTEL ChoiceYou-------\n"<< endl;

            	cout<< "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar"<< endl;

            	cout<< "Packages Offered by ChoiceYou:\n"<< endl;

            	cout<< "1. Family Pack"<< endl;
            	cout<< "\t 1.500.000VND for a day"<< endl;
            	cout<< "2. Couple Pack"<< endl;
            	cout << "\t 1.000.000 for a day"<< endl;
            	cout<< "3. Single Pack"<< endl;
            	cout<< "\t 500.000 for a day"<< endl;

            	cout<< "\nPress another key to back or\nEnter Package number you want to book: ";
            	cin>> packChoice1;

            	if (packChoice1 == 1)
				{
                	hotelCost = 1500000;
                	cout<< "You have successfully booked Family Pack at ChoiceYou"<< endl;
                	cout<< "Goto Menu and take the receipt"<< endl;
            	}
            	else if (packChoice1 == 2)
				{
                	hotelCost = 1000000;
                	cout<< "You have successfully booked Couple Pack at ChoiceYou"<< endl;
                	cout<< "Goto Menu and take the receipt"<< endl;
            	}
            	else if (packChoice1 == 3)
				{
                	hotelCost = 500000;
                	cout<< "You have successfully booked Single Pack at ChoiceYou"<< endl;
                	cout<< "Goto Menu and take the receipt"<< endl;
            	}
            	else
				{
                	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
                	Sleep(1100);
                	system("CLS");
                	hotels();
            	}

            	cout<< "\nPress 1 to Redirect Main Menu: ";
            	cin>> gotoMenu;
            	system("CLS");
            	if(gotoMenu == 1)
				{
                	menu();
            	}
            	else
				{
                	menu();
            	}
        	}
        	else if(choiceHotel == 3)
			{
            	cout<< "-------WELCOME TO HOTEL ELEPHANTBAY-------\n"<< endl;
            	cout<< "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants"<< endl;
            	cout<< "Amazing offer in this summer: 500.000VND for a one day!!!"<< endl;

            	cout<< "\nPress another key to back or\nPress 1 to book this special package: ";
            	cin>> packChoice1;

            	if (packChoice1 == 1)
				{
                	hotelCost = 500000;
                	cout<< "You have successfully booked ElephantBay Special Pack"<< endl;
                	cout<< "Goto Menu and take the receipt"<< endl;
            	}
            	else
				{
                	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
                	Sleep(1100);
                	system("CLS");
                	hotels();
            	}
            	cout<< "\nPress 1 to Redirect Main Menu: ";
            	cin>> gotoMenu;
            	system("CLS");
            	if(gotoMenu == 1)
				{
                	menu();
            	}
            	else
				{
                	menu();
            	}
        	}
        	else
			{
            	cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
            	Sleep(1100);
            	system("CLS");
            	menu();
        	}
    	}
    	static float get_hotelCost()
    	{
    		return hotelCost;
		}
};
float Booking::hotelCost;
class Chargers //Multiple Inheritance of some other classes to Chargers
{
	private:
		char all[999];

	public:

    	void printBill()
    	{
        	ofstream outf("receipt.txt"); //receipt for bought items
        	{
            	outf<< "--------VIENVUONG Travel Agency--------"<< endl;
            	outf<< "-------------Receipt-------------"<< endl;
            	outf<< "_________________________________"<< endl;

            	outf<< "Customer ID: "<< Customer::get_cusID()<< endl<< endl;
            	outf<< "Description\t\t Total"<< endl;
            	outf<< "Hotel cost:\t\t "<< fixed<< setprecision(2)<< Booking::get_hotelCost()<< endl;
            	outf<< "Travel (cab) cost:\t "<< fixed<< setprecision(2)<< Cabs::get_lastCabCost()<< endl;

            	outf<< "_________________________________"<< endl;
            	outf<< "Total Charge:\t\t "<< fixed<< setprecision(2)<< Booking::get_hotelCost()+Cabs::get_lastCabCost()<< " VND"<< endl;
            	outf<< "_________________________________"<< endl;
            	outf<< "------------THANK YOU------------"<< endl;
        	}
        	outf.close();
        //cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    	}

    	void showBill()
    	{
        	ifstream inf("receipt.txt");
        	{
            	if(!inf)
            	{
                	cout<< "File Error!"<< endl;
            	}
            	while(!(inf.eof()))
            	{
                	inf.getline(all, 999);
                	cout<< all<< endl;
            	}
        	}
        	inf.close();
    	}
};
void menu()
{
	int mainChoice;
    int inChoice;
    int gotoMenu;
    Customer customer;
    Cabs cabs;
    Booking booking;
    Chargers chargers;
	cout<< "\t\t* VIEN VUONG Travels *"<< endl;
	cout<< "----------------------Main Menu----------------------"<<endl;
	cout<< "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
	cout<< "\t|\t\t\t\t\t|"<<endl;
	cout<< "\t|\tCustomer Management -> 1\t|"<< endl;
	cout<< "\t|\tCabs Management     -> 2\t|"<< endl;
	cout<< "\t|\tBookings Management -> 3\t|"<< endl;
	cout<< "\t|\tCharges & Bill      -> 4\t|"<< endl;
	cout<< "\t|\tExit		    -> 5\t|"<<endl;
	cout<< "\t|\t\t\t\t\t|" << endl;
    cout<< "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl<<endl;
	cout<< "Enter Choice: ";
	cin>> mainChoice;
	if(mainChoice == 1)
	{
		system("CLS");
		cout<< "------Customers------\n"<< endl;
        cout<< "1. Enter New Customer"<< endl;
        cout<< "2. See Old Customers"<< endl;
		cout<< "3. Back"<< endl;
        cout<< "\nEnter choice: ";
        cin>> inChoice;
       	system("CLS");
        if(inChoice == 1)
		{
            customer.getDetails();
        }
        else if(inChoice == 2)
		{
            customer.showDetails();
        }
        else
		{
            system("CLS");
            menu();
        }
        cout<< "Press 1 to Redirect Main Menu: ";
        cin>> gotoMenu;
        system("CLS");
        if(gotoMenu == 1)
		{
            menu();
        }
        else
		{
            menu();
        }
	}
    else if(mainChoice == 2)
	{
    	system("CLS");
        cabs.cabDetails();
    }
    else if(mainChoice == 3)
	{
    	system("CLS");
        cout<< "--> Book a Luxury Hotel using the System <--\n"<< endl;
        booking.hotels();
    }
    else if(mainChoice == 4)
	{
    	system("CLS");
        cout<< "-->Get your receipt<--\n"<< endl;
        chargers.printBill();
        cout<< "Your receipt is already printed you can get it from file path\n"<< endl;
        cout<< "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin>> gotoMenu;
        if(gotoMenu == 1)
		{
            system("CLS");
            chargers.showBill();
            cout<< "Press 1 to Redirect Main Menu: ";
            cin>> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
			{
                menu();
            }
            else
			{
                menu();
            }
        }
        else
		{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5)
	{
        cout<< "\n\n\t--GOOD-BYE!--"<< endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
	{
        cout<< "Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<< endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;
    return 0;
}
