#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int Billing();
void mainmenu();
void exit();
void item();
void AddEdit();
void mainmenuAdmin();
void reset();
void mainmenuCash();

void title(){
	//========Title========
	cout<<"======================================================================================================================================================================\n";
	cout<<"======================================================================================================================================================================\n";
	cout<<"\t\t\t\t\t\t\tBuns Talk \n ";
	cout<<"======================================================================================================================================================================\n";
	cout<<"======================================================================================================================================================================\n";
	cout<<"\n";
	
}
void exi(){
	//========Exit Function========
	char what ;
	int i;
	cout<<"\n\nTry Again = y , Exit = n :";
	cin>>what;
	
	if (what=='n'){
		exit(0);
	}
}
void helpCashier(){
	int i,function;
	system("cls");
	title();
	cout<<"\n\n\t\t\t\t\t 1 . You can only purches food only \n\t\t\t\t\t 2 . Need Add More items Please Contact Admin ";
	cout<<"\n\n\n\t\t\t\t\t  Contact us \n\t\t\t\t\t Smart Technolgy \n\t\t\t\t\t No18 Galle Road , Moratuwa .\n\t\t\t\t\t Tel : 07741628867 ";
	for (i=0;i<10;i++){
	cout<<"\n\n\t\t\t\t [1] Main Menu \t[2] Log out \t[3] Exit";
	cout<<"\n\n\t\t\tEnter Function : ";
	cin>>function;
	switch (function){
		case 1 :
			system("cls") ;
			mainmenuAdmin();
			i=2;
		break;
		case 2 :
			mainmenuAdmin();
			i=2;
		break;
		case 3 :
			exi();
			i=0;
		break;
		default:
			cout<<"\nEnter Valid Number \n";
			i=0;		
	}
	}
}
void login(){
	string user,password;
	
	cout<<"\n\n";
	//========Log in Function=========
	//=======Loop for again and again
	for (int i=0;i<1;){
		cout<<"\t\t\t\tEnter User Name : ";
		cin>>user;
		cout<<"\t\t\t\tEnter Password  : ";
		cin>>password;
		if (user=="Admin" && password=="12345"||user=="Cash" && password=="cash"){
			i=2;
		}
		else {
			cout<<"\t\t\t !!!!!!Error , User Name or Password Wrong!!!!";
			exi();
			i=0;
		}
	}
	if (user=="Admin"){
		system("cls");
		mainmenuAdmin();
	}		
	else{
		system("cls");
		mainmenuCash();
	}
}
void help(){
	
}
void addEdit(){
	title();
	int i,function;
	cout<<"\t\tEdit Items :";
	cout<<"\n\t\t\t\ Open items.txt And (Same Directory) You Can Add Or Delete Or Edit Price In txt file ";
	for (i=0;i<10;i++){
	cout<<"\n\n\t\t\t\t [1] Main Menu \t[2] Log out \t[3] Exit";
	cout<<"\n\n\t\t\tEnter Function : ";
	cin>>function;
	switch (function){
		case 1 :
			system("cls") ;
			mainmenuAdmin();
			i=2;
		break;
		case 2 :
			mainmenuAdmin();
			i=2;
		break;
		case 3 :
			exi();
			i=0;
		break;
		default:
			cout<<"\nEnter Valid Number \n";
			i=0;		
	}
	}	
}
int pribill(string bn[] , int bq[] , int bp[],int x,int s){
	system("cls");
	title();
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti=localtime(&tt);
	cout<<"\t\t\t\t\t Bill\t\t"<<asctime(ti)<<"\n\n";
	cout<<"\t\t\t"<<"Num "<<"Item "<<"\t\t\t\t\t\t\t"<<"qty"<<"\t\t"<<"U.Price"<<"\t\tTotal\n";
	int cash,discount,balance ;
	string enter;
	for (int c=0; c<=x;c++){
		
		cout<<"\t\t\t"<<c+1<<". "<<bn[c]<<"\t\t\t\t\t"<<bq[c]<<"\t\t"<<bp[c]<<"\t\t"<<bq[c]*bp[c]<<"\n";
	}
	cout<<"\n\t\t\t\t\t\t\t\t Sum Total : \t\t\t\t"<<s<<"\n";
		
	cout<<"\n\t\t\t\t***** Add Discout please enter dis ***** \n";
	cout<<"\t\t\t\t Enter Cash Amount : ";
	cin>>enter;
	if (enter =="DIS" || enter=="dis"||enter=="Dis"){
		cout<<"Enter Discount : ";
		cin>>discount;
		s=s-(s*discount)/100;
		cout<<"\n\t\t\t\t\t\t\t\t Sum Total : "<<s;
		cout<<"\n\t\t\t\tCash : ";
		cin>>cash;	
		balance=cash-s;
		cout<<"\n\t\t\t\tBalance : "<<balance;
	}
	else {
		stringstream convert;
		convert<<enter;
		convert>>cash;
		balance=cash-s;
		cout<<"\t\t\t\tBalance : "<<balance;
	}
	int function;
	cout<<"\n\n\t\t[1] Print Doc\t\t[2] Add new Bill\t\t[3] Main Menu";
	cout<<"\n\t\t\tEnter Function : ";
	cin>>function;
	if (function==1){
 
			ofstream printdoc;
			printdoc.open("sale.txt");
			if (printdoc.is_open()){
				printdoc<<"\t\t\ ================BunsTalk================== \n\t\t\t\t Bill Recipt\n\n ";
				printdoc<<"\t\t"<<"Num "<<"Item "<<"\t\t\t\t\t"<<"qty"<<"\t\t"<<"U.Price"<<"\t\tTotal\n";
				for (int c=0; c<=x;c++){
					printdoc<<"\t\t"<<c+1<<". "<<bn[c]<<"\t\t\t"<<bq[c]<<"\t\t"<<bp[c]<<"\t\t"<<bq[c]*bp[c]<<"\n";					
				}
				printdoc<<"\n\n\t\t\t\t\t Sum Total : \t\t\t\t"<<s<<"\n";
				printdoc<<"\n\t\t\t\t\t Cash : \t\t\t\t"<<cash<<"\n";
				printdoc<<"\n\t\t\t\t\t Balance : \t\t\t\t"<<balance<<"\n";
				printdoc<<"\n\n\t\t\t\t Thank You Come Again";	
				printdoc.close();			
		  		cout<<"Printing Succusfull";
				cout<<"\n\n\t\t[1] Add new Bill\t\t[2] Main Menu";
				cout<<"\n\t\t\tEnter Function : ";
				cin>>function;
				if (function==1){
					item();
				}
				else if (function==2){
					mainmenuAdmin();
				}
				else {
				cout<<"Enter Valid Id!!";
				}
				
				}
				else {
					cout<<"Printing Fail!!";
				}
	}else if (function==2){
			item();
		}	
	else if (function==3){
		mainmenuAdmin();
	}
	else {
		cout<<"Enter Valid Id!!";
	}	
}
void reset(){
	item();
}

void mainmenuAdmin(){
	title();
	int menu;
	//After Log in Main Menu 
	cout<<"\t\t\t\t User = Admin\n\n";
	cout<<"\t [1] Billing \t\t[2] How to Add or Edit Items\n";
	cout<<"\t [3] Daily Sales \t[4] Log out \n";
	cout<<"\t\t [5] Exit\n\n";
	cout<<"\t\tEnter Function : ";
	cin>>menu;
	
	cout<<menu;
	
	
	switch (menu){
		case 1 :
				system("cls");
				item();
			break;
		case 2 :
				system("cls");
				addEdit();
			break;
		case 3 :
				
			break;
		case 4 :
				login();
			break;
		case 5 :
				exi();
			break;
		default :
			cout<<"Enter Valid Number";
	}
	
	
}
void mainmenuCash(){
	title();
	int menu;
	//After Log in Main Menu 
	cout<<"\t\t\t\t User = Cashier\n\n";
	cout<<"\t [1] Billing \t\t[2] Help\n";
	cout<<"\t [3] Log out \t[4] Exit\n";
	cout<<"\t\tEnter Function : ";
	cin>>menu;

	switch (menu){
		case 1 :
				item();
			break;
		case 2 :
			helpCashier();
			break;
		case 3 :
			login();
			break;
		case 4 :
				exi();
			break;
		default :
			cout<<"Enter Valid Number";
	}
	
	
}
void item(){
	system("cls");
	title();
	ifstream menu("Item.txt");
    if (!menu) {
        cout << "file not found" << endl;
    }

    string item;
    int count = 1;
	string itemtxt[50];
	string itemname[50];
	string itemtxtprice[50];
	int itemprice[50];
    while (getline(menu, item)) {
        itemtxt[count]= item ;
        cout << "\t\t\t\t";
        cout << item <<"\n";
        itemname[count]=itemtxt[count].substr(7,23);
        itemtxtprice[count]=itemtxt[count].substr(31,35);
        
        stringstream convert;
		convert<<itemtxtprice[count];
		convert>>itemprice[count];
        
        
        count++;
    }
    menu.close();

	
	cout<<"\n\t\t["<<count+1<<"]"<<"Print Bill\t\t"<<"["<<count+2<<"]"<<"New Bill\t\t"<<"["<<count+3<<"]"<<"Main Menu\t\t\n";
	int i;
	string items[20];
	int itemsprice[20];
	string billName[1000];
	int billqty[1000];
	int billPrice[1000];
	int tot,sumTot,totCount;
	tot=0;
	sumTot=0;
	for(i=0;i<100;i++){
		int qty,choose;
		cout<<"\nEnter Item : ";
		cin>>choose;
		if (choose<=count+3){
		
		if (choose==count+1){
			i=110;	
		}else if (choose==count+2){
			reset();
		}else if (choose==count+3){
			mainmenuCash();
		}else{
			cout<<"Qty : ";
			cin>>qty;
			tot=itemprice[choose]*qty;
			sumTot=sumTot+tot;
			cout<<itemname[choose]<<"\t\t"<<qty<<"\t\t"<<itemprice[choose]<<"\t\t"<<tot<<"\t\t Sum Total Is : "<<sumTot<<"\n";
			billName[i]=itemname[choose];
			billqty[i]=qty;
			billPrice[i]=itemprice[choose];
			totCount=i;
		}
		}
		else {
			cout<<"Enter valid ID";
			i=i-1;
		}
		
	}
	pribill(billName,billqty,billPrice,totCount,sumTot);
	}

int main()
{	
	title();
	login();
	

  return 0;
}
