def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def ft_helper(cur, last):
        if cur > last:
            return
        print("Day", cur)
        ft_helper(cur + 1, last)

    ft_helper(1, days)
    print("Harvest time!")
