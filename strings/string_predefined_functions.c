#include <stdio.h>

#include <string.h>

int mystrlen(char str[])
{
       int len = 0;	
       while(str[len] != '\0')
       {
	       len++;
       }
       return len;       
}


int reverse_string(char str[])
{
	int i,j;
	char temp;
	for(i = 0, j = mystrlen(str) - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

char count_vowels(char str[ ])
{
    char ch;
    int i, count = 0;
    while(str[i] != '\0')
    {
	    ch = str[i];

	    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || 
			    ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		   count ++;
	    i++; 
    }
    return count;
}


char remove_vowels(char str[ ])
{
    char ch, result[100];
    int i = 0, j = 0, count = 0;
    while(str[i] != '\0')
    {
            ch = str[i];

            if(!(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || 
				   ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ))
            {
		    result[j++] = ch;
	    }
            i++;
    }
    result[j] = '\0';
    printf("string after removing vowels %s \n", result);
}


int remove_all_spaces(char str[])
{
    int i = 0, j = 0;
    while(str[i])
    {
        if(str[i] != ' ')
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}


int remove_extra_spaces(char str[])
{
	int i = 0 , j = 0, is_space = 0, len = strlen(str);
	while(i < len)
	{
            if(str[i] != ' ')
	    {
		    
		    break;
		    
	    }
	    i++;
	}   
	for( ; i < len; i++)
	{
		if(str[i] != ' ')
		{
			str[j++] = str[i];
		        is_space = 0;
		}
	        else if(is_space == 0)
		{
			str[j++] = str[i];
			is_space = 1;
		}	
	}	
	if(j > 0 && str[j -1] == ' ')
		j--;
	str[j] = '\0';
	
}


int my_strcpy(char src[], char dest[])
{
    int i = 0;
    while(src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


void my_strncpy(char *src[], char *dest[], int n)
{
    int i;
    while(src[i] != 0)
    {
	    dest[i] = src[i];
	    i++;
    }
    dest[i] = '\0';
}	


int my_strcmp(char str1[],char str2[])
{
    int i = 0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0')
           return 0;
    i++;
    }
    return str1[i] - str2[i];
}


void my_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0')
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
}


int my_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0' && j < n)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
}


char *my_strchr(char *str, char ch)
{
	while( *str != '\0')
	{
		if(*str == ch)
		{
			return str;
		}
		str++;
	}
	return NULL; 
}


char *my_strrchr(char *str, char ch)
{
	char *last = NULL;
	while(*str != '\0')
	{
		if(*str == ch)
		{
			last = str;
		}
		str++;
	}
	return last;
}


char *my_strstr(char *str, char *substr)
{
	if(*substr == '\0')
	{
		return str;
	}
	while(*str != '\0')
	{
		char *s = str;
		char *sub = substr;
		if(*s == *sub && *sub != '\0')
		{
			s++;
			sub++;
		}
		if(*sub == '\0')
		{
			return str;
		}
		str++;
	}
	return NULL;
}


char to_upper(char ch)
{
   if(ch >= 'a' && ch <= 'z')
   {
	   return ch - 32;
   }	   
   return ch;
}

void capital_first_letter(char *str)
{
	if(str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = to_upper(str[0]);
	}
}

void capital_firstletter_afterspace(char *str)
{
	char temp[100], result[100];
	my_strcpy(temp, str);
	char *token = strtok(temp, " \t");
	while(token != NULL)
	{
		capital_first_letter(token);
		my_strcat(result, token);
		my_strcat(result, " ");
                token = strtok(NULL, " \t");
	}
	strcpy(str, result);
} 	

int main ( )
{
	//char str[] = "      naga lak sh mi ";
	/* printf("length of string %d \n", mystrlen(str));

	reverse_string(str);
	printf("reverse string %s \n", str);
        strcpy(str2, str1);
        reverse_string(str2);
        if(strcmp(str1, str2) == 0)
        {
           printf("palindrome\n");
        }
        else
        {
                printf("not palindrome\n");
        }

	printf("no.of vowels %d in string \n", count_vowels(str));

	remove_vowels(str);

	remove_spaces(str);

	printf(" string after removing spaces %s \n", str);
        
	char src[] = "hello", dest[100];
        my_strcpy(src,dest);
	printf("copied string %s \n", dest);

	char src[] = "hello", dest[100];
        my_strncpy(dest, src, 3);
        printf(" %s\n", dest);	

	printf(" removing extra spaces:%s \n", str);
	remove_extra_spaces(str);
	printf(" removing extra spaces:%s \n", str);

	char dest[100] = "hello", src[] = "world";
	my_strncat(dest, " ", 1);
	my_strncat(dest,src,2);
	printf("%s \n", dest);

	char str[ ] = "sasuke";
	char ch = 's';
        char *ptr = my_strchr(str, ch);
	if(ptr == NULL)
	{
		printf("character is not found\n");
	}
	else
	{
		printf("character %c is found in string %s at %ld\n", ch, str, ptr - str);
	}

	char *ptr = my_strrchr(str, ch);
        if(ptr == NULL)
        {
                printf("character is not found\n");
        }
        else
        {
                printf("character %c is found in string %s at %ld\n", ch, str, ptr - str);
        }

	char str[] = "abcdefghi";
        char substr[] = "def";
	char *ptr = my_strstr(str, substr);
	if(ptr == NULL)
	{
		printf("not found %s\n",substr);
	}
	else
	{
		printf("substring %s is found at %ld\n", substr, ptr - substr);
	}
	int result;
        char str1[] = "itachi", str2[] = "itachi"; 	
	result = my_strcmp(str1,str2);
        if(result == 0)
           printf("equal\n");
        else
           printf("not equal\n");
	
	char str[] = "kakashi";
        int pos = 2;
        //memmove(&str[pos], &str[pos] + 1, strlen(str) - 1); // remove character from word
	memmove(&str[pos+1], &str[pos], strlen(str) - pos +1); // insert character
        str[pos] = 'T';							       
        printf("%s\n", str);

	char src[] = "sasuke";
        char dest[20];
        memcpy(dest, src + 2, 4);
        dest[4] = '\0';
        printf("%s\n", dest);*/	
         
	char str[] = "c programming";
        //capital_first_letter(str);
	capital_firstletter_afterspace(str);
        printf("%s\n", str);	
      
	return 0;
}	
