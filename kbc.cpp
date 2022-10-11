#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
ifstream fin;
class question
{
	private:
		string ques;
		string opt[4];
		char ans;
	public:
		void get(int r)
		{
			string q[3],op[3][4],answer[3];
			for(int j=0;j<3;j++)
			{
				getline(fin,q[j]);
				for(int i=0;i<4;i++)
					getline(fin,op[j][i]);
				getline(fin,answer[j]);
			}
			ques=q[r];
			for(int i=0;i<4;i++)
				opt[i]=op[r][i];
			ans=answer[r][0];
		}
		void put()
		{
			cout<<endl<<ques<<endl;
			for(int i=0;i<=3;i++)
			{
				int l=opt[i].length();
				cout<<endl<<setw(8)<<(char)(i+65)<<": "<<opt[i];
				i++;
				cout<<setw(40-l)<<(char)(i+65)<<": "<<opt[i]<<endl;
			}
		}
		char answer()
		{
			return ans;
		}
		string correct_option()
		{
			return opt[ans-65];
		}
		void fifty_fifty()
		{
			int i,j,k;
			srand(time(0));
			i=(int)ans-65;
			other_option:
			j=rand()%4;
			if(j==i)
				goto other_option;
			for(k=0;k<4;k++)
			{
				if(k!=i&&k!=j)
					opt[k]="";
			}
		}
};
void getdetails(string &name,int &age,string &place)
{
	cout<<" ****************************************************************************** ";
	cout<<" *                                                                            * ";
	cout<<" *                    ** WELCOME TO KAUN BANEGA CROREPATI **                  * ";
	cout<<" *                       --------------------------------                     * ";
	cout<<" *                                      BY                                    * ";
	cout<<" *                                                                            * ";
	cout<<" *                              Rohan Kumar Singh                             * ";
	cout<<" *                                                                            * ";
	cout<<" ****************************************************************************** ";
	cout<<"Congratulations for winning The Fastest Fingers First..\nHello and Welcome to the KBC..\n";
	cout<<"\nWe'd like to know a few things about you...\n";
	cout<<"\nEnter your Name: ";
	getline(cin,name);
	cout<<"\nEnter your Age: ";
	cin>>age;
	cout<<"\nEnter your Hometown : ";
	fflush(stdin);
	getline(cin,place);
}
void instructions(string &name,int &age,string &place)
{
	system("cls");
	cout<<" ******************************************************************************\n";
	cout<<" *                           KAUN BANEGA CROREPATI                            *\n";
	cout<<" ******************************************************************************\n";
	cout<<"Hello Everyone! Today we have a new player "<<name<<" from "<<place<<" who's "<<age<<" years old.\n";
	cout<<"So, Without further ado, let's start this amazing game of Kaun Banega Crorepati!\n";
	cout<<"Press 1 to read the instruction manual..\n";
	if(getch()=='1')
	{
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<"INSTRUCTIONS:\n";
		cout<<"1: There will be a total of 13 questions in the game.\n";
		cout<<"2: For each question, you will have 4 options to choose the correct answer from.";
		cout<<"3: Each correct answer will give you a prize money starting from Rs. 5,000 ranging to Rs. 5 crores and will let you progress you further in the game.\n";
		cout<<"4: You will also have 4 lifelines namely \"Audience Poll, 50-50, Double Dip(2X), and Ask the Expert\" to help you throughout the game if you get stuck at a question.\n";
		cout<<"5: If at any point, you give an incorrect answer, you won't be allowed to play further and will be eliminated.\n";
		cout<<"6: However, you will get the threshold amount you have earned, if any. The two threshold amounts will be at Rs. 80,000 and Rs. 3,20,000 respectively.\n";
		cout<<"7: You also have a provision to quit the game at any particular moment and walk away with your current winnings.\n";
	}
	cout<<"\nLET'S PLAY! Press Any Key to Continue..\n";		
	getch();
}
void audience_poll(char ans)
{
	int p[4]={0},i,j,bal=100,sticks;
	srand(time(0));
	i=(int)ans-65;
	p[i]=(rand()%21)+60;
	bal-=p[i];
	i=0;j=0;
	while(i<2)
	{
		if(p[j]==0)
		{
			p[j]=rand()%bal;
			bal-=p[j];
			i++;
		}
		j++;
	}
	if(p[2]==0)
		p[2]=bal;
	else
		p[3]=bal;
	system("cls");
	cout<<" ******************************************************************************\n";
	cout<<" *                           KAUN BANEGA CROREPATI                            *\n";
	cout<<" ******************************************************************************\n";
	cout<<"\n\n\n The Votes are in and are as follows:\n";
	for(i=0;i<4;i++)
	{
		sticks=p[i]/10;
		cout<<"          "<<(char)(i+65)<<": ";
		for(int j=0;j<=sticks;j++)
			cout<<"|";
		cout<<setw(10-sticks)<<setfill(' ');
		cout<<" ("<<p[i]<<"%"<<")\n";
	}
	cout<<"\nPress Any Key to Continue..\n";
	getch();
}
void expert_advice(char ans,string &name,string correct_option)
{
	system("cls");
	cout<<" ******************************************************************************\n";
	cout<<" *                           KAUN BANEGA CROREPATI                            *\n";
	cout<<" ******************************************************************************\n";
	cout<<"\n\nHello, "<<name<<". You've been playing really well and after much speculation ";
	cout<<"I've reached to this conclusion that the answer for this question must be..\n";
	cout<<"                        OPTION "<<ans<<": "<<correct_option<<".\n";
	cout<<"\nPress Any Key to Continue..\n";
	getch();
}
void double_dip()
{
	system("cls");
	cout<<" ******************************************************************************\n";
	cout<<" *                           KAUN BANEGA CROREPATI                            *\n";
	cout<<" ******************************************************************************\n";
	cout<<"\n\nSuccess!! Double Dip (2X) has been invoked for this Question.\n";
	cout<<"Now, you'll get a second chance even if you're wrong the first time.\n";
	cout<<"However, the lifeline will still be considered used up even when you get the answer correct in the first turn.";
	cout<<"\nPress Any Key to Continue..\n";
	getch();
}
void end(string &name,int qno,string prize)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	system("cls");
	cout<<" ******************************************************************************\n";
	cout<<" *                           KAUN BANEGA CROREPATI                            *\n";
	cout<<" ******************************************************************************\n";
	cout<<"Thank You So Much "<<name<<" For Playing This Game With Us.\n";
	cout<<"A Very Hearty Congratulations To You For Making It Up Until Question "<<qno<<".\n";
	cout<<"\nHere's Your Cheque For The Amount You've Won!!\n\n";
	cout<<"  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout<<"  $                    VIJAY MALYA FRAUD BANK OF INDIA                       $\n";
	cout<<"  $                   ---------------------------------                      $\n";
	cout<<"  $                                                         DATE: "<<ltm->tm_mday<<"/"<<ltm->tm_mon+1<<"/"<<ltm->tm_year+1900<<" $\n";
	cout<<"  $ Paid To: "<<name<<setw(66-name.length())<<"$\n";
	cout<<"  $"<<setw(73-prize.length())<<"Amount: Rs."<<prize<<" $\n";
	cout<<"  $                                   ~KBC~                                  $\n";
	cout<<"  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout<<"\nPress Any Key to Exit..\n";
	getch();
	exit(0);
}
int main()
{
	question ob[13];
	fin.open("questions.txt");
	if(!fin)
	{
		cout<<"ERROR!! Base Database Not Found.\n";
		exit(0);
	}
	string name,place;
	int age,i,n,second_chance=0,r;
	string threshold="0",inhand="0";
	char ch,ans[13];
	string prize[]={"5,000","10,000","20,000","40,000","80,000",
					"1,60,000","3,20,000","6,40,000","12,50,000",
					"25,00,000","50,00,000","1 Crore","5 Crores"};
	string lifelines[]={" |Audience Poll| "," |Expert's Advice| "," |50-50| "," |Double Dip(2X)| "};
	getdetails(name,age,place);
	instructions(name,age,place);
	srand(time(0));
	//storing data from file to class
	for(int i=0;i<13;i++)
	{
		r=rand()%3;
		ob[i].get(r);
	}
	for(i=0;i<13;i++)
	{
		question_screen:
		system("cls");
		cout<<" ******************************************************************************\n";
		cout<<" *                           KAUN BANEGA CROREPATI                            *\n";
		cout<<" ******************************************************************************\n";
		if(i==5)
			threshold="80,000";
		else if(i==7)
			threshold="3,20,000";
		cout<<"Threshold Amount: Rs."<<threshold;
		cout<<"                             In Hand: Rs.";
		if(i>0)
			inhand=prize[i-1];
		cout<<inhand;
		cout<<"\n\nLifelines:(L) ";
		for(int j=0;j<4;j++)
			cout<<lifelines[j];
		cout<<"\n                                                                 To Quit: (Q)";
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"Question "<<i+1<<":                                                 Prize: Rs."<<prize[i]<<endl;
		ob[i].put();
		cout<<"\n     Enter your Choice: ";
		cin>>ch;
		ans[i]=ob[i].answer();
		if(ans[i]==toupper(ch) || ans[i]==tolower(ch))
		{
			cout<<"\nCorrect Answer!! Congratulations, you won Rs. "<<prize[i]<<".\n";
			cout<<"Press Any Key to Continue..\n";
			getch();
		}
		else if(ch=='L' || ch=='l')
		{
			cout<<"\nThe Lifelines available for you are:\n";
			int a=0;
			while(a<4)
			{
				if(lifelines[a]!="")
					cout<<a+1<<": "<<lifelines[a];
				a++;
			}
			cout<<"\nWhich lifeline do you want to use: ";
			cin>>n;
			cout<<endl;
			if(lifelines[n-1]=="")
			{
				cout<<"You've already used up this lifeline and you cannot use it again!\n";
				cout<<"Press Any Key to Return to the Question..\n";
				getch();
				goto question_screen;
			}
			else
				lifelines[n-1]="";
			switch(n)
			{
				case 1:
					cout<<"You've chosen Audience Poll.The voting time for audience starts now!\n";
					cout<<"Press Any Key to Continue..\n";
					getch();
					audience_poll(ans[i]);
					goto question_screen;
					break;
				case 2:
					cout<<"You've chosen Expert's Advice. The Expert will present his opinion to you now!\n";
					cout<<"Press Any Key to Continue..\n";
					getch();
					expert_advice(ans[i],name,ob[i].correct_option());
					goto question_screen;
					break;
				case 3:
					cout<<"You've chosen 50-50. Any two incorrect options will be removed for you now!\n";
					cout<<"Press Any Key to Continue..\n";
					getch();
					ob[i].fifty_fifty();
					goto question_screen;
					break;
				case 4:
					double_dip();
					second_chance=1;
					goto question_screen;
					break;
				default:
					cout<<"\nERROR!! WRONG INPUT..\n";
			}
		}
		else if(ch=='Q' || ch=='q')
		{
			char quit;
			cout<<"Are you sure that you want to Quit the game and leave with your In-Hand Winnings(Y/N): ";
			cin>>quit;
			if(quit=='Y'||quit=='y')
				end(name,i,inhand);
			else
			{
				cout<<"So, you have decided to continue the game and keep playing..\n";
				cout<<"Press Any Key to Continue..";
				getch();
				goto question_screen;
			}
		}
		else
		{
			if(second_chance==1)
			{
				cout<<"Oops!! Incorrect Answer..\nYou have one more chance left because you chose Double Dip(2X)!\n";
				second_chance=0;
				cout<<"Press Any Key to Continue..\n";
				getch();
				goto question_screen;
			}
			cout<<"Oops!! Incorrect Answer.. Sorry, You can't continue any further!\n";
			cout<<"Correct Answer: Option "<<ans[i]<<endl;
			cout<<"Press Any Key to Continue..\n";
			getch();
			end(name,i,threshold);
		}
		if(second_chance==1)
			second_chance=0;
	}
	end(name,i,prize[i-1]);
}
