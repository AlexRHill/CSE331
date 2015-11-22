#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

typedef vector<vector<pair<int,float> > > Graph;

class compare{
public:
    //this is for comparing our paths
    int operator() (const pair<int,float>& p1, const pair<int,float> &p2){
        return p1.second > p2.second;
     }
};

void dijkstra(const Graph &g, const int &s, const int &d, vector<int> &path){
    vector<float> distance(g.size());
    vector<int> parent(g.size());
	
	//we set the distance to be roughly infinity
	//every node has a parent of -1, it gets changed if there's a path

    for(unsigned int i = 0 ;i < g.size(); i++){
        distance[i] = numeric_limits<float>::max();
        parent[i] = -1;
    }
    
    priority_queue<pair<int,float>, vector<pair<int,float> >, compare> queue;
	
	//we set up our queue
    
    distance[s] = 0.0;
    queue.push(make_pair(s, distance[s]));

    while(!queue.empty()){
        int u = queue.top().first;
        if(u==d){
            break;
        }
        
        queue.pop();

        for(unsigned int i=0; i < g[u].size(); i++){
            int v = g[u][i].first;
            float w = g[u][i].second;
            
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w;
                parent[v] = u;
                queue.push(make_pair(v, distance[v]));
            }
        }
		
		//we determine the shortest distances and collect them
    }

    path.clear();
    int p = d;
    path.push_back(d);
    while(p!=s){
		//we pass back the shortest path
        p = parent[p];
        path.push_back(p);
        if(p == -1){
            break;
        }
    }
}



int main(int argc, char* argv[]) {
    ifstream in_file;
    string in_name, line;
    string word, word2, word3;
    
    in_name = argv[1];
    
    in_file.open( in_name );
    
    int vertexnum = 0;
    
    vector<int> vertexes;

	//we read our file once to count the vertexes
    
    while(getline(in_file, line)){
        istringstream istrm(line);
        istrm >> word;
        istrm >> word2;
        
        int word_int = stoi(word);
        int word2_int = stoi(word2);

        
        if(find(vertexes.begin(), vertexes.end(), word_int) == vertexes.end()){
            vertexnum += 1;
            vertexes.push_back(word_int);
        }
        if(find(vertexes.begin(), vertexes.end(), word2_int) == vertexes.end()){
            vertexnum += 1;
            vertexes.push_back(word2_int);
        }

    }
    
    in_file.close();
    
    Graph g;
    g.resize(vertexnum);
	//we needed the number of vertexes to set up our graph
    
    in_file.open(in_name);
       
    while(getline(in_file, line)){
        istringstream istrm(line);
        istrm >> word;
        istrm >> word2;
        istrm >> word3;
        
        int word_int = stoi(word);
        int word2_int = stoi(word2);
        float word3_int = stof(word3);
        
        g[word_int].push_back(make_pair(word2_int,word3_int));

    }
	
	//now we load in our graph
    
    cout << fixed;
    
    cout << setprecision(2);
    
    vector<int> path;
    
    int source = stoi(argv[2]);
    int destination = stoi(argv[3]);
	
	if(source == destination){
		cout << source << "->" << source << " " << 0.0 << endl;
		return 0;
	}
    
    dijkstra(g,source,destination,path);
    
    for(int i=path.size()-1;i>=0;i--){
        if(path[i] == -1){
            cout << "NO PATH FOUND" << endl;
            return 0;
        }
        cout<<path[i]<<"->";
    }
    
    cout << '\b';
    cout << '\b';
    cout << " ";
    
    float total = 0;
     
    for(int i = path.size()-1;i>=0;i--){
        for(int j=0; j < g.size(); j++){
            for(int h=0; h < g[j].size(); h++){
                if(path[i] == j){
                    if(path[i-1] == g.at(j).at(h).first){
                        total += g.at(j).at(h).second;
                    }
                }
            }
        }
    }
    
    cout << total << endl;

    return 0;
}

