/* 
 * File:   cse331proj04.cpp
 * Author: kazambolt
 *
 * Created on March 27, 2014, 9:56 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <list>

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istringstream;
using std::stoi;
using std::map;
using std::list;


class Graph{
public:
    map<int,list<int>> vertices_;
    int num_ = 0;
    map<int,string> colors;
    
    //the first map is for listing each vertex and their adjacent vertices
    //the second map is for holding the color for each vertex
   

    bool BFS(int vertex){
        string color;
        
        if(vertex % 2 == 0){
            color = "WHITE";
        }
        else{
            color = "BLACK";
        }
        
        //this gives the color for the first vertex
       
        
        bool *visit = new bool[num_];
        for(int i = 0; i < num_; i++){
            visit[i] = false;
        }
        //all vertexes are initially not visited
        
        list<int> q;
        
        visit[vertex] = true;
        q.push_back(vertex);
        colors[vertex] = color;
        
        //then we process the first vertex
        
        list<int>::iterator i;
        
        while(!q.empty()){
            vertex = q.front();
            cout << vertex << " " << colors[vertex] << endl;
            
            //when we visit a vertex, we print it and it's color
            
            q.pop_front();
            
            for(i = vertices_[vertex].begin(); i != vertices_[vertex].end(); ++i){
                if(!visit[*i]){
                    visit[*i] = true;
                    q.push_back(*i);
                    if(colors[vertex] == "BLACK"){
                        colors[*i] = "WHITE";
                    }
                    else{
                        colors[*i] = "BLACK";
                    }
                    //when we add a vertex to the queue, we also give it a color in the colors map
                }
                else{
                    if(colors[vertex] == colors[*i]){
                        //if a vertex has already been visited, we check the colors
                        while(!q.empty()){
                            int k = q.front();
                            cout << k << " " << colors[vertex] << endl;
                            //if they're the same, we print out whatever vertexes are in the queue
                            q.pop_front();
                        }

                        cout << "CONFLICT " << vertex << " " << *i << endl;
                        //then we say where the conflict is
                        return 0;
                    } 
                }
            }
        }
        return 1;
    }
    
    
    

    bool isBipartite(){
        int startingvertex;
        string firstcolor;
        for(auto i : vertices_){
            startingvertex = i.first;
            break;
        }
        //this is the only way I knew to start with the first vertex
        
        bool end = BFS(startingvertex);
        
        return end;
    }
};


int main(int argc, char* argv[]) {
    ifstream in_file;
    string in_name, line;
    string word, word2;
    
    in_name = argv[1];
    
    in_file.open( in_name );
    
    Graph graph;
    //read in a file, get all the numbers, put it in the list of the graph
    while(getline(in_file, line)){
        istringstream istrm(line);
        istrm >> word;
        
        int word_int = stoi(word);
        
        list<int> v;
        while(istrm >> word2){
            int word2_int = stoi(word2);
            v.push_back(word2_int);
        }
        
        graph.vertices_[word_int] = v;
        graph.num_ += 1;
    }
    
    
    bool isB = graph.isBipartite();
	
	if(isB == 1){
		cout << "TRUE" << endl;
	}
	else{
		cout << "FALSE" << endl;
	}
        
    return 0;
}

