#include <stdio.h>

#include <stdint.h>

#define MUL(a,b) (a) * (b)

#define PRINT_BINARY(num)                \
do{                                      \
    int count = 0;                       \
    for(int i = 31; i >= 0; i--)          \
    {                                     \
	if(count == 4)                    \
	{                                 \
		printf(" ");              \
		count = 0;                \
	}                                 \
	printf("%d", ((num) >> i) & 1);   \
	count++;                          \
    }	                                  \
    printf("\n");                         \
}while(0)                                 

#define SET_BIT(num, pos) ((num) | (1 << (pos)))

#define CLEAR_BIT(num, pos) ((num) & ~ (1 << (pos)))

#define TOGGLE_BIT(num, pos) ((num) ^ (1 << (pos)))

#define ONES_COMPLIMENT(num) (~(num))

#define CHECK_SIGN(num) (((num) >> 31) & 1) 

#define TEST_BIT_POS(num, pos) (((num) >> (pos)) & 1)

#define SWAP_NIBBLE(num)  ((((num) & (0x0f)) << 4) | (((num) & (0xf0)) >> 4))

#define SWAP_BYTE(num) ((((num) & (0x00ff)) << 8) | (((num) & (0xff00)) >> 8))

#define LITTLE_ENDIAN_TO_BIG_ENDIAN(num) \
	(((num) & (0x000000ff)) << 24) | (((num) & (0x0000ff00)) << 8) | \
      (((num) & (0x00ff0000)) >> 8) | (((num) & (0xff000000)) >> 24)

#define COUNT_SET_BITS(num)              \
({	                                  \
	int count = 0, n;                    \
	n = num;                         \
        while(n)                        \
        {                                 \
		n = (n) & (n - 1);  \
		count++;                  \
	}                                 \
        count;                      \
})	                                   \


#define REVERSE_BITS(num)             \
({                                             \
    uint32_t n = (num);                       \
    uint32_t rev = 0;                         \
    for (int i = 0; i < 32; i++) {          \
        if ((n >> i) & 1U)                   \
            rev |= (1U << (31 - i));         \
    }                                          \
    rev;                                      \
})
#define SWAP_TWO_BITS_ATGIVEN_POS(num, pos1, pos2)\
({                                                            \
        if(((num) >> (pos1)) & 1) != (((num) >> (pos2)) & 1)  \
        {                                                     \
                num = ((num) ^ ((1 << pos1) | (1 << pos2))); \
        }                                                    \
        num;                                                 \
})                                                           \


#define ROTATE_RIGHT(num, rotations)\
      (((num) << (32 - rotations)) | ((num) >> (rotations)))	


#define ROTATE_LEFT(num, rotations) \
	(((num) << (rotations)) | ((num) >> (32 - rotations)))

#define MULTIPLICATION(num) ((num) << 1)

#define DIVISION(num)  ((num) >> 1)


#define SWAP_TWO_VARIABLES(a, b) \
do{                   \
	(a) ^= (b);   \
        (b) ^= (a);   \
        (a) ^= (b);   \
}while(0)	  

#define SIZE_OF(var) (((char*)(&var + 1)) - ((char*)(&var)))

struct stu
{
	char name1[20];
        int roll_no;
	char name2;
	int sal;
};


#define IS_EVEN(num) ((((num) % 2) == 0) ? "even" : "odd")

#define MAX1(a, b) ((a) > (b) ? a : b)

#define MAX2(a, b, c)  (((a) > (b)) && ((a) > (c)) ? a : ((b) > (c)) ? b : c)

#define MAX3(a, b, c)  \
	({             \
	   int max = (a) > (b) ? (a) : (b);\
	    max > (c) ? max : c;           \
	 })

#define PRINT_STRING(x) printf(#x)  //STRINGIZING OPERATOR

#define TOKEN_PASTING(a, b) a ## b

#define A 20

#define B 20
    
int main()    
{
	struct stu e1; 
	//printf("%d \n", MUL(2, 3));
	//printf("%d \n", MUL(5 - 2, 7 + 4));
	int num2 = 7;
        //PRINT_BINARY(num);
	/*num = SET_BIT(num, 3);
	num = CLEAR_BIT(num, 1);
	num = TOGGLE_BIT(num, 3);
	num = ONES_COMPLIMENT(num);
	num = CHECK_SIGN(num); // 0-> positive, 1-> negative
	num = TEST_BIT_POS(num, 1);
	num = SWAP_NIBBLE(num);
	num = SWAP_BYTE(num);
	num = LITTLE_ENDIAN_TO_BIG_ENDIAN(num);
	printf("count set bits %d\n", COUNT_SET_BITS(num));
	uint32_t reverse = REVERSE_BITS(num);
	PRINT_BINARY(reverse);
	SWAP_TWO_BITS_ATGIVEN_POS(num, 2, 3);
	num = ROTATE_RIGHT(num, 3);
	num = ROTATE_LEFT(num, 3);
	num = MULTIPLICATION(num);
	printf("%d\n", num);
	printf("%d\n", DIVISION(num));
	//PRINT_BINARY(num);
	int x = 5, y = 2;
	SWAP_TWO_VARIABLES(x,y);
	printf("after swap %d %d\n", x, y);
	char x;
	printf("size %ld\n", SIZE_OF(e1));

	printf("%s\n", IS_EVEN(num));
	int x = 10, y = 2, z = 20;
	printf("%d\n", MAX3(x, y, z));
        
	PRINT_STRING(hello);
	printf("%d\n", TOKEN_PASTING(num, 2));*/

	int res;
        #if(A > B)
	{
		res = A + B;
		printf("sum =%d\n", res);
	}
        #elif(A == B)
	{
		res = A - B;
		printf("diff =%d\n", res);
	}
        #else
	{
		res = A * B;
		printf("mul =%d\n", res);
	}
        #endif

	return 0;
}	
