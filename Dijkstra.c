@@ -0,0 +1,112 @@
#include <stdio.h>

#define MAX_NODES 10	// 최대 노드 수
#define INF 99999		// 
#define TRUE 1			// TRUE
#define FALSE 0			// FALSE

int distance[MAX_NODES];	// 거리를 저장하는 배열
int found[MAX_NODES];		// 최단 거리를 찾았는지 못찾았는지 저장하는 변수

// 노드를 표현하는 구조체
typedef struct GraphType {
	int n;	// 노드의 갯수를 저장
	int cost[MAX_NODES][MAX_NODES];	// 노드에서 노드까지의 거리가 저장됨
} GraphType;

// 출력 함수
void print_status(GraphType* g, int step) {

	printf("\tdistance:");

	for(int j = 0; j < g->n; j++) {	// 노드 개수만큼 반복
		if(distance[j] == INF) {	// 거리가 INF인 (아직 거리 계산이 안된 것) 값이 있으면
			printf("\t*");			// * 로 출력함	
		}else {
			printf("\t%d",distance[j]);
		}
	}
	printf("\n");
	printf("\tfound:\t");
	// 최단 경로가 발견 됐는지 안됐는지 출력함
	for(int k = 0; k < g->n; k++) {
		printf("\t%d",found[k]);
	}
	printf("\n");
		
}

// 노드에서 최단경로를 선택 함수
int choose(int distance[], int n, int found[]) {
	int min;
	int min_index;
	
	min = INF;
	min_index = -1;

	for(int i = 0; i < n; i++) {
		if(distance[i] < min && found[i] == FALSE) {
			min = distance[i];
			min_index = i;
		}
	}		

	return min_index;
					
}

void shortest_path(GraphType* g, int start_node) {
	int count = 0;
	int min_index;
	
	for(int i = 0; i < g->n; i++) {
		distance[i] = g->cost[start_node][i];
		found[i] = FALSE;
	}
	
	found[start_node] = TRUE;
	
	while(count < g->n) {
		printf("STEP %d\n",count);	
		print_status(g,g->n);
		
		min_index = choose(distance, g->n, found);
		found[min_index] = TRUE;
		
		
		for(int i = 0; i < g->n; i++) {
			if(g->cost[min_index][i] != 0 && found[i] != TRUE) {
				if(distance[min_index] + g->cost[min_index][i] < distance[i]) {
					distance[i] = distance[min_index] + g->cost[min_index][i];
				}
			}	
		}
		
			
			
		count++;
	}

	
		
}struct
int main(void) {


	GraphType G = { 6,
	{{0,5,3,7,INF,INF},
	{5,0,4,INF,7,9},
	{3,4,0,3,8,INF},
	{7,INF,3,0,4,INF},
	{INF,7,8,4,0,2},
	{INF,9,INF,INF,2,0}}
	};
	
	shortest_path(&G,2);

	return 0;
}

	
	
	
