#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;

class itemEntry {
public:
       float unit_price;
       int quantity ;
       char name[30];
       char company[30];
       bool sel;
       int bquantity;
};

class Store {
public:
       int numItem;
       itemEntry database[100];

       Store() {
              numItem = 0;
       }
       void insertItem(char itemName[], char company[], int c, float p);
       void deleteItem(char itemName[]);
       itemEntry *search(char itemName[]);
       void updateItem(char itemName[], int total, float price);
       void display();
       void finalPrice();
       void select(char itemName[], char com[], int unit);
};

void Store::display()
{
    int i;
    cout<<"Available products are:\n";
    for(i = 0; i < numItem; i++)
    {
        cout<<"\nName = "<<database[i].name<<"\nCompany = "<<database[i].company<<"\nUnit price = "<<database[i].unit_price<<"\nQuantity = "<<database[i].quantity<<"\n";
    }
}

void Store::select(char itemName[], char com[], int unit)
{
    int i;
    cout<<"Selected product:\n";
    for(i = 0; i < numItem; i++)
    {
        if(strcmp(itemName, database[i].name) == 0 && strcmp(com, database[i].company) == 0)
        {
            cout<<"Name of product: "<<itemName<<endl;
            cout<<"Name of company: "<<com<<endl;
            if(unit <= database[i].quantity)
            {
                database[i].bquantity = unit;
                cout<<"Number of units selected: "<<unit<<endl;
                database[i].sel = 1;
                database[i].quantity = database[i].quantity - unit;
            }
            else
            {
                cout<<"Invalid number of units"<<endl;
            }
        }
        return;
    }
}

void Store::insertItem(char itemName[], char company[], int c, float p) {
       strcpy(database[numItem].name, itemName);
       strcpy(database[numItem].company, company);
       database[numItem].quantity  = c;
       database[numItem].unit_price = p;
       cout << "Item Inserted Successfully.\n";
       ++numItem;
}

void Store::deleteItem(char itemName[]) {
       int i;
       for (i = 0; i < numItem; i++) {
              if (strcmp(itemName, database[i].name) == 0) {
                     database[i].quantity --;
                     cout << "Item Deleted Successfully.\n";
                     return;
              }
       }
       cout << "Item not found.\n";
}

itemEntry *Store::search(char itemName[]) {
       int i;
       for (i = 0; i < numItem; i++) {
              if (strcmp(itemName, database[i].name) == 0)
                     return &database[i];
       }
       return NULL;
}

void Store::updateItem(char itemName[], int total, float price)
{
       itemEntry *item = search(itemName);
       if (item == NULL)
       {
              cout << "Item not found.\n";
              return;
       }
       item->quantity  += total;
       item->unit_price = price;
}
void Store::finalPrice(void)
{
    int fp=0, i;
    for(i = 0; i < numItem; i++)
    {
        fp = fp + (database[i].unit_price*database[i].bquantity);
    }
    cout<<"Final amount is:"<<fp;
}

int main() {
       Store sto;
       char cond='f',option='f', name[30], company[30], quantity [10], unit_price[30], sel=0, bquantity [10];
       while(cond != '3'){
       cout<<"Press 1 for Buyer\nPress 2 for Seller\nPress 3 to Exit\n";
       cin>>cond;
       if (cond == '2'){
       option='f';
       while (option != 'e') {
              cout << "\n----------->Enter your choice:<------------\n";
              cout << "I for insert\n";
              cout << "D for delete\n";
              cout << "S for search\n";
              cout << "U for update\n";
              cout << "E for exit\n";

              cin>>name;
              option = name[0];

              switch (option) {

              case 'i':
                     cout << "Enter Name of Item\n"; 
                     cin>>name;
                      cout << "Enter Name of Company\n";
                     cin>>company;
                      cout << "Enter Quantity\n";
                     cin>>quantity;
                      cout << "Enter Unit Price\n";
                     cin>>unit_price;
                     sto.insertItem(name, company, atoi(quantity ), atof(unit_price));
                     break;
              case 'd':
                     cout << "Enter Name of Item:\n";
                     cin>>name;
                     sto.deleteItem(name);
                     break;
              case 's':
                     cout << "Enter Name of Item:\n";
                     cin>>name;
                     itemEntry *test;
                     test = sto.search(name);
                     if (test != NULL) {
                           cout << "---------------->Searching Result<---------------------" << endl;
                           cout << "Item found\n" << "Name of the Item:" << test->name << endl << "Company name:" << test->company << endl << "Number of quantity  available:" << test->quantity  << endl << "Unit price:" << test->unit_price << endl;
                     }
                     else
                           cout << "Item not found\n";
                     break;
              case 'u':
                     cout << "Enter details for update...\n";
                     cout << "Enter name: "; cin>>name;
                     cout << "Enter total new entry: "; cin>>quantity;
                     cout << "Enter new price: "; cin>>unit_price;
                     sto.updateItem(name, atoi(quantity ), atof(unit_price));
                     break;
                     /*        case 'e':
                     exit(0);
                     break;*/
              }
       }
       }
       else if (cond == '1'){
       option='f';
       while (option != 'e') {
              cout << "\n----------->Enter your choice:<------------\n";
              cout << "P for final price\n";
              cout << "S for selecting\n";
              cout << "D for display list of products\n";
              cout << "E for exit\n";

              cin>>name;
              option = name[0];

              switch (option) {

              case 'p':
                     sto.finalPrice();
                     break;
              case 's':
                     cout << "Enter name of product\n";
                     cin >> name;
                     cout << "Enter name of company\n";
                     cin >> company;
                     cout << "Enter number of units\n";
                     cin >> bquantity;
                     sto.select(name, company, atoi(bquantity));
                     break;
              case 'd':
                     sto.display();
                     break;
              }
       }
       }
       else if(cond == '3')
       {
           exit(0);
       }
       }
       return 0;

}