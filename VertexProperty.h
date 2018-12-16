#ifndef VERTEX_PROPERTY_H
#define VERTEX_PROPERTY_H

#include <set>
#include <exception>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream> // TODO REMOVE
#include <boost/any.hpp>
#include "Property.h"

enum Cardinality {SINGLE, LIST, SET};

template<typename T>
class VertexProperty {
	private:
		std::string my_key;
		std::vector<T>* my_values;
	public:
		VertexProperty(Cardinality card, std::string new_key, std::vector<T> new_values) {
			this->my_key = new_key;

			// sets are weird in general, and the default comparator won't work in this method
			if(card == SET) {
				throw std::runtime_error("Set cardinality not yet supported!");
			}
			else if(card == LIST) {
				my_values = new std::vector<T>(new_values.begin(), new_values.end());
			}
			else {
				if(new_values.size() > 1) throw std::runtime_error("Specified single Cardinality but provided a vector of size > 1!");
				my_values = new std::vector<T>(new_values.begin(), new_values.end());	
			}
		}

		std::string key() {
			return my_key;
		}

		std::vector<T> values() {
			return *my_values;
		}

		T value() {
			if(my_values->empty()) throw std::runtime_error("No values present for the given property key.");
			return my_values->at(0);
		}
};

#endif