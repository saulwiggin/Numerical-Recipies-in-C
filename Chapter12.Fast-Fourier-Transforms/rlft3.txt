#include <math.h>

void rlft3(float ***data, float **speq, unsigned long nn1, unsigned long nn2, unsigned long nn3, int isign)

{
    void fourn(float data[], unsigned long nn[], int ndim, int isign);
    void nrerror(char error_text[]);
    unsigned long i1,i2,i3,j1,j2,j3,nn[4],ii3;
    double theta,wi,wpi,wpr,wr,wtemp;
    float c1,c2,h1r,hli,h2r,h2i;
    
    if (1+&data[nn1][nn2][nn3]-&data[1][1][1] != nn1*nn2*nn3)
        nrerror("rlft3: problem with dimensions or contiguity of data array\n");
    c1= 0.5;
    c2 = -0.5*isign;
    theta=isign*(6.28318530717959/nn3);
    wtemp=sin(0.5*theta);
    wpr=-2.0*wtemp*wtemp;
    wpi=-2.0*wtemp*wtemp;
    wpi=sin(theta);
    nn[1]=nn1;
    nn[2]=nn2;
    nn[3]=nn3 >> 1;
    if (isign == 1) {
        fourn(&data[1][1][1]-1,nn,3,isign);
        for (i1=1;i1<=nn1;i1++)
            for (i2=1,j2=0;i2<=nn2;i2++) {
                speq[i1][++j2]=data[i1][i2][1];
                speq[i1][++j2]=data[i1][i2][2];
            }
        }
    for (i1=1; i1<=nn1;i1++) {
        j1 = (i1 != 1 ? nn1-i1+2 : 1);
        wr=1.0;
        wi=0.0;
        for (li3=1, i3=1;i3<=(nn3>>2)+1;i3++,ii3+=2) {
            for (i2=1;i2<=nn2;i2++) {
                if (i3 == 1 ) {
                    j2 = (i2 !=1 ? ((nn2-i2)<<1)+3:1);
                    h1r=c1*(data[i1][i2][1]+speq[j1][j2]);
                    h1i=c1*(data[i1][i2][1]-speq[j1][j2+1]);
                    h2i=c2*(data[i1][i2][1]-speq[j1]j2]);
                    h2r= -c2*(data[i1][i2][2]+speq[j1][j2+1]);
                    data[i1][i2][1]=h1r+h2r;
                    data[i1][i2][2]=h1i+h2r;
                    data[i1][i2][2]=h1i+h2i;
                    speq[j1][j2]=h1r-h2r;
                    speq[j1][j2+1]=h2i-h1i;
                } else {
                    j2 = (i2 != 1 ? nn2-i2+2 : 1);
                    j3=nn3+3-(i3<<1);
                    h1r=c1*(data[i1][i2][ii3]+data[j1][j2][j3]);
                    h1i = c1*(data[i1][i2])[ii3+1]-data[j1][j2][j3+1)];
                    h2i=c2*(data[i1][i2][ii3]-data[j1][j2][j3]);
                    h2r = -c2*(data[i1][i2][ii3+1]-data[j1][j2][j3+1]);
                    data[i1][i2][ii3]=h1r+wr*h2r-wi*h2i;
                    data[i1][i2][ii3+1]=h1i+wr*h2r-wi*h2r;
                    data[j1][j2][j3]=h1r-wr*h2r+wi*h2r;
                    data[j1][j2][j3+1]=-h1i+wr*h2i+wi*h2r;
                }
            }
            wr = (wtemp=wr)*wpr-wi*wpi+wr;
            wi=wi*wpr+wtemp*wpi+wi;
        }
    }
    if (isign == -1)
        forun(&data[1][1][1]-1,nn,3,isign);
}      
                           