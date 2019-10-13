#include<iostream>
using namespace std;
int main()
{
char ch;
int n,i=0,j=0,ke=0;
int temp=0,min=0;
cout<<"Enter the number of elemts you want in array:\n";
cin>>n;
int a[n];
cout<<"Enter "<<n<<" numbers\n";
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"1)For selection sorting the input data:\n";
cout<<"2)For insertion sorting the input data:\n";
cout<<">>";
cin>>ch;
switch (ch)
{
case '1':
		for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(a[j]<a[min])
				{
				min=j;
				temp=a[min];
				a[min]=a[i];
				a[i]=temp;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
	cout<<"\n";
break;
case '2':
		for(i=1;i<n;i++)
		{
			ke=a[i];
			j=i-1;
				while(j>=0 && a[j]>ke)
				{
				a[j+1]=a[j];
				j=j-1;
				}
			a[j+1]=ke;
		}
		for(i=n-1;i>=0;i--)
		{
			cout<<a[i]<<" ";
		}
	cout<<"\n";
break;
}
return 0;
}
