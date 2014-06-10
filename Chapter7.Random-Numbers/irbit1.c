#define IB1
#define IB2
#define IB5 16
#define IB18 131072

int irbit1(unsigned long *iseed)
{
unsigned long newbit;

newbit = (*iseed & IB18) >> 17
	^ (*iseed & IB5) >> 4
	^ (*iseed & IB2) >> 1
	^ (*iseed & IB1);
*iseed=(*iseed << 1) | newbit;
return (int) newbit;
}

