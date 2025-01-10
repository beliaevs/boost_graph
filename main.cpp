#include<iostream>
#include<string>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/adjacency_list.hpp>

using namespace boost;

struct Vertex
{
	std::string name;
};

struct Edge
{
	double d;
};

using graph_t = adjacency_list<vecS, vecS, directedS, Vertex, Edge>;

int main()
{
	constexpr int NumVertices = 5;
	graph_t g(NumVertices);
	auto idmap = boost::get(&Vertex::name, g);
	idmap[0] = "Sasha";
	idmap[1] = "Pasha";
	idmap[2] = "Dasha";
	idmap[3] = "Kashka";
	idmap[4] = "Ploshka";

	auto edgemap = boost::get(&Edge::d, g);
	add_edge(0, 1, Edge{2.3}, g);
	add_edge(0, 2, Edge{2.1}, g);
	add_edge(0, 3, Edge{1.1}, g);
	add_edge(1, 2, Edge{3.3}, g);
	add_edge(3, 4, Edge{2.7}, g);

	boost::write_graphviz(std::cout, g, make_label_writer(idmap), make_label_writer(edgemap));
	return 0;
}