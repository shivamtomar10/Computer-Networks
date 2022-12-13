#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;
int main()
{
	int nf,N,no_tr=0;
	srand(time(NULL));
	cout<<"Enter the number of frames : ";
	cin>>nf;
	cout<<"Enter the Window Size : ";
	cin>>N;
	int i=1,j;
	while(i<=nf)
	{
		int x=0;
		for(j=i ; j<i+N && j<=nf ; j++)
		{
			cout<<"Sent Frame "<<j<<endl;
			no_tr++;
		}
		for(j=i ; j<i+N && j<=nf ; j++)
		{
			int flag = rand()%2;
			if(!flag)
			{
				cout<<"Acknowledgement for frame "<<j<<endl;
				x++;
			}
			else
			{
				cout<<"Frame "<<j<<" Not Received "<<endl;
				cout<<"Retransmitting Window"<<endl;
				break;
			}
		}
		cout<<endl;
		i+=x;
	}
	cout<<"Total number of transmissions : "<<no_tr<<endl;
	return 0;
}

/* OUTPUT
Enter the number of frames : 10
Enter the Window Size : 4
Sent Frame 1
Sent Frame 2
Sent Frame 3
Sent Frame 4
Frame 1 Not Received
Retransmitting Window

Sent Frame 1
Sent Frame 2
Sent Frame 3
Sent Frame 4
Acknowledgement for frame 1
Acknowledgement for frame 2
Acknowledgement for frame 3
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Sent Frame 7
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Sent Frame 7
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Sent Frame 7
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Sent Frame 7
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Sent Frame 7
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Sent Frame 7
Acknowledgement for frame 4
Acknowledgement for frame 5
Acknowledgement for frame 6
Frame 7 Not Received
Retransmitting Window

Sent Frame 7
Sent Frame 8
Sent Frame 9
Sent Frame 10
Frame 7 Not Received
Retransmitting Window

Sent Frame 7
Sent Frame 8
Sent Frame 9
Sent Frame 10
Acknowledgement for frame 7
Acknowledgement for frame 8
Acknowledgement for frame 9
Frame 10 Not Received
Retransmitting Window

Sent Frame 10
Frame 10 Not Received
Retransmitting Window

Sent Frame 10
Frame 10 Not Received
Retransmitting Window

Sent Frame 10
Frame 10 Not Received
Retransmitting Window

Sent Frame 10
Frame 10 Not Received
Retransmitting Window

Sent Frame 10
Acknowledgement for frame 10

Total number of transmissions : 45

--------------------------------
Process exited after 57.08 seconds with return value 0
Press any key to continue . . .

*/
