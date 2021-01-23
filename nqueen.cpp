#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n=9;
int sol[9][9];
bool issafe(int row,int col)
{
   for(int j=0;j<n;j++)
   {
       if(sol[row][j]==1)
        return false;
   }
   for(int i=row,j=col;i>=0 && j>=0; i--,j--)
   {
      if(sol[i][j]==1)
        return false;
   }
   for(int i=row,j=col;i<n && j>=0;i++,j--)
    if(sol[i][j]==1)
        return false;
   return true;
}

bool nqueenrec(int col)
{
    if(col==n) return true;

        for(int i=0;i<n;i++)
        {
          if(issafe(i,col)==true)
          {
              sol[i][col]=1;
              if(nqueenrec(col+1)==true)
                return true;
              sol[i][col]=0;
          }
        }
    return false;
}
bool nqueen()
{
    if(nqueenrec(0)==false)
        return false;
    else
    {


        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<sol[i][j]<<" ";
                cout<<endl;
            }

    }
     return true;

}

int main()
{
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        sol[i][j]=0;
//sol[2][1]=1;
cout<<(nqueen()?"yes":"no");
cout<<endl;

    return 0;
}

