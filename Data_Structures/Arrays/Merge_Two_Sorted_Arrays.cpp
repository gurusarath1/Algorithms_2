int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3; // creating new array
    
    arr3 = new int[arr1Size + arr2Size];

    int pointer_0 = 0, pointer_1 = 0, pointer_2 = 0;

    while(pointer_1 < arr1Size && pointer_2 < arr2Size) {

        if(arr1[pointer_1] < arr2[pointer_2]) {

            arr3[pointer_0] = arr1[pointer_1];
            pointer_1++;
            pointer_0++;

        } else if (arr1[pointer_1] > arr2[pointer_2]) {

            arr3[pointer_0] = arr2[pointer_2];
            pointer_2++;
            pointer_0++;

        } else {

            arr3[pointer_0] = arr1[pointer_1];
            pointer_1++;
            pointer_0++;

            arr3[pointer_0] = arr2[pointer_2];
            pointer_2++;
            pointer_0++;

        }

    }

    while(pointer_1 < arr1Size) {

        arr3[pointer_0] = arr1[pointer_1];
        pointer_1++;
        pointer_0++;

    }

    while(pointer_2 < arr2Size) {

        arr3[pointer_0] = arr2[pointer_2];
        pointer_2++;
        pointer_0++;

    }

    return arr3; // returning array
}
