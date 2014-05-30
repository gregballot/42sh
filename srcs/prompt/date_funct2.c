/*
** date_funct2.c for date in /home/le-bor_d/rendu/42sh
** 
** Made by le-bor_d
** Login   <le-bor_d@epitech.net>
** 
** Started on  Sat May 24 14:46:03 2014 le-bor_d
** Last update Sat May 24 14:55:55 2014 le-bor_d
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "prompt.h"

void		t_flag2(struct tm *c_time_t)
{
  if (c_time_t->tm_hour <= 9)
    {
      if (printf("0%d:", c_time_t->tm_hour) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:", c_time_t->tm_hour) < 0)
      (void)write(2, "Printf failed\n", 14);
  if (c_time_t->tm_min <= 9)
    {
      if (printf("0%d:", c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:", c_time_t->tm_min) < 0)
      (void)write(2, "Printf failed\n", 14);
  if (c_time_t->tm_sec <= 9)
    {
      if (printf("0%d", c_time_t->tm_sec) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d", c_time_t->tm_sec) < 0)
      (void)write(2, "Printf failed\n", 14);
}

void		capital_t_flag2(struct tm *c_time_t)
{
  if (c_time_t->tm_hour <= 9)
    {
      if (printf("0%d:", c_time_t->tm_hour) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:", c_time_t->tm_hour) < 0)
      (void)write(2, "Printf failed\n", 14);
  if (c_time_t->tm_min <= 9)
    {
      if (printf("0%d:", c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:", c_time_t->tm_min) < 0)
      (void)write(2, "Printf failed\n", 14);
  if (c_time_t->tm_sec <= 9)
    {
      if (printf("0%d", c_time_t->tm_sec) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d", c_time_t->tm_sec) < 0)
      (void)write(2, "Printf failed\n", 14);
}

void		at_flag1(struct tm *c_time_t)
{
  if (c_time_t->tm_hour <= 9 && c_time_t->tm_min <= 9)
    {
      if (printf("0%d:0%d PM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else if (c_time_t->tm_min <= 9)
    {
      if (printf("%d:0%d PM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else if (c_time_t->tm_hour <= 9)
    {
      if (printf("0%d:%d PM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:%d PM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
      (void)write(2, "Printf failed\n", 14);
}

void		at_flag2(struct tm *c_time_t)
{
  if (c_time_t->tm_hour <= 9 && c_time_t->tm_min <= 9)
    {
      if (printf("0%d:0%d AM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else if (c_time_t->tm_min <= 9)
    {
      if (printf("%d:0%d AM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else if (c_time_t->tm_hour <= 9)
    {
      if (printf("0%d:%d AM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
	(void)write(2, "Printf failed\n", 14);
    }
  else
    if (printf("%d:%d AM", c_time_t->tm_hour, c_time_t->tm_min) < 0)
      (void)write(2, "Printf failed\n", 14);
}
