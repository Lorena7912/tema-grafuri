typedef struct Echipa Echipa;
typedef struct Graph Graph;
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

struct Queque
{
  Echipa *front, *rear;
};