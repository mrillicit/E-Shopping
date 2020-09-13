#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
#include<unistd.h>
using namespace std;

class item
{
    long int item_num;
    char item_name[20];
    long int quantity;
    double cost;
   
    public :
    item()     
    {
    }
     
    item(long int num,char name[],long int qty,double price)         
    {
        item_num=num;
        strcpy(item_name,name);
        quantity=qty;
        cost=price;
    }
   
    void create_item()
    {
       
            cout<<"\n\n\tEnter item number : ";
            cin>>item_num;
            cout<<"\tEnter item name : ";
            cin>>item_name;
            cout<<"\tEnter quantity of item : ";
            cin>>quantity;
            cout<<"\tEnter price of item  : ";
            cin>>cost;
       
    }
   

    void additem();
    void modifyitem();
    void deleteitem();
    void searchitem();
    void displayitem();
    
   
   
};

void item::additem()
{
    item i;
    fstream file;
    file.open("ekart.txt", ios::app | ios::binary);
    i.create_item();
    file.write((char*)&i,sizeof(i));
    cout<<"\n\n\tThe item has been created ";
    file.close();
}

void item::searchitem()
{
 item i;
 int num,flag=0;
 cout<<"\n\n\tEnter the item number to be searched :";
 cin>>num;
 ifstream file;
 file.open("ekart.txt");
 while(file.read((char*)&i,sizeof(i)))
 {
     if(num==i.item_num)
     {
         flag=1;
         cout<<"\n\n\tItem number     :"<<i.item_num;
        cout<<"\n\n\tItem name        :"<<i.item_name;
        cout<<"\n\n\tItem Quantity    :"<<i.quantity;
        cout<<"\n\n\tItem price       :"<<i.cost;
        break;
     }
     
 }
 if(flag==0)
     {
         cout<<"item not found!!";
     }
     cout<<"\n\n";
     file.close();
}

void item :: modifyitem()
{
    item i;
    int flag=0;
    int temp=0;
    long int num;
    fstream file;
    cout<<"Please enter the item number to be modified :";
    cin>>num;
    file.open("ekart.txt");
    while(file.read((char*)&i,sizeof(i)))
    {
        if(num==i.item_num)
        {
            flag=1;
            break;
        }
        else
        temp++;
    }
    if(flag==1)
    {
        long int pos=(temp)*sizeof(i);
        file.seekp(pos);
        cout<<"Please enter the details of the product :";
        i.create_item();
        file.write((char*)&i,sizeof(i));
        cout<<"\n\n\tRecord has been modified";

    }
    else
    {
        cout<<"\n\n\tNo match found";

    }
    file.close();
}

void item :: deleteitem()
{
    item i;
    int num,flag=0;
    ifstream file;
    cout<<"\n\n\n\tEnter the item number you want to delete :";
    cin>>num;
    file.open("ekart.txt");
    fstream file1;
    file1.open("temp.txt" ,ios::app);
    file.seekg(0,ios::beg);
    while(file.read((char*)&i,sizeof(i)))
    {
        if(i.item_num==num)
        {
            flag=1;
        }
        else
        {
            file1.write((char*)&i,sizeof(i));
           
        }
    }
    if(flag==0)
    {
        cout<<"\n\n\tItem not found";
       
    }
    else
    {
        cout<<"\n\n\tRecord deleted";
       
    }
    file1.close();
    file.close();
    remove("ekart.txt");
    rename("temp.txt" , "ekart.txt");
}


void item::displayitem()
{
    item i;
    fstream fin;
    fin.open("ekart.txt", ios::in | ios::binary);
    cout<<"\n\t\t|-----------------------------------------------------------------------|\n";
    cout<<"\t\t|"<<setw(18)<<"ITEM NUMBER  |"<<setw(18)<<"NAME  |"<<setw(18)<<"QUANTITY  |"<<setw(18)<<"COST  |";
    cout<<"\n\t\t|-----------------------------------------------------------------------|\n";
    cout<<"\t\t|"<<setw(18)<<"  |"<<setw(18)<<"  |"<<setw(18)<<"  |"<<setw(18)<<"  |"<<endl;
    while(fin.read((char*)&i,sizeof(i)))
    {
        cout<<"\t\t|"<<setw(15)<<i.item_num<<"  |"<<setw(15)<<i.item_name<<"  |"<<setw(15)<<i.quantity<<"  |"<<setw(15)<<i.cost<<"  |"<<endl;
       
    }
    cout<<"\t\t|"<<setw(18)<<"  |"<<setw(18)<<"  |"<<setw(18)<<"  |"<<setw(18)<<"  |"<<endl;
    cout<<"\t\t|-----------------------------------------------------------------------|\n";
    fin.close();
   
}
int main()
{
    item i;
    int ch , cond=0, option=0;
    {

    
      
        start:
        cout<<"Press 1 for Buyer\nPress 2 for Seller\nPress 3 to Exit\n";
        cin>>cond;
        if (cond == 2){

        cout<<"\n\t1 : Add item to ekart";
        cout<<"\n\t2 : Display all items";
        cout<<"\n\t3 : Search an item";
        cout<<"\n\t4 : Update an item";
        cout<<"\n\t5 : Delete an item";
        cout<<"\n\t6 : Exit";
        cout<<"\n\n\tEnter your choice :";
        cin>>ch;
       
        switch(ch)
        {
            case 1 : i.additem();
                     break;
            case 2 : i.displayitem();
                     break;
            case 3 : i.searchitem();
                     break;
            case 4 : i.modifyitem();
                     break;
            case 5 : i.deleteitem();
                    break;
            case 6 :   exit(0);
            default : cout<<"\n\t\twrong choice";
        }
     
    }
    else if(cond == 3) {

    }
    
    
        cout<<"\n\t1 : Display all items";
        cout<<"\n\t2 : Search an item";
        cout<<"\n\t3 : Exit";
        cout<<"\n\n\tEnter your choice :";
        cin>>ch;
       
        switch(ch)
        {
            case 1 : i.displayitem();
                     break;
            case 2 : i.searchitem();
                     break;
            case 5 : i.deleteitem();
                    break;
            case 3 :   exit(0);
            default : cout<<"\n\t\twrong choice";
        }
    
    }
    conti:
    int ans;
  
    cout<<"\n\n\tDo you want to continue ?";
    cout<<"\n\n\tPress 1 for YES or 0 for NO :";
    cin>>ans;
    if(ans==1)
    {
        goto start;
    }
    else if(ans==0)
    {
       
        exit(0);
    }
    else
    {
        cout<<"\n\t\tWrong input by user , choose the right option.";
        goto conti;
    }}
