#include <iostream>
#include <fstream>
#include <vector>
#include <list>

void reading_vector(std::vector<int>& vector_of_elements)
{
	int element;
	std::ifstream fin;
	fin.open("input.in");
	while (!fin.eof())
	{
		fin >> element;
		vector_of_elements.push_back(element);
	}
	fin.close();
}

void writing_vector(std::vector<int>v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void Max_Heapfy(std::vector<int>& vector_of_elements, int i)
{
	int left, right, imax;
	left = 2 * i + 1;
	right = 2 * i + 2;
	imax = i;
	if (left < vector_of_elements.size() && vector_of_elements[left]>vector_of_elements[imax])
	{
		imax = left;
	}
	if(right<vector_of_elements.size() && vector_of_elements[right]>vector_of_elements[imax])
	{
		imax = right;
	}
	if (imax != i)
	{
		std::swap(vector_of_elements[i], vector_of_elements[imax]);
		Max_Heapfy(vector_of_elements, imax);
	}
}

void Build_Max_Heap(std::vector<int>& vector_of_elements)
{
	for (int i = vector_of_elements.size()/2-1; i >= 0; i--)
	{
		Max_Heapfy(vector_of_elements, i);
	}
}

void HeapSort(std::vector<int>& vector_of_elements)
{
	std::vector<int>temp_vector;
	temp_vector.resize(vector_of_elements.size());
	Build_Max_Heap(vector_of_elements);
	int n = vector_of_elements.size();
	for (int i = n-1; i >=0; i--)
	{
		std::swap(vector_of_elements[i], vector_of_elements[0]);
		temp_vector[i] = vector_of_elements[vector_of_elements.size() - 1];
		vector_of_elements.pop_back();
		Max_Heapfy(vector_of_elements, 0);
	}
	vector_of_elements = temp_vector;
}

void print_vector(std::vector<int>vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
}


int main()
{
	std::vector<int>vector_of_elements;
	reading_vector(vector_of_elements);
	HeapSort(vector_of_elements);
	print_vector(vector_of_elements);

	return 0;
}
