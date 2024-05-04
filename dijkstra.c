#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int min, n, m, a[1000][1000], cur;
//min: đánh dấu vị trí có d ngắn nhất sau mỗi dòng=>check=1
//n: số đỉnh,m:số canh;a ma trận trọng số, 
//cur: vị trí min đã dánh dấu để thực thiện só ách độ dài cho hàng tiếp theo

struct dijkstra{
	int check;
	int value;
	int prev;
};
struct dijkstra b[1000];
void input();
void assign();
void dijkstra();

int main(){
	input();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n ; j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	dijkstra();
	FILE *tp;
	tp = fopen("dijkstra.out","w");
    fprintf(tp,"min: %d\n", b[n].value);
    fprintf(tp,"duong di: ");
    int i = n;
    int way[n+1], count = 1;
    while(i != 1){
    	way[count] = b[i].prev;
    	count++;
    	i = b[i].prev;
	}
	for(int i = count -1 ; i >= 1; i--){
		fprintf(tp,"%d ->",way[i]);
	}
	   fprintf(tp,"%d",n);
	return 0;
}
void input(){
	FILE *tp;
		int x;
	int begin, end, val;
	tp = fopen("dijkstra.txt","r");
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
void assign(){
	//đánh dấu cho bước đầu tiên: 1-1 có gí trị 0, check 1=1, các gtri còn lại 0,check=0
	for(int i = 1; i <= n; i++){
		b[i].value =INT_MAX;
		b[i].prev = 0;
	}
	b[1].check = 1;
	b[1].value = 0;
	min = n;//vì n là đỉnh cuối
}

void dijkstra(){
	assign();
	cur = 1;
	while(b[n].check != 1){
		for(int i = 1; i <= n; i++){ 
			if(b[i].check != 1 && a[cur][i] != 0 && (b[i].value > b[cur].value + a[cur][i])){
				b[i].value = b[cur].value + a[cur][i];
				b[i].prev = cur;
				if(b[min].value > b[i].value){
		    	   min = i;
			}
		    }

	   }
		b[min].check = 1;
		cur = min;
		min = n;
	}
}












