using namespace std;
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
class Equation
{
private:
	float Nu_Coeff[100];
	float Nu_Abs;
	string vars[100];
	string sign[100];
	int var_num;
    void Equ_Prep(string (&coeff)[100],string (&vars)[100],string (&sign)[100],float (&Nu_Coeff)[100],float &Nu_Abs,int &var_num)
    {
			 for(int j2=0;j2<var_num;j2++)
			 {
				 Nu_Coeff[j2]=0;
			 }
			 Nu_Abs=0;
		     for(int j2=0;j2<var_num;j2++)
			 {
				 Nu_Coeff[j2]=atof(coeff[j2].c_str());
			 }
			 for(int j2=0;j2<var_num;j2++)
			 {
				if(vars[j2]=="B")
					{
						continue;
				    }
				for(int k2=j2+1;k2<var_num;k2++)
			    {
				    if(vars[j2]==vars[k2]&&vars[k2]!="B")
					{
						Nu_Coeff[j2]=Nu_Coeff[j2]+Nu_Coeff[k2];
						vars[k2]="B";
					}
		   	    }
			 }
			 for(int j2=0;j2<var_num;j2++)
			 {
				 if(vars[j2]=="A")
				 {
					 Nu_Abs=Nu_Coeff[j2];
					 break;
				 }
			 }
    }
public:
    void set_Eqn(string equ);
    void set_Nu_Coeff(int i,float C);
    void Set_Nu_Abs(float A);
    void Set_vars(int i,string v);
    void Get_vars(string (&v)[100]);
    void Get_Nu_Coeff(float (&C)[100]);
    void Get_Nu_Abs(float &A);
    void Get_var_num(int &n);
    void Show_Eqn ();
};
class MaTrix
{
private:
	int Eqn_Num,Orig_Var_Num;
	Equation Equ[100];
    float Solution[100];
    float Denom;
    string Orig_Vars[100];
	void Original_Variables(string (&vars)[100][100],float (&nu_coeff)[100][100],string (&Orig_Vars)[100],int (&var_num)[100],int eqn_num,int &Orig_Var_Num)
    {
	   string Vars[10000];
	   int n=0;
	   for(int i=0;i<eqn_num;i++)
	   {
		for(int j=0;j<var_num[i];j++)
		{
			if(Vars[n]!=vars[i][j]&&vars[i][j]!="A"&&vars[i][j]!="B"&& nu_coeff[i][j]!=0)
				{
					Vars[n]=vars[i][j];
					n++;
			    }
		}
	    }
        for(int j2=0;j2<n;j2++)
	    {
			if(Vars[j2]=="B")
				{
					continue;
			    } 
			for(int k2=j2+1;k2<n;k2++)
		    {
			    if(Vars[j2]==Vars[k2]&&Vars[k2]!="B")
				{
					Vars[k2]="B";
				}
	   	    }
        }
	    for(int k2=0;k2<n;k2++)
		    {
			    if(Vars[k2]!="B")
				{
					Orig_Vars[Orig_Var_Num]=Vars[k2];
					Orig_Var_Num++;
				}
	   	    }
	    bubbleSort(Orig_Vars,Orig_Var_Num);
    }
    void swap (string &x1,string &y1){
		  string st_temp = x1;
          x1 = y1;
          y1 = st_temp;
    }
    void bubbleSort(string (&x)[100],int n){
           int i, j;
           for (i = 0; i < n-1; i++)
		   {   
              for (j = 0; j < n-i-1; j++) 
		      {
                 if (x[j] > x[j+1])
			     {
                   swap(x[j], x[j+1]);
			     }
		      }
           }
    }
    void Finialize (string vars[100],string Orig_Var [100],float Nu_Coeff[100],int var_num,int Orig_Var_Num,string (&Temp_var)[100],float (&Temp_Coeff)[100])
		{
			int n=0;
			for(int i=0;i<Orig_Var_Num;i++)
			{
				int flag=0;
				for(int j=0;j<var_num;j++)
				{
					if(Orig_Var[n]==vars[j])
						{
							Temp_var[n]=Orig_Var[n];
							Temp_Coeff[n]=Nu_Coeff[j];
							n++;
							flag=1;
							break;
					    }
				}
				if(flag==0) 
					{
						Temp_var[n]=Orig_Var[n];
						Temp_Coeff[n]=0;
						n++;
					}
			}
		}
public:
	void Column(string St_Var);
    void Set_MaTrix();
    void ADD(int x,int y);
    void SubtracT(int x,int y);
    void Substitute(int x,int y,string var);
    void Matrix(string var);
    void Value();
    void Get_Equation(int i);
    void Get_Orig_Var_Num();
    void Get_Orig_Var_Num(int& i);
    void Get_Denom();
    int Get_Eqn_Num();
    void Show_Solution();
};