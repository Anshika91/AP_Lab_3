#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define MAX_SIZE 10000001ll
class doubleHash {
   int TABLE_SIZE, keysPresent, PRIME;
   vector<int> hashTable;
   bitset<MAX_SIZE> isPrime;
   void __setSieve(){
       isPrime[0] = isPrime[1] = 1;
       for(long long i = 2; i*i <= MAX_SIZE; i++)
           if(isPrime[i] == 0)
               for(long long j = i*i; j <= MAX_SIZE; j += i)
                   isPrime[j] = 1;
           }
           int inline hash1(int value){
               return value%TABLE_SIZE;
           }
           int inline hash2(int value){
               return PRIME - (value%PRIME);
           }
           bool inline isFull(){
               return (TABLE_SIZE == keysPresent);
           }
       public:
           doubleHash(int n){
               __setSieve();
               TABLE_SIZE = n;
               PRIME = TABLE_SIZE - 1;
               while(isPrime[PRIME] == 1)
                   PRIME--;
               keysPresent = 0;
               for(int i = 0; i < TABLE_SIZE; i++)
                   hashTable.push_back(-1);
           }
           void __printPrime(long long n){
               for(long long i = 0; i <= n; i++)
                   if(isPrime[i] == 0)
                       cout<<i<<", ";
                   cout<<endl;
               }
               void insert(int value){
                   if(value == -1 || value == -2){
                       cout<<("ERROR : -1 and -2 can't be inserted in
                        the table\n");
                   }
                   if(isFull()){
                       cout<<("ERROR : Hash Table Full\n");
                       return;
                   }
                   int probe = hash1(value), offset = hash2(value);
                   while(hashTable[probe] != -1){
                       if(-2 == hashTable[probe])
                           break;
                       probe = (probe+offset) % TABLE_SIZE;
                   }
                   hashTable[probe] = value;
                   keysPresent += 1;
               }
               void erase(int value){
                   if(!search(value))
                       return;
                   int probe = hash1(value), offset = hash2(value);
                   while(hashTable[probe] != -1)
                       if(hashTable[probe] == value){
                           hashTable[probe] = -2;
                           keysPresent--;
                           return;
                       }
                       else
                           probe = (probe + offset) % TABLE_SIZE;
                   }
                   bool search(int value){
                       int probe = hash1(value), offset = hash2(value),
                       initialPos = probe;
                       bool firstItr = true;
                       while(1){
                           if(hashTable[probe] == -1)
                               break;
                           else if(hashTable[probe] == value)
                               return true;
                           else if(probe == initialPos && !firstItr)
                               return false;
                           else
                               probe = ((probe + offset) % TABLE_SIZE);
                           firstItr = false;
                       }
                       return false;
                   }
                   void print(){
                       for(int i = 0; i < TABLE_SIZE; i++)
                           cout<<hashTable[i]<<", ";
                       cout<<"\n";
                   }
               };
               int main(){
                   doubleHash myHash(13);
                   int insertions[] = {115, 12, 87, 66, 123},
                   n1 = sizeof(insertions)/sizeof(insertions[0]);
                   for(int i = 0; i < n1; i++)
                       myHash.insert(insertions[i]);
                   cout<< "Status of hash table after initial insertions
                   : "; myHash.print();
                   int queries[] = {1, 12, 2, 3, 69, 88, 115},
                   n2 = sizeof(queries)/sizeof(queries[0]);
                   cout<<"\n"<<"Search operation after insertion :
                   \n";
                   for(int i = 0; i < n2; i++)
                       if(myHash.search(queries[i]))
                           cout<<queries[i]<<" present\n";
                       int deletions[] = {123, 87, 66},
                       n3 = sizeof(deletions)/sizeof(deletions[0]);
                       for(int i = 0; i < n3; i++)
                           myHash.erase(deletions[i]);
                       cout<< "Status of hash table after deleting
                       elements : "; myHash.print();
                       return 0;
                   }
