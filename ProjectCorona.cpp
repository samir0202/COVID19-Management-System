#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<fstream>
#include <dos.h>
#include <dir.h>
#include<conio.h>
using namespace std;

class CoronaV
{
	private:
		int id;
		char name[15];
		char age[8];
		char add[20];
	public:
		void password();
		void SelfTest();
		void MaskTest();
		void SelfTest1();
		void Members();
		void AllMembers();
		int getac();
		void answer(string filename);
};
void SetColor(int);
void screen();
void CV();
void gotoxy(short x, short y);
/***********************************/
//Main Function
int main()
{
	fstream file;
	CoronaV b;
	int i=11;
	char h;
	system("cls");
	int n,p,found=0;
		system("cls");
		screen();
		gotoxy(18,12);
		SetColor(12.5);
		cout<<"W><E><L><C><O><M><E  T^O  P><R><O><J><E><C><T";
		gotoxy(23,14);
		SetColor(3);
		cout<<">>-Project By: SAMIR KUMAR DUBEY-<<";
		SetColor(29);
		gotoxy(28,15);
		cout<<"Hit Any Key To Continue...";
		getch();
		system("cls");
		screen();
		SetColor(12.5);
		gotoxy(11,12);
		cout<<"#StayHomeStaySafe <----------<|>---------> #OneMaskManyLives";
		gotoxy(25,13);
		SetColor(19);
		cout<<"Do Gaj Ki Doori Mask Hai Jaruri";
		SetColor(29);
		gotoxy(29,15);
		cout<<"Hit Any Key To Continue...";
		getch();
	while(1)
	{
		system("cls");
		screen();
		gotoxy(26,11);
		SetColor(13);
		cout<<"1. About Corona";
		gotoxy(26,12);
		cout<<"2. Self CovID Test/ Help Desk";
		gotoxy(26,13);
		cout<<"3. Mask Test";
		gotoxy(26,14);
		cout<<"4. Corona Sefty Rules";
		gotoxy(26,15);
		cout<<"5. Vaccine Report";
		gotoxy(26,16);
		cout<<"6. All Members(Only For Admin)";
		gotoxy(26,17);
		cout<<"7. Exit";
		gotoxy(26,18);
		SetColor(19);
		cout<<"Enter Choice :";
		cin>>n;
		switch(n)
		{
			case 1:
				system("cls");
				b.answer("Corona1.dat");
				getch();
				break;
			case 2:
				system("cls");
				screen();
				gotoxy(15,8);
				cout<<"Are you redg with our portal(Y/N): ";
				cin>>h;
				if(h=='y'||h=='Y')
				{
					b.SelfTest1();
					file.close();
				}
				else if(h=='n'||h=='N')
				{
				file.open("Corona.dat",ios::app| ios::binary);
				b.SelfTest();
				file.write((char *)&b,sizeof(b));
				getch();
				file.close();
				}
				else
				{
					gotoxy(15,9);
					cout<<"Bad Choice...";		
				}
				getch();
				break;
			case 3:
				system("cls");
				b.MaskTest();
				getch();
				break;
			case 4:
				system("cls");
				b.answer("CovID.dat");
				getch();
				break;
			case 5:
				system("cls");
				screen();
				gotoxy(26,11);
				cout<<"1. Indian"<<endl;
				gotoxy(26,12);
				cout<<"2. Russian"<<endl;
				gotoxy(26,13);
				cout<<"3. American"<<endl;
				SetColor(11);
				gotoxy(26,15);
				cout<<"Please Choose Country(1-5): ";
				cin>>p;
				if(p>3)
				{
				gotoxy(26,16);
				cout<<"Invalied Choice...";
				getch();
				break;
				}
				system("cls");
				if(p==1)
				b.answer("Indian.dat");
				else if(p==2)
				b.answer("RV.dat");
				else
				b.answer("AV.dat");
				getch();
				break;
			case 6:
				system("cls");
				screen();
				b.password();
				break;
			case 7:
				exit(0);
				break;
			default :
				gotoxy(26,20);
				cout<<"INVALIED CHOICE...TRY AGAIN";
				getch();
				system("cls");
		}
	}
}
int CoronaV:: getac() 
{
return(id);
}
void CoronaV:: AllMembers()
{
	SetColor(12);
	cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<add<<endl;
}
//Self Testing function for redg user

void CoronaV:: SelfTest1()
{
	fstream file;
	CoronaV b;
	int r;
	int found=0;
	screen();
	gotoxy(15,9);
		file.open("Corona.dat",ios::in| ios::binary);
		cout<<"Enter UID: ";
		cin>>r;
		while(file.read((char *)&b,sizeof(b)))
		{
			if(r==b.getac())
			{
				found=1;
			} 
		}
		if(found==1)
		{
			CV();
			return;
		}
		else
		{
		gotoxy(15,10);
		cout<<"UID Not found";
		return;
		}
	}
// Creat/Redg. New member with self testing
void CoronaV:: SelfTest()
{
	fstream file;
	CoronaV b;
	int r;
	int found=0;
	char h;
	system("cls");
	screen();
	system("cls");
	screen();
	gotoxy(28,7);
	cout<<"NEW ACCOUNT";
	gotoxy(28,8);
	cout<<"------------";
	gotoxy(17,9);
	cout<<"Redg.No:";
	gotoxy(45,9);
	cout<<"Name :";
	gotoxy(17,11);
	cout<<"Age: ";
	gotoxy(45,11);
	cout<<"Add :";
	gotoxy(17,13);
	file.open("Corona.dat",ios::in| ios::binary);
	gotoxy(25,9);
	cin>>r;
	while(file.read((char *)&b,sizeof(b)))
	{
		if(r==b.getac())
		{
			found=1;
		} 
	}
	if(found==1)
	{
		gotoxy(17,13);
		cout<<"UID is exit...\n";
		getch();
		return;
	}
	else
	{
		id=r;
		gotoxy(51,9);
		cin>>name;
		gotoxy(21,11);
		cin>>age;
		gotoxy(50,11);
		cin>>add;
	}
	gotoxy(17,13);
	cout<<"Record saved successfuly...\n";	
	gotoxy(17,15);
	cout<<"Hit any key to self testing...";
	getch();
	CV();
}

//Self Test function
void CV()
{
	char ch;
	char gh;
	char rh;
	CoronaV b;
	system("cls");
	SetColor(12);
	cout<<"Are you experiencing any of the following symptoms?\n";
	cout<<"\t->severe difficulty breathing(for example, struggling\n \t .for each breath, speaking in single words)\n\t->severe chest pain\n";
	cout<<"\t->having a very hard time waking up\n\t->feeling confused\n\t->lost consciousness\n";
	cout<<"Please answer in Y or N:";
	SetColor(2);
	cin>>ch;
	if(ch=='y'||ch=='Y'||ch=='n'||ch=='N')
	{
		system("cls");
		SetColor(12);
		cout<<"Are you experiencing any of the following symptoms (or a combination of these symptoms)?\n";
		cout<<"\t->fever\n\t->new cough\n\t->difficulty breathing (for example, struggling for each breath, \n\t  cannot hold breath for more than 10 seconds)";
		cout<<"\nPlease answer in Y or N:";
		SetColor(2);
		cin>>gh;
		if(gh=='y'||gh=='Y'||gh=='n'||gh=='N')
		{
			system("cls");
			SetColor(12);
			cout<<"Are you experiencing any of the following symptoms (or a combination of these symptoms)?\n";
			cout<<"\t->muscle aches\n\t->fatigue\n\t->headache\n\t->sore throat\n\t->runny nose";
			cout<<"\nPlease answer in Y or N:";
			SetColor(2);
			cin>>rh;
			if(rh=='y'||rh=='Y'||rh=='n'||rh=='N')
			{
				system("cls");
				if(rh=='y'||rh=='Y'||gh=='y'||gh=='Y'||ch=='y'||ch=='Y')
				{
					cout<<"Self-assessment result: ";
					SetColor(4);
					cout<<"\n=>It is likely that you have COVID-19.\n";
					SetColor(3);
					cout<<"Please contect 107 or near COVID care center you are in risk but don't be panic.\n\n\n";
					b.answer("CovID.dat");
				}
				else
				{
					SetColor(3);
					cout<<"Self-assessment result:-";
					SetColor(2);
					cout<<"\n=>It is unlikely that you have COVID-19.\n\n\n";
					gotoxy(3,6);
					b.answer("CovID.dat");
				}
			}
			else
			return;
		}
		else
		return;
	}
	else
	return;
}
//Screen Design function
void screen()		
{
	SetColor(24);
	int i;
	for(i=5;i<=75;i+=2)
	{
		gotoxy(i,1);
		cout<<"=";
		gotoxy(i,25);
		cout<<"=";
		gotoxy(i,6);
		cout<<"*";
	}
	for(i=1;i<=25;i++)
	{
		gotoxy(3,i);
		cout<<"=";
		gotoxy(75,i);
		cout<<"=";
	}
	gotoxy(27,3);
	SetColor(14);
	cout<<"CORONA VIRUS MANAGEMENT SYSTEM";
	gotoxy(32,4);
	SetColor(18);
	cout<<"CovID-19 CARE CENTER";
	gotoxy(5,24);
	SetColor(25);
	cout<<"@Copyright 2020, Reserved";
	gotoxy(58,24);
	cout<<"Source: WHO/ICMR";
}
//Color function
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
//Gotoxy function
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//Password functions
void CoronaV:: password()           
{
	screen();
	fstream file;
	CoronaV b;
	int k=11,i=0;
	char pass[10];
	char pass1[10]="samir123";
	char user[10];
	char user1[10]="Samir";
	SetColor(1);
	gotoxy(11,7);
	cout<<"This section is only for admin so sign up is not enable.";
	gotoxy(31,9);
	cout<<"LOGIN SCREEN";
	gotoxy(31,10);
	cout<<"------------";
	SetColor(13);
	gotoxy(25,12);
	cout<<"User Name: ";
	gotoxy(25,14);
	cout<<"Password: ";
	gotoxy(35,12);
	cin>>user;
	gotoxy(35,14);
	do
	{
		pass[i]=getch();
		if(pass[i]!='\r')
		{
			cout<<"*";
		}
		i++;
	}while(pass[i-1]!='\r');
		pass[i-1]='\0';
		if(strcmp(pass1,pass)==0&&strcmp(user1,user)==0)
		{
			system("cls");
			file.open("Corona.dat",ios::in|ios::binary);
				gotoxy(27,7);
				SetColor(15);
				cout<<"ALL MEMBERS";
				gotoxy(19,9);
				cout<<"UID\tName\tAge\tAddress\n";
				gotoxy(19,10);
				cout<<"=============================\n";
				while(file.read((char *)&b,sizeof(b)))
				{
					screen();
					gotoxy(19,k);
					b.AllMembers();
					k++;
				}
				k=11;
				getch();
				file.close();
		}
		else
		{
			gotoxy(25,16);
			cout<<"Invalied User or Password....";
			getch();
		}
}
/* File Reading Function*/
void CoronaV::answer(string filename)
{
ifstream fin(filename.c_str(), ios::in);
if (!fin.good()){
cerr<<"Invalid file.\n";
}
else
{
string line;
int k=1;
while(getline(fin, line)){
gotoxy(3,k);
cout<<line<<endl;
k++;
}
}
}
/*Mask Testing Function*/
void CoronaV:: MaskTest()
{
	CoronaV b;
	char ch,rh,gh;
	screen();
	gotoxy(15,8);
	SetColor(12);
	cout<<"Do you wear mask regularly(y/n): ";
	SetColor(6);
	cin>>ch;
	gotoxy(15,10);
	SetColor(12);
	cout<<"Do your mask cover your mouth and nose(y/n): ";
	SetColor(6);
	cin>>rh;
	gotoxy(15,12);
	SetColor(12);
	cout<<"Do you clean your mask ever day or ever half day(y/n): ";
	SetColor(6);
	cin>>gh;
	if(ch=='y'||ch=='Y'&& rh=='y'||rh=='Y'&& gh=='y'||gh=='Y')
	{
		gotoxy(15,14);
		SetColor(11);
		cout<<"Your Mask is safe and good to wear"<<endl;
		gotoxy(15,16);
		SetColor(2);
		cout<<"Always use mask and hadrub to protect your self";
		gotoxy(15,17);
		cout<<"#Do_Gaj_Ki_Doori_Mask_Hai_Jaruri || #OneMaskManyLives";
	}
	else
	{
		gotoxy(15,14);
		SetColor(11);
		cout<<"Your Mask is not safe and not good to wear"<<endl;
		gotoxy(15,16);
		SetColor(2);
		cout<<"Always use mask and hadrub to protect your self";
		gotoxy(15,17);
		cout<<"[#Do_Gaj_Ki_Doori_Mask_Hai_Jaruri] [#OneMaskManyLives]";
	}
	getch();
	system("cls");
	SetColor(3);
	b.answer("MaskTest.dat");
}
