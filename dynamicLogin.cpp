#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;


		void registr();
        void login();
        void forgot();
        void newaccount();
        

int main()
{
	int choice;
	cout<<"\n\n\n\t*****************  WELLCOME TO ALPHA BANKING  *****************"<<endl;
	cout<<"\n\n\n\t01. REGISTER";
	cout<<"\n\n\t02. LOGIN";
	cout<<"\n\n\t03. FORGOT";
	cout<<"\n\n\t04. EXIT";
	cout<<"\n\n\tSelect Your Option (1-4) ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			registr();
			break;
		case 2:
            login();
            break;
        case 3:    
            forgot();
            break;
        case 4:   
		    system("cls"); 
            cout<<"\n\t\t  Thanks for Using our best Services\n\n\n";
            return 0;
            break;
        default:
        	cout<<"\n\tSorry! Wrong Option...";
        	cin.get();
        	cin.get();
        	system("cls");
        	main();
	}
}

void registr()
{
	string user,pass;
	system("cls");
	cout<<"\n\n\n\tEnter Your Username ";
	cin>>user;
	cout<<"\n\tEnter Your Password ";
	cin>>pass;
	cout<<"\n\tCongratulations! You Registered Successfully...";
	cin.get();
	cin.get();
	ofstream file("database.txt" , ios::binary | ios::app);
	file<<user<<' '<<pass<<endl;
	system("cls");
	main();
}

void login()
{
	int exist;
	string use,pas,u,p;
	system("cls");
	cout<<"\n\n\n\tEnter Your Username ";
	cin>>use;
	cout<<"\n\tEnter Your Password ";
	cin>>pas;
	
	ifstream search("database.txt");
	while(search>>u>>p)
	{
		if(u==use && p==pas)
		{
			exist = 1;
		}
	}
	search.close();
	if(exist == 1)
	{
	   newaccount();	
	
	}
	else
	{
		cout<<"\n\tSorry! Login Error Account not Found";
		cin.get();
		cin.get();
		system("cls");
		main();
	}
}

void forgot()
{
	int choice1;
	system("cls");
	cout<<"\n\n\n\t1.Search by Username";
	cout<<"\n\n\t2.Search by password";
	cout<<"\n\n\t3.Main menu";
	cout<<"\n\n\tSelect You Option (1-3) ";
	cin>>choice1;
	switch(choice1)
	{
		case 1:
		{
			int ex=0;
			string user1,u1,p1;
			system("cls");
			cout<<"\n\n\n\tEnter Your Remembererd Username ";
			cin>>user1;
			
			ifstream search1("database.txt");
			while(search1>>u1>>p1)
			{
				if(user1==u1)
				{
					ex = 1;
					break;
				}
			}
			search1.close();
			if(ex==1)
			{
				cout<<"\n\n\tHurrah! Your Account Found";
				cout<<"\n\n\tYour Password is "<<p1;
				cin.get();
				cin.get();
				system("cls");
				main();
			}
			else
			{
				cout<<"\n\n\tSorry! Your Password not Found..";
				cin.get();
				cin.get();
				system("cls");
				main();
			}
			break;
	   }
		case 2:
		{
			int exi=0;
			string pass1,u1,p1;
			system("cls");
			cout<<"\n\n\n\tEnter Your Remembererd Password ";
			cin>>pass1;
			
			ifstream search2("database.txt");
			while(search2>>u1>>p1)
			{
				if(pass1==p1)
				{
					exi = 1;
					break;
				}
			}
			search2.close();
			if(exi==1)
			{
				cout<<"\n\n\tHurrah! Your Account Found";
				cout<<"\n\n\tYour Username is "<<u1;
				cin.get();
				cin.get();
				system("cls");
				main();
			}
			else
			{
				cout<<"\n\n\tSorry! Your Username not Found..";
				cin.get();
				cin.get();
				system("cls");
				main();
	       }
	       break;
		}
	    case 3:
	    {	
	    	system("cls");
	    	main();
	    	break;
        }  
		default:
	    {
			cout<<"\n\n\tSorry! Wrong Option...";
	    	cin.get();
	    	cin.get();
	    	forgot();
	   }
	}
}
void newaccount()
{
long int opti;
		system("cls");
		cout<<"\n\n\n\tWelcome";
		cout<<"\n\n\t01. Logout";
	    cout<<"\n\n\tSelect Your Option (1-2) ";
		cin>>opti;
		switch(opti)
	   {
        case 1:   
            system("cls");
		    main();
		    break;
        default:
        	cout<<"\n\tSorry! Wrong Option...";
        	cin.get();
        	cin.get();
        	system("cls");
        	newaccount();	
}
}



