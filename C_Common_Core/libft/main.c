#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Helper Functions for strmapi and striteri ---
char	mapi_helper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32); // Convert to uppercase
	return (c);
}

void	iteri_helper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32; // Convert to uppercase
	}

// --- Linked List Helper Functions for lstmap and lstclear ---
void	del_list_content(void *content)
{
	free(content); // Frees the malloc'ed content
}

void	*map_list_content(void *content)
{
	char	*str;
	char	*new_str;

	str = (char *)content;
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	int i = 0;
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return (new_str);
}

int main(void)
{
	printf("==================================================\n");
	printf("          42 LIBFT COMPREHENSIVE TEST SUITE       \n");
	printf("==================================================\n\n");

	/* ------------------------------------------------------------------ */
	/* PART 1 & PART 2: MEMORY AND STRING FUNCTIONS                       */
	/* ------------------------------------------------------------------ */
	printf("=== PART 1 & PART 2 TESTS ===\n");

	// 1. ft_memset
	char arr1[] = "abcdefgh";
	ft_memset(arr1, 'X', 5);
	printf("ft_memset:     [%s] (Expected: XXXXXfgh)\n", arr1);

	// 2. ft_memcpy & ft_memmove (Overlap test is highly critical!)
	char move_src[] = "abcdefghijkl";
	// memmove must safely handle overlapping memory areas, memcpy might fail here.
	ft_memmove(move_src + 3, move_src, 5); 
	printf("ft_memmove:    [%s] (Expected: abcabcdeijkl)\n", move_src);

	char cp_src[] = "abcdef";
	char cp_dst[] = "123456789";
	ft_memcpy(cp_dst, cp_src, 4);
	printf("ft_memcpy:     [%s] (Expected: abcd56789)\n", cp_dst);

	// 3. ft_memchr & ft_memcmp
	char mem_arr[] = "42Kocaeli";
	char *chr_res = ft_memchr(mem_arr, 'K', 9);
	printf("ft_memchr:     [%s] (Expected: Kocaeli)\n", chr_res);
	printf("ft_memcmp:     [%d] (Expected: 0)\n", ft_memcmp("abc", "abc", 3));

	// 4. ft_strdup & ft_substr (Contains Malloc!)
	char *dup = ft_strdup("Leakproof Test");
	char *sub = ft_substr(dup, 10, 4); // extracts "Test"
	char *sub_edge = ft_substr("hello", 10, 3); // Start > len case (Must return empty string "")
	printf("ft_strdup:     [%s]\n", dup);
	printf("ft_substr:     [%s] (Expected: Test)\n", sub);
	printf("ft_substr edge:[%s] (Expected: Empty string)\n", sub_edge);
	free(dup);
	free(sub);
	free(sub_edge);

	// 5. ft_strjoin & ft_strtrim (Contains Malloc!)
	char *join = ft_strjoin("42", "Network");
	char *trim = ft_strtrim("   !!!Hello 42!!!   ", " !");
	printf("ft_strjoin:    [%s] (Expected: 42Network)\n", join);
	printf("ft_strtrim:    [%s] (Expected: Hello 42)\n", trim);
	free(join);
	free(trim);

	// 6. ft_strlcpy & ft_strlcat
	char lcpy_dst[10];
	size_t lcpy_ret = ft_strlcpy(lcpy_dst, "12345", sizeof(lcpy_dst));
	printf("ft_strlcpy:    dst=[%s], ret=%zu (Expected: 12345, 5)\n", lcpy_dst, lcpy_ret);

	char lcat_dst[20] = "abc";
	size_t lcat_ret = ft_strlcat(lcat_dst, "def", sizeof(lcat_dst));
	printf("ft_strlcat:    dst=[%s], ret=%zu (Expected: abcdef, 6)\n", lcat_dst, lcat_ret);

	// 7. ft_strchr, ft_strrchr & ft_strnstr
	char *find_str = "42_network_42";
	printf("ft_strchr:     [%s] (Expected: _network_42)\n", ft_strchr(find_str, '_'));
	printf("ft_strrchr:    [%s] (Expected: _42)\n", ft_strrchr(find_str, '_'));
	printf("ft_strnstr:    [%s] (Expected: network_42)\n", ft_strnstr(find_str, "net", 13));
	printf("ft_strncmp:    [%d] (Expected: 0)\n", ft_strncmp("abc", "abc", 3));

	// 8. ft_itoa (Contains Malloc!)
	char *itoa_min = ft_itoa(-2147483648); // INT_MIN test is essential!
	printf("ft_itoa:       [%s] (Expected: -2147483648)\n", itoa_min);
	free(itoa_min);

	// 9. ft_strmapi & ft_striteri
	char *strmapi_res = ft_strmapi("hello", mapi_helper);
	printf("ft_strmapi:    [%s] (Expected: HELLO)\n", strmapi_res);
	free(strmapi_res);

	char striteri_arr[] = "world";
	ft_striteri(striteri_arr, iteri_helper);
	printf("ft_striteri:   [%s] (Expected: WORLD)\n", striteri_arr);

	// 10. ft_split (Most critical malloc structure!)
	printf("\n--- FT_SPLIT TEST ---\n");
	char **split_res = ft_split("  Kocaeli   Istanbul   Bursa  ", ' ');
	int s_idx = 0;
	while (split_res && split_res[s_idx])
	{
		printf("split[%d]: [%s]\n", s_idx, split_res[s_idx]);
		free(split_res[s_idx]); // Freeing individual words
		s_idx++;
	}
	free(split_res); // Freeing the pointer array itself

	// 11. ft_put..._fd functions (Outputs to console)
	printf("\n--- PUT_FD FUNCTIONS ---\n");
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);
	ft_putstr_fd(" -> Network\n", 1);
	ft_putendl_fd("Newline test line", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);


	/* ------------------------------------------------------------------ */
	/* BONUS: ALL LINKED LIST FUNCTIONS                                   */
	/* ------------------------------------------------------------------ */
	printf("\n=== BONUS (LINKED LIST) TESTS ===\n");

	// Creating elements with ft_lstnew
	t_list *head = ft_lstnew(ft_strdup("first element"));
	t_list *node2 = ft_lstnew(ft_strdup("second element"));
	t_list *node3 = ft_lstnew(ft_strdup("third element"));

	// Structuring with ft_lstadd_front & ft_lstadd_back
	ft_lstadd_back(&head, node2);       // head -> node2
	ft_lstadd_front(&head, node3);      // node3 -> head -> node2 (node3 becomes new head)

	printf("ft_lstsize:    [%d] (Expected: 3)\n", ft_lstsize(head));
	
	t_list *last_node = ft_lstlast(head);
	printf("ft_lstlast:    [%s] (Expected: second element)\n", (char *)last_node->content);

	// ft_lstiter test (Verifies iteration by printing content)
	printf("ft_lstiter:    ");
	t_list *tmp = head;
	while (tmp)
	{
		printf("[%s] -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	// ft_lstmap test (Creates a new mapped list, keeps the old one intact)
	t_list *mapped_list = ft_lstmap(head, map_list_content, del_list_content);
	printf("ft_lstmap:     ");
	tmp = mapped_list;
	while (tmp)
	{
		printf("[%s] -> ", (char *)tmp->content); // Expected: uppercase content
		tmp = tmp->next;
	}
	printf("NULL\n");

	// ft_lstdelone test
	t_list *dummy = ft_lstnew(ft_strdup("element to delete"));
	ft_lstdelone(dummy, del_list_content); // successfully frees dummy node and content

	// Cleaning: ft_lstclear (Prevents memory leaks)
	ft_lstclear(&head, del_list_content);
	ft_lstclear(&mapped_list, del_list_content);

	printf("\n🔥 --- ALL TESTS COMPLETED SUCCESSFULLY --- \n");
	return (0);
}

