#include<stdio.h>
 
int top = 0, front = 0, temp=-1, a[8][8], vis[8], stack[8];
void dfs( int s, int n );
void push( int item );
int pop();
int main(void){
	int n, i, s, ch, j;
    char c, dummy;
    printf("Input number of vertex : ");
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("Input 1 if %d conected %d. If not, input 0 : ", i, j);
            scanf("%d",&a[i][j]);
        }
	}
	printf("The Adjacency Matrix : \n");
    for(i = 0;i < n;i++){
 		for (j = 0;j < n;j++){
 			printf(" %d", a[i][j]);
 		}
 		printf("\n");
 	}

 	for (i = 0;i < n;i++)
 		vis[i] = -1;
 	printf("Input start number :");
 	scanf("%d", &s);

	for(i=0;i<8; i++){
		stack[i] = -1;
		vis[i] = -1;
		front = 0;
		top = 0;
	}

 	dfs(s,n);
 
	return 0;
}  
void dfs(int s,int n)
{
	int i, k, j, pass = 0, temp[8];
 	push(s);
 	vis[s] = 1;
 	k = pop();
	temp[0] = k;
 	if (k != -1)
 		printf("%d ",k);
 	while(pass != 7){
		for(i=0;i<8; i++){
			stack[i] = -1;
			front = 0;
			top = 0;
		}
 		for (i = 0;i < n;i++)
 			if ((a[k][i] != 0) && (vis[i] == -1)){
				push(i);
 			}
 		k = pop();
		if(k == -1 && pass > 2){
			k = temp[pass-2];
			continue;
		}
		else
			temp[pass] = k;

 		if ( k != -1 ){
			vis[k] = 1;
 			printf("%d ", k);
			pass ++;
		}
 	}
 	for (i = 0;i < n;i++)
 		if (vis[i] == -1)
 			dfs(i, n);
}
 
 
 
void push(int item){
 	if(front == 19)
 		printf("Stack overflow ");
 	else
 		stack[front++] = item;
 }
  
int pop(){
 	int k;
 	if (top == -1)
 		return (0);
  	else{
 		k = stack[top++];
 		return (k);
 	}
 }