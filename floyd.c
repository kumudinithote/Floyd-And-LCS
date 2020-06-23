#include<stdio.h>

#define min(x,y) ((x) <= (y)) ? (x) : (y)

// Recursive Function to print path of given
// vertex u from source vertex v

void printPath(int path[10][10], int v, int u)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u]);
    printf(" %d", path[v][u]);
}

// Function to print the shortest cost with path
// information between all pairs of vertices
void printSolution(int cost[10][10], int path[10][10], int floydsMatrix[10][10], int noOfVertices)
{
  printf("\n Matrix of output data:\n");
  for (int i=0;i<noOfVertices;i++) {
    for (int j=0;j<noOfVertices;j++)
       printf("%d \t",cost[i][j]);
    printf("\n");
  }

    for (int v = 0; v < noOfVertices; v++)
    {
        for (int u = 0; u < noOfVertices; u++)
        {
            printf("Distance from vertex %d to %d => %d \t",v, u, cost[u][v]);

            if (u != v && path[v][u] != -1 && cost[u][v] != floydsMatrix[u][v])
            {
                printf("Path through => ");
                printPath(path, v, u);
            }

            printf("\n");
        }
    }

}

// Function to run Floyd-Warshell algorithm
void FloydWarshell(int floydsMatrix[10][10],int noOfVertices)
{
    // cost[] and parent[] stores shortest-path
    // (shortest-cost/shortest route) information
    int cost[10][10], path[10][10];

    // initialize cost[] and parent[]
    for (int v = 0; v < noOfVertices; v++)
    {
        for (int u = 0; u < noOfVertices; u++)
        {
            // initally cost would be same as weight
            // of the edge
            cost[v][u] = floydsMatrix[v][u];

            if (v == u)
                path[v][u] = 0;
            else if (cost[v][u] != 999)
                path[v][u] = v;
            else
                path[v][u] = -1;
        }
    }

    // run Floyd-Warshell
    for (int k = 0; k < noOfVertices; k++)
    {
        for (int v = 0; v < noOfVertices; v++)
        {
            for (int u = 0; u < noOfVertices; u++)
            {
                // If vertex k is on the shortest path from v to u,
                // then update the value of cost[v][u], path[v][u]

                if (cost[v][k] != 999 && cost[k][u] != 999
                    && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            // if diagonal elements become negative, the
            // graph contains a negative weight cycle
            if (cost[v][v] < 0)
            {
                return;
            }
        }
    }
    printf("reahced end\n" );
    // Print the shortest path between all pairs of vertices
    printSolution(cost, path, floydsMatrix, noOfVertices);
}

// main function
int main()
{
  int floydsMatrix[10][10];
  int noOfVertices;
  int noOfEdges;

  printf("Enter the number of vertices between 5 to 10:\n");
  scanf("%d",&noOfVertices);

  //Initial matrix
  for (int i=0;i<noOfVertices;i++) {
    for (int j=0;j<noOfVertices;j++)
      if(i==j)
       floydsMatrix[i][j]=0;
      else if(i < j){
        floydsMatrix[i][j]=rand() % 9 + 1;
        floydsMatrix[j][i] = floydsMatrix[i][j];
      }
  }
  /*
  //take the number of weighted vertices
  printf("Enter the number of edges that has to be weighted :\n");
  scanf("%d",&noOfEdges);

  //Assign ramdom weight to edges
  printf("Assigning random weights to edges :\n");
  for (int i=0;i<noOfEdges;i++) {
    int x_coordinate = rand() % noOfVertices;
    int y_coordinate = rand() % noOfVertices;
    if(x_coordinate != y_coordinate) {
      int weight = rand() % 100;
      printf("%d %d %d\n", x_coordinate, y_coordinate, weight);
      floydsMatrix[x_coordinate][y_coordinate]=weight;
      floydsMatrix[y_coordinate][x_coordinate]=weight;
      printf("%d \n", floydsMatrix[x_coordinate][y_coordinate]);
    }
    else{
      i--;
    }
  }
  */


  printf("\n Matrix of input data:\n");
  for (int i=0;i<noOfVertices;i++) {
    for (int j=0;j<noOfVertices;j++)
       printf("%d \t",floydsMatrix[i][j]);
    printf("\n");
  }

  FloydWarshell(floydsMatrix,noOfVertices);
  return 0;
}
