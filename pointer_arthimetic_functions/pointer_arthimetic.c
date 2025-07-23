#include <stdio.h>


int second_last(int *arr, int size)
{
	if(size < 2)
		return -1;
	return *(arr + size - 2);
}


int swap(int **a, int **b)
{
	int *temp = *a;
	*a = *b;
	*b = temp;
	//return **a;
}

void pre_post_increment_operations()
{
        // 50        41        30        21            20        20        11
   // *++ptr, ++*ptr, *ptr++, *(ptr++), (*ptr)++, *(++ptr), ++(*ptr)

    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *ptr = arr;
    // *++ptr;
    // printf("%d\n", *ptr); // 20
    // ++*ptr;
    // printf("%d\n", *ptr); // 21
    // *ptr++;
    // printf("%d\n", *ptr); // 30

    // *(ptr++);
    // printf("%d\n", *ptr); // 40
    // (*ptr)++;
    // printf("%d\n", *ptr); // 41
    // *(++ptr);
    // printf("%d\n", *ptr); // 50
    // ++(*ptr);
    // printf("%d\n", *ptr); // 51
    printf("%d %d %d %d %d %d %d \n", *++ptr, ++*ptr, *ptr++, *(ptr++), (*ptr)++, *(++ptr), ++(*ptr));

}	

int main()
{
	/*int arr[ ] = {10, 20, 30, 40, 50}, *p;
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("enter elements \n");
	for(p = arr; p <= arr + 5 - 1; p++)
		scanf("%d", p);
	printf("reverse elements\n");
	for(p = arr + 5 - 1; p >= arr; p--)
	     printf("%d ", *p);
        
        int result = second_last(arr, size);
	printf("%d\n", result);

	int arr[2][2] = { {10, 20}, {30, 40}};
	int *p = &arr;
	for(p = &arr[0][0]; p <= &arr[2 -1][2 - 1]; p++)
		printf("%d ", *p);
        
	int x = 10, y = 20;
	int *p = &x, *q = &y;
	swap(&p, &q);
        //printf("%d\n", result);
	
	printf( "*p = %d *q = %d\n", *p, *q);*/
        pre_post_increment_operations();
	return 0;
       

}

