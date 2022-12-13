#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TOT_FRAME 500
#define FRAMES_SEND 10

using namespace std;
int i,j;			//global variables 
class sel_repeat
{
	private:
		int fr_send_at_instance;
		int arr[TOT_FRAME];
		int send[FRAMES_SEND];
		int rcvd[FRAMES_SEND];
		char rcvd_ack[FRAMES_SEND];
		int sw,rw;
	public:
		void input();
		void sender(int);
		void reciever(int);
};

void sel_repeat::input()
{
	int n,m;
	cout<<"enter the no. of bits for the sequence number: ";
	cin>>n;
	m=pow(2,n);
	int t=0;
	fr_send_at_instance = (m/2);
	for(i=0;i<TOT_FRAME;i++)
	{
		arr[i]=t;
		t=(t+1)%m;
	}
	for(i=0;i<fr_send_at_instance;i++)
	{
		send[i]=arr[i];
		rcvd[i]=arr[i];
		rcvd_ack[i]='n';
	}
	rw = sw = fr_send_at_instance;
	sender(m);
}

void sel_repeat::sender(int m)
{
	for(i=0;i<fr_send_at_instance;i++)
	{
		if(rcvd_ack[i]=='n')
			cout<<"SENDER : frame "<<send[i]<<" is sent \n";
	}
	reciever(m);
}

void sel_repeat::reciever(int m)
{
	time_t t;
	int f,f1,a1;
	char ch;
	srand((unsigned)time(&t));
	for(i=0;i<fr_send_at_instance;i++)
	{
		if(rcvd_ack[i]=='n')
		{
			f=rand()%10;
			if(f!=5)
			{
				for(j=0;j<fr_send_at_instance;j++)
				{
					if(rcvd[j]==send[i])
					{
						cout<<"RECIEVER : Frame "<<rcvd[j]<<" recieved correctly\n";
						rcvd[j]=arr[rw];
						rw=(rw+1)%m;
						break;
					}
				}
				if(j==fr_send_at_instance)
					cout<<"RECIEVER : Duplicate frame "<<send[i]<<" discarded\n";
				a1=rand()%5;
				if(a1==3)
				{
					cout<<"Acknowledgement "<<send[i]<<" lost\n";
					cout<<"[SENDER TIMEOUTS --> RESEND THE FRAME]\n";
					rcvd_ack[i]='n';
				}
				else
				{
					cout<<"Acknowledgement "<<send[i]<<" recieved\n";
					rcvd_ack[i]='n';
				}
			}
			else
			{
				int id=rand()%2;
				if(id=0)
				{
					cout<<"RECIEVER : Frame "<<send[i]<<" is damaged\n";
					cout<<"RECIEVER : Negetive acknowledgement "<<send[i]<<" sent\n";
				}
				else
				{
					cout<<"RECIEVER : Frame "<<send[i]<<" is lost\n";
					cout<<"[SENDER TIMEOUTS --> RESEND THE FRAME]\n";
				}
				rcvd_ack[i]='n';
			}
		}
	}
	for(int j=0;j<fr_send_at_instance;j++)
	{
		if(rcvd_ack[i]=='n')
			break;
	}
	i=0;
	for(int k=i;k<fr_send_at_instance;k++)
	{
		send[i]=send[k];
		if(rcvd_ack[k]=='n')
			rcvd_ack[i]='n';
		else
			rcvd_ack[i]='p';
		i++;
	}
	for(int k=i;k<fr_send_at_instance;k++)
	{
		send[k]=arr[sw];
		sw=(sw+1)%m;
		rcvd_ack[k]='n';
	}
	cout<<"Want to continue...";
	cin>>ch;
	cout<<"\n";
	if(ch=='y')
		sender(m);
	else
		exit(0);
}

int main()
{
	sel_repeat sr;
	sr.input();
	return 0;
}

/* OUTPUT

enter the no. of bits for the sequence number: 4
SENDER : frame 0 is sent
SENDER : frame 1 is sent
SENDER : frame 2 is sent
SENDER : frame 3 is sent
SENDER : frame 4 is sent
SENDER : frame 5 is sent
SENDER : frame 6 is sent
SENDER : frame 7 is sent
RECIEVER : Frame 0 recieved correctly
Acknowledgement 0 recieved
RECIEVER : Frame 1 recieved correctly
Acknowledgement 1 lost
[SENDER TIMEOUTS --> RESEND THE FRAME]
RECIEVER : Frame 2 recieved correctly
Acknowledgement 2 recieved
RECIEVER : Frame 3 recieved correctly
Acknowledgement 3 recieved
RECIEVER : Frame 4 is lost
[SENDER TIMEOUTS --> RESEND THE FRAME]
RECIEVER : Frame 5 is lost
[SENDER TIMEOUTS --> RESEND THE FRAME]
RECIEVER : Frame 6 recieved correctly
Acknowledgement 6 recieved
RECIEVER : Frame 7 recieved correctly
Acknowledgement 7 lost
[SENDER TIMEOUTS --> RESEND THE FRAME]
Want to continue...

*/
