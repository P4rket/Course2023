#include "palindrome.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <stddef.h>
#define MAX_LEN 256

int palindrome(wchar_t str[], int lng )
{
    int n = lng/2;
    for ( int i = 0; i < n; i++ )
    {
        int m = lng - i - 1;
        if ( str[i] != str[m] )
        {
            return 0;
        }

    }
    return 1;
}

int needfile(int argc, char **argv)
{
     setlocale(LC_ALL, "");
  wchar_t buf[MAX_LEN];

  if(argc != 2)
  {
    wprintf(L"Неверное количество аргументов\n");
    return -1;
  } 
  else 
  {
    FILE *f;
   
    if (( f = fopen(argv[1] , "r")) == NULL) 
    {
      wprintf(L"Ошибка при открытии файла\n");
      return -1;
    }
    else 
    {
    wchar_t c;
    int k = 0;
    while ((c = fgetwc(f)) != EOF)
    {
      if(c != '.' && c != ',' && c != ':' && c != ';' && c != '!' && c != '?' && c != '\n' && c != ' ')
      {
        if(iswalpha(c) || iswdigit(c))
        {
          if (iswalpha(c))
            c = towlower(c);
          buf[k] = c;
          k++;
          if(k > MAX_LEN)
          {
            wprintf(L"Слишком большой текст\n");
            return 1;
          }
        }
      } 
    }
    fclose(f);
    if(k == 0)
    {
      wprintf(L"Файл пуст\n");
      return 1;
    }
    int response = palindrome(buf, k);
    if (response)
    {
       wprintf(L"Это палиндром\n");
    } 
    else
    {
      wprintf(L"Полиндром не обнаружен\n");
    }
    }
  }
  
  return 0;
}