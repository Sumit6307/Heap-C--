#include <bits/stdc++.h>

 using namespace std;

  class heap {
     public :
     int arr[100];
      int size = 0;
  
      heap() {
         
         arr[0] = -1;
          size = 0;
      }

         
        void insert(int val) {
              
                 size = size +1;
                int index = size;
                  arr[index] = val;

              while(index>1) {
                    
                    int  parent = index/2;

                   if(arr[parent] < arr[index])  {
  
                      swap(arr[parent], arr[index]);
                       index = parent;

                      
                   }
                   else {
                      return ;
                   }
              }
        } 

 
  void deletefromHeap() {
          
         if(size==0) {
            cout<<"No element to delete";
         }

        
            arr[1] = arr[size];
             size--;
         
     
      int i  = 1;
         
          while(i<size) {

      int left = 2*1;
       int right = 2*i +1;
      int largest = i;

        if(left <= size && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right <= size && arr[largest]  < arr[right] ) {
             largest = right;
        }
   
      if(largest == i) {
           return;
      }
      else {
          swap(arr[i],arr[largest]);
          i = largest;
      }

  }  
  }
  
  
  void print() {
     
      for(int i = 1 ;i<=size;i++) {
          
          cout << arr[i] << " ";
      }  cout<<endl;
  }

  };


  void heapify(int arr[] , int n , int i ) {

      int  largest = i;
      int  left = 2*i;
      int    right = 2*i +1;

    if(left <=n &&  arr[largest] < arr[left] ) {
         largest = left;
    }

    if( right <= n && arr[largest] < arr[right] ) {
            largest = right;
    }

       if(largest !=i ) {
                
          swap(arr[i], arr[largest]);
          heapify(arr, n , largest );
           
       }
  
  }
     

    void heapsort(int arr[], int n) {

           int size = n;

             while(size>1) {
              
            swap(arr[size], arr[1]);
            size--;

            heapify(arr, size,1);

             }

    }
 
  int main () {
  
     heap h;
       
        h.insert(10);
        h.insert(20);
        h.insert(50);
        h.insert(30);
        h.insert(80);
        h.insert(90);
      
         cout<<"Heap After Insertion\n";
        h.print();
          cout<<endl;

        h.deletefromHeap();
     
        cout<<"Heap After deletion\n";
       h.print();
       


     int arr[7] = {-1,20,30,29,53,86,56};
       int n = 6;

     for(int i = n/2 ; i>0;i--) {
         heapify(arr, n , i);

     }      
    cout << "Heapified array : ";
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
           

  // heap sort 

       heapsort(arr,n);

       cout << "Heap Sort array : ";
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

     return 0;

  }

       
