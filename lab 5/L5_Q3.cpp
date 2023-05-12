#include <iostream>
using namespace std;
int main()
{
   const int numCRs = 30;
   int crSum = 56;
   bool found = false;
   for (int i = 1; i <= numCRs-3; i++)
   {
     for (int j = i+1; j <= numCRs-2; j++)
     {
       for (int k = j+1; k <= numCRs-1; k++)
       {
         for (int l = k+1; l <= numCRs; l++)
         {
           if (i+j+k+l == crSum)
           {
             cout << "The CRs whose sum is " << crSum << " are:" << i << ", " << j << ", " << k << ", " << l
             << endl;
             found = true;
         }
     }
 }
}
}
if (!found)
{
 cout << "No combination of 4 CRs adds up to " << crSum << endl;
}
return 0;
} 
