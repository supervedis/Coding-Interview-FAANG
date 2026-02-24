#include<stdio.h>
#include<math.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
double max_area(int*, size_t);

int main(){
    int heights[] = {4,8,1,2,3,9};
    size_t size = sizeof heights/sizeof *heights;
    printf("Maximum area = %lf\n",max_area(heights,size-1));
    return 0;
}

double max_area(int* heights, size_t size){
    double maxArea = 0.0;
    double area = 0.0;
    int length = 0, width = 0;
    int* i = heights;
    int* j = heights + size;
    while (i < j)
    {
        //length = MAX(*i,*j);
        length = (*i <= *j) ? *i : *j;
        width = (int) (j-i);
        area = length*width;
        maxArea = fmax(maxArea, area);
        if((*i) <= (*j))
            ++i;
        else
            --j;
        
    }
    
    return maxArea;
}

