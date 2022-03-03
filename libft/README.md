# Libft

[![asimon's 42Project Score](https://badge42.herokuapp.com/api/project/asimon/Libft)](https://github.com/JaeSeoKim/badge42)

_Voici ma libft pour l'école 42 - 2019_

_Je rajouterai des fonctions au fur et à mesure afin de faciliter mes prochains programmes_

## Table of content

1. [ft_atoi](#ft_atoi)
2. [ft_bzero](#ft_bzero)
3. [ft_calloc](#ft_calloc)
4. [ft_gnl](#ft_gnl)
5. [ft_isalnum](#ft_isalnum)
6. [ft_isalpha](#ft_isalpha)
7. [ft_isascii](#ft_isascii)
8. [ft_isdigit](#ft_isdigit)
9. [ft_isprint](#ft_isprint)
10. [ft_itoa](#ft_itoa)
11. [ft_memccpy](#ft_memccpy)
12. [ft_memchr](#ft_memchr)
13. [ft_memcmp](#ft_memcmp)
14. [ft_memcpy](#ft_memcpy)
15. [ft_memmove](#ft_memmove)
16. [ft_memset](#ft_memset)
17. [ft_putchar](#ft_putchar)
18. [ft_putendl](#ft_putendl)
19. [ft_putnbr_fd](#ft_putnbr_fd)
20. [ft_putstr_fd](#ft_putstr_fd)
21. [ft_count_word](#ft_count_word)
22. [ft_strchr](#ft_strchr)
23. [ft_split](#ft_split)
24. [ft_strdup](#ft_strdup)
25. [ft_strjoin](#ft_strjoin)
26. [ft_strlcat](#ft_strlcat)
27. [ft_strlcpy](#ft_strlcpy)
28. [ft_strlen](#ft_strlen)
29. [ft_strmapi](#ft_strmapi)
30. [ft_strncmp](#ft_strncmp)
31. [ft_strnstr](#ft_strnstr)
32. [ft_strrchr](#ft_strrchr)
33. [ft_strtrim](#ft_strtrim)
34. [ft_substr](#ft_substr)
35. [ft_tolower](#ft_tolower)
36. [ft_toupper](#ft_toupper)
37. [ft_putchar](#ft_putchar)
38. [ft_putstr](#ft_putstr)
39. [ft_strncpy](#ft_strncpy)

***


## ft_atoi

### Idée global
Convertion d'une string en integer.

### Prototype
```
int   ft_atoi(char *str)
```
### Arguments
Une chaine de caracteres remplis de chiffres.

### Return
Retourne un int, retourne 0 si rien n'est a convertir.

#### Appel
```
char  *str;
int   ret

str = "42";
ret = ft_atoi(str); // Retourne 42
```
***


## ft_bzero

### Idée global
Insére dans le pointeur (* *s*), un nombre *n* '\0'

### Prototype
```
void  ft_bzero(char *s, size_t n)
```

### Arguments 
Un pointeur sur * *s*

### Return
Rien

### Appel
```
char    *str;
int     size;

size = 42;
str = (char *)malloc(sizeof(char) * (size + 1));
ft_bzero(str, size);
```

***


## ft_calloc

### Idée Global
Alloue sur la heap et initialise ses cases a '\0'

### Prototype
```
void  ft_calloc(size_t count, size_t size)
```

### Arguments
Un *size_t size* representant la taille d'un type de case (int, char, unsigned int...), et un *size_t count* representant le nombre de cases.

### Return
Retourne un pointeur sur une chaine de caractères '\0' allouée sur la heap 

### Appel
```
char    *str;
size_t  count;
size_t  size;

size = sizeof(int);
count = 42;
str = ft_calloc(count, size);
```
***

## ft_isalnum

### Idée Global
Verifie si un caractère est alphanumérique 

### Prototype
```
int   ft_isalnum(char c)
```

### Arguments
Prend un *char c*

### Return
Retourne 1 si alphanumérique, 0 si non.

### Appel
```
char  str[3];

str[0] = '4';
str[1] = '2';
str[2] = ' ';
ft_isalnum(str[0]); // Retourne 1
ft_isalnum(str[1]); // Retourne 1
ft_isalnum(str[2]); // Retourne 0
```
***

## ft_isalpha

### Idée Global
Verifie si le caractère est alphabétique (minuscule ou majuscule)

### Prototype
```
int   ft_isalpha(char c)
```

### Arguments
Prend un *char c*

### Return
Retourne 1 si le caractère est alphabétique, 0 si non.

### Appel
```
char   yes;
char   no;

yes = 'a';
no = ' ';
ft_isaplha(yes); // Retourne 1
ft_isalpha(no); // Retourne 0
```

***

## ft_isascii

### Idée Global
Verifie si le caractère fait partie de la table ascii (valeur du char entre 0 et 127)

### Prototype
```
int   ft_isascii(char c)
```

### Arguments
Prend un *char c*

### Return
Retourne 1 si le caractère est dans la table ascii, 0 si non.

### Appel
```
char    yes;
char    no;

yes = '0'; // Code ascii => 48
no = 'ç'; // Code ascii => 128
ft_isascii(yes); // Retourne 1
ft_isascii(no); // Retourne 0
```

***

## ft_isdigit

### Idée Global
Verifie si le caractère est numérique (code ascii entre 48 et 57)

### Prototype
```
int   ft_isdigit(char c)
```

### Arguments
Prend un *char c*

### Return
Retourne 1 si le caractère est numérique, 0 si non.

### Appel
```
char    yes;
char    no;

yes = '0';
no = 'a';
ft_isdigit(yes); // Retourne 1
ft_isdigit(no); // Retourne 0
```

***

## ft_isprint

### Idée Global
Verifie si le caractère peut etre afficher (code ascii entre 32 et 126)

### Prototype
```
int   ft_isprint(char c)
```

### Arguments
Prend un *char c*

### Return
Retourne 1 si le caractère est affichable, 0 si non.

### Appel
```
char    yes;
char    no;

yes = ' ';
no = '\0';

ft_isprint(yes); // Retourne 1
ft_isprint(no); // Retourne 0
```

***

## ft_itoa

### Idée Global
Convertie un int en une chaine de caractère

### Prototype
```
char    *ft_itoa(int n)
```

### Arguments
Prend un *int n*

### Return
Retourne un pointeur sur une chaine de caractères  

### Appel
```
int   n;
char  *ret;

n = 42;
ret = ft_itoa(n); // ret[0] == '4', ret[1] == '2'
```

***

## ft_memccpy

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_memchr

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_memcmp

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_memcpy

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_memmove

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_memset

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_putchar

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_putendl

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_putnbr_fd

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_putstr_fd

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_count_word

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strchr

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_split

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strdup

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strjoin

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strlcat

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strlcpy

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strlen

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strmapi

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strncmp

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strnstr

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strrchr

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strtrim

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_substr

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_tolower

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_toupper

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_putchar

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_putstr

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
## ft_strncpy

### Idée Global

### Prototype

### Arguments

### Return

### Appel

***
