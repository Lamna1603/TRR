#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n, m, a[1000][1000], w[1000][1000], p[1000][1000];

void input();
void assign();
void Floyd();
void out();

int main(){
	input();
	assign();
	Floyd();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(w[i][j] == INT_MAX)
			   w[i][j] = -1;
		}
	}
	out(); 
	return 0;
}

void input(){
	FILE *tp;
		int x;
	int begin, end, val;
	tp = fopen("Floyd.txt","r");
	if(tp == NULL) { printf("du lieu rong!"); return ;}
	// x:  
	// 1. do thi vo huong
	// 2. do thi co huong
	fscanf(tp,"%d",&x);
	fscanf(tp,"%d",&n);
	fscanf(tp,"%d",&m);
    //thong so: (begin, end, value) 
	if(x == 1){
	   for(int i = 1; i <= m; i++){
          fscanf(tp,"%d",&begin);
          fscanf(tp,"%d",&end);
          fscanf(tp,"%d",&val);
          a[begin][end] = a[end][begin] = val;
	   }
    }
    else{
	   for(int i = 1; i <= m; i++){
          fscanf(tp,"%d",&begin);
          fscanf(tp,"%d",&end);
          fscanf(tp,"%d",&val);
          a[begin][end] = val;
	   }
    }
    fclose(tp);
}

void out(){
	FILE *tp;
	tp = fopen("floyd.out","w");
    fprintf(tp,"[W]:\n");
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		fprintf(tp, "%d  ", w[i][j]);
		}
		fprintf(tp, "\n");
	}
	fprintf(tp,"[P]:\n");
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		fprintf(tp, "%d  ", p[i][j]);
		}
		fprintf(tp, "\n");
	}
	fclose(tp);
}
void assign(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] != 0){
			   w[i][j] = a[i][j];
			   p[i][j] = j;
		    }
			else w[i][j] = INT_MAX;
		}
	}
}

void Floyd(){

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if( w[i][k] != INT_MAX &&w[k][j] != INT_MAX&& w[i][j] > w[i][k] + w[k][j]){
					w[i][j] = w[i][k] + w[k][j];
					p[i][j] = k;
				}
			}
		}
	}

}
















