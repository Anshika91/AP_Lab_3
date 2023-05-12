#include <bits/stdc++.h>
using namespace std;
int main()
{
   const int numFloors = 2;
   const int crPerFloor = 15;
   int crNum = 1;
   int crCount[numFloors] = {0};
   for (int floor = 1; floor <= numFloors; floor++)
   {
     for (int i = 1; i <= crPerFloor; i++)
     {
       crCount[floor-1]++;
       crNum++;
   }
}
cout << "Total number of CRs on first floor: " << crCount[0] << endl;
cout << "Total number of CRs on second floor: " << crCount[1] << endl;
return 0;
}
