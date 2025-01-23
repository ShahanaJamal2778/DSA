



public class quickSort {
public static void main(String[] args){
    int[] arr={12,31,35,8,32,17};
   quick_sort(arr,0,arr.length-1);
for(int i:arr){
    System.out.println(i);
}
}
public static void quick_sort(int []arr,int str,int end){
    if(str<end) {
        int p_i = set_pivort(arr, str, end);
        quick_sort(arr, str, p_i - 1);
        quick_sort(arr, p_i + 1, end);
    }

}

public static int set_pivort(int[] arr, int start,int end){

    int pivot=arr[end];
    int index=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<=pivot){
            index++;
            int t=arr[j];
            arr[j]=arr[index];
        arr[index]=t;}
    }
    index++;
    int t=arr[end];
    arr[end]=arr[index];
    arr[index]=t;
    return index;
}



}
