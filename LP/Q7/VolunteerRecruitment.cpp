  #include<iostream>
  #include<cstdio>
  #include<cstring>
  #include<algorithm>
  #include<cmath>
  using namespace std;
  const int N=2000;
  const double eps=1e-8,INF=1e15;
 inline int read(){
	int t;
	cin>>t;
	return t;
 }
 int n,m;
 double a[N][N],ans[N];
 int S[N],F[N];
 int id[N<<1];
 int q[N];
 void Pivot(int l,int e){
     swap(id[n+l],id[e]);
     double t=a[l][e]; a[l][e]=1;
     for(int j=0;j<=n;j++) a[l][j]/=t;
     for(int i=0;i<=m;i++) if(i!=l && abs(a[i][e])>eps){
         t=a[i][e]; a[i][e]=0;
         for(int j=0;j<=n;j++) a[i][j]-=a[l][j]*t;
     }
 }
 bool init(){
     while(true){
         int e=0,l=0;
         for(int i=1;i<=m;i++) if(a[i][0]<-eps && (!l||(rand()&1))) l=i;
         if(!l) break;
         for(int j=1;j<=n;j++) if(a[l][j]<-eps && (!e||(rand()&1))) e=j;
         if(!e) {puts("Infeasible");return false;}
         Pivot(l,e);
    }
    return true;
 }
 bool simplex(){
     while(true){
         int l=0,e=0; double mn=INF;
         for(int j=1;j<=n;j++) 
             if(a[0][j]>eps) {e=j;break;}
         if(!e) break;
         for(int i=1;i<=m;i++) if(a[i][e]>eps && a[i][0]/a[i][e]<mn)
             mn=a[i][0]/a[i][e],l=i;
         if(!l) {puts("Unbounded");return false;}
         Pivot(l,e);
    }
     return true;
 }
 void myinput(){
     m=read();n=read();
	 for(int i=1;i<=m;i++)
		 a[i][0]=-read();//b
     for(int i=1;i<=n;i++){
        S[i]=read();
		F[i]=read();
		a[0][i]=-read();//目标函数系数
	 }
	//生成系数矩阵A
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(i>=S[j] && i<=F[j])
				a[i][j]=-1;		
		}
	//输出初始矩阵检验
	/*
	for (int i=0;i<=m;i++){
		for (int j=0;j<=n;j++)
			printf("%.2lf ",a[i][j]);
		cout<<endl;
	}
	cout<<endl;
	*/
}
 int main(){
	 myinput();
	 
     for(int i=1;i<=n;i++) id[i]=i;
     if(init() && simplex()){
		//输出结果矩阵检验
		/*
		for (int i=0;i<=m;i++){
			for (int j=0;j<=n;j++)
				printf("%.2lf ",a[i][j]);
			cout<<endl;
		}
		*/
	
         printf("%d\n",(int)a[0][0]);
         //for(int i=1;i<=m;i++) ans[id[n+i]]=a[i][0];
         //for(int i=1;i<=n;i++) printf("%d ",(int)ans[i]);
     }
 }