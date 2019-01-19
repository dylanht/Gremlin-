#include "GraphTraversal.h"
#include "AddEdgeStep.h"
#include "TraversalStep.h"
#include <string>
#include <vector>

AddEdgeStep::AddEdgeStep(std::string label_arg)
: TraversalStep(MAP, ADD_EDGE_STEP) {
	label = label_arg;
	out_vertex_traversal = NULL;
	in_vertex_traversal = NULL;
}

// Return something like AddEdgeStep(label)
std::string AddEdgeStep::getInfo() {
	std::string info = "AddVertexStep(";
	info += label + ")";
	return info;
}

GraphTraversal* AddEdgeStep::get_out_traversal() { return this->out_vertex_traversal; }
GraphTraversal* AddEdgeStep::get_in_traversal() { return this->in_vertex_traversal; }
void AddEdgeStep::set_out_traversal(GraphTraversal* new_traversal) { this->out_vertex_traversal = new_traversal; }
void AddEdgeStep::set_in_traversal(GraphTraversal* new_traversal) { this->in_vertex_traversal = new_traversal; }
std::string AddEdgeStep::get_label() { return this->label; }