#include <iostream>
#include <vector>
#include <map>
#define INF 9999

void Dijkstra(std::vector<std::vector<int>> G, int n, int start) {
	std::vector<std::vector<int>> cost(10,std::vector<int>(10));
	std::vector<int>  dist(10), pred(10);
	int visited[10], count, mindist, nextnode, i, j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
		  if (G[i][j] == 0) cost[i][j] = INF;
		  else cost[i][j] = G[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		dist[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	dist[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1) {
		mindist = INF;
	
		for (i = 0; i < n; i++){
			if (dist[i] < mindist && !visited[i]) {
				mindist = dist[i];
				nextnode = i;
			}
		}
		
	visited[nextnode] = 1;
		for (i = 0; i < n; i++){
			if (!visited[i])
			if (mindist + cost[nextnode][i] < dist[i]) {
				dist[i] = mindist + cost[nextnode][i];
				pred[i] = nextnode;
			}
		}
		count++;
	}

	for (i = 0; i < n; i++){
		if (i != start) {
			std::cout << "\nDistance from source to " << i << ": " << dist[i];
		}
	}
}

int main() {
	int n=7;
	int rows=7; //stroki
	int cols=7; //stolbci
	std::vector<std::vector<int>> G(rows, std::vector<int>(cols));
	for(int i=0; i<rows; i++){ // zapolnayu matrix
		for(int j=0; j<cols; j++){
			std::cout << "[" << i << "] [" << j << "]\t";
			std::cin >> G[i][j];
			std::cout << "\n";			
		}
	}  
	  
	Dijkstra(G, n, 0);

  return 0;
}
