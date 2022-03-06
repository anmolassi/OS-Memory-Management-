#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n,p;
	cout<<"Enter the no. of processes:"<<endl;
	cin>>p;
	cout<<"Enter the no. of memory blocks: "<<endl;
	cin>>n;
	int process[p],block[n],index[n];
	cout<<"Enter the processes:"<<endl;
	for(int i=0;i<p;i++)
	{
		cout<<"P"<<i<<"\t";
		cin>>process[i];
	}
	cout<<"Enter the blocks :"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"B"<<i+1<<"\t";
		cin>>block[i];
		index[i]=i+1;
	}
	//allocation starts 
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(block[i]>block[j])
            {
                int temp=block[i];
                block[i]=block[j];
                block[j]=temp;
                int temp1=index[i];
                index[i]=index[j];
                index[j]=temp1;
            }
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<"-----------------------------------------------------------------"<<endl<<endl<<endl;
    cout<<"Process Blocks"<<endl;
    for(int i=0;i<p;i++)
    {
    	int j;
    	for(j=0;j<n;j++)
    	{
    		if(block[j]>=process[i])
    		{
    			cout<<"P"<<i<<"\tB"<<index[j]<<endl;
    			block[j]=INT_MIN;
    			break;
			}
		}
		if(j==n)
		{
			cout<<"P"<<i<<"\tNot Allocated"<<endl;
		}
	}
}
