#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<graphics.h>
using namespace std;

void student_login();
void teacher_login();
void que(ofstream&,ofstream&);
void cheak(char,ofstream&);
void s();
void teach(string);
void average(ifstream&,ifstream&);
void logo();
void choice();

int main()
{
logo();

cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
cout<<"---------------------------------------- FEEDBACK SYSTEM ------------------------------------------\n";
cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
choice();
}

void choice()
{
    char ch;
int dd;
while(ch!=3)
{
cout<<"\n"<<"1.student\n2.Teacher\n3.Exit\nEnter your choice : ";
cin>>ch;
fflush(stdin);
if(ch=='1')
{
    dd=1;
}
else if(ch=='2')
{
    dd=2;
}
else if(ch=='3')
{
    break;
}

else{
    cout<<"\n"<<"Invalid choice. Reenter choice: ";
    choice();
}
switch(dd)
{
case 1:student_login();
       break;

case 2:teacher_login();
       break;

default:cout<<"\n"<<"Invalid choice";
}

}
}

void student_login()
{
string jjj,jj,uname,password;
jjj="sea";
cout<<"\nEnter username : ";
cin>>uname;
jj=uname.substr(0,3);
//cout<<"\n"<<jj;
if(jj!=jjj)
{
    cout<<"Invalid username";
    student_login();

}

cout<<"\nEnter password : ";
cin>>password;

if(uname!=password)
{
cout<<"\nInvalid password";
student_login();
}
s();
}

void teacher_login()
{
string uname,password;

cout<<"\nEnter username : ";
cin>>uname;
cout<<"\nEnter password : ";
cin>>password;

if(uname!=password)
{
cout<<"\nInvalid username or password";
teacher_login();
}
teach(uname);
}

void s()
{

ofstream o1,o2,o3,s1,s2,s3;
o1.open("teacher1.dat",ofstream::app);
o2.open("teacher2.dat",ofstream::app);
o3.open("teacher3.dat",ofstream::app);
s1.open("teacher1sug.dat",ofstream::app);
s2.open("teacher2sug.dat",ofstream::app);
s3.open("teacher3sug.dat",ofstream::app);

cout<<"\n\nTeacher1 name\n";
que(o1,s1);

cout<<"\n\n\nTeacher2 name\n";
que(o2,s2);

cout<<"\n\n\nTeacher3 name\n";
que(o3,s3);

o1.close();
o2.close();
o3.close();
s1.close();
s2.close();
s3.close();

cout<<"\n\n";
cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
cout<<"------------------------------ THANK YOU FOR YOUR VALUABLE FEEDBACK --------------------------------\n";
cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
}

void que(ofstream &o, ofstream &s)
{
    fflush(stdin);
char ans1;
cout<<"\nQ.1.Is the teacher well preapared to the lecture?\n 1)Always\n 2)Most of the time\n 3)Only a few times\n 4)Never\n\nans: ";
cin>>ans1;
cheak(ans1,o);
fflush(stdin);
cout<<"\nQ.2.How does the teacher has command on subject?\n 1)Extremly well\n 2)Better\n 3)Well\n 4)inadequate\n\nans: ";
cin>>ans1;
cheak(ans1,o);
fflush(stdin);
cout<<"\nQ.3.Are the lectures interactive?\n 1)Always\n 2)Most of the time\n 3)Only a few times\n 4)Never\n\nans: ";
cin>>ans1;
cheak(ans1,o);
fflush(stdin);
cout<<"\nQ.4.How is the teacher's control over the class?\n 1)Maintain good discipline by her/his presence\n2 )Some order in the class \n 3)Frequently in disorder\n 4)Class always noicy\n\nans: ";
cin>>ans1;
cheak(ans1,o);
fflush(stdin);
cout<<"\nQ.5.Is teacher available and approchable for discussion and doubts?\n 1)Always\n 2)Most of the time\n 3)Only a few times\n 4)Never\n\nans: ";
cin>>ans1;
cheak(ans1,o);
fflush(stdin);
char j,n;
cout<<"\n"<<"Want to give any suggestion(y/n): ";
cin>>j;
fflush(stdin);
if(j=='y'||j=='n')
{
if(j=='y')
{
char sug[100];
cout<<"\nEnter your suggestion :";
cin.ignore();
cin.getline(sug,100);
s<<sug;
fflush(stdin);
s<<"\n";
}
}
s.close();

}

void cheak(char ans,ofstream &o)
{
if(ans=='1'||ans=='2'||ans=='3'||ans=='4')
{
  o<<ans;
}
else
{
cout<<"\nInvalid answer \nRe-enter answer : ";
cin>>ans;
cheak(ans,o);
}
}

void teach(string uname){
    ifstream i,ss;
    if(uname.compare("teacher1")==0){
        i.open("teacher1.dat");
        ss.open("teacher1sug.dat");
        average(i,ss);
    }
    else if(uname.compare("teacher2")==0){
        i.open("teacher2.dat");
        ss.open("teacher1sug.dat");
        average(i,ss);
    }
    else if(uname.compare("teacher3")==0){
        i.open("teacher3.dat");
        ss.open("teacher1sug.dat");
        average(i,ss);
    }
}

void average(ifstream &i ,ifstream &ss)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");

int count=0,d=0,b,avg,avg1;
char r;
r=i.get();
while(!i.eof())
{
    if(r=='1')
   	{
	  b=100;
	}
    if(r=='2')
	{
 	  b=75;
	}
    if(r=='3')
	{
 	  b=50;
	}
    if(r=='4')
	{
 	  b=25;
	}
    d=d+b;
    r=i.get();
    count++;
}

    avg=d/count;
    cout<<"\nOverall average="<<avg<<" %"<<"\n\n";
    avg1=(avg*2.6)+avg;
    char avg2[5];

      setlinestyle(4,0,20);
      arc(300,200,0,avg1,100);
      setcolor(3);
      settextstyle(8,0,6);
      outtextxy(70,360,"OVERALL AVARAGE");
      setlinestyle(0,0,2);
      line(60,350,570,350);
      setlinestyle(0,0,2);
      line(60,420,570,420);
      setcolor(RED);
      settextstyle(8,0,6);
      sprintf(avg2,"%d",avg);
      outtextxy(240,170,avg2);
      outtextxy(340,170,"%");
      getch();


      closegraph();

char j;

cout<<"\nSuggestion given by students :\n";
while(!ss.eof())
{
ss.get(j);
cout<<j;
}
cout<<"\n";
ss.close();
i.close();
}

void logo(){
      initwindow(494,651,"images");
    readimagefile("dyp11.jpg",0,0,494,651);
  getch();
closegraph();
  }
