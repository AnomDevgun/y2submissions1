/*
Programmer: ANOM DEVGUN
Implemented finding of sparse mat
And Transposing Using simple transpose and fast transpose
*/
#include<iostream>
using namespace std;
class mat
{
private :
    int a[20][20],b[20][20],t,i,j,r,c,l,m,cma;
public:
    void input(int,int);
    void spacal();
    void simtra();
    void fatra();
};
void mat::input(int r,int c)
{
    l=r;
    m=c;
    cout<<"Enter Elements Of Matrix\n";
    for (i=0;i<l;i++)
    {
        for(j=0;j<m;j++)
        cin>>a[i][j];
    }
    cout<<"The Entered Matrix is\n";
    for(i=0;i<l;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void mat::spacal()
{
    int ctr=1;

    for(i=0;i<l;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j] != 0)
            {
                b[ctr][0]=i;
                 b[ctr][1]=j;
                  b[ctr][2]=a[i][j];
                ctr++;
            }

        }
    }
    cma=ctr;
    b[0][0]=l;
    b[0][1]=m;
    b[0][2]=ctr-1;
    cout<<"The sparse matrix of the given matrix is : \n";
       for(i=0;i<ctr;i++)
{
cout<<"\n";
for(j=0;j<3;j++)
cout<<b[i][j]<<" ";
}
}
void mat::simtra()
{
    t=b[0][0];
    b[0][0]=b[0][1];
    b[0][1]=t;
    t=0;
    int i=1,cg=cma;                            
    while(cma>0)
    {
        t=b[i][0];
        b[i][0]=b[i][1];
        b[i][1]=t;
        i++;
        cma--;
    }
    for(i=0;i<cg;i++)
{
cout<<"\n";
for(j=0;j<3;j++)
cout<<b[i][j]<<" ";
}
}
void mat::fatra()
{
int c[20][20];
int i,j,o,p,cnt[10],pos[10];
for(i=0;i<=b[0][2];i++)
{
    o=b[i][1];
    cnt[o]++;
}
pos[0]=1;
for(i=1;i<b[0][1];i++)
{
    pos[i]=pos[i-1]+cnt[i-1];
}
for(i=1;i<=b[0][2];i++)
{
    o=b[i][1];
    p=pos[o];
    pos[o]++;
    c[p][0]=b[i][1];
    c[p][1]=b[i][0];
    c[p][2]=b[i][2];
}
c[0][0]=b[0][0];
c[0][1]=b[0][1];
c[0][2]=b[0][2];
for(i=0;i<=c[0][2];i++)
{
cout<<"\n";
for(j=0;j<3;j++)
cout<<c[i][j]<<" ";
}
}
int main()
{
    mat obj;
    int k,n;
    char ch;
    cout<<"Enter The Rows and Columns of Matrix \n";
    cin>>k>>n;
    obj.input(k,n);
    obj.spacal();
    cout<<"\n1)For Simple transpose\n";
    cout<<"2)For Fast Transpose\n";
    cin>>ch;
    switch(ch)
    {
        case '1': obj.simtra();
        break;
        case '2': obj.fatra();
        break;
        default:cout<<"Incorrect choice, no corresponding option\n";
    }
    return 0;

}

