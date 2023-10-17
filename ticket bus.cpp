#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<unistd.h>


using namespace std;

void DisplayAdmin(); //function prototype

class Bus // class first
{
	private :
		//attributes
		int BusNo;
		string DriverID;
		double TicketPrice;
		string Date;
		string FromStation;
		string Arrival;
		string DestinationStation;
		string Departure;
		
	public :
		Bus()
		{
			BusNo = 0;
			DriverID = "0000";
			TicketPrice = 0.0;
			Date = "";
			FromStation = "";
			Arrival = "";
			DestinationStation = "";
			Departure = "";
		}
		
		Bus(int a, string b, double e, string f, string g, string h, string i, string j)
		{
			BusNo = a;
			DriverID = b;
			TicketPrice = e;
			FromStation = f;
			Arrival = g;
			DestinationStation = h;	
			Departure = i;
			Date = j;
		}
		
		//////// Set //////////////
		void setBusNo(int a)
		{
			BusNo = a;
		}
		
		void setDriverID(string b)
		{
			DriverID = b;
		}
		
		void setFrom(string e)
		{
			FromStation = e;
		}
		
		void setArrival(string f)
		{
			Arrival = f;
		}
		
		 void setDestination(string g)
		{
			DestinationStation = g;
		}
		
		void setDeparture(string h)
		{
			Departure = h;
		}
		
		void setTicketPrice(double i)
		{
			TicketPrice = i;
		}
		
		void setDate(string j)
		{
			Date = j;
		}
		
		///////// get /////////////////
		int getBusNo()
		{
			return BusNo;
		}
		
		string getDriverID()
		{
			return DriverID;
		}
		
		string getFrom()
		{
			return FromStation;
		}
		
		string getDestination()
		{
			return DestinationStation;
		}
		
		double getTicketPrice()
		{
			return TicketPrice;
		}
		
		string getArrival()
		{
			return Arrival;
		}
		
		string getDeparture()
		{
			return Departure;
		}
		
		string getDate()
		{
			return Date;
		}
		
		////////function////////////
		
		virtual void Ticket(int a, string b)
		{
			cout<<"HELLO"<<endl;
		}
		
};

class BusA : public Bus //class second & inheritance
{
	private :
		int BasNo;
		string driverID;
		double ticketPrice;
		string date;
		string fromStation;
		string arrival;
		string destinationStation;
		string departure;
	
	protected :
		string seat[8][4];
		string Passengername[8][4];
		int seatno;
		
	public :
		BusA()
		{
			for(int x = 0; x < 8; x++)
			{
				for(int y = 0; y < 4; y++)
				{
					seat[x][y] = "O";
				}
			}
			
			for(int j = 0; j < 8; j++)
			{
				for(int k = 0; k < 4; k++)
				{
					Passengername[j][k]="Empty";
				}
			}
		}
		
		void setBusA(Bus obj)
		{
			BasNo = obj.getBusNo();
			driverID = obj.getDriverID();
			ticketPrice = obj.getTicketPrice();
			fromStation = obj.getFrom();
			arrival = obj.getArrival();
			destinationStation = obj.getDestination();	
			departure = obj.getDeparture();
			date = obj.getDate();
		}
		
		int getBasNo()
		{
			return BasNo;
		}
		
		void setPassengername(int a, string c)
		{
			seatno = a;
			Passengername[seatno/4][(seatno%4)-1] = c;
		}
		
		void setSeatname(int b)
		{
			seatno = b;
			seat[seatno/4][(seatno%4)-1] = "X";
		}
		
		string getSeatname(int c)
		{
			seatno = c;
			return seat[seatno/4][(seatno%4)-1];
		}
		
		string getPassengername(int d)
		{
			seatno = d;
			return Passengername[seatno/4][(seatno%4)-1];
		}
		
		void displaySeat()
		{
			int s = 0;
			
			for(int j = 0; j < 8; j++)
			{
				for(int p = 0; p < 4; p++)
				{
					s++;
					cout<<" "<<setw(10)<<s<<".  "<<seat[j][p]<<" ";	
				}
				cout<<endl;
			}
		}
		
		void Ticket(int a, string b)
		{
			cout<<"\n                     Bus Details"<<endl<<endl;
			for(int j = 0; j < 62; j++)
			{
				cout<<"%";
			}
			cout<<endl<<endl;
			cout<<"Name : "<<b<<endl;
			cout<<"Driver ID : "<<driverID<<right<<setw(30)<<"Arrival :"<<arrival<<endl;
			cout<<"No Bus : "<<BasNo<<right<<setw(38)<<"Departure :"<<departure<<endl;
			cout<<"Date : "<<date<<right<<setw(26)<<"No Seat :"<<a<<endl;
			cout<<"From : "<<fromStation<<right<<setw(38)<<"Destination : "<<destinationStation<<endl;
			cout<<"Price : RM"<<fixed<<showpoint<<setprecision(2)<<ticketPrice<<endl<<endl;

			for(int x = 0; x < 62; x++)
			{
				cout<<"%";
			}
		}
		
		friend ostream &operator<< (ostream &output, const BusA &d) //operator<< (cout)
    	{
			output<< endl
			<<"\n Bus No : "<<d.BasNo<<setw(42)<<"Arrival Time : "<<d.arrival
			<<"\n Date : "<<d.date<<setw(32)<<"Departure Time : "<<d.departure
			<<"\n From : "<<d.fromStation
			<<"\n Destination : "<<d.destinationStation
			<<"\n Price : RM "<<fixed<<showpoint<<setprecision(2)<<d.ticketPrice;		  	
		  	return output;
		}
		
};

class BusB : public Bus //class third & inheritance
{
	private :
		int basNo;
		string driveriD;
		double ticketprice;
		string date1;
		string fromstation;
		string arrival1;
		string destinationstation;
		string departure1;
		
	protected :
		string seat1[10][4];
		string Passname[10][4];
		int noseat;
		
	public :
		BusB()
		{
			for(int x = 0; x < 10; x++)
			{
				for(int y = 0; y < 4; y++)
				{
					seat1[x][y] = "O";
				}
			}
		}
		
		void setBusB(Bus obj)
		{
			basNo = obj.getBusNo();
			driveriD = obj.getDriverID();
			ticketprice = obj.getTicketPrice();
			fromstation = obj.getFrom();
			arrival1 = obj.getArrival();
			destinationstation = obj.getDestination();	
			departure1 = obj.getDeparture();
			date1 = obj.getDate();
		}
		
		int getbasNo()
		{
			return basNo;
		}
		
		void setPassname(int a, string c)
		{
			noseat = a;
			Passname[noseat/4][(noseat%4)-1] = c;
		}
		
		void setNamaseat(int b)
		{
			noseat = b;
			seat1[noseat/4][(noseat%4)-1] = "X";
		}
		
		string getNamaseat(int c)
		{
			noseat = c;
			return seat1[noseat/4][(noseat%4)-1];
		}
		
		string getPassname(int d)
		{
			noseat = d;
			return Passname[noseat/4][(noseat%4)-1];
		}
		
		void displaySeat()
		{
			int s = 0;
			
			for(int j = 0; j < 10; j++)
			{
				for(int p = 0; p < 4; p++)
				{
					s++;
					cout<<" "<<setw(10)<<s<<".  "<<seat1[j][p]<<" ";	
				}
				cout<<endl;
			}
		}
		
		void Ticket(int a, string b)
		{
			cout<<"\n                     Bus Details"<<endl<<endl;
			for(int j = 0; j < 62; j++)
			{
				cout<<"%";
			}
			cout<<endl<<endl;
			cout<<"Name : "<<b<<endl;
			cout<<"Driver ID : "<<driveriD<<right<<setw(30)<<"Arrival :"<<arrival1<<endl;
			cout<<"No Bus : "<<basNo<<right<<setw(38)<<"Departure :"<<departure1<<endl;
			cout<<"Date : "<<date1<<right<<setw(26)<<"No Seat :"<<a<<endl;
			cout<<"From : "<<fromstation<<right<<setw(38)<<"Destination : "<<destinationstation<<endl;
			cout<<setw(47)<<"Price : RM"<<fixed<<showpoint<<setprecision(2)<<ticketprice<<endl<<endl;
			for(int x = 0; x < 62; x++)
			{
				cout<<"%";
			}

		}
		
		friend ostream &operator<< (ostream &output, const BusB &d) //operator<< (cout)
    	{
			output<< endl
			<<"\n Bus No : "<<d.basNo<<setw(42)<<"Arrival Time : "<<d.arrival1
			<<"\n Date : "<<d.date1<<setw(32)<<"Departure Time : "<<d.departure1
			<<"\n From : "<<d.fromstation
			<<"\n Destination : "<<d.destinationstation
			<<"\n Price : RM "<<fixed<<showpoint<<setprecision(2)<<d.ticketprice;		  	
		  	return output;
		}
			
};

class DetailsBus //class fourth // aggregations
{
	public :
		
		void displaybus(Bus* bus1)
		{
			cout<<endl;
			for(int i = 0; i < 15; i++)
			{
				cout<<"-";
			}
			cout<<"AVAILABLE BUS";
			for(int i = 0; i < 15; i++)
			{
				cout<<"-";
			}
			cout<<endl;
			
				for(int j = 0; j < 62; j++)
				{
					cout<<"=";
				}
				cout<<endl;
				cout<<"Driver ID : "<<bus1->getDriverID()<<setw(30)<<"Arrival :"<<bus1->getArrival()<<endl;
				cout<<"No Bus : "<<bus1->getBusNo()<<setw(38)<<"Departure :"<<bus1->getDeparture()<<endl;
				cout<<"Date : "<<bus1->getDate()<<endl;
				cout<<setw(44)<<"From : "<<bus1->getFrom()<<endl;
				cout<<setw(51)<<"Destination : "<<bus1->getDestination()<<endl;
				cout<<setw(47)<<"Price : RM"<<fixed<<showpoint<<setprecision(2)<<bus1->getTicketPrice()<<endl;
				for(int x = 0; x < 62; x++)
				{
					cout<<"=";
				}
				cout<<endl<<endl;
		}
			
};

void TicketDisplay(Bus &objek, int a, string b) //function header for pass to virtual polymorphism
{
	objek.Ticket(a, b);
}

int main()
{
	
	Bus obj[5]={Bus(1, "0000", 25.50, "SKUDAI", "7.00AM","ALOR GAJAH","7.45AM", "23 APRIL 2022"), //initialize details buses using constructor parameters & object for class Bus
				Bus(2, "0001", 43.70, "SKUDAI", "8.45AM","BATU CAVES","9.00AM", "23 APRIL 2022"),
				Bus(3, "0002", 33.00, "SKUDAI", "9.30AM","SEREMBAN","10.00AM", "23 APRIL 2022"),
				Bus(4, "0003", 15.50, "SKUDAI", "9.45AM","MUAR","10.15AM", "23 APRIL 2022"),
				Bus(5, "0004", 30.00, "SKUDAI", "11.30AM","NILAI","12.00PM", "23 APRIL 2022")};
				
	BusA opt1[3]; //default constructor & object for class BusA
	BusB opt2[2]; //default constructor & object for class BusB
				
	int choice, busnumber, busnumber2;
	int busNo, seatnum;
	double price;
	string driverID, from, destination, arrival, departure, date, passengername; 
	char option1, option2,payment;
	
	MAINMENU :
	system("COLOR 4F"); //set background color
	cout<<"\t\tWELCOME TO KONOHA BUS STATION\t\t"<<endl;
	for(int i = 0; i<60; i++)
	{
		cout<<"=";
	}
	cout<<endl;
	cout<<"||                                                         ||\n";
	cout<<"||                                                         ||\n";
	cout<<"||               1- Bus Available                          ||\n";
	cout<<"||               2- Booking Bus                            ||\n";
	cout<<"||               3- Admin                                  ||\n";
	cout<<"||               4- Exit System                            ||\n";
	cout<<"||                                                         ||\n";
	cout<<"||                                                         ||\n";
	cout<<"||                                                         ||\n";
	for(int i = 0; i<60; i++)
	{
		cout<<"=";
	}	
	cout<<endl;		
	cout<<"Enter your choice  : ";
	cin>> choice;
	
	switch(choice)
	{
		case 1: // if user enter choice == 1
			{
				system("COLOR 1F"); //set background color
				system("cls");
				for(int i = 0; i<3; i++)
				{
					opt1[i].setBusA(obj[i]); //inheritance
				}
				
				opt2[0].setBusB(obj[3]); //inheritance
				opt2[1].setBusB(obj[4]);
				
				cout<<"\n                    BUS AVAILABLE                   "<<endl;
				for(int x = 0; x<3; x++)
				{
					for(int j = 0; j<60; j++)
					{
						cout<<"*";
					}
					cout<<opt1[x];
					cout<<endl;
				}
				
				for(int x = 0; x<2; x++)
				{
					for(int j = 0; j<60; j++)
					{
						cout<<"*";
					}
					cout<<opt2[x];
					cout<<endl;
				}
				
				for(int j = 0; j<60; j++)
					{
						cout<<"*";
					}
				
				cout<<endl;
				system("pause");
				system("cls");
				goto MAINMENU;
			}
			break;
		case 2 : // if user enter choice == 2
			{
				system("cls");
				for(int i = 0; i<3; i++)
				{
					opt1[i].setBusA(obj[i]); //inheritance object BusA with object Bus
				}
				
				opt2[0].setBusB(obj[3]); //inheritance object BusB with object Bus
				opt2[1].setBusB(obj[4]); //inheritance object BusB with object Bus
				
				RESERVATION :
				system("COLOR 5F");
				for(int y = 0; y<80; y++)
				{
					cout<<"%";
				}
				cout<<"\n\n\t\t  Enter bus number : ";
				cin>>busnumber2;
				
				if(busnumber2 >= 1 || busnumber <= 3) //compare bus number insert by user
				{					
					if(busnumber2 == opt1[busnumber2 - 1].getBasNo())
					{
						cout<<endl;
						opt1[busnumber2 - 1].displaySeat();
						cout<<"\n O -> Available || X -> Reserved\n\n";
						
						NAME :
						
						for(int y = 0; y<80; y++)
						{
							cout<<"%";
						}
						cout<<"\n\nPlease enter seat : ";
						cin>>seatnum;
						
						if(seatnum >= 1 && seatnum <= 32) //compare seat number insert by user
						{
							 
							if(opt1[busnumber2 - 1].getSeatname(seatnum) == "O")
							{
								cout<<"\nPlease enter name : ";
								cin.ignore(1,'\n');
								getline(cin, passengername);
								
								opt1[busnumber2 - 1].setSeatname(seatnum);
								opt1[busnumber2-1].setPassengername(busnumber2, passengername);
								
								//SINI
								system("cls");
								for(int y = 0; y<80; y++)
								{
									cout<<"%";
								}
								cout<<endl<<endl;
								opt1[busnumber2 - 1].displaySeat();
								
								PAYMENT :
								cout<<"\n\nYour seat has been reserved. Enter P to proceed for the payment : ";
								cin>>payment;
								
								if(payment == 'P' || payment == 'p')
								{
									system("cls");
								
									opt1[busnumber2 - 1].setBusA(obj[busnumber2-1]); //inheritance
									
									TicketDisplay(opt1[busnumber2 -1], seatnum, passengername); //polymorphism
									cout<<endl;
									cout<<"\nHere is your ticket. Thankyou for purchase with us :) !"<<endl<<endl;
									system("pause");
									system("cls");
								}
								else
								{
									goto PAYMENT;
								}
							
								goto MAINMENU;
								
							}
							else if(opt1[busnumber2 - 1].getSeatname(seatnum) == "X")
							{
								cout<<"\nThe seat no. is already reserved.\n";
								goto NAME;
							}	
						}
						else
						{
							cout<<"\nThere are only 32 seats available in this bus. \n";
							goto NAME;
						}
		
					}
				}
				if(busnumber2 == 4) //compare bus number insert by user
				{
					
						if(busnumber2 == opt2[0].getbasNo())
						{
							cout<<endl;
							opt2[0].displaySeat();
							cout<<"\n\n O -> Available || X -> Reserved\n\n";
							
							NAME1 :
							for(int y = 0; y<80; y++)
							{
								cout<<"%";
							}
							
							cout<<"\n\nPlease enter seat : ";
							cin>>seatnum;
							
							if(seatnum >= 1 && seatnum <= 40) //compare seat number insert by user
							{
								 
								if(opt2[0].getNamaseat(seatnum) == "O")
								{
									cout<<"\nPlease enter name : ";
									cin.ignore(1,'\n');
									getline(cin, passengername);
									
									opt2[0].setNamaseat(seatnum);
									opt2[0].setPassname(busnumber2, passengername);
									
									system("cls");
									for(int y = 0; y<80; y++)
									{
										cout<<"%";
									}
									cout<<endl<<endl;
									opt2[0].displaySeat();
									
									PAYMENT1 :
									cout<<"\n\nYour seat has been reserved. Enter P to proceed for the payment : ";
									cin>>payment;
									
									if(payment == 'P' || payment == 'p')
									{
										system("cls");
								
										opt2[0].setBusB(obj[3]); //inheritance
										
										TicketDisplay(opt2[0], seatnum, passengername); //polymorphism
										cout<<endl;
										system("pause");
										system("cls");
									}
									else
									{
										goto PAYMENT1;
									}
									
									goto MAINMENU;
										
									}
									else if(opt2[0].getNamaseat(seatnum) == "X")
									{
										cout<<"\nThe seat no. is already reserved.\n";
										goto NAME1;
									}
									
							}
							else
							{
								cout<<"\nThere are only 32 seats available in this bus.\n";
								goto NAME1;
							}
			
						}
				}
				if(busnumber2 == 5) //compare bus number insert by user
				{
					if(busnumber2 == opt2[1].getbasNo())
					{
						cout<<endl;
						opt2[1].displaySeat();
						cout<<"\n\n O -> Available || X -> Reserved\n\n";
							
						NAME2 :
						for(int y = 0; y<80; y++)
						{
							cout<<"%";
						}
						
						cout<<"\n\nPlease enter seat : ";
						cin>>seatnum;
							
						if(seatnum >= 0 && seatnum <= 40) //compare seat number insert by user
						{
								 
							if(opt2[1].getNamaseat(seatnum) == "O")
							{
								cout<<"\nPlease enter name : ";
								cin.ignore(1,'\n');
								getline(cin, passengername);
								
								opt2[1].setNamaseat(seatnum);
								opt2[1].setPassname(busnumber2, passengername);
								
								system("cls");
								for(int y = 0; y<80; y++)
								{
									cout<<"%";
								}
								cout<<endl<<endl;
								opt2[1].displaySeat();
									
								PAYMENT2 :
								cout<<"\n\nYour seat has been reserved. Enter P to proceed for the payment : ";
								cin>>payment;
								
								if(payment == 'P' || payment == 'p')
								{
									system("cls");
								
									opt2[1].setBusB(obj[4]); //inheritance
										
									TicketDisplay(opt2[1], seatnum, passengername); //polymorphism
									cout<<endl;
									system("pause");
									system("cls");
								}
								else
								{
									goto PAYMENT2;
								}
									
								goto MAINMENU;
									
							}
							else if(opt2[1].getNamaseat(seatnum) == "X")
							{
								cout<<"\nThe seat no. is already reserved.\n";
								goto NAME2;
							}
								
						}
						else
						{
							cout<<"\nThere are only 32 seats available in this bus.\n";
							goto NAME2;
						}
			
					}
				}
				else
				{
					cout<<"\nInvalid bus number. Please Re-Enter \n";
					system("pause");
					system("cls");
					goto RESERVATION;
				}
					
			}
			break;
		case 3 : // if user enter choice == 3
			{
				//Admin admin1;
				system("COLOR 60"); // set background color
				DisplayAdmin(); //function call
				DetailsBus *bus[5]; // object for class DetailsBus & aggregations
				getch();
				
				ADMIN :
				system("cls");
				for(int i = 0; i<5; i++)
				{
					bus[i]->displaybus(&obj[i]); //aggregations pass object to function in class
				}
				
				cout<<"Update the bus schedule ? ( Yes - Y || No - N )"<<endl;
				cin>>option1;
				if(option1 == 'Y' || option1 == 'y')
				{
					system("cls");
					cout<<"===============================UPDATE BUS PROGRESS ==============================="<<endl;
					for(int i = 0; i < 5; i++)
					{
						for(int j = 0; j<82; j++)
						{
							cout<<"=";
						}
						cout<<endl;
						cout<<"Enter bus number : ";
						cin>>busNo;
						cin.ignore(1,'\n');
						cout<<"Driver ID : ";
						getline(cin, driverID);
						cout<<"Date : ";
						getline(cin, date);
						cout<<"Arrival : ";
						getline(cin, arrival);
						cout<<"Departure : ";
						getline(cin, departure);
						cout<<"From : ";
						getline(cin, from);
						cout<<"Destination : ";
						getline(cin, destination);
						cout<<"Price : RM";
						cin>>price;

						
						obj[i].setBusNo(busNo); //object call function
						obj[i].setDriverID(driverID);
						obj[i].setDate(date);
						obj[i].setArrival(arrival);
						obj[i].setDeparture(departure);
						obj[i].setFrom(from);
						obj[i].setDestination(destination);
						obj[i].setTicketPrice(price);
						
					}
					
					system("cls");
					cout<<"============================= UPDATED ==========================="<<endl;
					
					for(int j = 0; j<82; j++)
					{
						cout<<"=";
					}
					for(int i = 0; i<5; i++)
					{
						bus[i]->displaybus(&obj[i]); //aggregations pass object to function in class
						cout<<endl;
					}
					
					system("pause");
					system("cls");
					goto MAINMENU;
				}
				else if( option1 == 'N' || option1 == 'n')
				{
					system("cls");
					goto MAINMENU;
				}
				else
				{
					cout<<"Invalid input. Please Re-enter"<<endl<<endl;
					system("pause");
					goto ADMIN;
				}		
			}
			break;
		case 4 : // if user enter choice == 4
			{
				exit(0);				
			}
			break;
		default : // if user enter choice other than 1, 2 ,3 and 4
	        cout<<"\nCHOICE NOT AVAILABLE"<<endl;
	        cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
			getch();
			system("cls");
	        goto MAINMENU;
	}
	
	
	return 0;
}

void DisplayAdmin() //function header
{
	system("cls");
	ADMINDISPLAY :
	string a, b;
	system("COLOR 60"); //set background color
	cout<<"\n\n\t\t\t********************************** \n";
    cout<<"\t\t\t       SKUDAI STATION ADMIN   \n";
    cout<<"\t\t\t***********    MENU   ************\n\n";
        
    cout<<"\t\t\tEnter your staff ID :";
    cin>>a; //store staff ID enter by user
            
    while( a != "12345") //Admin ID - 12345
    {
        cout<<"\n\t\t\tPlease insert the correct staff ID "<<endl;
        cout<<"\t\t\tPRESS ANY KEY TO CONTINUE"<<endl;
		getch();
		system("cls"); //clearscreen
	    goto ADMINDISPLAY;
        cout<<"\n\n\t\t\tEnter your staff ID :";
        cin>> a;
    }
           
    cout<<"\t\t\tEnter password :";
    cin>>b;
           
    while( b != "98765") //Admin password - 98765
    {
    	cout<<"\n\t\t\tPlease insert the correct password "<<endl;
		cout<<"\t\t\tPRESS ANY KEY TO CONTINUE"<<endl;          	 
		getch();
		system("cls");
	    goto ADMINDISPLAY;
        cout<<"\n\n\t\t\tEnter password :";
        cin>> a;
    }
        cout<<"\n\t\t\t     Staff Login Succesfull";	
}

