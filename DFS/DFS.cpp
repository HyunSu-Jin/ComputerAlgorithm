// 2012003738 _ ChaJeongMin _ B

#include <stdio.h>
#include <stdlib.h>

#define WHITE			0
#define GRAY				1
#define BLACK			2

#define TREE_EDGE		1
#define BACK_EDGE		2
#define FORWARD_EDGE		3
#define CROSS_EDGE		4

unsigned int time = 0;
unsigned int numV = 0;

typedef struct _vertex
{
	int color;
	int d;
	int f;
	int pred;
} Vertex;

// 구조체 멤버 중 자기 구조체를 타입으로 하는 포인터 next을 사용하는 이유는,
// 리스트 형태로 연결하고자 하기 위함.
typedef struct _edge
{
	int toV;
	int type;
	struct _edge * next;
} Edge;

// 각 Vertxt 마다 Adjacency list 구조체가 하나씩 배당되는 것으로 생각
Vertex SetV[1000];
Edge * adjlist[1000]={NULL,};

void addEdge(int fromV, int toV)
{
	Edge * newEdge;
	Edge * temp;
	temp = adjlist[fromV];

	newEdge = (Edge*)malloc(sizeof(Edge));
	newEdge->toV = toV;
	newEdge->next = NULL;

	if(adjlist[fromV] == NULL)
	{
		adjlist[fromV] = newEdge;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newEdge;
	}
}

void DFS_Visit(int fromV)
{
	Edge * edge_fromV;
	edge_fromV = adjlist[fromV];

	time ++;
	/* DISCOVERY */
	SetV[fromV].color = GRAY;
	SetV[fromV].d = time;

	while(edge_fromV != NULL)
	{
		int toV;
		toV = edge_fromV->toV;

		switch(SetV[toV].color)
		{
		case WHITE:
			edge_fromV->type = TREE_EDGE;		// 1
			SetV[toV].pred = fromV;
			DFS_Visit(toV);
			break;

		case GRAY:
			edge_fromV->type = BACK_EDGE;		// 2
			break;

		case BLACK:
			if(SetV[fromV].d < SetV[toV].d)
				edge_fromV->type = FORWARD_EDGE;// 3
			else if(SetV[fromV].d > SetV[toV].d)
				edge_fromV->type = CROSS_EDGE;	// 4
			break;

		default:
			break;
		}

		edge_fromV = edge_fromV->next;
	}

	/* FINISHED */
	SetV[fromV].color = BLACK;
	time ++;
	SetV[fromV].f = time;
}

void DFS(void)
{
	int i;
	for(i=1; i<=numV; i++)
	{
		SetV[i].color = WHITE;
		SetV[i].pred = NULL;
	}
	time = 0;
	for(i=1; i<=numV; i++)
	{
		if(SetV[i].color == WHITE)
		{
			DFS_Visit(i);
		}
	}
}

int main(void)
{
	int i=0;
	int fromV, toV;
	Edge * temp;

	scanf("%d", &numV);
	while(scanf("%d %d", &fromV, &toV) != EOF)
	{
		addEdge(fromV, toV);
	}

	DFS();

	for(i=1; i<=numV; i++)
	{
		temp = adjlist[i];
		while(temp != NULL)
		{
			printf("%d %d %d \n", i, temp->toV, temp->type);
			temp = temp->next;
		}
	}
	return 0;
}