
using namespace std;


	

int main()
{
	ofstream phonefile("phone.txt");
    string number, line,name,search_name, del_name;
	int choice;
	while(true)
	{
		//................menu........................
		cout<<"  ****phone book****  "<<endl;
		cout<<"1. Add number"<<endl;
		cout<<"2. Search"<<endl;
		cout<<"3. Delete"<<endl;
		cout<<"4. Exit"<<endl;
		//............................................
		cout<<"choose between 1 to 4 and press enter: "<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1:
			{
				cout<<"enter the phone number you want:"<<endl;
				cout<<"type 'e' to go back to menu :)"<<endl<<endl<<endl;
				for(; ;)
				{
				cout<<"number:";
				cin>>number;
				
				if(number=="e")
				{
					break;
				}
				
				phonefile<<number<<' ';
				cout<<"name:";
				cin.ignore();
				getline(cin,name);
				phonefile<<name<<' '<<endl;
				}
				phonefile.close();
				break;	
			}
				
			case 2:
			{
				ifstream phonefile("phone.txt");
				bool found=0;
			    cout<<"enter a name for finding its phone number:"<<endl;
			    cin.ignore();
			    getline(cin,search_name);
			    while(phonefile>>number)
				{
			    	phonefile>>name;
			    	
			    	if(name==search_name)
					{
				    	cout<<name<<" : "<<number<<endl;
				    	found=1;
				    	break;
					}
					else if (found==0)
					{
						continue;
					}
					cout<<search_name<<"is not in this phonebook"<<endl;
					
				}
				break;	
			}
				
			case 3:
			{
				int lnum;
				ofstream temp("temp.txt");
				fstream a("phone.txt");
				cout<<"enter a name for deleting the record:"<<endl;
			    cin.ignore();
			    getline(cin,del_name);
				while(getline(a,line) && !a.eof())
				{
					if ((lnum=line.find(del_name, 0)) != string::npos)
					{
						continue;
					}
					temp<<line<<endl;
				}
				a.close();
				int k = remove("phone.txt");
				if(k==0)
				cout<<"deleted";
				else
				cout<<"nt suc";
				
				temp.close();
				rename("temp.txt" , "phone.txt");
			}
				break;
			
			case 4:
			{
				return 0;
			}
		}
		getch();
		system("cls");
	}
	return 0;
}
