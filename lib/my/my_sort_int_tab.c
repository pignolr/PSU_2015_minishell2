/*
** my_sort_int_tab.c for sort_int_tab in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:29:49 2016 pignol_r
** Last update Fri Jan 22 23:17:27 2016 pignol_r
*/

void    my_sort_int_tab(int *tab, int size)
{
  int   i;
  int   stock;

  i = 0;
  while (i < size)
    {
      if (tab[i] < tab[i - 1])
	{
	  stock = tab[i - 1];
	  tab[(i - 1)] = tab[i];
	  tab[i] = stock;
	  my_sort_int_tab(tab, size);
	}
      i++;
    }
}
