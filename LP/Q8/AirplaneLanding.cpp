  #include<iostream>
  #include<cstdio>
  #include<cstring>
  #include<algorithm>
  #include<cmath>
  using namespace std;
  const int N=15;
  const double eps=1e-8,INF=1e15;
 inline float read(){
	float t;
	cin>>t;
	return t;
 }
 int m=15;
 int n=7;
 float a[N][N],ans[N];
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
 int myinput(){
	 //初始化
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			a[i][j]=0;		
		
    for(int i=1;i<=5;i++){
        a[i+5][0]=-read();
		a[i][0]=read();//b
	 }
	a[0][6]=1;//c
	if(a[1][0] < 0) return 0;
	 
	 
	//生成系数矩阵A
	for(int i=1;i<=5;i++)
		a[i][i]=1;
	for(int i=6;i<=10;i++)
		a[i][i-5]=-1;		
	for(int i=11;i<=14;i++){
		int t=i-10;
		a[i][t]=1;
		a[i][t+1]=-1;
		a[i][6]=1;
	}
		
	//输出矩阵检验
	/*
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++)
			printf("%.2lf ",a[i][j]);
		cout<<endl;
	}
	*/
	return 1;
}

int main(){
	 if(myinput()==0)
		 return 0;
	 
     for(int i=1;i<=n;i++) id[i]=i;
     if(init() && simplex()){
        //printf("%.2f\n",-a[0][0]);
		for(int i=1;i<=m;i++) ans[id[n+i]]=a[i][0];
        for(int i=1;i<=4;i++) printf("%.2f ",ans[i]);
		printf("%.2f",ans[5]);
     }
 }