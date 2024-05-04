#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n, m, a[1000][1000];

struct bellmanford{
	int value;
	int prev;
};
struct bellmanford b[1000];

void input();
void assign();
void bellmanFord();
void out();

int main(){
	input();
	assign();
	bellmanFord();
	out(); 
	return 0;
}

void input(){
	FILE *tp;
		int x;
	int begin, end, val;
	tp = fopen("bellman.txt","r");
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
	tp = fopen("bellman.out","w");
	fprintf(tp,"           ");
	for(int i = 1; i <= n; i++){
		fprintf(tp,"%d   ", i);
	}
	fprintf(tp,"\nmin value: ");
	for(int i = 1; i <= n; i++){
		fprintf(tp,"%d   ", b[i].value);
    }
    	fprintf(tp,"\nprev:      ");
    for(int i = 1; i <= n; i++){
		fprintf(tp,"%d   ", b[i].prev);
    }	
	fclose(tp);
}
void assign(){
	for(int i = 1; i <= n; i++){
		b[i].value =INT_MAX;
		b[i].prev = 0;
	}

	b[1].value = 0;
}

void bellmanFord(){
	int i = 1;
	while(i <= n){
		for(int j = 1; j <= n; j++){
			if(a[i][j] != 0 && b[j].value > b[i].value + a[i][j]){
				b[j].value = b[i].value + a[i][j];
				b[j].prev = i;
			}
		}
		i++;
	}
}
















