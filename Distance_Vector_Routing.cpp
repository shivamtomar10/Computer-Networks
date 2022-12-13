#include<iostream>
using namespace std;
int main()
{
	int graph[50][50];
	int i,j,k,t;
	int nn;
	cout<<"enter the number of nodes : ";
	cin>>nn;
	
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			graph[i][j]=-1;
		}
	}
	
	char ch[7]={'A','B','C','D','E','F','G'};
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			if(i==j)
			{
				graph[i][j]=0;
			}
			if(graph[i][j] == -1)
			{
				cout<<"\nenter distance between "<<ch[i]<<"-"<<ch[j]<<":";
				cin>>t;
				graph[i][j]=graph[j][i]=t;
			}
		}
	}
	
	int via[50][50];
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			via[i][j]=-1;
		}
	}
	
	cout<<"\n after initialization";
	for(i=0;i<nn;i++)
	{
		cout<<"\n"<<ch[i]<<" Table";
		cout<<"\nNode\tDist\tVia";
		for(j=0;j<nn;j++)
		{
			cout<<"\n"<<ch[j]<<"\t"<<graph[i][j]<<"\t"<<via[i][j];
		}
	}
	
	int sh[50][50][50];
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			for(k=0;k<nn;k++)
			{
				if((graph[i][j]>-1)&&(graph[j][k]>-1))
				{
					sh[i][j][k]=graph[j][k]+graph[i][j];
				}
				else
				{
					sh[i][j][k]=-1;
				}
			}
		}
	}
	
	for(i=0;i<nn;i++)
	{
		cout<<"\n\nFOR "<<ch[i];
		for(j=0;j<nn;j++)
		{
			cout<<"\nFROM "<<ch[j];
			for(k=0;k<nn;k++)
			{
				cout<<"\n"<<ch[k]<<" "<<sh[i][j][k];
			}
		}
	}
	
	int final[50][50];
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			final[i][j]=graph[i][j];
			via[i][j]=i;
			for(k=0;k<nn;k++)
			{
				if(final[i][j]>sh[i][k][j] || final[i][j]==-1)
				{
					if(sh[i][k][j]>-1)
					{
						final[i][j]=sh[i][k][j];
						via[i][j]=k;
					}
				}
			}
			if (final[i][j]==-1)
			{
				for(k=0;k<nn;k++)
				{
					if((final[i][k]!=-1) && (final[k][j]!=-1))
					{
						if((final[i][j]==-1) || ((final[i][j]!=-1) && (final[i][j]>final[i][k]+final[k][j])))
						{
							if(final[i][k]+final[k][j]>-1)
							{
								final[i][j]=final[i][k]+final[k][j];
								via[i][j]=k;
							}
						}
					}
				}
			}
		}
	}
	
	for(i=0;i<nn;i++)
	{
		cout<<"\n"<<ch[i]<<" Table";
		cout<<"\nNode\tDist\tVia";
		for(j=0;j<nn;j++)
		{
			cout<<"\n"<<ch[j]<<"\t"<<final[i][j]<<"\t";
			if(i==via[i][j])
				cout<<"-";
			else
				cout<<ch[via[i][j]];
		}
	}
	return 0;
}


/* OUTPUT

enter the number of nodes : 5

enter distance between A-B:5

enter distance between A-C:2

enter distance between A-D:3

enter distance between A-E:-1

enter distance between B-C:4

enter distance between B-D:-1

enter distance between B-E:3

enter distance between C-D:-1

enter distance between C-E:4

enter distance between D-B:-1

enter distance between D-C:-1

enter distance between D-E:-1

enter distance between E-A:-1

enter distance between E-D:-1

 after initialization
A Table
Node    Dist    Via
A       0       -1
B       5       -1
C       2       -1
D       3       -1
E       -1      -1
B Table
Node    Dist    Via
A       5       -1
B       0       -1
C       4       -1
D       -1      -1
E       3       -1
C Table
Node    Dist    Via
A       2       -1
B       4       -1
C       0       -1
D       -1      -1
E       4       -1
D Table
Node    Dist    Via
A       3       -1
B       -1      -1
C       -1      -1
D       0       -1
E       -1      -1
E Table
Node    Dist    Via
A       -1      -1
B       3       -1
C       4       -1
D       -1      -1
E       0       -1

FOR A
FROM A
A 0
B 5
C 2
D 3
E -1
FROM B
A 10
B 5
C 9
D -1
E 8
FROM C
A 4
B 6
C 2
D -1
E 6
FROM D
A 6
B -1
C -1
D 3
E -1
FROM E
A -1
B -1
C -1
D -1
E -1

FOR B
FROM A
A 5
B 10
C 7
D 8
E -1
FROM B
A 5
B 0
C 4
D -1
E 3
FROM C
A 6
B 8
C 4
D -1
E 8
FROM D
A -1
B -1
C -1
D -1
E -1
FROM E
A -1
B 6
C 7
D -1
E 3

FOR C
FROM A
A 2
B 7
C 4
D 5
E -1
FROM B
A 9
B 4
C 8
D -1
E 7
FROM C
A 2
B 4
C 0
D -1
E 4
FROM D
A -1
B -1
C -1
D -1
E -1
FROM E
A -1
B 7
C 8
D -1
E 4

FOR D
FROM A
A 3
B 8
C 5
D 6
E -1
FROM B
A -1
B -1
C -1
D -1
E -1
FROM C
A -1
B -1
C -1
D -1
E -1
FROM D
A 3
B -1
C -1
D 0
E -1
FROM E
A -1
B -1
C -1
D -1
E -1

FOR E
FROM A
A -1
B -1
C -1
D -1
E -1
FROM B
A 8
B 3
C 7
D -1
E 6
FROM C
A 6
B 8
C 4
D -1
E 8
FROM D
A -1
B -1
C -1
D -1
E -1
FROM E
A -1
B 3
C 4
D -1
E 0
A Table
Node    Dist    Via
A       0       -
B       5       -
C       2       -
D       3       -
E       6       C
B Table
Node    Dist    Via
A       5       -
B       0       -
C       4       -
D       8       A
E       3       -
C Table
Node    Dist    Via
A       2       -
B       4       -
C       0       -
D       5       A
E       4       -
D Table
Node    Dist    Via
A       3       -
B       8       A
C       5       A
D       0       -
E       9       A
E Table
Node    Dist    Via
A       6       C
B       3       -
C       4       -
D       9       A
E       0       -
--------------------------------
Process exited after 56.03 seconds with return value 0
Press any key to continue . . .


*/
