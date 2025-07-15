#include <stdio.h>
#include <stdint.h>

void printBinary(int data)
{
	int count = 0;
	for(int i = 31; i >= 0; i--)
	{
		if(count == 4)
		{
			count = 0;
			printf(" ");
		}
		printf("%d", (data >> i) & 1);
		count++;
	}
	printf("\n");
}

int setBit(int num, int pos)
{
	return(num | (1 << pos));
}

int clearBit(int num, int pos)
{
	return(num & ~ (1 << pos));
}

int toggleBit(int num, int pos)
{
	return(num ^ (1 << pos));
}

int swapNibble(int num)
{
	return(((num & 0x0f) << 4) | ((num & 0xf0) >> 4));
}

int swapByte(int num)
{
	return(((num & 0x00ff) << 8) | ((num & 0xff00) >> 8));
}

int little_to_big(int num)
{
	return(((num & 0x000000ff) << 24 ) | ((num & 0xff000000) >> 24)
		       	| ((num & 0x0000ff00) << 8) | ((num & 0x00ff0000) >> 8)) ;
}

void is_little_endian(void)
{
	uint8_t byte = 0;
	uint32_t data = 1;
	byte = (uint8_t)data;
	if(byte == 1)
		printf("little endian\n");
	else
		printf("big endian \n");

}

int setbit_count_1(int num)
{
	int count = 0;
	while(num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}

int setbit_count_2(int num)
{
	int count = 0;
	while(num)
	{
		if(num & 1)
			count++;
		num = num >> 1;   
	}
	return count;
}

int reverse_Bit_1(int num)
{
	int rev = 0;
	for( int i = 0; i < 31; i++)
	{
		if((num >> i) & 1) 
		{
			rev = rev | (1 << (31 -i));
		}
	}
	return rev;
}

int reverse_bit_2(int num)
{
	num = (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1)); //adjacent bits swap
	printBinary(num);
	num = (((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2));
	printBinary(num);
	num = (((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4));
	printBinary(num);
	num = (((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8));
	printBinary(num);
	//num = (((num & 0xffff0000) >> 16) | ((num & 0x0000ffff) << 16));
	num = ((num >> 16) | (num << 16));
	printBinary(num);
	return num;
}

int swap_two_bits_atgiven_pos(int num, int pos1, int pos2)
{
	if(((num >> pos1) & 1) != ((num >> pos2) & 1))
	{
		num = (num ^ (1 << pos1) | (1 << pos2));
	}
	return num;
}

int swap_two_bits(int data, int p1, int p2)
{
	int pos_1, pos_2; 
	int mask = 0;
	pos_1 = 1u & (data >> p1); /* Use unsigned literal for portability */
	pos_2 = 1u & (data >> p2); /* Use unsigned literal for portability */
	mask = ~((1u << p1) | (1u << p2)); /* Use unsigned literal for portability */
	printBinary(mask);
	data = data & mask;
	printBinary(data);
	data = data | (pos_2 << p1) | (pos_1 << p2);
	printBinary(data);
	return data;
}

int rotate_right(int num, int rotations)
{
	return((num << (32 - rotations)) | (num >> rotations));
}

int rotate_left(int num, int rotations)
{
	return((num << rotations) | (num >> (32 - rotations)));
}

void swap_2var_withoutusing_3var(int *a, int *b)
{
	*a ^= *b ^= *a ^= *b;
}

int test_bit_position(int num, int pos)
{
	return((num >> pos) & 1);  
}

int multiplication(int num)
{
	return( num << 1);
}

int division(int num)
{
	return(num >> 1);
}

int check_sign(int num)
{
	return((num >> 31) & 1); 
}

int ones_compliment(int num)
{
	return(~(num));
}

int main()
{
	int num = 0x1;
	/* int a = 7, b = 11;
	  printBinary(num);
	  num = setBit(num, 3);
	  printBinary(num);
	  num = clearBit(num, 1);
	  printBinary(num);
	  num = toggleBit(num, 1);
	  num = swapNibble(num);
	  num = swapByte(num);
	  printBinary(num);
	  num = little_to_big(num);
	  is_little_endian();
	  num = count(num);
	  num = setbit_count2(num);
	  num = reverse_bit_1(num);
	  printBinary(num);
	  num =reverse_bit_2(num);
	  printBinary(num);
	  num = swap_two_bits_atgiven_pos(num, 0, 31);
	  num = swap_two_bits(num, 2,7);
	  printBinary(num);
	  num = rotate_right(num, 3);
	  num = rotate_left(num, 4);
	  printf(" a = %d b = %d \n", a, b);
	  swap_2var_withoutusing_3var(&a, &b);
	  printf(" a = %d b = %d \n", a, b);
	  printBinary(num);
	  num = test_bit_position(num, 3);
	  printBinary(num);
	  num = multiplication(num);
	  printBinary(num);
	  num = division(num);
	  num = check_sign(num);*/
	  num = ones_compliment(num);
	  printBinary(num);
	  printf(" %x ", num);
}
