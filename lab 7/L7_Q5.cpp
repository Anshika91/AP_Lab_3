void hashing(int table[], int tsize, int arr[], int N)
{
   for (int i = 0; i < N; i++) {
       int hv = arr[i] % tsize;
       if (table[hv] == -1)
           table[hv] = arr[i];
       else {
           for (int j = 0; j < tsize; j++) {
               int t = (hv + j * j) % tsize;
               if (table[t] == -1) {
                   table[t] = arr[i];
                   break;
               }
           }
       }
   }
}
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
}
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
