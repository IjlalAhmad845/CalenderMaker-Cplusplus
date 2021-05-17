#include<iostream>
#include<conio.h>
using namespace std;

class date
{public:
    int dd;
    int mm;
    int yy=1;
    int wk;


     void chk_month()                                     ///-----------definition for check months
 {    if(mm==2 || mm==3 || mm==11)wk=wk+3;
 else if(mm==4 || mm==7)wk=wk+6;
 else if(mm==9 || mm==12)wk=wk+5;
 else if(mm==5)wk=wk+1;
 else if(mm==6)wk=wk+4;
 else if(mm==8)wk=wk+2;
}


    void week()
{
wk=wk%7;
     if(wk==2)cout<<"Day--->  Sunday";
else if(wk==3)cout<<"Day--->  Monday";
else if(wk==4)cout<<"Day--->  Tuesday";
else if(wk==5)cout<<"Day--->  Wednesday";
else if(wk==6)cout<<"Day--->  Thursday";
else if(wk==0)cout<<"Day--->  Friday";
else if(wk==1)cout<<"Day--->  Saturday";
cout<<endl;}

};
class calender:public date{
public:
    long year,calenderNo,weekNo,dates,week_1st,spaces,i,j,week_left,centuries_months,centuries,leap_years; ///declared variables


#define a year
#define b calenderNo
#define k weekNo
#define l dates
#define d week_1st
#define c spaces
#define m week_left
#define e centuries_months
#define f centuries
#define g leap_years

    calender()      ///--------------------------------------------------constructor for assigning values
{k=7;l=1;d=i=j=k=c=e=f=g=0;}
void input1()                ///---------------------------------------------function for input
{cout<<"Enter date (dd/mm/yyyy) -->";
cin>>dd>>mm>>yy;
a=yy;}
void input2()
{cout<<"Enter year-->";
cin>>a;
}
void calc()                 /**                     MAIN CALCULATION            */
{
if(a<=1900)                     ///-----------------for years less than 1900
{e=a/100;if((1900-a)%200==0)f=21-e;else f=20-e;} ///-----------for particular century year
if((18-e)%4==0)g--;         ///---------------for calculate special centuries,divisible by 4 (they hay extraordinary calenders)
if(a%200>0 && a%200<100)f--;                /// special centuries with extra of 1 day

if(a<100)g-=3;          /// ---------------see above line these years are less than 200 ###
if(a<2015)
{for(i=a;i<2015;i++)
if(i%4==0)g++;              ///-------------for calculating leap years
for(i=20;i>e;i--)
{if(i%4==0&&e>0)g++;}           ///----------for calculating centuries divisible by 4(centuries have extra 1 day)
///---------------------------And in this case we add 1 because we are calculating previous years
if(a>2000 && a<2015)f++;            /// An error between 2000 to 2014
a=a-g+f;            ///----------------------------------subtracted leap years and added centuries
for(b=1;a<0;b++){if(a<0)a=7+a;}}      ///---------in this case 'a' became negative
///------------------------------ actual code for understanding 7-(-1*a)
if(a>2100){e=a/100;f=e-20;}     ///---calculation for 21 above centuries
if(a>2016)              ///--------calculation for years more than 2015
{for(i=2015;i<a;i++)
if(i%4==0)g++;                  ///-------------------------------calculating leap years
for(i=21;i<=e;i++)
{if(i%4==0&&e>0)g++;}               ///---------for calculating centuries divisible by 4
if((e-22)%4==0)
    g++;
if(a%200>0 && a%200<100)f++;        /// --------------special centuries with extra of 1 day
if(a%500==0)f--;            ///----------------- for years between two thousand's'
if(a%2000>400 && a%2000<500)f--;        ///----------------------for series 2400-500,4400-500,6400-500
if((a-1600)%2000>0 && (a-1600)%2000<100 )f--; ///----------------------for series 3600-700,5600-700,7600-700

a=a+g-f;}       ///adding leap years and special centuries and subtracting 1 extra day for next century
b=a%28;              ///repetition of calenders every 28 years
wk=b;
}

void maker()                                     /** MAKING CALENDER   **/
{a=32;                              ///-------------------------------default for January
for(e=1;e<=13;e++)
{if(e==8)e++;               ///----------------------------gap for August 31 days
if(yy%4==0 && e==3)b=b+1;               ///-----------------------------special case for February for leap years 29 days
if(d!=0)
    {if(e==2)                           ///--------------------------special cases for February
    {b=b+3;
    if(yy%4==0)a=30;                    ///checking leap year for 29 days
     else a=29;}
     if(e==3)a=32;          ///--------- after February the starting point of march is same but ending point here decided
        else if(e==4 || e==6 || e==9 || e==10 || e==12){b=b+3;if(e==9)a=32;else a=31;}
    /**         first month ends then its days decided
            every month decide its previous one days but September decided 31 so we make a condition  **/
            else if(e==5 || e==7 || e==11 || e==13){b=b+2;a=32;}}

b=b%7;
k=d=c=0;l=1;
if(e==1)cout<<"January\n";
else if(e==2)cout<<"February\n";
else if(e==3)cout<<"March\n";
else if(e==4)cout<<"April\n";
else if(e==5)cout<<"May\n";
else if(e==6)cout<<"June\n";
else if(e==7)cout<<"July\n";
else if(e==9)cout<<"August\n";
else if(e==10)cout<<"September\n";
else if(e==11)cout<<"October\n";
else if(e==12)cout<<"November\n";
else if(e==13)cout<<"December\n";



    cout<<"sun"<<" "<<"mon"<<" "<<"tue"<<" "<<"wed"<<" "<<"thu"<<" "<<"fri"<<" "<<"sat"<<endl;

     if(b==0){c=c+20;k=k+2;}            /// ------------assigning spaces
else if(b==1){c=c+24;k=k+1;}            ///-------------values of k stars for right side of month for days
else if(b==2){c=c+0;k=k+7;}
else if(b==3){c=c+4;k=k+6;}
else if(b==4){c=c+8;k=k+5;}
else if(b==5){c=c+12;k=k+4;}
else if(b==6){c=c+16;k=k+3;}
for(i=1;i<=c;i++)
    cout<<" ";
    for(i=1;i<=6;i++)                                   ///==============making month with one by one week
    {if(d==0)                                          ///=============for printing first week of the month
    {d++;
    for(m=1;m<=k;m++)
    {cout<<" "<<l<<"  ";l++;}
    cout<<endl;}                                        /// ============first week completed
        for(m=1;m<=7;m++)                                ///================rest of the weeks
            {cout<<" "<<l;l++;
            if(l<=10)cout<<"  ";
            else cout<<" ";
            if(m%7==0)cout<<endl;           ///==week switcher ///when month ends on sat it's automatically switch next line
            if(l==a){if(a==32 && k!=3)cout<<endl;       ///===month switcher ///when month not ends on sat above stat not run
                   else if(a==31 && k!=2)cout<<endl;    ///adjustment for 30
                   else if(a==29 && k!=7)cout<<endl;    ///adjustment for 28
                   else if(a==30 && k!=1)cout<<endl;    ///adjustment for 29
                                     /**         above code means there are 2 line breaker for every month
                                        if above one not run then below one (second code) runs to counter balance it **/
            cout<<endl;break;}}                                   ///---------------to stop dates and goto next line
            if(l==a)break; }}                 ///===========================================to stop weeks
}
chk_date()
{if(yy%4==0)
{if(mm>2)wk+=dd%7;       ///--------------for leap years (due to Feb 29 one day added on march onwards)
    else wk+=dd%7-1;  }      ///------------------but for leap years days before 29 Feb remains same
else if(yy%4!=0)                ///------------------for non-leap years
    wk+=dd%7-1;

}
};
///===============================================================================================*****FUNTIONS OUT OF CLASS*****
void condition_both();          ///-----------------------------------------show day as well as calender
void condition_day();           ///------------------------------------------------show day
void condition_year();              ///-----------------------------------------show calender
void userchoice();          ///----------------------choice input function

calender ob1;char ch;       ///------------------------------------------declared global variables
int main()
{userchoice();
if(ch=='C' || ch=='c')              ///-----------------condition only for checking year
{if(ob1.a>0)
  condition_year();
  else
        cout<<"year does not exist";
}

else{///-------------------------------------------------------conditions for checking date validity
if(ob1.mm<=12 && ob1.mm>=0 && ob1.yy>0)                 ///------------checking for valid year and month
{   ///---------if user choose day function then above condition is always true because year=1 (by default)
    if((ob1.dd<=31) && (ob1.mm==1 || ob1.mm==3 || ob1.mm==5 || ob1.mm==7 || ob1.mm==8 || ob1.mm==10 || ob1.mm==12))
     {if(ch=='D' || ch=='d')condition_day();        ///---------only call day function after checking
     else if(ch=='B' || ch=='b')condition_both();}          ///--------------call day and calender function
///----------------------------------------------------------checking months which have 31days
    else if((ob1.dd<=30) && (ob1.mm==4 || ob1.mm==6 || ob1.mm==9 || ob1.mm==11 ))
    {if(ch=='D' || ch=='d')condition_day();
     else if(ch=='B' || ch=='b')condition_both();}
///----------------------------------------------------------checking months which have 30days
    else if(ob1.mm==2)                  ///-----------Special case for FEB
    {
          if(ob1.dd==29 && ob1.yy%4==0)      ///-------checking leap year validity
          {if(ch=='D' || ch=='d')condition_day();
     else if(ch=='B' || ch=='b')condition_both();}

            else if(ob1.dd<=28)
            {if(ch=='D' || ch=='d')condition_day();
     else if(ch=='B' || ch=='b')condition_both();}

            else cout<<"29 Feb does not exist in "<<ob1.a;                      ///condition only for FEB
    }
else cout<<"invalid date";
    }
else cout<<"invalid date";
}       ///--------------------------------end if
getch();}

void condition_both()
{ob1.calc();
ob1.chk_month();
ob1.chk_date();
ob1.week();
cout<<"Here is the year--->\n";
ob1.maker();
}
void condition_day()
{ob1.calc();
ob1.chk_month();
ob1.chk_date();
ob1.week();
}
void condition_year()
{ob1.calc();
 cout<<"Here is the year---->\n"; ob1.maker();
}
void userchoice()
{do{
    cout<<"Do you want day Calculator(D) or Calender (C) or both(B)\nInput--->";
cin>>ch;
if(ch=='B' || ch=='b')
    ob1.input1();
    else if(ch=='C' || ch=='c')
        ob1.input2();
    else if(ch=='D' || ch=='d')
        ob1.input1();
else {cout<<"Invalid choice!!!!";
    cout<<"\nDo you want to choose again(Y) or not (N) (negetive choice will close the program) \nEnter your decision-->";
cin>>ch;
}
}while(ch=='Y' || ch=='y');
}
