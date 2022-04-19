# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// arrays's element
struct item
{
    int data;
    struct item *next;
};

struct item *int_array_to_list(int *array, int len)
{
    // return pointer to the first element of the linked list //
    if (!len) {
        return NULL;
    }
    struct item *tmp;
    tmp = malloc(sizeof(*tmp));
    tmp->data = *array;
    tmp->next = int_array_to_list(array + 1, len - 1);
    return tmp;
}

int sum_list(struct item *list)
{
    // return sum of all elements of the list //
    if (list) {
       return list->data + sum_list(list->next); 
    } else {
        return 0;
    }
}

int main(){
    int data_points[] = {1,2,3,4,5,6};
    int len = sizeof(data_points) / sizeof(*data_points);
    struct item *ll = int_array_to_list(data_points, len);
    int sum = sum_list(ll);
    printf("%d\n", sum);
    return 0;
}
