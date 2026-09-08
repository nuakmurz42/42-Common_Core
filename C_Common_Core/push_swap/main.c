#include "push_swap.h"


void ft_print_strategy(t_strategy strategy)
{
        if (strategy == ADAPTIVE)
                printf("ADAPTIVE\n");
        else if (strategy == SIMPLE)
                printf("SIMPLE\n");
        else if (strategy == MEDIUM)
                printf("MEDIUM\n");
        else if (strategy == COMPLEX)
                printf("COMPLEX\n");
}

int main(int argc, char **argv)
{
        t_options options;
        t_list *a;

        a = NULL;
        if (argc == 1)
                return (0);
        ft_start(&options);
        if (!ft_parser_args(&a, &options, argc, argv))
                return (1);
        ft_print_strategy(options.strategy);
        printf("bench: %d, strategy: %d\n", options.bench, options.strategy);
        
        ft_lstclear(&a);
        return (0);
}