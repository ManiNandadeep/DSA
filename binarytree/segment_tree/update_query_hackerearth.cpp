#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
int N,M,A[MAXN],STMX[4*MAXN],STMN[4*MAXN],X,Y,C;
char str[10] ;
void buildst(int idx,int ss,int se){
	if(ss == se){
		STMX[idx] = A[ss] ;
		STMN[idx] = A[ss] ;
		return ;
	}
	int mid = (ss + se)/2;
	buildst(2*idx,ss,mid) ;
	buildst(2*idx+1,mid+1,se) ;
	STMX[idx] = max(STMX[2*idx],STMX[2*idx+1]) ;
	STMN[idx] = min(STMN[2*idx],STMN[2*idx+1]) ;
}
void update(int idx,int ss,int se,int val,int pos){
	if(ss == se){
		STMX[idx] = val ;
		STMN[idx] = val ;
		return ;
	}
	int mid = (ss + se)/2 ;
	if(pos <= mid)
		update(2*idx,ss,mid,val,pos) ;
	else
		update(2*idx+1,mid+1,se,val,pos) ;
	
	STMX[idx] = max(STMX[2*idx],STMX[2*idx+1]) ;
	STMN[idx] = min(STMN[2*idx],STMN[2*idx+1]) ;
}
pair<int,int> query(int idx,int ss,int se,int l,int r){
	if(l > se || r < ss){
		return make_pair(INT_MIN,INT_MAX);
	}
	if(l <= ss && se <= r){
		return make_pair(STMX[idx],STMN[idx]);
	}
	int mid = (ss + se)/2 ;
	pair<int,int>left,right;
	left  = query(2*idx,ss,mid,l,r) ;
	right = query(2*idx+1,mid+1,se,l,r) ;
	return make_pair(max(left.first,right.first),min(left.second,right.second)) ;
}
bool check(int L,int R,int C){
	pair<int,int>ret = query(1,1,N,L,R) ;
	return ((ret.first-A[L] <= C) && (A[L]-ret.second <= C)) ;
}
void solve(int X,int C){
	int V1,V2 ;
	V1 = V2 = -1 ;
	if(C >= 0){
		int low , high , mid ;
		low = X ;
		high = N ;
		while(low <= high){
			mid = (low + high)/2 ;
			bool f = check(X,mid,C) ;
			if( f && (mid == N || check(X,mid+1,C) == 0)){
				break ;
			}else if(f){
				low = mid+1 ;
			}else{
				high = mid-1 ;
			}
		}
		V1 = mid-X+1;
		pair<int,int>ret= query(1,1,N,X,mid); 
		V2 = max(ret.first-A[X],A[X]-ret.second);
	}
	printf("%d %d\n",V1,V2) ;	
}
int main(){
	scanf("%d%d",&N,&M) ;
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]) ;
	}	
	buildst(1,1,N) ;
	while(M--){
		scanf("%s",str+1) ;
		if(str[1] == 'U'){
			scanf("%d%d",&X,&Y) ;
			A[X] = Y ;
			update(1,1,N,Y,X) ;
	
		}else if(str[1] == 'Q'){
			scanf("%d%d",&X,&C) ;
			solve(X,C) ;			
		}
	}
	return 0 ;
}