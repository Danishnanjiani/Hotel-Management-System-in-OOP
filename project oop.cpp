#include <iostream>
#include <limits>
#include <fstream>
#include<time.h>	//for time.
using namespace std;
class hotel{
	
	string ename;
	int contact,cinc,exp;
	
	public:
		virtual string getname() = 0;
		
	
};

class customer : public hotel{
	
	string name,cnic;
	int contact;
	float bill1,bill2,bill3;
	
	public:
		customer(){
			
			name = "abd";
			contact = 0000000;
		}
		
		customer(string n,int con){
			
			name = n;
			contact = con;
		}
		
		string getname(){
			
			return name;
		}
		
		int getcontact(){
			
			return contact;
		}
		string getcnic(){
			
			return cnic;
		}
		
		void setcnic(string cn){
			
			cnic = cn;
		}
		
		float calbilleco(int d,float bprice,float lprice){
			
			float bill1=0;
			bill1 = d*5000+bprice+lprice;
			return bill1;
		}
		
		float calbillexe(int d,float bprice){
			
			float bill2;
			bill2 = (d*15000)+(bprice);
			return bill2;
		}
		
		float calbillpres(int d){
			
			float bill3;
			bill3 = (d*30000);
			return bill3;
		}
		
		void display(float calculate){
			
			cout<<"Bill is "<<calculate<<endl;
		}
		//~customer {
		//}
};

class employee : public hotel{
	
	public:
			string ename,cnic;
			int contact;
			float exp;
	
		employee(string na,int c){
		
			ename = na;
			contact = c;
		}
		
		void setexp(float ex){
			
			exp = ex;
		}
		
		void setcnic(string cn){
			
			cnic = cn;
		}
		
		string getname(){
			
			return ename;
		}
		
		int getcontact(){
			
			return contact;
		}
		string getcnic(){
			
			return cnic;
		}
		//~employee{
		//delete emp;}
};



int main()
{            											 			/////////////////////////////////////
	
	int option,opt,con,num,cl,d,l,b ,y,ans,choice,i,j,br,lanc,C,lo,z=6,zz=6;
	char o='n',key;
	string n,cn, place,data,password,data2;
	float bprice=500,lprice=1000 ,ex,calculate;
	
	time_t t;  
 	time(&t);  
 	cout<<"\n\tDate and Time\n\t"<<ctime(&t); // FOR CURRENT TIME.
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	for(i=100;i<=10000;i++)
	{
		cout<<"\r\t\t\t\t\t\tLOADING.....%"<<i/100;
	}
	system("CLS"); 
	cout<<"\n\n\t\t\t\t\t  ****************************************"<<endl;
	cout<<"\t\t\t\t\t  ****************************************"<<endl;
	cout<<"\t\t\t\t\t    WELCOME TO THE SEVEN STAR HOTEL!"<<endl;
	cout<<"\t\t\t\t\t  ****************************************"<<endl;
	cout<<"\t\t\t\t\t  ****************************************"<<endl<<endl<<endl;
	
	cout<<"\t\t\t\t\t   Choose\n";
	cout<<"\t\t\t\t\t   1 - Admin Login\n";
	cout<<"\t\t\t\t\t   2 - Data Entry\n";
	
	while(!(cin >> choice)){
					cout<<"Error!\nEnter number!!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				} 
		
	if(choice == 1)
	{
		cout<<"\t\t\tEnter passcode.\n";
		cin>>password;
		
		while(password != "0444")
		{
		   cout<<"t\t\tWrong Password!!\n";
		   cout<<"t\t\tEnter correct Password!\n";
		   cin>>password;
		}
		
	jump:
		system("CLS");
		cout<<"\t\t\t\t **********************\n";
		cout<<"\t\t\t\t   W  E  L  C  O  M  E\n";
		cout<<"\t\t\t\t **********************\n\n";
		cout<<"\n\t\t1- COUSTOMER DATA";
		cout<<"\n\t\t2- EMPLOYEE DATA";
		cout<<"\n\t\t3- SEARCH ROOM";
		cout<<"\n\t\t4- SEARCH EMPLOYEE\n";
		while(!(cin >> j)){
					cout<<"Error!\nEnter number!!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
		
		if(j == 1)
		{
			cout<<"\t\t\t"<<"CUSTOMER DATA"<<endl<<endl;
			ifstream in;
    		in.open("Customer Data.txt",ios::app);
    		//in>>data;
    		while(!in.eof())
			{
				getline(in,data);
				cout<<data<<endl;
			}
			in.close();
			cout<<"\t\t\tPress char for continue:";
		    cin>>key;
			goto jump;			
		}
		
		else if(j == 2)
		{
			cout<<endl<<"\t\t\t"<<"EMPLOYEE DATA"<<endl<<endl;
		
			ifstream inn;
    		inn.open("Employee Data.txt",ios::app);
    		inn>>data2;
    		while(!inn.eof())
			{
				getline(inn,data2);
				cout<<data2<<endl;
			}
			cout<<"\t\t\tPress char for continue:";
			cin>>key;
			goto jump;			
		}
		else if(j == 3){
				ifstream fin;
				fin.open("Customer Data.txt",ios::in);
				if(fin.fail())
				{
					cout << "Input file opening failed.\n";
					exit(1);
				}	
				string search;
				cout << "Please enter a room number: ";
				cin  >> search;
				int isFound=0;
				while(!fin.eof())
				{
					string temp = "";
					getline(fin,temp);
					for(int i=0;i<search.size();i++)
					{
						if(temp[i]==search[i])
						{
							isFound = 1;
							cout<<temp;
							break;
							cout<<"\t\t\tPress char for continue:";
							cin>>key;
							goto jump;
						}
						else
						{
							isFound =0;
							break;
							cout<<"\t\t\tPress char for continue:";
							cin>>key;
							goto jump;
							
						}
					}
				}

				if(fin.eof()&&(isFound))
				{
					cout << "Name not found!\n";
				}

					fin.close();
					cout<<"\t\t\tPress char for continue:";
					cin>>key;
					goto jump;
				}
		
		    else if(j==4){
				ifstream fin;
				fin.open("Employee Data.txt",ios::in);
				if(fin.fail())
				{
					cout << "Input file opening failed.\n";
					exit(1);
					cout<<"\t\t\tPress char for continue:";
					cin>>key;
					goto jump;
				}
				string search;
				cout << "Please number of employee: ";
				cin  >> search;
				bool isFound=0;
				while(!fin.eof())
				{
					string temp = "";
					getline(fin,temp);
					for(int i=0;i<search.size();i++)
					{
						if(temp[i]==search[i])
						{
							isFound = 1;
							cout<<temp;
							cout<<"\t\t\tPress char for continue:";
							cin>>key;
							goto jump;
						}
						else
						{
							isFound =0;
							break;
							cout<<"\t\t\tPress char for continue:";
		    				cin>>key;
							goto jump;	
						}
					}
				}
				if(fin.eof()&&(isFound))
				{
					cout << "Name not found!\n";
					cout<<"\t\t\tPress char for continue:";
					cin>>key;
					goto jump;
				}

				fin.close();
				}		
		
				else
				{
		    		cout<<"\t\t\tSorry option not exist!!\n";
					cout<<"\t\t\tPress char for continue:";
					cin>>key;
					goto jump;
				}
	}
	
	if(choice == 2)
	{
	 back:
		do
		{	
		cout<<"\t\t1- FOR BOOKING"<<endl<<endl;
		cout<<"\t\t2- FOR EMPLOYEMENT"<<endl;
				while(!(cin >> option)){
					cout<<"Error!\nEnter number!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
		
		if(option==1)
		{
			system("CLS");
			cout<<"\t WE ARE OFFERING THREE KINDS OF ROOMS, THESE ARE GIVEN BELOW\n"<<endl;  
			cout<<"1-  ECONOMY        ---------- Rs 5000   /day"<<endl;
			cout<<"2-  EXECUTIVE      ---------- Rs 15000  /day"<<endl;
			cout<<"3-  PRESIDENTIAL   ---------- Rs 30000  /day"<<endl;
		    cout<<"4-  FOR BACK:"<<endl;
					
			cout<<"Choose options for further details:"<<endl;
			while(!(cin >> opt)){
					cout<<"Error!\nEnter number!!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
		
			if(opt==1)
			{
			
				system("CLS");
				cout<<"\t\t"<<"Economy Room"<<endl<<endl;
				cout<<"\t\t1 bed, Along with 1 mattress. "<<"\n"<<"\t\tDinner will be provided, breakfast and lunch will be charged.\n"<<endl;
				cout<<"\t\tour indoor gaming facility will be available."<<endl<<endl;
				
				cout<<"\t\tpress y for continue n for back."<<endl;
				
                cin >> o;
                while(o != 121 && o != 110) {
                cout << "Try entering y or n : ";
                cin >> o;
                } 
			
			  if(o == 'y')
			  {
				system("CLS");
				cout<<"Enter name"<<endl;
				cin>>n;
				cl=0;
				while(cl!=2)
				{
					cout<<"Enter contact."<<endl;
					cin>>con;
					int count=1;
					num=con;
				
					while(num!=0)
					{
						num = num/10;
						count++;
					};
					if(count!=11)
					{
						cout<<"Invalid Contact length..!"<<endl;
					}
					if(count==11)
					{
						cl=2;
					}
				
			    };
				cin.clear();
				cout<<"Enter your City."<<endl;
				cin>>cn;
				z++;
				customer c(n,con);
				c.setcnic(cn);
				cin.clear();
				
				ofstream out;
				out.open("Customer Data.txt",ios::app);
				out<<endl<<z<<"\t"<<c.getname()<<"\t\t"<<c.getcontact()<<"\t"<<c.getcnic()<<"\t\tEconomy"<<endl; 
				out.close();
				
				cout<<"How many days do you stay? "<<endl;
				while(!(cin >> d)){
					cout<<"Error!\nEnter number!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				cout<<"How many days do you wish to avail lunch and breakfast?"<<endl;
				while(!((cin >> l)&&(cin >> b))){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				
				while(b>d||l>d)																
				{
					cout<<"Enter correct days\n";
					cin>>l>>b;
				}
				cout<<"\t\t\tBREAKFAST MENU "<<endl;
				for(lo=0 ; lo<b ;lo++)
				{
					cout<<"\t\t\tDay "<<lo+1<<endl;
					cout<<"\t\t1- Poatao Waffle		50 pkr\n\t\t2-Special Honey Waffle	 	100 pkr\n\t\t3-Shortcut Apple Pancakes		150 pkr\n";
					while(!(cin >> C)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
					
					if(C == 1)
					br+=50;
					if(C == 2)
					br+=100;
					if(C == 3)
					br+=150;				
				}
				C=0;
				cout<<"\t\t\tLUNCH MENU"<<endl;
				for(lo=0 ; lo<l ;lo++)
				{
					cout<<"\t\t\tDay "<<lo+1<<endl;
					cout<<"\t\t1- Chicken Curry		500 pkr\n\t\t2-Mutton Curry	     650 pkr\n\t\t3-Veg Curry		250 pkr\n";
					while(!(cin >> C)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
					
					if(C == 1)
					lanc+=500;
					if(C == 2)
					lanc+=650;
					if(C == 3)
					lanc+=250;				
				}												
				
				calculate = c.calbilleco(d,br,lanc);
				c.display(calculate);
				
				cout<<"HAVE A NICE STAY!"<<endl ;
				
				
			  }				
			}
		}
		
		if(opt==2)
		{
			system("CLS");
			cout<<"\t"<<"Executive Room"<<endl<<endl;
			cout<<"2 beds, Along with 1 mattress "<<"\n"<<"Dinner and lunch will be provided, breakfast will be charged."<<endl;
		    cout<<"Our indoor gaming facilities are available, along with a swimming pool."<<endl<<endl;
		    cout<<"press y for continue n for back."<<endl;
			cin >> o;
                while(o != 121 && o != 110) {
                cout << "Invalid input\nEnter y or n!: ";
                cin >> o;
                } 
			if(o=='y')
			{
				system("CLS");
				cout<<"Enter name"<<endl;
				cin>>n;	
				cl=0;
				
				while(cl!=2)
				{
					cout<<"Enter contact."<<endl;
					cin>>con;
					int count=1;
					num=con;
				
					while(num!=0)
					{
					
						num = num/10;
						count++;
					};
				//cout<<""<<count;
					if(count!=11)
					{
						//cl==11;
						cout<<"Invalid Contact Length."<<endl;
					}
				
					if(count==11)
					{
						cl=2;
					}
				
			    };
			    
				cin.clear();
				
				cout<<"Enter your city"<<endl;
				cin>>cn;
				z++;
				customer c(n,con);
				c.setcnic(cn);
				ofstream out;
				out.open("Customer Data.txt",ios::app);
				out<<endl<<z<<"\t"<<c.getname()<<"\t\t"<<c.getcontact()<<"\t"<<c.getcnic()<<"\t\tExecutive"<<endl; 
				out.close();
				
				cout<<"How many days do you stay? "<<endl;
				while(!(cin >> d)){
					cout<<"Error!\nEnter number!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				cout<<"How many days do you avail breakfast?"<<endl;
				while(!(cin >> b)){
					cout<<"Error!\nEnter number!"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				
				while(b>d)																
				{
					cout<<"Enter correct days for breakfast\n";
					cin>>b;
				}
				br = 0;
				cout<<"\t\t\tBREAKFAST MENU"<<endl;
				for(lo=0 ; lo<b ;lo++)
				{
					cout<<"\t\t\tDay "<<lo+1<<endl;
					cout<<"\t\t1- Poatao Waffle		50 pkr\n\t\t2-Special Honey Waffle	 95 pkr\n\t\t3-Shortcut Apple Pancakes	 110 pkr\n";
					while(!(cin >> C)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
					
					if(C == 1)
					br+=50;
					if(C == 2)
					br+=95;
					if(C == 3)
					br+=110;				
				}
				calculate = c.calbillexe(d,br);
				c.display(calculate);		
				cout<<"HAVE A NICE STAY!"<<endl ;		
		    }
	    }
		if(opt==3)
		{
			system("CLS");
			cout<<"\t"<<"Presidential Room"<<endl<<endl;
			cout<<"3 beds , along with 1 mattress "<<"\n"<<"Dinner, lunch and breakfast will be provided."<<endl;
		    cout<<"Our indoor gaming facility will be available. Access to Gym will also be given along with private swimming pools for each room."<<endl;
		    cout<<"Upon a stay for more than 10 days, platimnum hotel card will be given which will have a 20% discout on next visit."<<endl<<endl;
		    cout<<"press y for continue n for back."<<endl;
			cin >> o;
                while(o != 121 && o != 110) {
                cout << "Try entering y or n : ";
                cin >> o;
                } 
			
			if(o=='y')
			{
				system("CLS");
				cout<<"Enter name"<<endl;
				cin>>n;
				cl=0;
				while(cl!=2)
				{
					cout<<"Enter contact."<<endl;
					cin>>con;
					int count=1;
					num=con;
					while(num!=0)
					{
						num = num/10;
						count++;
					};
					if(count!=11)
					{
						cout<<"Inccorect contact length."<<endl;
					}
					
					if(count==11)
					{
						cl=2;
					}
				
			    };
				cin.clear();
				
				cout<<"Enter city"<<endl;
				cin>>cn;
				z++;
				customer c(n,con);
				c.setcnic(cn);
				
				ofstream out;
				out.open("Customer Data.txt",ios::app);
				out<<endl<<z<<"\t"<<c.getname()<<"\t\t"<<c.getcontact()<<"\t"<<c.getcnic()<<"\t\tPresidential"<<endl; 
				out.close();
					
				cout<<"How many days to you plan to stay? "<<endl;
				while(!(cin >> d)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				
				calculate = c.calbillpres(d);
				c.display(calculate);
				cout<<"HAVE A NICE STAY!"<<endl ;			
		   }
	    }
	    else if(opt == 4)
	    {
	    	cout<<"\t\t\tPress char for continue:";
		    cin>>key;
			goto back;
	    }
	    
		if(option == 2)
		{
			system("CLS");
			cout<<"1- if you want to be hired for the room service-maximum employee allowed are 75"<<endl ;
			cout<<"2- if you want to be hired for the services for kitchen-maximum employee allowed are 20"<<endl ;
			cout<<"3- if you want to be hired to take care for the customers on the reception"<<endl ;
		
			cout<<"Choose from above options for further details:"<<endl;
			while(!(cin >> opt)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
		
			if(opt == 1) 
			{
				system("CLS");
				cout<<"WOW- you are here to give your services for our 5 star rooms"<<endl;
				cout<<"YOU have to clean the room for our customers atleast 3 times a day"<<endl;
				cout<<"You should be availaible for our customers at doorstep"<<endl<<"More details would be listed when you join this service"<<endl;
		
				cout<<"If you wish to proceed, press y otherwise press n."<<endl;
				cin >> o;
                while(o != 121 && o != 110) {
                cout << "Try entering y or n : ";
                cin >> o;
                } 
			
				if(o=='y')
				{
					system("CLS");	
					cout<<"Enter name"<<endl;
					cin>>n;
				
					cl=0;
					while(cl!=2)
					{
						cout<<"Enter contact."<<endl;
						cin>>con;
						int count=1;
						num=con;
				
						while(num!=0)
						{
							num = num/10;
							count++;
						};
						if(count!=11)
						{
							cout<<"Inccorect contact length."<<endl;
						}
						if(count==11)
						{						
						  	cl=2;
						}
				
			    	};
					cin.clear();
				
					cout<<"Enter city"<<endl;
					cin>>cn;
				
					employee e(n,con);
					e.setcnic(cn);
					zz++;
					ofstream op;
				    op.open("Employee Data.txt",ios::app);
				    op<<endl<<zz<<"\t"<<e.getname()<<"\t\t"<<e.getcontact()<<"\t"<<e.getcnic()<<"\t\tRoom service"<<endl; 
				    op.close();
				    
					cout<<"Enter the years of experience"<<endl ;
					while(!(cin >> ex)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
					e.setexp(ex);
				
					cout<<"Enter where you have worked previoulsy and for how many years"<<endl;
					cin>>place>>ex;
				
					cout<<"nice you have worked at"<<" "<<place<<" for"<<" "<<ex<<" "<<"years"<<endl<<endl ;
					if(ex>2){
						cout<<"CONGRATULATIONS! You're hired!"<<endl;
					}
					else{
						cout<<"Sorry you do not meet out requirement of atleast 3 years of experience.."<<endl;
					}
				}	
			}
				
			if(opt == 2) 
			{
				
					system("CLS");
					cout<<"WOW- you are here to give your services for our kitchen"<<endl;
					cout<<"YOU must expert in cooking different types of food such as ITALIAN - CHINESE - BBQ etc"<<endl;
					cout<<"Your duty will also be to make sure that the kitchen is clean all the day"<<endl<<"More details would be listed when you join this service"<<endl;
					cout<<"\nIf you wish to proceed, press y otherwise press n."<<endl;
					cin >> o;
                while(o != 121 && o != 110) {
                cout << "Try entering y or n : ";
                cin >> o;
                }
					if(o=='y')
					{
						system("CLS");	
						cout<<"Enter name"<<endl;
						cin>>n;
				
						cl=0;
						while(cl!=2)
						{
							cout<<"Enter contact."<<endl;
							cin>>con;
							int count=1;
							num=con;
				
							while(num!=0)
							{
								num = num/10;
								count++;
							};
							if(count!=11)
							{
								cout<<"Inccorect contact length."<<endl;
							}
							
							if(count==11)
							{
								cl=2;
							}
				
			    		};
						cin.clear();
				
						cout<<"Enter city"<<endl;
				        cin>>cn;
				
						employee e(n,con);
					    e.setcnic(cn);
						zz++;
						ofstream op;
				        op.open("Employee Data.txt",ios::app);
				        op<<endl<<zz<<"\t"<<e.getname()<<"\t\t"<<e.getcontact()<<"\t"<<e.getcnic()<<"\t\tKitchen"<<endl; 
				        op.close();
						
						cout<<"Enter the years of experience"<<endl ;
						while(!(cin >> y)){
				        	cout<<"Error! Enter number"<<endl;
					        cin.clear();
					        cin.ignore(123, '\n');
				        }	
						cout<<"Enter where you have worked previoulsy and for how many years"<<endl;
						cin>>place>>ex;
				
						cout<<"nice you have worked at"<<" "<<place<<" for"<<" "<<ex<<" "<<"years"<<endl ;
						if(ex>2){
						cout<<"CONGRATULATIONS! You're hired!"<<endl;
					}
					else{
						cout<<"Sorry you do not meet out requirement of atleast 3 years of experience.."<<endl;
					}
					}
		
			}
			
			if(opt == 3) 
			{
					system("CLS");
					cout<<"WOW- you are here to give your services for our reception"<<endl;
					cout<<"YOU should have a little idea of how to use the technology"<<endl;
					cout<<"You should also have good communication skills to communicate with our customers"<<endl<<"More details would be listed when you join this service"<<endl;
					cout<<"If you wish to proceed, press y otherwise press n."<<endl;
					cin >> o;
                while(o != 121 && o != 110) {
                cout << "Try entering y or n : ";
                cin >> o;
                } 
				
					if(o=='y')
					{
						system("CLS");	
						cout<<"Enter name"<<endl;
						cin>>n;
				
						cl=0;
						while(cl!=2)
						{
							cout<<"Enter contact."<<endl;
							cin>>con;
							int count=1;
							num=con;
				
							while(num!=0)
							{
								num = num/10;
								count++;
							};
							if(count!=11)
							{
								
								cout<<"Inccorect contact length."<<endl;
							}
							
							if(count==11)
							{
								cl=2;
							}
				
			    		};
						cin.clear();
				
						cout<<"Enter city"<<endl;
				        cin>>cn;
				
						employee e(n,con);
					    e.setcnic(cn);
					    zz++;
					    ofstream op;
				        op.open("Employee Data.txt",ios::app);
				        op<<endl<<zz<<"\t"<<e.getname()<<"\t\t"<<e.getcontact()<<"\t"<<e.getcnic()<<"\t\tReception"<<endl; 
				        op.close();
				
						cout<<"Enter the years of experience"<<endl ;
						while(!(cin >> y)){
					cout<<"Error! Enter number"<<endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
						cout<<"Enter where you have worked previoulsy and for how many years"<<endl;
						cin>>place>>ex;
				
						cout<<"nice you have worked at"<<" "<<place<<" for"<<" "<<ex<<" "<<"years"<<endl ;
						if(ex>2){
						cout<<"CONGRATULATIONS! You're hired!"<<endl;
					}
					else{
						cout<<"Sorry you do not meet out requirement of atleast 3 years of experience.."<<endl;
					}
					}
			}
		}

	} 	
		
		while(o=='n');
		
	}
	
}
