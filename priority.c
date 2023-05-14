#include<stdio.h>
void swap(int *a,int *b)
{
int temp =*a;
*a=*b;
*b=temp;
}
int main()
{
int n,i;
float sum=0,sum1=0;
float awt,atat;
printf("enter number of processes:");
scanf("%d",&n);
int p[n],bt[n],ct[n],wt[n],at[n],tat[n];
printf("enter arrival times:");
for(int i=0;i<n;i++)
{
scanf("%d",&at[i]);
}
printf("enter burst times:");
for(int i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n-1;j++)
{
if (bt[j]>bt[j+1])
{

swap(&bt[j],&bt[j+1]);
swap(&at[j],&at[j+1]);
}}}

for(int i=0;i<n;i++)
{
if(at[i]==0)
{
ct[i]=bt[i];
}
else if(at[i]>ct[i-1])
{
ct[i]=ct[i-1]+bt[i]+(at[i]-ct[i-1]);
}
else
{
ct[i]=ct[i-1]+bt[i];
}
}
for(int i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
}
for(int i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
}
for(int i=0;i<n;i++)
{
sum+=wt[i];
sum1+=tat[i];
}
awt=sum/n;
atat=sum1/n;
printf("AT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
for(int i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
}

printf("avg wait time=%f",awt);
printf("avg turnaround time=%f",atat);
}
