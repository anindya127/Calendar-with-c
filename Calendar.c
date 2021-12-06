#include<stdio.h>

int monthday(int mm,int yy);
int leepyear(int yearn);
void calendar(int year);
void allmonth(int m,int y);
int get1stweekday(int yer);

int main()
{
    int y;
    printf("Enter the year: ");
    scanf("%d",&y);
    calendar(y);
    return 0;
}

int leepyear(int yearn)
{
    return (yearn%4==0&&yearn%100!=0||yearn%400==0);
}

void calendar(int year)
{
    int month,day,days_In_a_Month,weekDay=0,startingDay;
    startingDay=get1stweekday(year);
    for(month=1;month<=12;month++)
        {
            allmonth(month,year);
            days_In_a_Month=monthday(month,year);
            printf("Su Mo Tu We Th Fr Sa\n");
            for(weekDay=0;weekDay<startingDay;weekDay++)
            {
                printf("   ");
            }
            for(day=1;day<=days_In_a_Month;day++)
            {
                printf("%2d ",day);
                weekDay++;
                if(weekDay>6)
                {
                    printf("\n");
                    weekDay=0;
                }
                startingDay=weekDay;
            }
        }
}

void allmonth(int m,int y)
//m= month number, y= year
{
    char *monthsname[]={"\0","January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("\n\n    %s  %d      \n",monthsname[m],y);
}

int monthday(int mm,int yy)
//mm=month, yy=year
{
    int monthDay[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(leepyear(yy))
    {
        monthDay[2]=29;
    }
    return monthDay[mm];
}

int get1stweekday(int yer)
{
    int dday;
    dday=(((yer-1)*365)+((yer-1)/4)-((yer-1)/100)+((yer)/400)+1)%7;
    return dday;
}

