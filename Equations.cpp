#include "Equations.h"
using namespace std;
void Equation::set_Eqn(string equ){
	    string abs,coeff[100];
	    int length = equ.length();
		int n=0,flag=0,flag2=0,just=0,temp=0;
	     for(int j=0;j<20;j++)
		 {
			 just=0;
	          for(int i=n;i<length;i++)
	          {
		      if(((equ[i]>='0'&&equ[i]<='9')||equ[i]=='.'||(equ[i]=='-'&&coeff[j]==""))&&flag==0)
		      {
		      	coeff[j]=coeff[j]+equ[i];
		      }
			  else if((equ[i]>='a'&&equ[i]<='z')||(equ[i]>='A'&&equ[i]<='Z')||(equ[i]=='_')||((flag==1)&&(equ[i]!='='&&equ[i]!='+'&&equ[i]!='-')))
		      {
		       	vars[j]=vars[j]+equ[i];
			    flag=1;
		      }
			  if(i==length-1)
			  {
			      n=length;
				  break;
			  }
		      if(equ[i]=='+'||equ[i]=='-'&&(i!=0&&i!=temp))
		      {
				n=i+1;
		       	sign[j]=equ[i];
			    flag=0;
			    break;
		      }
			  if(equ[i]=='='&&i!=0)
			  {
				  sign[j]=equ[i];
				  n=i+1;
				  temp=n;
				  flag=0;
				  just=1;
				  flag2=1;
				  break;
			  }
			  }
			  if(vars[j]=="")
			  {
				  vars[j]="A";
			  }
			  if (vars[j]=="A" && flag2==0 && j==0)
			  {
				  coeff[j]="-"+coeff[j];
			  }
			  if(j>0 && coeff[j]!="")
				{
				 if(sign[j-1]=="-"&&flag2!=1&&vars[j]!="A")
				{
					coeff[j]="-"+coeff[j];
				}
				 if(sign[j-1]=="+"&&flag2==1&&just==0&&vars[j]!="A")
				{
					coeff[j]="-"+coeff[j];
				}
				 if(sign[j-1]=="-"&&flag2==1&&just==1&&vars[j]!="A")
				{
					coeff[j]="-"+coeff[j];
				}
				 if(sign[j-1]=="+"&&flag2!=1&&vars[j]=="A")
				{
					coeff[j]="-"+coeff[j];
				}
				 if(sign[j-1]=="-"&&flag2==1&&just==0&&vars[j]=="A")
				{
					coeff[j]="-"+coeff[j];
				}
				 if(sign[j-1]=="+"&&flag2==1&&just==1&&vars[j]=="A")
				{
					coeff[j]="-"+coeff[j];
				}
				}
			  else if (j>0)
			  {
				if(sign[j-1]=="-" && flag2==1 && vars[j]!="A")
				{
					coeff[j]="-"+coeff[j];
				}
				if(sign[j-1]=="-" && flag2==0 && vars[j]!="A")
				{
					coeff[j]="-"+coeff[j];
				}
			  }
			  if(coeff[j]==""&&vars[j]!="A"&&flag2!=1)
				{
					coeff[j]="1";
				}
				if(coeff[j]=="-"&&vars[j]!="A"&&flag2!=1)
				{
					coeff[j]="-1";
				}
				if(coeff[j]==""&&vars[j]!="A"&&flag2==1&&just==0)
				{
					coeff[j]="-1";
				}
				if(coeff[j]==""&&vars[j]!="A"&&flag2==1&&just==1)
				{
					coeff[j]="1";
				}
				if(coeff[j]==""&&vars[j]!="A"&&flag2==1&&just==0)
				{
					coeff[j]="-1";
				}
				if(coeff[j]=="-"&&vars[j]!="A"&&flag2==1&&just==1)
				{
					coeff[j]="-1";
				}
				if(coeff[j]=="-"&&vars[j]!="A"&&flag2==1)
				{
					coeff[j]="1";
				}
				if(n==length)
			   {
				   var_num=j+1;
				   break;
			   }
	     }
		 Equ_Prep(coeff,vars,sign,Nu_Coeff,Nu_Abs,var_num);
}
void Equation::set_Nu_Coeff(int i,float C){
    Nu_Coeff[i]=C;
}
void Equation::Set_Nu_Abs(float A){
    Nu_Abs=A;
}
void Equation::Set_vars(int i,string v){
	vars[i]=v;	
}
void Equation::Get_vars(string (&v)[100]){
   for(int i=0; i<var_num ;i++){v[i]=vars[i];}
}
void Equation::Get_Nu_Coeff(float (&C)[100]){
   for(int i=0; i<var_num ;i++){C[i]=Nu_Coeff[i];}
}
void Equation::Get_Nu_Abs(float &A){
   A=Nu_Abs;
}
void Equation::Get_var_num(int &n){
   n=var_num;
}
void Equation::Show_Eqn (){
	for(int i=1;i<var_num+1;i++)
			{
				if(Nu_Coeff[i-1]==0)
				{}
				else if (Nu_Coeff[i-1]!=1 && Nu_Coeff[i-1]!=-1) 
				{cout<<Nu_Coeff[i-1]<<vars[i-1];}
				else if (Nu_Coeff[i-1]==1)
				{cout<<vars[i-1];}
				else if (Nu_Coeff[i-1]==-1) 
				{cout<<"-"<<vars[i-1];}
				if(Nu_Coeff[i]==0)
				{}
				else if (i!=var_num && Nu_Coeff[i]>0)
				{cout<<"+";}
			}
			cout<<"="<<Nu_Abs<<"\n";
}
void MaTrix::Set_MaTrix(){
	string st_equ;
	Orig_Var_Num=0;
	cout<<"Enter Number Of Eqns : ";
	getline (cin,st_equ);
	Eqn_Num=atof(st_equ.c_str());
	for(int i1=0;i1<Eqn_Num;i1++)
	{
    	string eqn="";
		cout<<"Enter Eqn ";
		cout<<i1+1;
		cout<<" : ";
		getline(cin,eqn);
		Equ[i1].set_Eqn(eqn);
	}
	string eqn_Var[100][100]={};
	float nu_Coeff[100][100]={};
	int var_num[100]={};
	for(int i=0;i<Eqn_Num;i++){Equ[i].Get_vars(eqn_Var[i]);}
	for(int i=0;i<Eqn_Num;i++){Equ[i].Get_Nu_Coeff(nu_Coeff[i]);}
	for(int i=0;i<Eqn_Num;i++){Equ[i].Get_var_num(var_num[i]);}
	Original_Variables(eqn_Var,nu_Coeff,Orig_Vars,var_num,Eqn_Num,Orig_Var_Num);
	for (int i2=0;i2<Eqn_Num;i2++)
	 {
		 string Vars[100]={};
		 float Coeff[100]={};
		 Finialize(eqn_Var[i2],Orig_Vars,nu_Coeff[i2],var_num[i2],Orig_Var_Num,Vars,Coeff);
		 for(int I1=0;I1<100;I1++){Equ[i2].Set_vars(I1,Vars[I1]);Equ[i2].set_Nu_Coeff(I1,Coeff[I1]);}
	 }
	 Equ[0].Get_vars(Orig_Vars);
}
void MaTrix::ADD(int x,int y){
	float sum,Nu_Abs_x,Nu_Abs_y;
	float Nu_Coeff_x[100]={},Nu_Coeff_y[100]={};
	Equ[x-1].Get_Nu_Coeff(Nu_Coeff_x);
	Equ[y-1].Get_Nu_Coeff(Nu_Coeff_y);
	Equ[x-1].Get_Nu_Abs(Nu_Abs_x);
	Equ[y-1].Get_Nu_Abs(Nu_Abs_y);
	int flag=0;
	for(int i=0;i<Orig_Var_Num;i++)
	{
		sum=0;
		sum=Nu_Coeff_x[i]+Nu_Coeff_y[i];
		if (sum==0)
		{continue;}
        else if(i==0 && sum==1)
		{
			cout<<Orig_Vars[i];
			flag=1;
		}
		else if(i==0 && sum==-1)
		{
			cout<<"-"<<Orig_Vars[i];
			flag=1;
		}        
		else if(i==0)
		{
			cout<<sum<<Orig_Vars[i];
			flag=1;
		}
		else if(sum==-1 && i!=0 && flag==1)
		{
			cout<<"-"<<Orig_Vars[i];
		}
		else if(sum<0 && i!=0 && flag==1)
		{
			cout<<sum<<Orig_Vars[i];
		}
		else if(sum==1 && i!=0 && flag==1)
		{
			cout<<"+"<<Orig_Vars[i];
		}
		else if(flag==1)
		{
			cout<<"+"<<sum<<Orig_Vars[i];
		}
		else 
		{
		if(sum==1)
		{
			cout<<Orig_Vars[i];
			flag=1;
		}
		else if(sum==-1)
		{
			cout<<"-"<<Orig_Vars[i];
			flag=1;
		}        
		else 
		{
			cout<<sum<<Orig_Vars[i];
			flag=1;
		}
		}
	}
	sum=Nu_Abs_x+Nu_Abs_y;
	cout<<"="<<sum<<"\n";
}
void MaTrix::SubtracT(int x,int y){
	float sum,Nu_Abs_x,Nu_Abs_y;
	float Nu_Coeff_x[100]={},Nu_Coeff_y[100]={};
	Equ[x-1].Get_Nu_Coeff(Nu_Coeff_x);
	Equ[y-1].Get_Nu_Coeff(Nu_Coeff_y);
	Equ[x-1].Get_Nu_Abs(Nu_Abs_x);
	Equ[y-1].Get_Nu_Abs(Nu_Abs_y);
	int flag=0;
	for(int i=0;i<Orig_Var_Num;i++)
	{
		sum=0;
		sum=Nu_Coeff_x[i]-Nu_Coeff_y[i];
		if (sum==0)
		{continue;}
        else if(i==0 && sum==1)
		{
			cout<<Orig_Vars[i];
			flag=1;
		}
		else if(i==0 && sum==-1)
		{
			cout<<"-"<<Orig_Vars[i];
			flag=1;
		}        
		else if(i==0)
		{
			cout<<sum<<Orig_Vars[i];
			flag=1;
		}
		else if(sum==-1 && i!=0 && flag==1)
		{
			cout<<"-"<<Orig_Vars[i];
		}
		else if(sum<0 && i!=0 && flag==1)
		{
			cout<<sum<<Orig_Vars[i];
		}
		else if(sum==1 && i!=0 && flag==1)
		{
			cout<<"+"<<Orig_Vars[i];
		}
		else if(flag==1)
		{
			cout<<"+"<<sum<<Orig_Vars[i];
		}
		else 
		{
		if(sum==1)
		{
			cout<<Orig_Vars[i];
			flag=1;
		}
		else if(sum==-1)
		{
			cout<<"-"<<Orig_Vars[i];
			flag=1;
		}        
		else 
		{
			cout<<sum<<Orig_Vars[i];
			flag=1;
		}
		}
	}
	sum=Nu_Abs_x-Nu_Abs_y;
	cout<<"="<<sum<<"\n";
}
void MaTrix::Substitute(int x,int y,string var){
	float sum,factor,Nu_Abs_x,Nu_Abs_y;
	float Nu_Coeff_x[100]={},Nu_Coeff_y[100]={};
	Equ[x-1].Get_Nu_Coeff(Nu_Coeff_x);
	Equ[y-1].Get_Nu_Coeff(Nu_Coeff_y);
	Equ[x-1].Get_Nu_Abs(Nu_Abs_x);
	Equ[y-1].Get_Nu_Abs(Nu_Abs_y);
	int flag=0;
	for(int i=0;i<Orig_Var_Num;i++)
	{
		if(Orig_Vars[i]==var)
		{
			factor=Nu_Coeff_x[i]/Nu_Coeff_y[i];
		}
	}
	for(int i=0;i<Orig_Var_Num;i++)
	{
		sum=0;
		sum=Nu_Coeff_x[i]-factor*Nu_Coeff_y[i];
		if (sum==0 || Orig_Vars[i]==var)
		{continue;}
        else if(i==0 && sum==1)
		{
			cout<<Orig_Vars[i];
			flag=1;
		}
		else if(i==0 && sum==-1)
		{
			cout<<"-"<<Orig_Vars[i];
			flag=1;
		}        
		else if(i==0)
		{
			cout<<sum<<Orig_Vars[i];
			flag=1;
		}
		else if(sum==-1 && i!=0 && flag==1)
		{
			cout<<"-"<<Orig_Vars[i];
		}
		else if(sum<0 && i!=0 && flag==1)
		{
			cout<<sum<<Orig_Vars[i];
		}
		else if(sum==1 && i!=0 && flag==1)
		{
			cout<<"+"<<Orig_Vars[i];
		}
		else if(flag==1)
		{
			cout<<"+"<<sum<<Orig_Vars[i];
		}
		else 
		{
		if(sum==1)
		{
			cout<<Orig_Vars[i];
			flag=1;
		}
		else if(sum==-1)
		{
			cout<<"-"<<Orig_Vars[i];
			flag=1;
		}        
		else 
		{
			cout<<sum<<Orig_Vars[i];
			flag=1;
		}
		}
	}
	sum=Nu_Abs_x-factor*Nu_Abs_y;
	cout<<"="<<sum<<"\n";
}
void MaTrix::Matrix(string var){
	string Mat;
	float sum,Nu_Abs_i;
	float Nu_Coeff_j[100]={};
	if (var!="")
	{
		for(int k=0;k<Orig_Var_Num;k++)
		{
			if(Orig_Vars[k]==var)
			{
				Mat=Orig_Vars[k];
				break;
			}
		}
	}
	for(int i=0;i<Eqn_Num;i++)
	{
		for(int j=0;j<Orig_Var_Num;j++)
		{
			if(Orig_Vars[j]==Mat && Mat!="")
			{
				Equ[i].Get_Nu_Abs(Nu_Abs_i);
				cout.width(5);
				cout<<left<<Nu_Abs_i;
				continue;
			}
			Equ[i].Get_Nu_Coeff(Nu_Coeff_j);
			cout.width(5);
		    cout<<left<<Nu_Coeff_j[j];
		}
		cout<<"\n";
	}
}
void MaTrix::Value(){
	int sign=1;
	double sum=0,multiple=0,Temp_Denom=1;
	double coeff[100][100]={},abs[100]={},factor=0,temp=0;
	float Nu_Abs_why;
	float Nu_Coeff_why[100]={};
	for(int why=0;why<Orig_Var_Num;why++)
	{
		Equ[why].Get_Nu_Coeff(Nu_Coeff_why);
		Equ[why].Get_Nu_Abs(Nu_Abs_why);
		for(int WHY=0;WHY<Orig_Var_Num;WHY++)
		{
			coeff[why][WHY]= Nu_Coeff_why[WHY];
		}
		abs[why]=Nu_Abs_why;
	}
	for(int x=0;x<Orig_Var_Num;x++)
	{
			if(coeff[x][x]==0)
			{
				for(int z=x;z<Orig_Var_Num;z++)
				{
					if(coeff[z][x]!=0)
						{
					    for(int k=0;k<Orig_Var_Num;k++)
						   {
				              temp=coeff[x][k];
				              coeff[x][k]=coeff[z][k];
				              coeff[z][k]=temp;
						   }
						temp=abs[x];
						abs[x]=abs[z];
						abs[z]=temp;
						sign*=-1;
						break;
					    }
					}
				}
	}
	for(int i=0;i<Orig_Var_Num;i++)
	{
		   factor=coeff[i][i];
		   Temp_Denom*=factor;
		for(int k=0;k<Orig_Var_Num;k++)
			{coeff[i][k]=coeff[i][k]/factor;}
		abs[i]=abs[i]/factor;
		for(int j=i+1;j<Orig_Var_Num;j++)
		{
			multiple=coeff[j][i];
			for(int k=0;k<Orig_Var_Num;k++)
			{
				coeff[j][k]-=(coeff[i][k]*multiple);
			}
			abs[j]-=(abs[i]*multiple);
		}
	}
	Temp_Denom*=sign;
	for(int y=1;y<Orig_Var_Num;y++)
	{
		Temp_Denom*=coeff[y][y];
	}
	Denom=Temp_Denom;
	Solution[Orig_Var_Num-1]=abs[Orig_Var_Num-1]/coeff[Orig_Var_Num-1][Orig_Var_Num-1];
	for(int l=Orig_Var_Num-2;l>=0;l--)
	{
		sum=0;
		for(int n=Orig_Var_Num-1;n>l;n--)
		{
			sum+=coeff[l][n]*Solution[n];
		}
		abs[l]-=sum;
		Solution[l]=abs[l]/coeff[l][l];
	}
}
void MaTrix::Get_Orig_Var_Num(){
	cout<<Orig_Var_Num<<"\n";
}
void MaTrix::Get_Orig_Var_Num(int& i){
	i=Orig_Var_Num;
}
void MaTrix::Get_Equation(int i){
	Equ[i].Show_Eqn();
}
void MaTrix::Get_Denom(){
	cout<<Denom<<"\n";
}
int MaTrix::Get_Eqn_Num(){
	return Eqn_Num;
}
void MaTrix::Show_Solution(){
	for(int s=0;s<Orig_Var_Num;s++)
			{
				cout<<Orig_Vars[s]<<"="<<Solution[s]<<"\n";
			}
}
void MaTrix::Column(string St_Var){
	float Nu_Coeff[100][100];
	for(int i=0;i<Orig_Var_Num;i++){Equ[i].Get_Nu_Coeff(Nu_Coeff[i]);}
	for(int i=0;i<Eqn_Num;i++)
			{
				for(int j=0;j<Orig_Var_Num;j++)
					if(Orig_Vars[j]==St_Var)
						{
							cout<<Nu_Coeff[i][j]<<"\n";
				            break;
					    }
			}
}
