typedef volatile unsigned int REG;    /* Hardware register definition */

#define REG_READ32(reg)			(*(REG *)(reg))
#define REG_WRITE32(reg,val)	(*(REG *)(reg) = (val))


int main(void)
{
	volatile int a = 0;
	volatile unsigned int val32;
	
	a = 2;
	a = 3;
	a = 4;
	
	
	val32 = REG_READ32(0x40040000);
	REG_WRITE32(0x40040000, 0x5555);
	val32 = REG_READ32(0x40040000);
	REG_WRITE32(0x40040000, 0xAAAA);
	val32 = REG_READ32(0x40040000);
	
	val32 = (*(volatile unsigned int *)(0x40040000));
	(*(volatile unsigned int *)(0x40040000)) = 0x12345678;
	val32 = (*(volatile unsigned int *)(0x40040000));			// 只读出5678，可能是HW的原因
	(*(volatile unsigned int *)(0x40040000)) = 0x87654321;
	val32 = (*(volatile unsigned int *)(0x40040000));
	
	while(1);
}
