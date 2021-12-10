
using namespace std;

template <typename T>
int bst_search(T* arr, int low,int high,T element){
    int mid;
    if (high>=low){
        mid=(high+low)/2;
        if (arr[mid]==element)
            return mid;
        else if (arr[mid]>element)
            return bst_search(arr,low,mid-1,element);
        else
            return bst_search(arr,mid+1,high,element);
    }
    else
        return -1;
    
}
template <typename T>
int bf_search(T* arr, int size,T element){

        for (int i =0; i<size;i++){
            if((*(arr+i))==(element))
                return i;
            

}
        
        return -1;
    }
// template <typename T>
// int cs_search(T* arr, int low,int high,T element){
//     if (arr[low]==element)
//         return low;
//     else if (low==high)
//         return -1;
//     else
//         return cs_search(arr,low+1,high,element);
    
// }