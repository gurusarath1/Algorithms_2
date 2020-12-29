/*
Input #
An array with integers and its size

Output #
An array with only odd integers

Sample Input #
Arr = [1,2,4,5,10,6,3]

Sample Output #
Arr = [1,5,3]
*/


int * removeEven( int *& Arr, int size ) {
  
  int pointer_1 = 0;


  for(int i=0; i<size; i++) {

    if(Arr[i] % 2 != 0) {
      Arr[pointer_1] = Arr[i];
      pointer_1++;
    }

  }

  return Arr;
}
