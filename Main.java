import java.util.Scanner;


import java.util.Scanner;
public class Main {
    public static void main(String[] args) {


//        System.out.println("searching by linear search");
//        Scanner sc = new Scanner(System.in);
//        int tosearch = sc.nextInt();
        int[] arr = {12, 34, 90, 78, 9, 12, 90};
        //   int[] arr = {1,2,3,4,5,6};
//        for (int i = 0; i < arr.length; i++) {
//            if (tosearch == arr[i]) {
//                System.out.println("value is found at index " + i);
//            }
//        }
//                if(i==arr.length){
//                    System.out.println("value is not found ");
//                }

//        System.out.println("sorting by binary search");
//        Scanner sc2 = new Scanner(System.in);
//        int tosearch2 = sc2.nextInt();
//        int[] arr2 = {9, 12, 12, 34, 56, 78, 78, 78};
//        int l = 0;
//        int r = arr2.length - 1;
//        int mid;
//        boolean flag = false;
//        while (l <= r) {
//            mid = (l + r) / 2;
//            if (tosearch2 == arr2[mid]) {
//                System.out.println("value is found at index " + mid);
//                flag = true;
//                int left = mid - 1;
//                while (left >= 0 && arr2[left] == tosearch2) {
//                    System.out.println("value is found at index " + left);
//                    left--;
//                }
//                int right = mid + 1;
//                while (right <= arr2.length - 1 && arr2[right] == tosearch2) {
//                    System.out.println("value is found at index " + right);
//                    right++;
//                }
//                break;
//            } else if (arr2[mid] > tosearch2) {
//                r = mid - 1;
//            } else {
//                l = mid + 1;
//            }
//            if (l > r) {
//                System.out.println("value is not found");
//            }
//        }

//        System.out.println("selection sort ");
//
//        for( int i = 0; i < arr.length - 1; i++){
//        int smallest=i;
//        for(int j=i+1;j<arr.length;j++){
//            if(arr[j]<arr[smallest]){
//                smallest=j;
//            }
//        }
//        swap(arr,smallest,i);
//
//        }
//        for(int s:arr){
//                System.out.println(s);
//
//        }

        //Insertion sort

//        for (int i = 1; i < arr.length - 1; i++) {
//            int hold = arr[i];
//            int previous = i - 1;
//            while (previous >= 0 && arr[previous] > hold) {
//                arr[previous + 1] = arr[previous];
//                previous--;
//            }
//            arr[previous + 1] = hold;
//
//
//        }
//            for (int j = i - 1; j >= 0; j--) {
//
//                if (hold <arr[j]) {
//                    int t = arr[j];
//                    arr[j] = hold;
//                    arr[i] = t;
//
//                }
//            }


//        System.out.println("bubble sorting");
//
//        for (int i = 0; i < arr.length - 1; i++) {
//            boolean isSwap=false;
//            for (int j = 0; j < arr.length-i-1; j++) {
//                if (arr[j]>arr[j+1]) {
//                    swap(arr, j + 1, j);
//                    isSwap=true;
//                }}
//if(!isSwap){
//    System.out.println("array is already sorted");
//    break;
//
//            }
//        }


        //Merge sort
        int[] arr4 = {6, 3, 9, 5, 2, 8};
        int n = arr4.length;
        divide(arr4, 0, n - 1);


        for (int s : arr4) {
            System.out.println(s);

        }
    }

    private static void conquer(int[] arr, int si, int mid, int ei) {
        int merged[] = new int[ei - si + 1];

        int index1 = si;
        int index2 = mid + 1;
        int x = 0;

        // Merging process
        while (index1 <= mid && index2 <= ei) {
            if (arr[index1] < arr[index2]) {
                merged[x] = arr[index1];
                x++;
                index1++;
            } else {
                merged[x] = arr[index2];
                x++;
                index2++;
            }
        }

        // Copy remaining elements from the left subarray
        while (index1 <= mid) {
            merged[x] = arr[index1];
            x++;
            index1++;
        }

        // Copy remaining elements from the right subarray
        while (index2 <= ei) {
            merged[x] = arr[index2];
            x++;
            index2++;
        }

        // Copy the merged array back into the original array
        for (int i = 0, j = si; i < merged.length; i++, j++) {
            arr[j] = merged[i];
        }
    }

    public static void divide(int[] arr, int si, int ei) {
        if (si >= ei) {
            return;
        }

        int mid = si + (ei - si) / 2; // Find the middle index
        divide(arr, si, mid);  // Recursively divide the left half
        divide(arr, mid + 1, ei);  // Recursively divide the right half
        conquer(arr, si, mid, ei);  // Merge the two halves
    }



    public static void swap(int[] arr, int i, int j) {
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
    }
}