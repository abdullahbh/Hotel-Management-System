#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;


class room      //Parent Class declaration, We declare the main class here and all the child classes are inherited from this.
{
    protected:
    
    int floor_no;   //initializing the Floor No of Hotel
    int room_no;    //initializing the Room No on every Floor of Hotel
    int Type;   //initializing the Room Type of Hotel 
    int age;    //initializing the age of customer
    int ID;     //initializing the ID of customer
    int temp;
    int days;   //initializing the days of stay of customer
    int price;  //initializing the price of Room Types
    int cash;   ////initializing the cash paid by customer in advance
    int check=0;
    int reserve_check=0;
    char choice;
    char name[100]; //initializing the array of customer's name
    char Gender;

    public:

    int floor[5][50];   //initializing the array of Hotel (5*50=250)containing 5 Floors and 50 Rooms on each Floor


    room()  //Constructor storing the values in array of different floors according to different room types
    {
        for(int i=0; i<5; i++)  //Outer Loop
        {
            for(int j=0; j<10; j++) //Inner Loop
            {
                floor[i][j]=1;  //Standard Room
            }

            for(int j=10; j<20; j++)
            {
                floor[i][j]=2;  //Moderate Room
            }

            for(int j=20; j<30; j++)
            {
                floor[i][j]=3;  //Superior Room
            }

            for(int j=30; j<40; j++)
            {
                floor[i][j]=4;  //Junior Suite
            }

            for(int j=40; j<50; j++)
            {
                floor[i][j]=5;  //Suite 
            }
        }
    }

    void Hotel();   //Function to initialize the Hotel's Main Menu
    void Add(); //Function to take customer's data including Floor No
    void reserve_Add(); //Function to take customer's data including Floor No, in case of Reservation 
    void select_type(int);  //Function to select the Room Type
    void reserve_select_type(int);  //Function to select the Room Type, in case of Reservation 
    void search_room(int,int);  //Function to check the availibility of Room
    void reserve_search_room(int,int);  //Function to check the availibility of Room, in case of Reservation 
    void balance(); //Function to take the amount from user and calculate the bill
    void reserve(); //Function to Get into reservation menu in Main Menu
    void detail_report();   //function to view detailed report in Main menu
    void view_reserve();
    virtual int bill()=0;   //Function to calculate bill
};

void room::Hotel()  //Function to initialize the Hotel's Main Menu
{
        int choice;

        cout<<"\n\t\t\t\t*************";
        cout<<"\n\t\t\t\t* MAIN MENU *";
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\n\n\t\t\t1.Reserve A Room";
        cout<<"\n\t\t\t2.Check in a Customer/Visitor";
        cout<<"\n\t\t\t3.View Reserved Rooms";
        cout<<"\n\t\t\t4.Detailed Report";
        cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;

        while(choice<1 && choice>5)
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (1-5): ";
            cin>>choice;
        }        

        switch(choice)  //Select from the Menu
        {
            case 1:
            {
                reserve();  //Function to Get into reservation menu in Main Menu.
                break;
            }

            case 2:
            {
                Add();  //Function to take customer's data.
                break;
            }

            case 3:
            {
                view_reserve();
                break;
            }

            case 4:
            {
                detail_report();
                break;

            }

            case 5:
            {
                cout<<"Have a nice day"<<endl;
                exit(0);    //Exit Condition
            }

            default:
            {
                cout<<"Wrong choice!!!"<<endl;
                cout<<"Press any key to continue!!"<<endl;
            }
        }

}

void room::view_reserve()
{
    cout<<"RESERVATIONS"<<endl;
    cout<<"room number: "<<room_no<<endl;
    cout<<"floor: "<<floor_no<<endl;
    cout<<"Type: ";

    if(Type==1)
    {
        cout<<"standard"<<endl;
    }

    else if(Type==2)
    {
        cout<<"moderate"<<endl;
    }

    else if(Type==2)
    {
        cout<<"moderate"<<endl;
    }

    else if(Type==3)
    {
        cout<<"superior"<<endl;
    }

    else if(Type==4)
    {
        cout<<"junior suite"<<endl;
    }

    else if(Type==5)
    {
        cout<<"suite"<<endl;
    }
}

void room::Add()       //Function to take customer's data including Floor No
{   
    fstream ob;
    ob.open("demo.txt",  ios::app );

    cout<<"Enter your Name"<<endl;  //Enter all the Details
    cin>>name;
    cout<<"Enter your Age"<<endl;
    cin>>age;
    cout<<"Enter your ID"<<endl;
    cin>>ID;
    cout<<"Specify your Gender. M/F"<<endl;
    cin>>Gender;
    cout<<"Enter days to reserve"<<endl;
    cin>>days;
    cout<<"Enter your Floor No 1-5 "<<endl;
    cin>>floor_no;  //Enter the floor No on which you want a room

    ob<<name<<"\n";
    ob<<age<<"\n";
    ob<<ID<<"\n";
    ob<<Gender<<"\n";
    ob<<days<<"\n";
    ob<<floor_no<<"\n";

    while(floor_no<1 && floor_no>5 )
    {
        cout<<"Invalid sInput! : out of range"<<endl;
        cout<<"Please Enter Again (1-5): ";
        cin>>floor_no;  
    }

    if(floor_no==1) //1st Floor
    {
       select_type(floor_no);
    }
    else if(floor_no==2)    //2nd Floor
    {
       select_type(floor_no);
    }
    else if(floor_no==3)    //3rd Floor
    {
       select_type(floor_no);
    }
    else if(floor_no==4)    //4th Floor
    {
       select_type(floor_no);
    }
    else if(floor_no==5)    //5th Floor
    {
       select_type(floor_no);
    }

    ob.close();

} 

void room::reserve_Add()    //Function to take customer's data including Floor No, in case of Reservation
{
    fstream ob;
    ob.open("demo1.txt",  ios::app );
    
    cout<<"Enter your Name"<<endl;
    cin>>name;
    cout<<"Enter your Age"<<endl;
    cin>>age;
    cout<<"Enter your ID"<<endl;
    cin>>ID;
    cout<<"Specify your Gender"<<endl;
    cin>>Gender;
    
    cout<<"Enter days to reserve"<<endl;
    cin>>days;
    cout<<"Enter your Floor No 1-5 "<<endl;
    cin>>floor_no;

    ob<<name<<"\n";
    ob<<age<<"\n";
    ob<<ID<<"\n";
    ob<<Gender<<"\n";
    ob<<days<<"\n";

    
    while(floor_no<1 && floor_no>=5 )
    {
        cout<<"Invalid Input! : out of range"<<endl;
        cout<<"Please Enter Again (1-5): ";
        cin>>floor_no;
    }
    
    ob<<floor_no<<"\n";

    if(floor_no==1)
    {
       reserve_select_type(floor_no);
    }
    else if(floor_no==2)
    {
       reserve_select_type(floor_no);
    }
    else if(floor_no==3)
    {
       reserve_select_type(floor_no);
    }
    else if(floor_no==4)
    {
       reserve_select_type(floor_no);
    }
    else if(floor_no==5)
    {
       reserve_select_type(floor_no);
    }


    ob.close();
}
void room::select_type(int floor_no)    //Function to select the Room Type
{
    fstream ob;
    ob.open("demo.txt", ios::app);

    cout<<"***Enter your Room type***"<<endl;
    cout<<"Enter between (1-5) "<<endl;
    cout<<"Press 1 for Standard :300 RS"<<endl;
    cout<<"Press 2 for Moderate :500 RS"<<endl;
    cout<<"Press 3 for Superior :1000 RS"<<endl;
    cout<<"Press 4 for junior Suit :2000 RS"<<endl;
    cout<<"Press 5 for Suite :5000 RS"<<endl;
    cin>>Type;
    ob<<Type;

    while(Type<1 && Type>5 )
    {
        cout<<"Invalid Input! : out of range"<<endl;
        cout<<"Please Enter Again (1-5): ";
        cin>>Type;
        ob<<Type;
    }

    if(Type==1)
    {
        cout<<"Enter room number 0-9"<<endl;
        cin>>room_no;
        ob<<room_no;

        while(room_no<0 && room_no>9 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (0-9): ";
            cin>>room_no;
            ob<<room_no;
        }

        search_room(room_no, floor_no);
    }

    else if(Type==2)
    {
        cout<<"Enter room number 10-19"<<endl;
        cin>>room_no;
        ob<<room_no;

        while(room_no<10 && room_no>19 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (10-19): ";
            cin>>room_no;
            ob<<room_no;
        }

        search_room(room_no, floor_no);
    }

    else if(Type==3)
    {
        cout<<"Enter room number 20-29"<<endl;
        cin>>room_no;
        ob<<room_no;
        
        while(room_no<20 && room_no>29 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (20-29): ";
            cin>>room_no;
            ob<<room_no;
        }

        search_room(room_no, floor_no);
    }

    else if(Type==4)
    {
        cout<<"Enter room number 30-39"<<endl;
        cin>>room_no;
        ob<<room_no;

        while(room_no<30 && room_no>39 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (30-39): ";
            cin>>room_no;
            ob<<room_no;
        }

        search_room(room_no, floor_no);
    }

    else if(Type==5)
    {
        cout<<"Enter room number 40-49"<<endl;
        cin>>room_no;
        ob<<room_no;
        ob<<room_no;

        while(room_no<40 && room_no>49 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (40-49): ";
            cin>>room_no;
            ob<<room_no;
        }       

        search_room(room_no, floor_no);
    }

     ob.close();

}

void room::reserve_select_type(int floor_no)    //Function to select the Room Type, in case of Reservation 
{
    fstream ob;
    ob.open("demo1.txt", ios::app);

    cout<<"Enter Your Room Type 1-5"<<endl;
    cout<<"***Enter your Room type***"<<endl;
    cout<<"Press 1 for Standard :300 RS"<<endl;
    cout<<"Press 2 for Moderate :500 RS"<<endl;
    cout<<"Press 3 for Superior :1000 RS"<<endl;
    cout<<"Press 4 for junior Suit :2000 RS"<<endl;
    cout<<"Press 5 for Suite :5000 RS"<<endl;
    cin>>Type;
    while(Type<1 && Type>5 )
    {
        cout<<"Invalid Input! : out of range"<<endl;
        cout<<"Please Enter Again (1-5): ";
        cin>>Type;
        ob<<Type;
    }

    if(Type==1)
    {
        cout<<"Enter room number 0-9"<<endl;
        cin>>room_no;
        while(room_no<0 && room_no>9 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (0-9): ";
            cin>>room_no;
            ob<<room_no;
        }
        reserve_search_room(room_no, floor_no);
    }

    else if(Type==2)
    {
        cout<<"Enter room number 10-19"<<endl;
        cin>>room_no;
        ob<<room_no;

        while(room_no<10 && room_no>19 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (10-19): ";
            cin>>room_no;
            ob<<room_no;
        }

        reserve_search_room(room_no, floor_no);
    }

    else if(Type==3)
    {
        cout<<"Enter room number 20-29"<<endl;
        cin>>room_no;
        ob<<room_no;
        
        while(room_no<20 && room_no>29 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (20-29): ";
            cin>>room_no;
            ob<<room_no;
        }

        reserve_search_room(room_no, floor_no);
    }

    else if(Type==4)
    {
        cout<<"Enter room number 30-39"<<endl;
        cin>>room_no;
        ob<<room_no;

        while(room_no<30 && room_no>39 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (30-39): ";
            cin>>room_no;
            ob<<room_no;
        }

        reserve_search_room(room_no, floor_no);
    }

    else if(Type==5)
    {
        cout<<"Enter room number 40-49"<<endl;
        cin>>room_no;
        ob<<room_no;
        
        while(room_no<40 && room_no>49 )
        {
            cout<<"Invalid Input! : out of range"<<endl;
            cout<<"Please Enter Again (40-49): ";
            cin>>room_no;
            ob<<room_no;
        }        

        reserve_search_room(room_no, floor_no);
    }

    ob.close();

}


void room::search_room(int room_no, int floor_no)   //Function to check the availibility of Room
{


    for(int i=0; i<50; i++)
    {
        if(floor[floor_no][room_no]==true)
        {
            cout<<"room not available"<<endl;
            break;
        }

        else
        {
            cout<<"room is available"<<endl;
            floor[floor_no][room_no]=true;
            cout<<"Room has been allotted successfully"<<endl;
            check++;
            balance();
            break;
        }
    }

    Hotel();
}

void room::reserve_search_room(int room_no, int floor_no)   //Function to check the availibility of Room, in case of Reservation
{
    for(int i=0; i<50; i++)
    {
        if(floor[floor_no][room_no]==true)
        {
            cout<<"room not available"<<endl;
        }

        else
        {
            cout<<"room is available"<<endl;
            floor[floor_no][room_no]=true;
            cout<<"Room has been RESERVED successfully"<<endl;
            reserve_check++;
            break;
        }
    }
}
void room::balance()    //Function to take the amount from user and calculate the bill
{
    fstream ob;
    fstream ob1;
    ob.open("demo.txt", ios::app);
    ob1.open("demo1.txt", ios::app);

    int total_balance;
    char choice;
    cout<<"Enter the amount that you want to pay right now"<<endl;
    cin>>cash;
    ob<<cash;
    ob1<<cash;


    if(cash==0)
    {
        bill();
    }

    else
    {
        total_balance=cash-bill();
        cout<<"your remaining balance after bill is: "<<total_balance<<endl;
    }

    ob.close();
    ob1.close();
}

void room::reserve()
{
    cout<<"***Welcome to Reservation Menu***"<<endl;
    reserve_Add();

}

void room::detail_report()
{
    cout<<"\n\t\t***DETAILED REPORT***"<<endl;
    cout<<"\n\t\tcustomers have checked in today: "<<check<<endl;
    cout<<"\n\t\tCustomers checked out today: "<<endl;
    cout<<"\n\t\tRooms reserved: "<<reserve_check<<endl;
    cout<<"\n\t\tEmpty Rooms: "<<250-check<<endl;
    Hotel();
}

class standard: public room
{
    protected:

    int revenue;

    public:

    standard()
    {

    }

    int bill()
    {
        int price=300;
        revenue=days*price;
        cout<<"Your bill is : "<<revenue<<endl;
        return revenue;
    }
};

class moderate: public room
{
    int revenue;

    public:

    moderate()
    {

    }

    int bill()
    {
        int price=500;
        revenue=days*price;
        cout<<"Your bill is : "<<revenue<<endl;
        return revenue;
    }
};

class superior: public room
{
    int revenue;

    public:

    superior()
    {

    }

    int bill()
    {
        int price=1000;
        revenue=days*price;
        cout<<"Your bill is : "<<revenue<<endl;
        return revenue;
    }
};

class junior_suite: public room
{
    int revenue;

    public:

    junior_suite()
    {

    }

    int bill()
    {
        int price=2000;
        revenue=days*price;
        cout<<"Your bill is : "<<revenue<<endl;
        return revenue;   
    }
};

class suite: public room
{
    int revenue;

    public:

    suite()
    {

    }

    int bill()
    {
        int price=5000;
        revenue=days*price;
        cout<<"Your bill is : "<<revenue<<endl;
        return revenue;    
    }
};


int main()
{

    moderate M;
    M.Hotel();

    suite S;
    S.Hotel();

    return 0;
}