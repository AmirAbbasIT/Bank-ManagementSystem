#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>//For Sleep 
using namespace std;
int get();
class bank
{
	protected:
	string name;
    string gender;
    string city;
	public:
		bank()
		{
		}
		void data()
		{
			cout<<"enter your name:";
			cin>>name;
			cout<<"Enter your gender:";
			cin>>gender;
			cout<<"Enter city:";
			cin>>city;
		}
		void display()
		{
			cout<<"NAME:  "<<name<<endl;
			cout<<"Gender:  "<<gender<<endl;
			cout<<"City:  "<<city;
		}

};
class current:public bank{
	int amount;
	int account;
	public:
		current():bank()
		{
		}
		void data(int account)
		{
			this->account=account;
		bank::data();
			cout<<"enter the amount to diposit=";
			cin>>amount;
			cout<<"your account number is="<<account;
		}
		void getfromfile(string name,string gender,string city,int amount,int account)
		{
			this->name=name;
			this->gender=gender;
			this->city=city;
			this->amount=amount;
			this->account=account;
		}
		void display()
		{
			bank::display();
			cout<<"Amount:  "<<amount<<endl;
			cout<<"Account:  "<<account<<endl;
		}
	int check()
		{
			return account;
		}
void operator +=(int amount)
{
this->amount+=amount;					
}
void operator -=(int amount)
{
this->amount-=amount;	
}				
friend ostream& operator<<(ostream &obj,current& o);
string getname()
{
	return name;
}
string getgender()
{
	return gender;
}
string gecity()
{
	return city;
}	
int getamount()
{
	return amount;
}
int accountnum()
{
	return account;
}	
};
class Saving:public bank{
	int amount;
	int account;
	public:
	Saving():bank()
	{
		
	}
	void data(int account)
		{
			this->account=account;
		bank::data();
			cout<<"enter the amount to diposit=";
			cin>>amount;
			cout<<"your account number is="<<account;
			
		}
		void getfromfile(string name,string gender,string city,int amount,int account)
		{
			this->name=name;
			this->gender=gender;
			this->city=city;
			this->amount=amount;
			this->account=account;
		}
	void display()
		{
			bank::display();
			cout<<"Amount:  "<<amount<<endl;
			cout<<"Account:  "<<account<<endl;
		}
		void operator +=(int amount)
		{
		this->amount+=amount;	
		}
		void operator -=(int amount)
		{
			this->amount-=amount;
		}	
	int check()
	{
		return account;
	}
friend ostream& operator<<(ostream& obj,Saving& o);	
string getname()
{
	return name;
}
string getgender()
{
	return gender;
}
string gecity()
{
	return city;
}	
int getamount()
{
	return amount;
}
int accountnum()
{
	return account;
}	
};
//int bank::account_no=0;
int main()
{
	system("color 3f");
	for(int i=1;i<=6;i++)
	{
		cout<<"...WELCOME TO MY BANK...\n";
		if(i%2==0)
		cout<<"\n\n\n\tLOADING.";
		else
		cout<<"\n\n\n\tLOADING..";
		Sleep(500);
		system("cls");
		
	}
	int n,c;
	int list_s=0; // for saving account... 
	int list_c=0;    // for current account...
	current obj[10];
	Saving obj2[10];
	{ // accessing existing saving accounts....
	string name,gender,city;
	int amount,account;
	fstream in("Current.txt",ios::in );
	if(in)
	{
	while(!in.eof())
	{
	in>>name;
	in>>gender;
	in>>city;
	in>>amount;
	in>>account;
	if(account==list_c)
	{
	obj[list_c].getfromfile(name,gender,city,amount,account);
	list_c++;		
	}
	else
	break;
	}
	in.close();	
	}
	}
		{ // accessing existing saving accounts....
	string name,gender,city;
	int amount,account;
	fstream in("Saving.txt",ios::in );
	if(in)
	{
	while(!in.eof())
	{
	in>>name;
	in>>gender;
	in>>city;
	in>>amount;
	in>>account;
	if(account==list_s)
	{
	obj2[list_s].getfromfile(name,gender,city,amount,account);
	list_s++;		
	}
	else
	break;
	}
	in.close();	
	}
	}
	
	for( ; ;)
	{
			{
		fstream out("Current.txt",ios::out); // saving data into filesss... of current accounts..
           for(int i=0;i<list_c;i++)
           {
  			out<<obj[i].getname()<<endl;
			out<<obj[i].getgender()<<endl;
			out<<obj[i].gecity()<<endl;
			out<<obj[i].getamount()<<endl;
			out<<obj[i].accountnum()<<endl;         	
		   }
		   out.close();
	}
		{
		fstream out("Saving.txt",ios::out);// saving data into files... of saving accounts...
           for(int i=0;i<list_s;i++)
           {
  			out<<obj[i].getname()<<endl;
			out<<obj[i].getgender()<<endl;
			out<<obj[i].gecity()<<endl;
			out<<obj[i].getamount()<<endl;
			out<<obj[i].accountnum()<<endl;         	
		   }
		   out.close();
	}
			for(;;) // menu for accounts...
	{
		c=1;
		system("cls");
		cout<<"Creat A New Account:     <\n\n\nLOGIN INTO SYSTEM:\n\n\nENTER FOR DEPOSIT:\n\n\nENTER For Withdraw:\n\n\nPRESS ENTER TWICE TO SELECT..";
		getch();
		if(getch()=='\r')
		break;
		if(GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
        cout<<"Creat A New Account:\n\n\nLOGIN INTO SYSTEM:      <\n\n\nENTER FOR DEPOSIT:\n\n\nENTER For Withdraw:\n\n\nPRESS ENTER TWICE TO SELECT..";
		c=2;
		if(getch()=='\r')
		break;			
		}
		getch();
		if(GetAsyncKeyState(VK_DOWN))
		{
		system("cls");
			cout<<"Creat A New Account:\n\n\nLOGIN INTO SYSTEM:\n\n\nENTER FOR DEPOSIT:      <\n\n\nENTER For Withdraw:\n\n\nPRESS ENTER TWICE TO SELECT..";
		c=3;
		if(getch()=='\r')
		break;
		}
		getch();
		if(GetAsyncKeyState(VK_DOWN))
		{
		system("cls");
		cout<<"Creat A New Account:\n\n\nLOGIN INTO SYSTEM:\n\n\nENTER FOR DEPOSIT:\n\n\nENTER For Withdraw:     <\n\n\nPRESS ENTER TWICE TO SELECT..";
		c=4;
		if(getch()=='\r')
		break;
		}
		getch();
	
	}
	int ch; // selecting type of account
	{
		system("cls");
		cout<<"ENTER 1 FOR CURRENT Account:\nEnter 2 FOR SAVING Account:";
		cin>>ch;
	}
	switch(ch)
	{
		case 1: // managing current account...
		{
				system("cls");
	switch(c) 
	{
		case 1: 
		{
			obj[list_c].data(list_c);
			getch();
		}

		break;	
		case 2:
			{
				n=get();
				for(int i=0;i<10;i++)
				{
					if(n==obj[i].check())
					{
						cout<<obj[i];
						getch();
						break;
					}
					
				}
			}
		break;	
		case 3:
			{
				n=get();
				for(int i=0;i<10;i++)
				{
					if(n==obj[i].check())
					{
						int cash;
						cout<<"Enter cash to diposit=";
						cin>>cash;
						obj[i]+=cash;
						break;
					}
				}
			}
		break;
		case 4:
	{
		n=get();
		for(int i=0;i<10;i++)
		{
			if(n==obj[i].check())
			{
				int csh;
				cout<<"enter amount to withdraw=";
				cin>>csh;
				obj[i]-=csh;
				break;
			}
		}
	}
	break;
		default:
		exit(1);		
	}	
		}
		break;
		case 2:  // managing saving account...
		{
				system("cls");
	switch(c)  
	{
		case 1:
		{
		    obj2[list_s].data(list_s);
			getch();
		list_s++;		
		} 
		break;	
		case 2:
			{
				n=get();
				for(int i=0;i<10;i++)
				{
					if(n==obj2[i].check())
					{
						cout<<obj2[i];
						getch();
						break;
					}
					
				}
			}
		break;	
		case 3:
			{
				n=get();
				for(int i=0;i<10;i++)
				{
					if(n==obj2[i].check())
					{
						int cash;
						cout<<"Enter cash to diposit=";
						cin>>cash;
						obj2[i]+=cash;
						break;
					}
				}
			}
		break;
		case 4:
	{
		n=get();
		for(int i=0;i<10;i++)
		{
			if(n==obj2[i].check())
			{
				int csh;
				cout<<"enter amount to withdraw=";
				cin>>csh;
				obj2[i]-=csh;
				break;
			}
		}
	}
	break;
		default:
		exit(1);		
	}	
		}
		
	}

		system("cls");
	getch();
}
return 0;
}
int get() // to get account number from the user...
{
	int ac;
	cout<<"enter your account number= ";
	cin>>ac;
	return ac;
}
ostream& operator<<(ostream &obj,current& o) // overloading outputstream
{
	obj<<"Name: "<<o.name<<endl;
	obj<<"Gender:  "<<o.gender<<endl;
	obj<<"City:  "<<o.city<<endl;	
	obj<<"Amount: "<<o.amount<<endl;
	obj<<"Account: "<<o.account<<endl;
	return obj;
}
ostream& operator<<(ostream& obj,Saving& o) //overloading outputstream
{
	obj<<"Name: "<<o.name<<endl;
	obj<<"Gender:  "<<o.gender<<endl;
	obj<<"City:  "<<o.city<<endl;	
	obj<<"Amount: "<<o.amount<<endl;
	obj<<"Account: "<<o.account<<endl;
	return obj;
} 
