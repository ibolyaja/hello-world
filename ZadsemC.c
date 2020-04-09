#include<stdio.h>
#include<math.h>

typedef struct{
	double re;
	double im;
}cmplx;

void nta_komplexna_odmocnina(cmplx z, cmplx *r, char n);

int main(void)
{
	cmplx z;
	z.re=-5;
	z.im=7;
	char n=7;
	cmplx r[n];
	nta_komplexna_odmocnina(z,r,n);
	return 0;
}

void nta_komplexna_odmocnina(cmplx z, cmplx *r, char n)
{
	
	double angle;
	double R=pow(pow(z.re,2)+pow(z.im,2),1.0/2);
	int k;
	for(k=0;k<n;k++)
	{
		angle=atan(z.im/z.re);
		if(angle<0)
		{
			r[k].re=pow(R,1.0/n)*cos((angle+M_PI+2*k*M_PI)/n);
			r[k].im=pow(R,1.0/n)*sin((angle+M_PI+2*k*M_PI)/n);
		}
		if(z.re<0)
		{
			r[k].re=pow(R,1.0/n)*cos((angle+M_PI+2*k*M_PI)/n);
			r[k].im=pow(R,1.0/n)*sin((angle+M_PI+2*k*M_PI)/n);
		}
		else
		{
		r[k].re=pow(R,1.0/n)*cos((angle+2*k*M_PI)/n);
		r[k].im=pow(R,1.0/n)*sin((angle+2*k*M_PI)/n);
		}
		printf("%lf+i(%lf)\n",r[k].re,r[k].im);
	}
}
