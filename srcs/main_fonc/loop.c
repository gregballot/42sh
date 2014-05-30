/*
** loop.c for  in /home/ballot_g/rendu/42sh/srcs/conf
**
** Made by Gregoire Ballot
** Login   <ballot_g@epitech.net>
**
** Started on  Fri Apr 25 13:37:11 2014 Gregoire Ballot
** Last update Fri Apr 25 13:38:18 2014 Gregoire Ballot
*/

void	main_loop(t_tab *tab, int i)
{
  while (tab->buff = my_getline(tab, &i))
    {
      if (only_space(tab) != -1)
  	if ((tab->buff[0] >= 32) && (tab->buff[0] <= 126))
  	  exec_all(tab);
      free(tab->buff);
      tab->buff = NULL;
    }
}
