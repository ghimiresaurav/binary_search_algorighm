#include <iostream>
#include<cmath>

using std::cout;

//using template for support in all data types 
template <typename T>
int get_index_of(T, T [], int, int);

int main(){
    int size, index;

    int int_arr[] = {1, 2, 7, 8, 9, 10, 50, 69, 70, 78, 90, 93, 97};
    size = sizeof(int_arr)/sizeof(int_arr[0]);
    index = get_index_of<int>(69, int_arr, 0, size-1);
    //if index is invalid
    (index == -1)
    ? cout<<"Item not found :/"<<std::endl
    : cout<<"Searched item is in index: "<<index<<std::endl;

    char char_arr[] = {'A', 'B', 'C', 'D', 'E'};
    size = sizeof(char_arr)/sizeof(char_arr[0]);
    index = get_index_of<char>('S', char_arr, 0, size-1);
    //if index is invalid
    (index == -1)
    ? cout<<"Item not found :/"<<std::endl
    : cout<<"Searched item is in index: "<<index<<std::endl;

    float float_arr[] = {1.23, 1.54, 1.69, 2, 2.45, 2.69, 3.05, 3.69, 3.98, 4.20, 4.69, 5.02};
    size = sizeof(float_arr)/sizeof(float_arr[0]);
    index = get_index_of<float>(3.05 , float_arr, 0, size-1);
    //if index is invalid
    (index == -1)
    ? cout<<"Item not found :/"<<std::endl
    : cout<<"Searched item is in index: "<<index<<std::endl;

}
template <typename T>
int get_index_of(T x, T temp_arr[], int start, int end){
    //make sure the start index is less than the ending index
    if(start <= end){
        //get the index at middle
        //floor it so the value is always an integer
        int mid_index = floor((start + end) / 2);

        //if the item being searched for is less than the element at the middle of the array the element must be in the first half
        if(x < temp_arr[mid_index])
            return get_index_of(x, temp_arr, start, mid_index - 1);
        
        //if the item being searched for is greater than the element at the middle of the array the element must be in the second half
        else if(x > temp_arr[mid_index])
            return get_index_of(x, temp_arr, mid_index + 1, end);

        //if the item being searched for is equal to the element in the middle of the array return the index
        else if(x == temp_arr[mid_index]) return mid_index;
    }
    //if the element is not found, return an invalid index
    return -1;
}