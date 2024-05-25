typedef struct Echipa Echipa;
typedef struct Graph Graph;
typedef struct Queue Queue;
struct Echipa
{ int i;
  int victorii;
  char *nume;
  float punctaj;
  struct Echipa *next;
};
struct Graph
{
    int V;
    int E;
    int **a;
};

struct Queue
{
  Echipa *front, *rear;
};