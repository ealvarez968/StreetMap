#ifndef ROUTE_MODEL_H
#define ROUTE_MODEL_H

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:
  	auto &FindClosestNode(float x, float y);
    class Node : public Model::Node {
      public:
        // Add public Node variables and methods here.
      	Node* parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
      	std::vector<Node *> neighbors;
       void FindNeighbors();
      
      float distance(const Node other)  {
        	return sqrt(pow( x- other.x,2)+pow(y -other.y,2));
       }
        
        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}
      
      private:
        // Add private Node variables and methods here.
        int index;
      	Node * FindNeighbor(std::vector<int> node_indices);
        RouteModel * parent_model = nullptr;
    };
  
  auto &SNodes(){ return m_Nodes;};
  auto &GetNodeToRoadMap(){return node_to_road;};
    
    // Add public RouteModel variables and methods here.
    RouteModel(const std::vector<std::byte> &xml);  
    std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.
  

  private:
    // Add private RouteModel variables and methods here.
  std::unordered_map<int, std::vector<const Model::Road*>> node_to_road;
  void CreateNodeToRoadHashmap();
  	std::vector<Node> m_Nodes;

};

#endif
