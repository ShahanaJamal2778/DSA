public class Binary_searching {


    public static void main(String[] args){

        int[] myarr={17,19,28,36,44,54,60,71,79,88};
        int l=0,r=9,mid,search=0;
        System.out.println(" enter the value to be searched: ");
        search=46;

        while(l<=r)
        {
            mid=(r+l)/2;
            if(search==myarr[mid])
            {
                System.out.println(" value found");

                break;

            }

            if (search<myarr[mid])
            {
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(r<l)
        {
            System.out.println(" value not found");

        }


    }
}
