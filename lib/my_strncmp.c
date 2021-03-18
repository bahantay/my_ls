int my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  while (*s1 && *s2 && i++ < n)
    {
      if (*s1 > *s2)
        return (1);
      else if (*s1 < *s2)
        return (-1);
      s1++;
      s2++;
    }
  if ((!*s1 && !*s2) || *s1 == *s2)
    return (0);
  else if (*s1 > *s2)
    return (1);
  else
    return (-1);
}
