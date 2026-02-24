/* Given an array of integers, return the indices of two numbers 
that add up to a given integer.

Constraints:
- all the numbers are positive
- No duplicates in the array
- Return null if no solution available
- There will always be a solution available
- Can there be multiple pairs that add to the target value
  . Only 1 pair of numbers add up to the target solution

Test cases:
1. Solution available
   input =>[1,3,7,9,2], target=11 output => [3,4] 
2. No solution available
   input =>[1,3,7,9,2], target=29 output => null
3. Empty array with a target
   input =>[], target=11 output => null
5. Single element array with a target
   input =>[1], target=11 output => null 
6. input =>[1,3], target=4 output => [0,1] 
   
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct TwoSumSol TwoSumSol;

struct TwoSumSol {
    int solution[2];
};

TwoSumSol* two_sum(int* arr, int target);

int main(){
    int arr[] = {1,3,7,9,2};
    int target = 11;
    TwoSumSol* sol = two_sum(arr, target);
    printf("%d %d\n",sol->solution[0], sol->solution[1]);
    free(sol);
    return 0;
}

TwoSumSol* two_sum(int* arr, int target){
    int* p1;
    int* p2;
    int element=0, j=0;
    TwoSumSol* sol = (TwoSumSol*) malloc(sizeof(TwoSumSol));
    for (size_t i = 0; i < 5; i++)
    {
        p1 = arr+i;
        p2 = arr;
        element = target - *p1;
        j = i+1;
        while (j < 5)
        {
            if(element== *(p2+j)){
                sol->solution[0] = i;
                sol->solution[1] = j;
                return sol;
            }
            j++;
        }
    }
    return nullptr;
}