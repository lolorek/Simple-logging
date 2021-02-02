#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool isnumber( const std::string & v ) {
    for( size_t i = 0; i < v.size(); ++i ) {
        if( v[ i ] < '0' || v[ i ] > '9' ) return false;

    }
    return true;
}


void rejestracja()
{
			system("cls");
			// otwieranie kliku liczbakont
			int a;
	 		fstream liczbakont;
            liczbakont.open("liczbakont.txt", ios::in | ios::out);
            liczbakont>>a;
            int i;
            i=1+a;

			//tworzenie kolejnych plikow
            FILE *files[20];
            char filename[20];
            sprintf(filename, "%d.txt", i);
            files[i] = fopen(filename, "w");

			
            string login;
            string haslo;
			//wprowadzanie zmian w licznie kont
            fstream liczb;
            liczb.open("liczbakont.txt", ios::out);
            liczb<<i;
			//tworzenie plikow dla poszczegolnych kont
			
            fstream plik(to_string(i)+".txt");
            plik<<"\n";
            cout<<"Enter login: "<<endl;
            cin>>login;
            plik<<login<<"\n";
            cout<<"Your login is: "<<login<<endl;
			system("cls");
            cout<<"Enter password: "<<endl;
            cin>>haslo;
            plik<<haslo<<"\n";
			system("cls");
			cout<<"Your ID is: "<<i<<endl;
			cout<<endl;
            cout<<"Everything is ok!"<<endl;
			cout<<endl;
			
            liczbakont.close();

            cout<<"Registration was successful!"<<endl;
			cout<<endl;
			cout<<"Press enter to continue"<<endl;
			system("Pause");
			system("cls");
}
        

void logowanie()
{
	system("cls");
	string a;
	fstream plik;
	plik.open("liczbakont.txt", ios::out | ios::in);
	plik>>a;
	int l = atoi(a.c_str());	
	plik.close();
	
	
	cout<<"Enter your ID: ";
	string ID;
	cin>>ID;
	if(isnumber(ID))
					{
						string str=ID;
						int idkon = atoi(str.c_str());			
						
						if(idkon<=l)
							{
		    					cout<<"ID correct!"<<endl;
		    					string a,b,c;
		    					string log, pass;
		    					ifstream plik(to_string(idkon)+".txt");
		    					while(!plik.eof())
									{
										plik>>a;
										plik>>b;
										
									}
				
								cout<<"Enter your login: "<<endl;
								cin>>log;
								cout<<endl;
								if(log == a)
								cout<<"Enter your password:  "<<endl;
								else 
									{ 
										cout<<"Wrong login. "<<endl;
										system("pause");
										return logowanie();
									}
				
				
								cin>>pass;
								cout<<endl;
								if(pass == b)
								{
								system("cls");
								cout<<"Logged in to your account!"<<endl;
								system("pause");
								exit(123);
								}
								else 
									{ 
										cout<<"Wrong password!"<<endl;
										system("pause");
										return logowanie();
									}
				
								
							}	
							else
						{
							cout<<"Wrong ID!"<<endl;
							system("pause");
							return logowanie();
		    			} 
							plik.close();  		
					}
					
		}
			
            
            



int main()
{
	int n = 1;
	cout<<" ----------------"<<endl;
	cout<<"|Welcome to Bank!|"<<endl;
	cout<<" ----------------"<<endl;
	do
	{	
	cout<<"1. Register."<<endl;
	cout<<"2. Log in."<<endl;
	cout<<"3. Exit."<<endl;
	int w;
	cin>>w;
	switch(w)
	{
		case 1:
			{
				rejestracja();
				break;
			}
			
		case 2:
			{
				logowanie();
				break;
					
			}

		case 3:
		{
			system("pause");
			exit(123);
			break;
		}

		default:
		{
			cout<<"You chose the wrong option. The program will turn off"<<endl;
			cout<<endl;
			system("pause");
			exit(123);
			break;
		}
	
	}
	}
	while(n > 0);
	
	
}
