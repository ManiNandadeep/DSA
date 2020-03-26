#include<bits/stdc++.h>
using namespace std;
struct Interval{
    float s,e;
};
bool compareInterval(Interval i1,Interval i2)
{
    return (i1.s<i2.s);
}
void mergeIntervals(Interval arr[],int n)
{
    if(n<=0)
        return;
    stack<Interval> s;
    sort(arr,arr+n,compareInterval);
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        Interval top=s.top();
        if(top.e<arr[i].s)
            s.push(arr[i]);
        else if(top.e < arr[i].e)
        {
            top.e=arr[i].e;
            s.pop();
            s.push(top);
        }
    }
    cout<<"The merged Intervals are:";
    while(!s.empty())
    {
        Interval t=s.top();
        cout<< "["<< t.s<<","<<t.e<<"]";
        s.pop();
    }
    return;
}
int main(void)
{
    Interval arr[]={{2.34,5.68},{8,12.1},{4.23,15},{20,23},{18,19},{16,18.5},{32,35},{26,33}};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr,n);
    return 0;
}
