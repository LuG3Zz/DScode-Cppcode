#include <stdio.h>
#define MaxVertexNum 100


typedef struct {
    int verNum;
    int edgeNum;
    VerType vertex[MaxVertexNum];
    EdgeType edges[MaxVertexNum][MaxVertexNum];

} MGraph;

typedef char VerType;
typedef int EdgeType;