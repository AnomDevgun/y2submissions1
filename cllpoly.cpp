#include<iostream>
using namespace std;
struct node{
int exp;
int pow;
struct node *nxt;
};
typedef struct node *NODE;


NODE attach(int ex,int po,NODE hd){         //ATTACH POLY
NODE nn,temp;
nn= new node;
nn->exp = ex;
nn->pow = po;
temp = hd;
while(temp->nxt != hd)
{
    temp = temp->nxt;
}
temp->nxt = nn;
nn->nxt=hd;
return hd;
}


NODE read(NODE hd){             //INPUT POLY
int i=1,coef,pow;
cout<<"Enter -1 as coefficient to end polynomial.\n";
while(1){
    cout<<"Enter the "<<i<<" coefficient: ";
    cin>>coef;
    if(coef == -1)
        break;
    cout<<"Enter its power: ";
    cin>>pow;
    hd = attach(coef,pow,hd);
i++;
}
return hd;
}


NODE poly_add(NODE head1, NODE head2, NODE head3)
{
            NODE a,b;
            int coeff;
            a = head1->nxt;
            b = head2->nxt;
            while(a != head1 && b != head2)
            {
                        if(a->pow == b->pow)
                        {
                                    coeff = a->exp + b->exp;
                                    if(coeff != 0)
                                                head3 = attach(coeff, a->pow, head3);
                                    a = a->nxt;
                                    b = b->nxt;
                        }
                        else if(a->pow > b->pow)
                        {
                                     head3 = attach(a->exp, a->pow, head3);
                                    a = a->nxt;
                        }
                        else
                        {
                                    head3 = attach(b->exp, b->pow, head3);
                                    b = b->nxt;
                        }
            }
            while(a != head1)
            {
                        head3 = attach(a->exp, a->pow, head3);
                        a = a->nxt;
            }
            while(b != head2)
            {
                        head3 = attach(b->exp, b->pow, head3);
                        b = b->nxt;
            }
            return head3;
}


void disp(NODE hd)
{
    NODE tmp;
    if(hd->nxt == hd){
        cout<<"\nThe Polynomial doesn't exist.\n";
        return;
    }
    tmp= hd->nxt;
    while(tmp != hd)
    {
        cout<<tmp->exp<<"x^"<<tmp->pow;
        tmp= tmp->nxt;
        if(tmp != hd)
            cout<<"+";
    }

}


int main(){
NODE p1,p2,p3;
p1= new node;
p2=new node;
p3=new node;
p1->nxt=p1;
p2->nxt=p2;
p3->nxt=p3;
cout<<"Enter first poly.\n";
p1 = read(p1);
cout<<"Enter second ploy.\n";
p2 = read(p2);
p3 = poly_add(p1,p2,p3);
cout<<"\nFirst Poly:\n";
disp(p1);
cout<<"\nSecond poly:\n";
disp(p2);
cout<<"\nAdded poly:\n";
disp(p3);
return 0;
}
