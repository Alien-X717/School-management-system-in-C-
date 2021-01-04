
#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<process.h>
#include<dos.h>
int choice;     //GLOBAL VARIABLES I AND J DECLARED
char ch;            //GLOBAL CHARACTER OF CHOICE
class school            //CLASS SCHOOL
{
int rolno,clasno;
char  name[21],emailid[31],addr[51],phno[11];
public:
void showall(int x,int s=0,int d=0)
{                        //FUNCTION TO SHOW ALL THE DETAILS
if(s==0)
{clrscr();}
cout<<"\n\n";
textcolor(11);
cprintf("          NAME   :   ");
textcolor(10);
cprintf(name);
if(d==1)
{
delay(50);
}
cout<<"\n\n";
textcolor(11);
cprintf("        ROLL NO. :   ");
cout<<rolno<<"\n\n";
if(d==1)
{
delay(50);
}
textcolor(11);
cprintf("          CLASS  :   ");
cout<<x<<"\n\n";
if(d==1)
{
delay(50);
}
textcolor(11);
cprintf("         E-MAIL  :   ");
textcolor(10);
cprintf(emailid);
if(d==1)
{
delay(50);
}
cout<<"\n\n";
textcolor(11);
cprintf("      CONTACT NO.:   ");
textcolor(10);
cout<<phno;
if(d==1)
{
delay(50);
}
cout<<"\n\n";
textcolor(11);
cprintf("         ADDRESS :   ");
textcolor(10);
cprintf(addr);

}

void droprol()             //FUNCTION TO DESC. ROLL NO. BY 1
  { --rolno;}
void srn()                 //FUNCTION TO SHOW ROLL NO.
{
cout<<rolno;
}

void snm()                  //FUNCTION TO SHOW NAME
{
 textcolor(GREEN);
 cprintf(name);
}
  void get(int clno,int rno)         //GET FUNCTION TO GET DETAILS OF ALL
  {                                  //STUDENTS OF ALL CLASSES
  int j;
  cout<<"\n";
  pline(14,80);
  cout<<"\n\n\tENTER STUDENT'S NAME : ";
  s14:gets(name);
   for(int s=0;s<strlen(name);s++)
  {
   if(name[s]!=' ')
   {
    if(!isalpha(name[s]))
    {
     wrong(" NAME : ");
     goto s14;
    }
   }
  }
  clasno=clno;
  rolno=(clno*100)+rno;
  cout<<"\tSTUDENT'S ROLL NO. = "<<rolno<<"\n";
  cout<<"\tENTER STUDENT'S CONTACT NO. : ";
  s6:gets(phno);
  for(j=0;j<strlen(phno);j++)
  {
   if(isalpha(phno[j]))
     goto s9;
  }
  if((strlen(phno)!=10&&strlen(phno)!=7))
  {
  s9:textcolor(RED);
   cprintf("        PLEASE ENTER A VALID CONTACT NO. : ");goto s6;
  }
  cout<<"\tENTER STUDENT'S E-MAIL ID (IF ANY) OR ENTER NULL : ";
  gets(emailid);
  cout<<"\tENTER STUDENT'S RESEDENTIAL ADDRESS : ";
  gets(addr);
 }
 void show(int sc)       //FOR SHOWING STUDENT'S DETAILS OF A CLASS
 {
  cout<<setw(6)<<rolno<<setw(28)<<name<<"\t\t";
  if(sc==1)
  {
   if(strlen(phno)==7)
   {cout<<"0731-";
   puts(phno); }
   else
   {cout<<"91";
    puts(phno);}
  }
}
 void modify()          //TO MODIFY VALUES OF STUDENT
 {
 clrscr();
 int j;
 textcolor(GREEN);
 cout<<"\n\n\t\t";
 cprintf("RECORD FOUND !");
 textcolor(15);
 cprintf(" ");
 char nm[21],cno[11],eid[31],add[51];
 delay(330);
 cout<<"\n\n\tROLL NO. = "<<rolno;
 delay(50);
 cout<<"\n\tSTUDENT'S NAME : "<<name;
 delay(50);
 cout<<"\n\tADDRESS : "<<addr;
 delay(50);
 cout<<"\n\tE-MAIL ADDRESS : ";
 delay(50);
 cout<<emailid;
 delay(50);
 cout<<"\n\tCONTACT NO. : "<<phno<<"\n\n";
 delay(500);
 pline(14,80);
 delay(50);
 cout<<"\n\n\tENTER NEW NAME (OR '.'TO RETAIN OLD ONE) : ";
 s15:gets(nm);
 if(nm[0]!='.')
 {
  for(int s=0;s<strlen(nm);s++)
  {
   if(nm[s]!=' ')
   {
    if(!isalpha(nm[s]))
     {wrong(" NAME: ");
      goto s15;
      }
    }
   }
  }
 cout<<"\tENTER NEW ADDRESS (OR '.'TO RETAIN OLD ONE) : ";
 gets(add);
  cout<<"\tENTER NEW E-MAIL ADDRESS (OR '.'TO RETAIN OLD ONE) : ";
 gets(eid);
  cout<<"\tENTER NEW CONTACT NO. (OR '.'TO RETAIN OLD ONE) : ";
 s12:gets(cno);
 if(nm[0]!='.')
 {
  strcpy(name,nm);
  }
 if(add[0]!='.')
 {
  strcpy(addr,add);
  }
 if(eid[0]!='.')
 {
 strcpy(emailid,eid);
 }
 if(cno[0]!='.')
 {
  for(j=0;j<strlen(cno);j++)
  {
   if(isalpha(cno[j]))
     goto s13;
  }
  if((strlen(cno)!=10 && strlen(cno)!=7))
  {
  s13:cout<<"\t";
  textcolor(RED);
  cprintf("PLEASE ENTER A VALID CONTACT NO. : ");goto s12;
  }
  strcpy(phno,cno);
 }
message("PLEASE WAIT!... MODIFYING RECORD... ");
message("RECORD MODIFIED SUCCESSFULLY!");
textcolor(10);
cprintf("\n\n%s\n","MODIFIED RECORD OF STUDENT :");
textcolor(15);
cprintf(" ");
delay(50);
cout<<"\n\tROLL NO. = "<<rolno;
delay(50);
cout<<"\n\tSTUDENT'S NAME : "<<name;
delay(50);
cout<<"\n\tADDRESS : "<<addr;
delay(50);
cout<<"\n\tE-MAIL ADDRESS : ";
delay(50);
cout<<emailid<<"\n\tCONTACT NO. : "<<phno;
}                      //CLOSING MODIFY
};       //END OF CLASS SCHOOL
//___________
//CLASS MARKS
//___________
class marks
{
int marks[5],per,total,markstat,res;
char sub[6][25];
public:
marks()
{
marks[1]=0;
marks[2]=0;
marks[3]=0;
marks[4]=0;
marks[5]=0;
markstat=0;
}

void suballot(int clasno)        //FUNTION SUBALLOT TO ALLOT MAIN AND OPTIONAL
{                      //SUBJECTS OF ALLL STUDENTS ACCORDING TO THEIR CLASSES
 if(clasno>=1 && clasno<5)
  { strcpy(sub[1],"ENGLISH");
    strcpy(sub[2],"HINDI");
    strcpy(sub[3],"MATHEMATICS");
    strcpy(sub[4],"ENVIRONMENTAL STUDIES");
    strcpy(sub[5],"GENERAL KNOWLEDGE");
  }
  else if(clasno>=5&&clasno<=8)
  {
  strcpy(sub[1],"ENGLISH");
  strcpy(sub[2],"HINDI");
  strcpy(sub[3],"MATHEMATICS");
  strcpy(sub[4],"SCIENCE");
  strcpy(sub[5],"SOCIAL STUDIES");
  }
  else if(clasno>=9&&clasno<=10)
  {
  strcpy(sub[1],"SCIENCE");
  strcpy(sub[2],"SOCIAL SCIENCE");
  strcpy(sub[3],"MATHEMATICS");
  strcpy(sub[4],"ENGLISH");
  cout<<"\n\tOPTIONAL SUBJECTS :\n\n\t1. HINDI\n\t2. SANSKRIT\n\t3. FRENCH\n\tENTER YOUR CHOICE :";
  s1:cin>>choice;
  switch(choice)
  {
  case 1:strcpy(sub[5],"HINDI");break;
  case 2:strcpy(sub[5],"SANSKRIT");break;
  case 3:strcpy(sub[5],"FRENCH");break;
  default:wrong(" CHOICE (ONLY 1,2,3)");goto s1;
  };
  }
  else
  {strcpy(sub[5],"ENGLISH");
  cout<<"\n\tSELECT STUDENT'S STREAM\n\n\t1. PCM\n\t2. PCB\n\t3. COMMERCE\n\tENTER YOUR CHOICE : ";
  s2:cin>>choice;
  switch(choice)
  {
  case 1:strcpy(sub[1],"PHYSICS");
	 strcpy(sub[2],"CHEMISTRY");
	 strcpy(sub[3],"MATHEMATICS");
	 break;
  case 2:
	 strcpy(sub[1],"PHYSICS");
	 strcpy(sub[2],"CHEMISTRY");
	 strcpy(sub[3],"BIOLOGY");
	 break;
  case 3:
	 strcpy(sub[1],"BUSINESS STUDIES");
	 strcpy(sub[2],"ACCOUNTENCY");
	 strcpy(sub[3],"ECONOMICS");
	 break;
 default:{wrong(" CHOICE (ONLY 1,2,3): ");
	  goto s2;}
};
  cout<<"\n\tSELECT YOUR OPTIONAL SUBJECT\n\n\t1. COMPUTER SCIENCE\n\t2. PHYSICAL EDUCATION";
  cout<<"\n\t3. MASS MEDIA\n\t4. INFORMATION PRACTICES";
  if(choice==3)
  cout<<"\n\t5. MATHEMATICS ";
  cout<<"\n\tENTER YOUR CHOICE : ";
  s3:cin>>choice;
  switch(choice)
 {
  case 1:strcpy(sub[4],"COMPUTER SCIENCE");
	 break;
  case 2:strcpy(sub[4],"PHYSICAL EDUCATION");
	 break;
  case 3:strcpy(sub[4],"MASS MEDIA");
	 break;
  case 4:strcpy(sub[4],"INFORMATION PRACTICES");
	  break;
  case 5:if(strcmp(sub[1],"PHYSICS")==0)
	 {
	 wrong(" CHOICE : ");
	 goto s3;
	 }
	 else
	 strcpy(sub[4],"MATHEMATICS")	;
	 break;
 default:{wrong(" CHOICE : ");
	 goto s3;
	 }
 };
}
}
void showsub(int d=0)         //FUNCTION TO SHOW SUBJECTS OF A STUDENT
{
textcolor(11);
cout<<"\n\n\t";
cprintf("STUDENT'S SUBJECTS :");
cout<<"\n";
for(int c=1;c<6;c++)
{
cout<<"\n\t";
textcolor(10);
cprintf(sub[c]);
if(d==1)
{
delay(50);
}
}
}
void getmarks()                         //FUNCTION GETMARKS TO ENTER
{                                       //THE MARKS OF EACH STUDENT
 int i;
 if(markstat==1)
 {
  cout<<"\n\n\t";
  textcolor(4);
  cprintf("MARKS ARE ALREADY ALLOTED DO YOU WANT TO OVER WRITE(Y/N)? ");
  cin>>ch;
  if(toupper(ch)=='Y')
    markstat=0;
   else
   { cout<<"\n\n\t\t\t";
     textcolor(10);
     cprintf("MARKS RETAINED ");
   }
}
if(markstat==0)
{
 cout<<"ENTER MARKS OF STUDENT "<<"\n\n";
 total=0;
 for(i=1;i<6;i++)
 {
  s4:cout<<setw(25)<<sub[i]<<" : ";
  cin>>marks[i];
  if(marks[i]>100 || marks[i]<0)
  {
   textcolor(4);
   cprintf("RE-ENTER YOUR MARKS : ");
   goto s4;
   }
  total+=marks[i];
 }
  per=total/5;
  markstat=1;
  if(per>=33)
   { res=1; }
 else
   { res=2;}
 }
}
void stat()
{
if(markstat==0)
{textcolor(14);
cprintf("NOT ALLOTED");
}
else if(markstat==1)
{
 textcolor(10);
 cprintf("ALLOTED");
}
}
void showmarks(int d=0)                      //FUNCTION SHOWMARKS TO SHOW
{                                     //MARKS OF STUDENTS
int i;
if(markstat==1)
{
cout<<"\n\n\t";
textcolor(2);
cprintf("STUDENT'S MARKS GAINED ARE AS FOLLOW : ");
cout<<"\n\n";
for(i=1;i<6;i++)
{
cout<<"\t"<<sub[i]<<" : "<<marks[i]<<"\n";
if(d==1)
{
delay(50);
}
}
cout<<"\n";
pline(5,80);
if(d==1)
{
delay(50);
}
cout<<"\n\n\t";
textcolor(11);
cprintf("TOTAL MARKS OBTAINED : ");
cout<<total<<"/500\n\t";
if(d==1)
{
delay(50);
}
cprintf("PERCENTEAGE GAINED : ");
cout<<per<<" %\n\n";
if(d==1)
{
delay(50);
}
 if(res==1)
 {
 cout<<"\n\t\t";
 textcolor(10);
 cprintf("PASS! STUDENT IS PROMOTED TO NEXT CLASS ");
 }
 if(res==2)
 {
  cout<<"\n\t\t";
  textcolor(4);
  cprintf(" FAIL! STUDENT IS NOT PROMOTED TO NEXT CLASS");
 }
}
else
{
 message("MARKS NOT ALLOTTED");
 delay(100);
}
}
void result()   //FUNCTION TO SHOW RESULT
{
switch(res)
{
case 1:textcolor(10);
	   cprintf("PASS");
	   break;
case 2:textcolor(4);
	   cprintf("FAIL");
	   break;
default:  if(markstat==0)
	 {textcolor(14);
	  cprintf("NOT ALLOTED");
	  }break;
};
}
};
//___________________
//END OF CLASS MARKS
//___________________
//____________
//CLASS FEES *
//____________
class fees
{
int fee[4],paymod,status;
public:
fees()
{
fee[0]=0;
fee[1]=0;
fee[2]=0;
fee[3]=0;
status=0;
}
~fees()
{
}
void payfee(int clasno)                   //FUNCTION PAY FEE TO MANAGE FEES
{                               //OF STUDENTS
long int amt;
int i;
if(clasno>=1&&clasno<5)
 amt=32000;
else if(clasno>4 && clasno<9)
 amt=40000;
else
 amt=48000;

 if(status==0)
 {
 fees();
 cout<<"\tDO YOU WANT TO PAY FEES IN:\n\t1. INSTALLMENT \n\t2. IN LUMPSUM\n ";
 s25:cin>>paymod;
 }


switch(paymod)
{
case 1:
	i=0;
	while(fee[i]!=0)
	{
	 ++i;
	}
	 if(i>=4)
	 {
	 status=1;
	 goto s24;
	 }
	 cout<<"\n\tINSTALLMENT NO. "<<i+1<<" HAS TO BE PAYED ";
	 cout<<"\n\tPAY THE INSTALLMENT NOW (Y/N)? ";
	 cin>>ch;
	if(toupper(ch)=='Y')
	{
	 fee[i]=1;
	 cout<<"\n\t";
	 textcolor(10);
	 cprintf("AMOUNT RECIEVED ");
	 status=i+3;
	}
	else
	goto s27;
	break;

case 2: if(fee[3]==1)
	 {
	  status=1;
	  goto s24;}

	cout<<"\n\tPAY THE FEES NOW IN LUMPSUM AMOUNT OF RS : "<<amt<<" (Y/N)?";
	cin>>ch;
	if(toupper(ch)=='Y')
	{  for(i=0;i<4;i++)
	 {
	  fee[i]=1;
	 }
	 status=1;
	}

       if(fee[3]==1)
       {
	s24:cout<<"\n\n\t\t\t";
	textcolor(3);
	cprintf("FEES HAS BEEN PAID");
       }
       else if(toupper(ch)=='N')
       {
	s27:cout<<"\n\n\t\t\t";
	textcolor(4);
	cprintf("FEES IS DUE ");
	status=2;
	}
    break;

default:textcolor(RED);
	wrong("       PAYMODE(1or2 only)? : ");
	status=0;
	paymod=0;
	goto s25;
	 break;
  };
}
void stats()
{
switch(status)
{
case 0:textcolor(11);
       cprintf("UNCHECKED!");
       break;
case 1:textcolor(10);
       cprintf("PAID");

       break;
case 2:textcolor(4);
       cprintf("DUE");
       break;
case 3:textcolor(2);
       cprintf("1st PAID");
       break;
case 4:textcolor(2);
       cprintf("2nd PAID");
       break;
case 5:textcolor(2);
       cprintf("3rd PAID");
       break;
case 6:textcolor(10);
       cprintf("PAID");
       break;
};
}
int check()
{
int chk;
if(status==0 || status==2)
{
 chk=1;
}
else
{
chk=0;
}
return(chk);
}
}; //___________________
   //END OF CLASS FEES *
   //___________________
void wrong(char sen[25])           //WRONG CHOICE
{
textcolor(RED);
cprintf("        PLEASE RE-ENTER YOUR ");
cprintf(sen);
getch();
}
//______________________________________________
//FUNCTION TO DELETE DATA FILES PRESENT ON DISK
//______________________________________________
void dlete(int no,int x=1)
{
for(int s=0;s<x;s++)
{
switch(no)
{
case 1:remove("cl1.dat");
       remove("cl1f.dat");
       remove("cl1m.dat");
       break;
case 2:remove("cl2.dat");
       remove("cl2f.dat");
       remove("cl2m.dat");
       break;

case 3:remove("cl3.dat");
       remove("cl3f.dat");
       remove("cl3m.dat");
       break;
case 4:remove("cl4.dat");
       remove("cl4f.dat");
       remove("cl4m.dat");
       break;

case 5:remove("cl5.dat");
       remove("cl5f.dat");
       remove("cl5m.dat");
       break;

case 6:remove("cl6.dat");
       remove("cl6f.dat");
       remove("cl6m.dat");
       break;

case 7:remove("cl7.dat");
       remove("cl7f.dat");
       remove("cl7m.dat");
       break;

case 8:remove("cl8.dat");
       remove("cl8f.dat");
       remove("cl8m.dat");
       break;

case 9:remove("cl9.dat");
       remove("cl9f.dat");
       remove("cl9m.dat");
       break;
case 10:remove("cl10.dat");
	remove("cl10f.dat");
	remove("cl10m.dat");
	break;
case 11:remove("cl11.dat");
	remove("cl11f.dat");
	remove("cl11m.dat");
	break;
case 12:remove("cl12.dat");
	remove("cl12f.dat");
	remove("cl12m.dat");
	break;

default:cprintf("UNABLE TO DELETE FILE OF CLASS : ");
	cout<<no;
	break;
};
++no;
}
getch();
}
//______________________________
//STARTUP FUNCTION FOR LOGIN
//______________________________
void start()
{
 int clno,rep,i,j,len,p=0,wp=0,plen;
 char schname[21],pas[11],cod[11];
 ifstream in("config.dat",ios::in || ios::binary);  // IF SNAME DOSEN'T EXIST
 if(!in)
 {
 ofstream out("config.dat",ios::out || ios::app || ios::binary);
 cout<<"\n\n\t\t\t\t";
 textcolor(11);
 cprintf("WELCOME");
 cout<<"\n\n\t\tENTER YOUR SCHOOL NAME PLEASE : ";
 s33:gets(schname);                     // TAKING SCHOOL NAME FROM THE USER
 for(int z=0;z<strlen(schname);z++)
 {
  if((!isalpha(schname[z])) && (schname[z]!=' '))
  {
   textcolor(4);
   cout<<"\n\t\t";
   cprintf("RE-ENTER THE SCHOOL NAME");
   goto s33;
  }
 }
 for(z=0;z<strlen(schname);z++)
 {
 if(islower(schname[z]))
   schname[z]=toupper(schname[z]);
 }
 len=strlen(schname);
 out.seekp(0);
 out<<len;
 out.write((char*)&schname,len); //STORING THE SCHOOL NAME
 cout<<"\n\t\tSET UP YOUR LOGIN PASSWORD : ";
 s34:cin>>pas;  //SETTING UP LOGIN PASSWORD FOR THE USER
 plen=strlen(pas);
 for(z=0;z<5;z++)
 {
  if(!(isalnum(pas[z])))
  {
   s35:textcolor(4);
   cout<<"\n\t\t";
   cprintf("RE-ENTER YOUR PASSWORD : ");
   goto s34;
  }
 }
 if(z<4)
  { goto s35;}
 else
 {
  out<<plen;
  out.write((char*)&pas,plen); // STORING THE PASSWORD IN THE FILE
 }
 clrscr();
 textcolor(10);
 cout<<"\n\n\t\t\t";
 cprintf("NOW YOU ARE READY ");
 delay(500);
 out.close();
 } //!in
else
{
in.seekg(0);
in>>len;                       //SCHOOL NAME FROM FILE
in.read((char*)&schname,len);
in>>plen;
in.read((char*)&pas,plen);     //READING PASSWORD
in.close();
s36:clrscr();
}
textcolor(15);
cprintf(" ");
cout<<"\n\n\n\t\tENTER YOUR PASSWORD PLEASE OR ENTER 0 TO EXIT : ";
cin>>cod;
if(cod[0]=='0')
exit(0);              //TAKING PASSWORD FROM THE USER
++wp;
p=0;
if(strlen(cod)==plen)
{
for(int z=0;z<plen;z++)
{
 if(cod[z]==pas[z])
  ++p;
}
}
if(p==plen)      //IF ENTERED PASSWORD IS CORRECT
{
 clrscr();
 textcolor(10);
 cout<<"\n\n\n\t\t";
 cprintf("ACCESS GRANTED PRESS ENTER TO CONTINUE");
 }
else                          //FOR ENTERING WRONG PASSWORD
{
   textcolor(4);
   cout<<"\n\t\t";
   if(wp<5 && wp>0)
   {
   cprintf("WRONG PASSWORD : ");
   delay(1000);
   textcolor(15);
   cprintf(" ");
   goto s36;
   }
   else if(wp==5)
   {
    cprintf("ACCESS DENIED");
    delay(1000);
    exit(0);
   }
}
getch();
}

void loading(int k)   //LOADING ANIMATION
{
clrscr();
int c,i,j;
do
{
for(i=1;i<10;i++)
{
  clrscr();
  cout<<"\n\n\n\n\t\t\t\t";
  textcolor(k);
  cprintf("PLEASE WAIT!");
  cout<<"\n\n\n";
  for(j=1;j<i;j++)
  {
  cout<<"\t";
  }
  textcolor(11);
  cprintf("______________");
  delay(40);
}
--k;
}while(k>0);
clrscr();
}

void wait(char prnt[44],int a) //LOADING LINE ANIMATION
{
do
{
clrscr();
for(int j=0;j<39;j++)
{
clrscr();
  cout<<"\n\n\n\n\t\t\t\t  ";
  textcolor(11);
  cprintf(prnt);
  cout<<"\n\n";
for(int i=0;i<39;i++)
{
if(i==j)
textcolor(11);
else
textcolor(4);
cprintf("__");
}
delay(20);
}
a--;
}while(a>0);
}
//_____________
//MAIN FUNCTION
//_____________
void main()
{
ifstream fin,finf,finm;
ofstream fout,foutf,foutm;
void wrong(char sen[15]);
void dlete(int no,int x=1);
void memorystat(int d);
void message(char msg[50]);
void loading(int k);
void wait(char prnt[44],int a);
void line(int n,int col,int d);
void back(int n,int col,int d);
void anim();
void pline(int col,int len);
school A[21];
marks M[21];
int clno,rep,i,j,len,p=0,plen;
char schname[21],pas[11],cod[11],cho;
strt:start();
line(6,4,80);
wait("WELCOME",2);
anim();
do
{
clrscr();
fees F[21];
ifstream fins("config.dat",ios::in | ios::binary);
fins.seekg(0);
fins>>len;
fins.read((char*)&schname,len);
fins>>plen;
fins.read((char*)&pas,plen);
fins.close();
cout<<"\n\n\t\t\t       ";
textcolor(1);
cout.write(schname,len);
textcolor(14);
cout<<"\n\n\t\t\t\t";
cprintf("  MAIN MENU ");
cout<<"\n";
pline(11,80);
cout<<"\n\t\t\t(1).  ADD STUDENT RECORD\n";
delay(50);
cout<<"\t\t\t(2).  VIEW RECORDS OF A CLASS\n";
delay(50);
cout<<"\t\t\t(3).  MODIFY RECORDS\n";
delay(50);
cout<<"\t\t\t(4).  DELETE RECORDS\n";
delay(50);
cout<<"\t\t\t(5).  CHECK FEES\n";
delay(50);
cout<<"\t\t\t(6).  ALLOT STUDENT'S MARKS\n";
delay(50);
cout<<"\t\t\t(7).  SHOW STUDENT'S MARKS\n";
delay(50);
cout<<"\t\t\t(8).  SEE DATABASE STATUS\n";
delay(50);
cout<<"\t\t\t(9).  RESET\n";
delay(50);
cout<<"\t\t\t(0).  EXIT\n";
pline(11,80);
cout<<"\n\t\tENTER YOUR CHOICE (0 - 9) : ";
delay(50);
s7:cin>>cho;

if((cho<'0' || cho>'9' ) || isalpha(cho))
{
textcolor(RED);
cprintf("                RE-ENTER YOUR CHOICE : ");
goto s7;
}
else
{
if(cho!='0'&& cho!='9'&& cho!='8')
{cout<<"\t\tENTER THE CLASS NO.(1-12) : ";
s5:cin>>clno;
switch(clno)             //TO OPEN CLASSES RECORDS FILES FROM DISK
{
case 1:fout.open("cl1.dat",ios::out || ios::binary || ios::app);
       fin.open("cl1.dat",ios::in || ios::binary);
       foutm.open("cl1m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl1m.dat",ios::in || ios::binary);
       foutf.open("cl1f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl1f.dat",ios::in || ios::binary);
       break;
case 2:fout.open("cl2.dat",ios::out || ios::binary || ios::app);
       fin.open("cl2.dat",ios::in || ios::binary);
       foutm.open("cl2m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl2m.dat",ios::in || ios::binary);
       foutf.open("cl2f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl2f.dat",ios::in || ios::binary);
       break;
case 3:fout.open("cl3.dat",ios::out || ios::binary || ios::app);
       fin.open("cl3.dat",ios::in || ios::binary);
       foutm.open("cl3m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl3m.dat",ios::in || ios::binary);
       foutf.open("cl3f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl3f.dat",ios::in || ios::binary);
       break;
case 4:fout.open("cl4.dat",ios::out || ios::binary || ios::app);
       fin.open("cl4.dat",ios::in || ios::binary);
       foutm.open("cl4m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl4m.dat",ios::in || ios::binary);
       foutf.open("cl4f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl4f.dat",ios::in || ios::binary);
       break;
case 5:fout.open("cl5.dat",ios::out || ios::binary || ios::app);
       fin.open("cl5.dat",ios::in || ios::binary);
       foutm.open("cl5m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl5m.dat",ios::in || ios::binary);
       foutf.open("cl5f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl5f.dat",ios::in || ios::binary);
       break;
case 6:fout.open("cl6.dat",ios::out || ios::binary || ios::app);
       fin.open("cl6.dat",ios::in || ios::binary);
       foutm.open("cl6m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl6m.dat",ios::in || ios::binary);
       foutf.open("cl6f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl6f.dat",ios::in || ios::binary);
       break;
case 7:fout.open("cl7.dat",ios::out || ios::binary || ios::app);
       fin.open("cl7.dat",ios::in || ios::binary);
       foutm.open("cl7m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl7m.dat",ios::in || ios::binary);
       foutf.open("cl7f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl7f.dat",ios::in || ios::binary);
       break;
case 8:fout.open("cl8.dat",ios::out || ios::binary || ios::app);
       fin.open("cl8.dat",ios::in || ios::binary);
       foutm.open("cl8m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl8m.dat",ios::in || ios::binary);
       foutf.open("cl8f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl8f.dat",ios::in || ios::binary);
       break;
case 9:fout.open("cl9.dat",ios::out || ios::binary || ios::app);
       fin.open("cl9.dat",ios::in || ios::binary);
       foutm.open("cl9m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl9m.dat",ios::in || ios::binary);
       foutf.open("cl9f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl9f.dat",ios::in || ios::binary);
       break;
case 10:fout.open("cl10.dat",ios::out || ios::binary || ios::app);
	fin.open("cl10.dat",ios::in || ios::binary);
	foutm.open("cl10m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl10m.dat",ios::in || ios::binary);
       foutf.open("cl10f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl10f.dat",ios::in || ios::binary);
	break;
case 11:fout.open("cl11.dat",ios::out || ios::binary || ios::app);
	fin.open("cl11.dat",ios::in || ios::binary);
	foutm.open("cl11m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl11m.dat",ios::in || ios::binary);
       foutf.open("cl11f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl11f.dat",ios::in || ios::binary);
	break;
case 12:fout.open("cl12.dat",ios::out || ios::binary || ios::app);
	fin.open("cl12.dat",ios::in || ios::in);
	foutm.open("cl12m.dat",ios::out || ios::binary || ios::app);
       finm.open("cl12m.dat",ios::in || ios::binary);
       foutf.open("cl12f.dat",ios::out || ios::binary || ios::app);
       finf.open("cl12f.dat",ios::in || ios::binary);
	break;
default:textcolor(RED);
	cprintf("                RE-ENTER THE CLASS NO. : ");goto s5;
};
}clrscr();
switch(cho)                      //TO SWITCH MAIN MENU CHOICES
{
case '1':i=0;                    //TO ADD RECORDS
       while(!fin.eof())
       {++i;
       fin.read((char*)&A[i],sizeof (A[i]));
       finm.read((char*)&M[i],sizeof (M[i]));
       };
       if(i<21)
       {do
       {
       line(4,14,80);
       clrscr();
       cout<<"\n\n\t";
       textcolor(11);
       cprintf("REGISTERED STUDENTS RECORDS TILL NOW : ");
       cout<<i-1;
       textcolor(15);
       cprintf(".\n");
       A[i].get(clno,i);
       M[i].suballot(clno);
       fout.seekp(0,ios::end);
       foutm.seekp((i-1)*sizeof(M[i]));
       fout.write((char*)&A[i],sizeof(A[i]));
       foutm.write((char*)&M[i],sizeof (M[i]));
       i++;
       delay(300);
       loading(2);
       message("RECORD CREATED ");
       A[i-1].showall(clno,1,1);
       M[i-1].showsub(1);
       cout<<"\n\n\t\tDO YOU WANT TO ADD MORE RECORDS (Y/N)? ";
       cin>>ch;
       if(i==21)
       goto s18;
       }while(toupper(ch)=='Y');
       cho='y';
       goto s0;
       }
       else
       {
       cout<<"\n\n\n";
       textcolor(GREEN);
       s18:message("CLASS IS FULL! NO MORE RECORDS CAN BE ADDED\n");
       delay(1000);
       }
       break;

case '2':rep=0;
	 line(4,11,80);
	 s21:textcolor(15);
	 cprintf(" ");
	 clrscr();
	 textcolor(11);
	 cprintf("\n\n%s%d\n","LIST OF STUDENTS OF CLASS :",clno);
	 cout<<"\n ROLL NO.\t\t    NAME\t\t CONTACT NO.\n";
	 pline(11,80);
	 cout<<"\n";
	 if(toupper(ch)!='B')
	 {
	 i=1;
	 while(!fin.eof())
	 {
	  fin.read((char*)&A[i],sizeof (A[i]));
	  finm.read((char*)&M[i],sizeof (M[i]));
	  ++i;
	 }
	 }
	  for(int n=1;n<i-1;n++)
	 {
	 A[n].show(1);
	 if(rep==0)
	 {
	 delay(50);
	 }
	 }
	 if(i==2)
	 {
	  message("CLASS IS EMPTY !..");
	  delay(100);
	  cho='y';
	  goto s0;
	 }
	 textcolor(YELLOW);
	 cout<<"\n\n\t";
	 cprintf("TOTAL RECORDS PRESENT : ");
	 cout<<(i-2)<<"\n";
	 pline(11,80);
	 cout<<"\n\tENTER STUDENT'S ROLL NO. TO VIEW IT'S DETAILS OR 0 TO GO BACK : ";
	 s20:textcolor(15);
	     cprintf(" ");
	 cin>>j;           //STEP  S20
	 int N=j-(clno*100);
	 if(j==0)
	  {
	   back(4,11,80);
	   cho='y';
	   goto s0;
	  }
	 else if(N<i-1 && N>0)
	 {
	  s22:clrscr();
	      textcolor(15);
	      cprintf("  RECORD : ");
	      cout<<N<<"/"<<i-2;
	      A[N].showall(clno,1);
	      M[N].showsub();
	  cout<<"\n";
	  pline(4,80);
	  textcolor(15);
	  cprintf(" ");
	  cout<<"\n\tN TO SEE NEXT ONE \n\tP TO SEE PREVIOS ONE \n\tOR B TO GO BACK :";
	  s23:cin>>ch;
   switch(ch)
   {
   case 'b':
   case 'B':++rep;
	    goto s21;
	    break;
   case 'n':
   case 'N': if(N<i-2)
	     {++N;
	      goto s22; }
	     else
	     { textcolor(14);
	       cprintf("        THIS IS THE LAST ONE!");
	     textcolor(15);
	     cprintf(" ");
	     goto s23; }
	      break;
   case 'p':
   case 'P': if(N>1)
	       {  --N;
		goto s22; }
	    else
	    {textcolor(14);
	       cprintf("        THIS IS THE FIRST ONE! ");
	     textcolor(15);
	     cprintf(" ");
	     goto s23;  }
  default:textcolor(RED);
	  cout<<"\t";
	  cprintf("RE-ENTER YOUR CHOICE ");
	  goto s23;
  };
	}
	 else
	 {
	  textcolor(4);
	  cout<<"\t";
	  j=0;
	  wrong("ROLL NO. ");
	  //cprintf("RE-ENTER ROLL NO. (OR 0 TO GO BACK) : ");
	  goto s20;
	 }

	  break;

case '3':clrscr();
	 i=1;
	 while(!fin.eof())
	 {
	  fin.read((char*)&A[i],sizeof (A[i]));
	  ++i;
	 }
	  if(i==2)
	 {
	  message("CLASS IS EMPTY !..");
	  cho='y';
	  goto s0;
	 }
	 line(4,14,50);
	 do
	 {
	 clrscr();
	 textcolor(15);
	 cprintf(" ");
	 cout<<"\n\n ROLL NO.\t\tNAME\n\n";
	 pline(14,50);
	 cout<<"\n\n";
	  for(n=1;n<i-1;n++)
	 {
	  A[n].show(0);
	  cout<<"\n";
	  if(rep==0)
	  {
	   delay(40);
	  }
	 }
	  cout<<"\n";
	 textcolor(YELLOW);
	 cprintf("   TOTAL RECORDS PRESENT : ");
	 cout<<(i-2)<<"\n";
	 pline(14,80);
	  textcolor(15);
	  cprintf(" ");
	  cout<<"\nENTER STUDENT'S ROLL NO. TO MODIFY THE RECORD (OR 0 TO GO BACK) : ";
	  s11:cin>>j;
	  n=j-(clno*100);
	  if(n<i-1&&n>0)
	  {
	  cout<<"RECORD FOUND ! \n";
	  textcolor(15);
	  cprintf(" ");
	  A[n].modify();
	  fout.seekp((n-1)*sizeof(A[n]));
	  fout.write((char*)&A[n],sizeof(A[n]));
	  }
	  else
	  {
	  textcolor(RED);
	  cprintf("SORRY!.. RECORD NOT FOUND\n RE-ENTER ROLL NO.: ");
	  cout<<"\nOR ENTER '0' TO GO BACK : ";
	  if(j==0)
	  {
	   back(4,14,50);
	   cho='y';
	   goto s0;
	  }
	  else
	  goto s11;
	 }
	 textcolor(15);
	 cprintf(". ");
	 cout<<"\n\n\t\ DO YOU WANT TO MODIFY MORE RECORDS(Y/N)? : ";
	 cin>>ch;
	 if(toupper(ch)=='N')
	 {
	 cho='Y';
	 goto s0;
	 }
	 }while(toupper(ch)=='Y');
	 break;

case '4':rep=0;
	 line(5,14,50);
	 do
	 {
	 textcolor(15);
	 cprintf(" ");
	 clrscr();
	 fout.close();
	 foutf.close();
	 foutm.close();
	 fout.open("temp.dat",ios::out || ios::app || ios::binary);
	 foutf.open("tempf.dat",ios::out || ios::app || ios::binary);
	 foutm.open("tempm.dat",ios::out || ios::app || ios::binary);
	 fout.seekp(0,ios::beg);
	 foutf.seekp(0,ios::beg);
	 foutm.seekp(0,ios::beg);
	 i=1;
	 fin.seekg(0,ios::beg);
	 while(!fin.eof())
	  {
	   fin.read((char*)&A[i],sizeof (A[i]));
	   finf.read((char*)&F[i],sizeof (F[i]));
	   finm.read((char*)&M[i],sizeof (M[i]));
	   ++i;
	  }
	 if(i==2)
	 {
	  message("CLASS IS EMPTY !..");
	  delay(100);
	  cho='y';
	  goto s0;
	 }
	   cout<<"\n";
	   textcolor(GREEN);
	   cprintf("    CLASS : ");
	   cout<<clno;
	   textcolor(15);
	   cprintf(" ");
	   cout<<"\n\n ROLL NO.\t\tNAME\n\n";
	 pline(14,50);
	 cout<<"\n\n";
	  for(n=1;n<i-1;n++)
	 {
	  A[n].show(0);
	  cout<<"\n";
	  if(rep==0)
	  {
	  delay(40);
	  }
	 }
	 cout<<"\n";
	 textcolor(YELLOW);
	 cprintf("   TOTAL RECORDS PRESENT : ");
	 cout<<(i-2)<<"\n";
	  pline(14,50);
	 textcolor(15);
	 cprintf(" ");
	 cout<<"\n\n\tENTER THE ROLL NO. OF THE RECORD TO BE DELETED";
	 cout<<"\n\tOR 0 TO GO BACK TO MAIN MENU : ";
	 s19:cin>>j;
	    int del=j-(clno*100);
	    if(del<(i-1) && del>0)
	     {
	      for(n=1;n<i-1;n++)
	      {
	       if(del==n)
	       {
		textcolor(RED);
		cprintf("        DO YOU WANT TO DELETE THE RECORD OF : ");
		A[n].snm();
		cprintf(" (Y/N)? ");
		cin>>ch;
		if(toupper(ch)=='N')
		 {
		  fout.write((char*)&A[n],sizeof (A[n]));
		  foutf.write((char*)&F[n],sizeof (F[n]));
		  foutm.write((char*)&M[n],sizeof (M[n]));
		  textcolor(11);
		  cout<<"\n\t\t";
		  cprintf("RECORD RETAINED! PRESS ENTER TO CONTINUE");
		 }
		else
		 {
		 textcolor(11);
		 cout<<"\n\t\t";
		 cprintf("RECORD DELETED! PRESS ENTER TO CONTINUE");
		 }
		}
		else
		{
		 if(n>del)
		 {
		  A[n].droprol();
		 }
		 fout.write((char*)&A[n],sizeof (A[n]));
		 foutf.write((char*)&F[n],sizeof (F[n]));
		 foutm.write((char*)&M[n],sizeof (M[n]));
		}
	       }
	     fin.close();
	     finf.close();
	     finm.close();
	  fout.close();
	  foutf.close();
	  foutm.close();
	  switch(clno)
	  {
	   case 1:  dlete(clno);
		    rename("temp.dat","cl1.dat");
		    rename("tempf.dat","cl1f.dat");
		    rename("tempm.dat","cl1m.dat");
		    fin.open("cl1.dat",ios::in || ios::binary);
		    finf.open("cl1f.dat",ios::in || ios::binary);
		    finm.open("cl1m.dat",ios::in || ios::binary);
		    break;
	   case 2:  dlete(clno);
		    rename("temp.dat","cl2.dat");
		    rename("tempf.dat","cl2f.dat");
		    rename("tempm.dat","cl2m.dat");
		    fin.open("cl2.dat",ios::in || ios::binary);
		    finf.open("cl2f.dat",ios::in || ios::binary);
		    finm.open("cl2m.dat",ios::in || ios::binary);
		    break;
	   case 3:  dlete(clno);
		    rename("temp.dat","cl3.dat");
		    rename("tempf.dat","cl3f.dat");
		    rename("tempm.dat","cl3m.dat");
		    fin.open("cl3.dat",ios::in || ios::binary);
		    finf.open("cl3f.dat",ios::in || ios::binary);
		    finm.open("cl3m.dat",ios::in || ios::binary);
		    break;
	   case 4:  dlete(clno);
		    rename("temp.dat","cl4.dat");
		    rename("tempf.dat","cl4f.dat");
		    rename("tempm.dat","cl4m.dat");
		    fin.open("cl4.dat",ios::in || ios::binary);
		    finf.open("cl4f.dat",ios::in || ios::binary);
		    finm.open("cl4m.dat",ios::in || ios::binary);
		    break;
	   case 5:  dlete(clno);
		    rename("temp.dat","cl5.dat");
		    rename("tempf.dat","cl5f.dat");
		    rename("tempm.dat","cl5m.dat");
		    fin.open("cl5.dat",ios::in || ios::binary);
		    finf.open("cl5f.dat",ios::in || ios::binary);
		    finm.open("cl5m.dat",ios::in || ios::binary);
		    break;;
	   case 6:  dlete(clno);
		    rename("temp.dat","cl6.dat");
		    rename("tempf.dat","cl6f.dat");
		    rename("tempm.dat","cl6m.dat");
		    fin.open("cl6.dat",ios::in || ios::binary);
		    finf.open("cl6f.dat",ios::in || ios::binary);
		    finm.open("cl6m.dat",ios::in || ios::binary);
		    break;;
	   case 7:  dlete(clno);
		    rename("temp.dat","cl7.dat");
		    rename("tempf.dat","cl7f.dat");
		    rename("tempm.dat","cl7m.dat");
		    fin.open("cl7.dat",ios::in || ios::binary);
		    finf.open("cl7f.dat",ios::in || ios::binary);
		    finm.open("cl7m.dat",ios::in || ios::binary);
		    break;
	   case 8:  dlete(clno);
		    rename("temp.dat","cl8.dat");
		    rename("tempf.dat","cl8f.dat");
		    rename("tempm.dat","cl8m.dat");
		    fin.open("cl8.dat",ios::in || ios::binary);
		    finf.open("cl8f.dat",ios::in || ios::binary);
		    finm.open("cl8m.dat",ios::in || ios::binary);
		    break;
	   case 9:  dlete(clno);
		    rename("temp.dat","cl9.dat");
		    rename("tempf.dat","cl9f.dat");
		    rename("tempm.dat","cl9m.dat");
		    fin.open("cl9.dat",ios::in || ios::binary);
		    finf.open("cl9f.dat",ios::in || ios::binary);
		    finm.open("cl9m.dat",ios::in || ios::binary);
		    break;;
	   case 10: dlete(clno);
		    rename("temp.dat","cl10.dat");
		    rename("tempf.dat","cl10f.dat");
		    rename("tempm.dat","cl10m.dat");
		    fin.open("cl10.dat",ios::in || ios::binary);
		    finf.open("cl10f.dat",ios::in || ios::binary);
		    finm.open("cl10m.dat",ios::in || ios::binary);
		    break;
	   case 11: dlete(clno);
		    rename("temp.dat","cl11.dat");
		    rename("tempf.dat","cl11f.dat");
		    rename("tempm.dat","cl11m.dat");
		    fin.open("cl11.dat",ios::in || ios::binary);
		    finf.open("cl11f.dat",ios::in || ios::binary);
		    finm.open("cl11m.dat",ios::in || ios::binary);
		    break;
	   case 12: dlete(clno);
		    rename("temp.dat","cl12.dat");
		    rename("tempf.dat","cl12f.dat");
		    rename("tempm.dat","cl12m.dat");
		    fin.open("cl12.dat",ios::in || ios::binary);
		    finf.open("cl12f.dat",ios::in || ios::binary);
		    finm.open("cl12m.dat",ios::in || ios::binary);
		    break;
	  default:  textcolor(RED);
		    cprintf("UNABLE TO RENAME(TEMP) AND OPEN !");
		    break;
	  };
	}         //CLOSING OF IF()
       else
       {
	textcolor(RED);
	cprintf("SORRY!.. RECORD NOT FOUND\n RE-ENTER ROLL NO.: ");
	cout<<"\nOR ENTER '0' TO GO BACK : ";
	if(j==0)
	{
	 back(5,14,50);
	 cho='Y';
	 goto s0;
	}
	else
	goto s19;
       }
	 delay(100);
	++rep;
	}while(rep>0);

case '5':rep=0;
	 i=1;
	 fin.seekg(0);
	 finf.seekg(0);
	 foutf.seekp(0);
	 while(!fin.eof())
	  {
	   finf.read((char*)&F[i],sizeof (F[i]));
	   fin.read((char*)&A[i],sizeof (A[i]));
	   ++i;
	  }
	 if(i==2)
	 {
	  message("CLASS IS EMPTY !..");
	  delay(100);
	  cho='Y';
	  goto s0;
	 }
	 line(5,14,80);
	 do
	 {
	   textcolor(15);
	   cprintf(" ");
	   clrscr();
	   textcolor(GREEN);
	   cprintf("\n%s","    CLASS : ");
	   cout<<clno;
	   textcolor(15);
	   cprintf(" ");
	   cout<<"\n ROLL NO.\t\tNAME\t\t\tSTATUS\n\n";
	 pline(14,80);
	 cout<<"\n\n";
	  for(n=1;n<i-1;n++)
	 {
	  A[n].show(0);
	  F[n].stats();
	  cout<<"\n";
	  if(rep==0)
	  {
	  delay(40);
	  }
	 }
	 cout<<"\n";
	 textcolor(10);
	 cprintf("   TOTAL RECORDS PRESENT : ");
	 cout<<(i-2)<<"\n";
	 pline(14,80);
	  textcolor(15);
	   cprintf(" ");
	 cout<<"\n\n\tENTER STUDENT'S ROLL NO. TO PAY THE FEES OR 0 TO EXIT : ";
	 s26:cin>>j;
	 if(j==0)
	  {
	   back(5,14,80);
	   cho='Y';
	   goto s0;
	  }
	 int fs=j-(clno*100);
	 if(fs>0 && fs<i-1)
	 {
	  finf.seekg((fs-1)*sizeof (F[fs]));
	  finf.read((char*)&F[fs],sizeof (F[fs]));
	  F[fs].payfee(clno);
	  foutf.seekp((fs-1)*sizeof(F[fs]));
	  foutf.write((char*)&F[fs],sizeof (F[fs]));
	  cout<<"\n\n\t\t";
	  delay(1000);
	  ++rep;
	 }
	 else
	 {
	  wrong("ROLL NO. : ");
	  goto s26;
	 }
	}while(rep>0);
	 break;

case '6':rep=0;
	 i=1;
	 fin.seekg(0);
	 finm.seekg(0);
	 while(!fin.eof())
	 {
	  fin.read((char*)&A[i],sizeof (A[i]));
	  finm.read((char*)&M[i],sizeof (M[i]));
	  ++i;
	 }
	 if(i==2)
	 {
	  message("CLASS IS EMPTY !..");
	  delay(100);
	  cho='Y';
	  goto s0;
	 }
	 line(4,14,80);
	 do
	 {
	 textcolor(15);
	 cprintf(" dtd");
	 clrscr();
	 textcolor(11);
	 cprintf("\n%s%d","LIST OF STUDENTS OF CLASS : ",clno);
	 textcolor(15);
	 cprintf(" ");
	 cout<<"\n\n ROLL NO.\t\t    NAME\t\tSTATUS\n";
	 pline(14,80);
	 cout<<"\n";
	 for(n=1;n<i-1;n++)
	 {
	 A[n].show(0);
	 M[n].stat();
	 cout<<"\n";
	 if(rep==0)
	 {
	 delay(40);
	 }
	 }
	 cout<<"\n";
	 textcolor(10);
	 cprintf("   TOTAL RECORDS PRESENT : ");
	 cout<<(i-2)<<"\n";
	 pline(14,80);
	 cout<<"\n\tENTER STUDENT'S ROLL NO. TO ALLOT THE MARKS OR 0 TO GO BACK : ";
	 s29:cin>>j;
	 if(j==0)
	  {back(4,14,80);
	   cho='Y';
	   goto s0;}

	 int m=j-(clno*100);
	 if(m>0 && m<i-1)
	  {
	   finm.seekg((m-1)*sizeof (M[m]));
	   finf.seekg((m-1)*sizeof (F[m]));
	   finm.read((char*)&M[m],sizeof (M[m]));
	   finf.read((char*)&F[m],sizeof (F[m]));
	   line(5,10,80);
	   cout<<"\n\n\t";
	   textcolor(2);
	   cprintf("NAME : ");
	   A[m].snm();
	   cout<<"\n\t";
	   cprintf("ROLL NO. : ");
	   A[m].srn();
	   cout<<"\n\n";
	   pline(10,80);
	   if(F[m].check()==0)
	   {
	   M[m].getmarks();
	   foutm.seekp((m-1)*sizeof (M[m]));
	   foutm.write((char*)&M[m],sizeof (M[m]));
	   cout<<"\n\n\t\t\t";
	   textcolor(10);
	   cprintf("MARKS SAVED");
	   delay(1000);
	    ++rep;
	   }
	   else if(F[m].check()==1)
	   {
	   textcolor(12);
	   cout<<"\n\n";
	   cprintf("FEES OF THIS STUDENT IS DUE OR NOT PAID, PLEASE FIRST PAY IT ");
	   delay(2500);
	   ++rep;
	   }
	  }
	  else
	   {
	    cout<<"\t";
	    wrong("ROLL NO. : ");
	    goto s29;
	   }
	  }while(rep>0);
	   break;

case '7':rep=0;
	 i=1;
	 fin.seekg(0);
	 finm.seekg(0);
	 while(!fin.eof())
	 {
	  fin.read((char*)&A[i],sizeof (A[i]));
	  finm.read((char*)&M[i],sizeof (M[i]));
	  ++i;
	 }
	 if(i==2)
	 {
	  message("CLASS IS EMPTY !..");
	  delay(100);
	  cho='y';
	  goto s0;
	 }
	 line(4,14,80);
	 do
	 {
	 textcolor(15);
	 cprintf(" ");
	 clrscr();
	 textcolor(11);
	 cprintf("\n\n%s%d","LIST OF STUDENTS OF CLASS :",clno);
	 cout<<"\n\n ROLL NO.\t\t    NAME\t\tRESULT\n";
	  pline(14,80);
	  cout<<"\n";
	  for(n=1;n<i-1;n++)
	 {
	 A[n].show(0);
	 M[n].result();
	 cout<<"\n";
	 if(rep==0)
	 {
	 delay(40);
	 }
	 }
	 cout<<"\n";
	 textcolor(10);
	 cprintf("   TOTAL RECORDS PRESENT : ");
	 cout<<(i-2)<<"\n";
	 pline(14,80);
	 cout<<"\n\tENTER STUDENT'S ROLL NO. TO SEE THE MARKS OR 0 TO GO BACK : ";
	 s30:cin>>j;
	 if(j==0)
	  {back(4,14,80);
	   cho='y';
	   goto s0;}
	 int SM=j-(clno*100);
	 if(SM>0 && SM<i-1)
	 {
	  finm.seekg((SM-1)*sizeof(M[SM]));
	  finm.read((char*)&M[SM],sizeof (M[SM]));
	  clrscr();
	  cout<<"\n\n\tNAME : ";
	  A[SM].snm();
	  cout<<"\n\tROLL NO. : ";
	  A[SM].srn();
	  M[SM].showmarks(1);
	  cout<<"\n\n\n\t ENTER Y TO GO BACK ";
	  cin>>ch;
	   if(toupper(ch)=='Y')
	   {
	    ++rep;
	   }
	 }
	 else
	   {
	    cout<<"\t";
	    wrong("ROLL NO. : ");
	    textcolor(15);
	    cprintf(" ");
	    goto s30;
	   }
	 }while(rep>0);
	 break;
case '8':clrscr();
	 int recn,g;
	 line(3,11,80);
	 cout<<"\n\n\t\tCLASS\t\tSTATUS\n";
	 pline(11,80);
	 cout<<"\n\n";
      for(i=1;i<13;i++)
      {

	cout<<"\t\t"<<i<<"\t\t";
	switch(i)
	{
	case 1:fin.open("cl1.dat",ios::in || ios::binary);
		break;
	case 2:fin.open("cl2.dat",ios::in || ios::binary);
	       break;
	case 3:fin.open("cl3.dat",ios::in || ios::binary);
	       break;
	case 4:fin.open("cl4.dat",ios::in || ios::binary);
	       break;
	case 5:fin.open("cl5.dat",ios::in || ios::binary);
	       break;
	case 6:fin.open("cl6.dat",ios::in || ios::binary);
	       break;
	case 7:fin.open("cl7.dat",ios::in || ios::binary);
	      break;
	case 8:fin.open("cl8.dat",ios::in || ios::binary);
	       break;
	case 9:fin.open("cl9.dat",ios::in || ios::binary);
		break;
	case 10:fin.open("cl10.dat",ios::in || ios::binary);
		break;
	case 11:fin.open("cl11.dat",ios::in || ios::binary);
		break;
	case 12:fin.open("cl12.dat",ios::in || ios::binary);
	       break;
	default:cprintf("ERROR");
		 break;
	};
	if(!fin)
	 cout<<"EMPTY CLASS\n";
	else
	{
	recn=1;
	fin.seekg(0);
	while(!fin.eof())
	 {
	 fin.read((char*)&A[g],sizeof (A[g]));
	 ++recn;
	 }
	 recn-=2;
	 fin.close();
	   textcolor(10);
	   cout<<recn;
	   cprintf(" RECORD");
	   if(recn>1)
	   {
	   cprintf("S");
	   }
	   cout<<"\n";
	   }
	  delay(20);
	 }
	 cout<<"\n";
	 pline(11,80);
	 cout<<"\n";
	 cout<<"\nENTER Y TO GO BACK";
	 cin>>cho;
	 goto s0;
	 break;

case '9':line(4,11,80);
	 clrscr();
	 cout<<"\n\n\n\n";
	 pline(11,80);
	 textcolor(4);
	 cout<<"\n\n\n\t\t";
	 cprintf("ARE YOU SURE YOU WANT TO RESET");
	 cout<<"\n\t\t";
	 cprintf("IT WIL DELETE ALL THE DATABASE (Y/N)!");
	 cin>>ch;
	 if(toupper(ch)=='Y')
	 {
	  cout<<"\n\n\n\t\tENTER YOUR PASSWORD PLEASE TO CONTINUE OR 0 TO EXIT : ";
	  cin>>cod;
	  if(cod[0]=='0')
	      {
	      cho='y';
	      goto s0;              //TAKING PASSWORD FROM THE USER
	      }
	      p=0;
	  if(strlen(cod)==plen)
	  {
	   for(int z=0;z<plen;z++)
	   {
	    if(cod[z]==pas[z])
	    ++p;
	   }
	  }
	 if(p==plen)      //IF ENTERED PASSWORD IS CORRECT
	  {
	  clrscr();
	  textcolor(10);
	  cout<<"\n\n\t\t\t";
	  cprintf("PRESS ENTER TO CONTINUE RESET");
	  dlete(1,12);
	  remove("config.dat");
	  loading(2);
	  message("RESET COMPLETED");
	  line(5,11,80);
	  clrscr();
	  goto strt;
	  }
	 else                          //FOR ENTERING WRONG PASSWORD
	 {
	  message("WRONG PASSWORD");
	  cho='Y';
	  goto s0;
	 }
       }
       else
       {
       cho='Y';
       goto s0;
       }
	 break;
case '0':goto s0;
};
}
cho='Y';
s0:textcolor(15);
cprintf("test...\n\n");
clrscr();
fout.close();         //CLOSING OUTPUT STREAM
fin.close();	  //CLOSING INPUT STREAM
foutf.close();
finf.close();
foutm.close();
finm.close();
}while(toupper(cho)=='Y');
back(6,11,80);
for(i=1;i<17;i++)
{
clrscr();             //EXITING SCREEN
int f,xi=1,yi=3;
do
{
clrscr();
cout<<"\n\n\n\n\n";
for(f=1;f<80;f++)
{
textcolor(xi);
cprintf("_");
xi++;
if(xi==16)
{xi=1;}
}
textcolor(i);
cout<<"\n\n\n\n\t\t\t";
cprintf("VISIT AGAIN");
cout<<"\n\n\n";
for(f=1;f<80;f++)
{
textcolor(xi);
cprintf("_");
xi++;
if(xi==16)
{xi=1;}
}
delay(50);
xi+=2;
yi--;
}while(yi>0);
}
exit(0);                 //ENDING
getch();
}
void message(char msg[50])
{
for(int i=1;i<6;i++)
{
clrscr();             //EXITING SCREEN
int f,xi=1,yi=3,z=10;
do
{
clrscr();
cout<<"\n\n\n\n\n";
for(f=1;f<80;f++)
{
textcolor(xi);
cprintf("_");
xi++;
if(xi==16)
{xi=1;}
}
textcolor(z);
cout<<"\n\n\n\n\t\t\t\t";
cprintf(msg);
cout<<"\n\n\n";
z+=4;
if(z>15)
{z=10;}
for(f=1;f<80;f++)
{
textcolor(xi);
cprintf("_");
xi++;
if(xi==16)
{xi=1;}
}
delay(100);
xi+=2;
yi--;
}while(yi>0);
}
clrscr();
}
void line(int n,int col,int d)   //FORWARD LINE ANIMATION
{
int dee=1;
do
{
clrscr();
for(int s=1;s<=n;s++)
{
cout<<"\n";
}
for(int x=1;x<=dee;x++)
{
textcolor(col);
cprintf("_");
}
delay(5);
++dee;
}while(dee<d);
textcolor(15);
cprintf("\n\ntest.\n\n");
clrscr();
}
void back(int n,int col,int d=0)   //BACKWARD LINE ANIMATION
{
do
{
clrscr();
for(int s=1;s<=n;s++)
{
cout<<"\n";
}
for(int x=1;x<=d;x++)
{
textcolor(col);
cprintf("_");
}
delay(5);
--d;
}while(d>=0);
textcolor(15);
cprintf("\ntest..\n\n");
clrscr();
}
void anim()
{
clrscr();
int d=1,x;
do
{
clrscr();
textcolor(14);
cout<<"\n\n\n\n\t\t\t\t";
cprintf("  MAIN MENU ");
cout<<"\n\n";
for(x=1;x<=80;x++)
{
if(x<d)
textcolor(11);
else if(x>d)
textcolor(4);
cprintf("_");
}
delay(10);
++d;
}while(d<80);
textcolor(15);
cprintf(" ");
clrscr();
}                           //***********
void pline(int col,int len) //line....  *
{                           //***********
for(int i=1;i<len;i++)
{
textcolor(col);
cprintf("_");
}
textcolor(15);
cprintf(" ");
}
//*************************
//    END OF PROGRAMME    *
//*************************