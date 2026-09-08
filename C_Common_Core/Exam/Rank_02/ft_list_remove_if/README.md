# ft_list_remove_if

## Assignment

Assignment name: `ft_list_remove_if`  
Expected files: `ft_list_remove_if.c`  
Allowed functions: `free`

Write a function called `ft_list_remove_if` that removes from the passed linked list every element whose data is equal to `data_ref`.

Prototype:

```c
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());