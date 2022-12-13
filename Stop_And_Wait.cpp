#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;
class timer
{
	private:
		unsigned long begtime;
	public:
		void start()
		{
			begtime=clock();
		}
		unsigned long elapsedtime()
		{
			return(((unsigned long)clock()-begtime)/CLOCKS_PER_SEC);
		}
};
int main()
{
	int frame[]={1,2,3,4,5,6,7,8,9,10};
	unsigned long seconds=10;
	srand(time(NULL));
	timer t;
	cout<<"Sender has to send the frame: ";
	for(int i=0;i<10;i++)
	{
		cout<<frame[i]<<" ";
	}
	cout<<"\n";
	int count=0;
	unsigned long delay=0;
	cout<<"\nSENDER\t\t\t\t\tRECEIVER\n";
	do
	{
		unsigned int timeout =0;
		cout<<"Sending frame: "<<frame[count];
		cout.flush();
		cout<<"\t\t";
		t.start();
		if(rand()%2)
		{
			int to=24600+rand()%(64000-24600)+1;
			for(int i=0;i<64000;i++)
				for(int j=0;j<to;j++){}
		}
		if(t.elapsedtime()<=seconds)
		{
			cout<<"Received frame: "<<frame[count]<<"\n";
			if (delay)
			{
				cout<<"Duplicate: ";
				delay=0;
			}
			cout<<endl;
			count++;
		}
		else
		{
			cout<<"---"<<endl<<"Timeout\n";
			timeout=1;
		}
		t.start();
		if(rand()%2 || timeout)
		{
			int to=24600+rand()%(64000-24600)+1;
			for(int i=0;i<64000;i++)
				for(int j=0;j<to;j++){}
			if(t.elapsedtime()>seconds)
			{
				cout<<"Delayed Ack: \n";
				count--;
				delay=1;
			}
			else if(!timeout)
			{
				cout<<"Acknowledgement : "<<frame[count+1]-1<<endl;
			}
			else
				cout<<"Acknowledgement : "<<frame[count]<<endl;
		}
	}while(count!=10);
	return 0;
}
