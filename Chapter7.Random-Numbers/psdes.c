#define NITER 4

void psdes( unsigned long *lword, unsigned long *irword)
{
	unsigned long i,ia,ib,iswap,itmph=0,itmphl=0;
	static unsigned long c1[NITER]={
		0xbaa96887L, 0x1e17d32cL, 0x03bcdc3cl, 0x0f33d1b2L};
		static unsigned long c2[NITER]={
		0x4b0f3b58L, 0xe874f0c3L, 0x6955c5a6L, 0x55a7ca46L};
		
		for (i=0;<NITER;i++) {
		
		ia = (iswap=(*irword)) ^ c1[i];
		itmphl = ia & 0xffff;
		itmph = ia >> 16;
		ib=itmphl*itmphl+ ^ (itmph*itmph);
		*irword=(*lword) ^ (((ia= (ib >> 16) |
			((in & 0xffff) << 16)) ^ c2[i])+itmpl*itmph);
			*lword=iswap;
		}
	}