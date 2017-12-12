#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <cmath>
//#include <cfloat>
#define size 100

struct Node
{
	char info;
	Node *pNext;
};

struct Stack
{
	Node *pTop;
};



Node *CreateNode(char x);
char pop(Stack &S, char x);
void push(Stack &S, Node *p);
int kiemtra(char x);
void createStack(Stack &S);
void xuly(char A[],char B[]);
int thutuUuTien(char x);
void dangHauTo(char B[],Stack ToanTu,char C[]);
void TinhToan(char x[],char y[],char z);
int kt(char x[]);
void xoachuoi(char x[]);
void ftoa(char x[],float a);
void ketqua(char C[],char x[]);
int timVT(char x[]);
void xoaVTchuoi(char x[],int k);
void ThemVitri(char A[],char x,int k);
void xuatkq(char C[]);
void chuanhoa(char s[]);

void main()
{
	char A[size],B[size],C[size]="",x[size];
	Stack ToanTu;
	createStack(ToanTu);
	printf("Nhap vao ki tu a neu muon dung!!\n");
	printf("Cac toan tu ban co the su dung +,-,*,/,^,%,(,) va kieu so thuc.\n");
	printf("luu y so thuc ko the dung %\n");
	do
	{
		printf("Nhap bieu thuc can tinh:");
		gets(A);
		if(A[0]!='a'&&A[1]!='\0')
		{
			if(A[0]!=NULL)
			{
				xuly(A,B);
				printf("Bieu thuc vua nhap:");
				int n=strlen(B);
				for(int j=0;j<n;j++)
				printf("%c",B[j]);
				printf("\n");
				dangHauTo(B,ToanTu,C);
				chuanhoa(C);
				printf("Dang hau to cua bieu thuc vua nhap: ");
				puts(C);
				ketqua(C,x);
				strrev(x);
				xuatkq(x);
			}
		}
	}
	while(A[0]!='a'&&A[1]!='\0');
    
    //return 0;
}

Node *CreateNode(char x)
{
	Node *p=new Node;
	if(p==NULL)
		return 0;
	p->info=x;
	p->pNext=NULL;
	return p;
}



void chuanhoa(char s[])
{
	while(s[0]==' ')
		xoaVTchuoi(s,0);
	while(s[strlen(s)-1]==' ')
		xoaVTchuoi(s,strlen(s)-1);
	int i=0;
	while(i<int(strlen(s)))
		if(s[i]==' ' && s[i+1]==' ')
			xoaVTchuoi(s,i);
		else
			i++;
}

int kt(char x[])
{
	int k=strlen(x),i=0;
	while(i<k)
	{
		if(x[i]=='.')
			return 1;
		else
			i++;
	}
	return 0;
}

void ftoa(char x[],float a)
{
	int i=0,j;
	float t=a;
	a=a*10000;
	int k=int(t);
	int h=int(a-int(k*int(pow(10,4))));
	if(h<0)
		h=-h;
	itoa(k,x,10);
	j=strlen(x);
	x[j++]='.';
	x[j]='\0';
	char y[size];
	itoa(h,y,10);
	strcat(x,y);
}

void xoachuoi(char x[])
{
	int k=strlen(x);
	int i=0;
	while(i<k)
	{
		while(x[i]!=NULL)
			x[i++]=NULL;
	}
}

void TinhToan(char x[],char y[],char z)
{
	float i=0;int j=0;
	if(kt(x)==0 && kt(y)==0)
	{		
		if(z=='*')
			j=int(atoi(x)*atoi(y));
		if(z=='/')
		{
			i=float(float(atoi(y))/atoi(x));
			if(i==int(i))
				j=int(i);
		}
		if(z=='^')
			j=int(pow(atoi(y),atoi(x)));
		if(z=='%')
			j=int(atoi(y)%atoi(x));
		if(z=='+')
			j=int(atoi(y)+atoi(x));
		if(z=='-')
			j=int(atoi(y)-atoi(x));
		xoachuoi(x);

		if(z=='/'&&i!=int(i))
		{
			ftoa(x,i);
		}
		else
		{
			itoa(j,x,10);
		}
		
	}
	else
	{
		if(z=='*')
			i=float(atof(x)*atof(y));
		if(z=='/')
			i=float(atof(y)/atof(x));
		if(z=='^')
			i=float(pow(atof(y),atof(x)));
		if(z=='+')
			i=float(atof(y)+atof(x));
		if(z=='-')
			i=float(atof(y)-atof(x));
		xoachuoi(x);
		

		if(i==int(i))
		{
			itoa(int(i),x,10);
		}
		else
		{
			ftoa(x,i);
		}
	}
}

int timVT(char x[])
{
	int l=strlen(x);
	for(int i=0;i<l;i++)
		if(kiemtra(x[i])==1)
			if(kiemtra(x[i+1])==0)
				i++;
			else
				return i;
	return 0;
}

void xuatkq(char C[])
{
	int l=strlen(C),i=0,d=0;
	while(i<l)
	{
		if(C[i]=='.')
		{
			d++;
			i++;
		}
		else
			i++;
	}
	if(d==0)
	{
		int x=atoi(C);
		printf("Ket qua cua bieu thuc la:%d ",x);
		printf("\n");
	}
	else
	{
		float y=float(atof(C));
		printf("Ket qua cua bieu thuc la:%.4f ",y);
		printf("\n");
	}
}

void ketqua(char C[],char x[])
{
	int l=strlen(C);
	int i,j=timVT(C),k=0,t=0;
	char y[size],z=C[j];
	i=j-1;
	int d=0;
	while(d<=1)
	{
		if(C[i]!=' ')
		{
			x[k++]=C[i];
			i--;
		}
		else
		{
			d++;
			i--;
		}
	}
	x[k]='\0';
	strrev(x);
	
	while(d<3 && i>=0)
	{
		if(C[i]!=' ')
		{
			y[t++]=C[i];
			i--;
		}
		else
		{
			d++;
			i--;
		}
	}
	y[t]='\0';
	strrev(y);
	
	i=i+1;
	while(i!=timVT(C))
		xoaVTchuoi(C,i);
	xoaVTchuoi(C,i);

	TinhToan(x,y,z);
	strrev(x);
	
	ThemVitri(C,' ',i+1);
	for(k=0;k<int(strlen(x));k++)
		ThemVitri(C,x[k],i+1);
	chuanhoa(C);
	
	int q=0;
	while(q<int(strlen(C)))
	{
		if(kiemtra(C[q])==1)
			ketqua(C,x);
		else
			q++;
	}
}

void ThemVitri(char A[],char x,int k)
{
	int n=strlen(A);
	for(int i=n;i>k;i--)
		A[i]=A[i-1];
	A[k]=x;
}

void xoaVTchuoi(char x[],int k)
{
	int l=strlen(x);
	for(int i=k;i<l;i++)
	{
		x[i]=x[i+1];
	}
	l--;
}

void dangHauTo(char B[],Stack ToanTu,char C[])
{
	int l=strlen(B);
	int i=0,k=0;
	char x;

	while(i<l)
	{
		if(B[i]==' ')
		{
			if(kiemtra(B[i-1])==1)
				i++;
			else
			{
				C[k++]=B[i];
				C[k]='\0';
				i++;
			}
			
		}
		else
		{
			if(kiemtra(B[i])==0)
			{
				C[k++]=B[i];
				
				C[k]='\0';
				i++;
			}
			
			else
			{
				if(B[i]=='(')
				{
					
					push(ToanTu,CreateNode(B[i]));
					i++;
				}
				else
				{
					if(B[i]==')')
					{
						while(ToanTu.pTop->info!='(')
						{
							C[k++]=' ';
							x=pop(ToanTu,x);
							C[k++]=x;
							C[k++]=' ';
							C[k]='\0';
						}
						pop(ToanTu,x);
						i++;
					}
					else
					{
						if(kiemtra(B[i])==1)
						{
							if(B[i+1]!=' ')
							{
								C[k++]=B[i];
								C[k]='\0';
								i++;
							}
							else
							{
								if(ToanTu.pTop==NULL||ToanTu.pTop->info=='(')
								{
									push(ToanTu,CreateNode(B[i]));
									i++;
								}
								else
								{
									if(thutuUuTien(ToanTu.pTop->info)==2)
									{
										x=pop(ToanTu,x);
										C[k++]=x;
										C[k++]=' ';
										C[k]='\0';
										push(ToanTu,CreateNode(B[i]));
									}
									else
									{
										if(thutuUuTien(B[i])==2)
										{
											push(ToanTu,CreateNode(B[i]));
										}
										else
										{
											x=pop(ToanTu,x);
											C[k++]=x;
											C[k++]=' ';
											C[k]='\0';
											push(ToanTu,CreateNode(B[i]));
										}
									}
								i++;
								}
							}
						}
						else
							i++;
					}	
				}
			}
		}
	}
	C[k++]=' ';
	C[k]='\0';
	while(ToanTu.pTop!=NULL)
	{
		x=pop(ToanTu,x);
		C[k++]=x;
		C[k++]=' ';
		C[k]='\0';
	}

}

int thutuUuTien(char x)
{
	if(x=='(')
		return 1;
	if(x=='*' || x=='/' || x=='%' || x=='^')
		return 2;
	if(x=='+' || x=='-')
		return 3;
	return 0;
}

void xuly(char A[],char B[])
{
	int k= strlen(A);int n=0;
	for(int i=0;i<k;i++)
	{
		if(kiemtra(A[i])==1)
		{
			if(thutuUuTien(A[i])==3 && (A[i-1]=='(' || kiemtra(A[i-1])==1 || i==0))
			{
					B[n++]=A[i];
			}
			else
			{
				B[n++]=' ';
				B[n++]=A[i];
				B[n++]=' ';
			}
		}
		else
			B[n++]=A[i];
	}
	B[n]='\0';
}

void createStack(Stack &S)
{
	S.pTop = NULL;
}

int kiemtra(char x)
{
	if ((x == '*') || (x == '/') || (x == '+') || (x == '-') || (x == '^') || (x == '%'))
		return 1;
	if( x=='(' || x==')')
		return 2;
	if(x==' '|| x=='\0')
		return 3;
	else
		return 0;
}

void push(Stack &S, Node *p)
{
	if (S.pTop == NULL)
		S.pTop = p;
	else
	{
		p->pNext = S.pTop;
		S.pTop = p;
	}
}

char pop(Stack &S, char x)
{
	if (S.pTop != NULL)
	{
		x = S.pTop->info;
		Node *p = S.pTop;
		S.pTop = S.pTop->pNext;
		delete p;
	}
	return x;
}

