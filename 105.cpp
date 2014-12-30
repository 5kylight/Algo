#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <set>
#include <memory>

using namespace std;

int main(){
	string line;
	 
	vector< vector<int> > data; 
	vector<int> response;
	while(getline(cin, line)){
 		istringstream is (line);
 		istream_iterator<int> it(is);
 		int temp;
		data.push_back(vector<int>{*it++,  temp = *it++});
		data.push_back(vector<int>{*it, temp});
 	}

 	sort(data.begin(), data.end(), [](const vector<int>&a, const vector<int>&b){
 		return a[0] < b[0];
 	});

 	//starting the right process, dill with this bullshit!
 	set< int > tree;
 	vector< vector<int> > ::iterator data_iterator = data.begin();
 	vector<int> tmp =  *data_iterator; 
 	set<int>::iterator tree_iter;
 	tree.insert(tmp[1]);
 	int prev_max = tmp[1];


 	++data_iterator;	
 	int current, val, max;
// 	printf("%d ", tmp[0]);
 	response.push_back(tmp[0]);
 	while( data_iterator != data.end()){
 		tmp = *data_iterator;
 		current = tmp[0];
	 	val = tmp[1];

 		if(!tree.empty()){

 			tree_iter = tree.find(val);
 			if (tree_iter != tree.end()){
 				max = *tree.rbegin();

				if (val >= max){
					// printf("%d ", val);
 					// printf("%d ", current);	
 					response.push_back(val);
					response.push_back(current);
 				}
 					tree.erase(tree_iter);
 					if(!tree.empty())
 					prev_max = *tree.rbegin();	
 			} else {
 				tree.insert(val);
 				max = *tree.rbegin();
	 			if ( max > prev_max ){
	 				// printf("%d ", prev_max);
	 				// printf("%d ", current);
	 				response.push_back(prev_max);
	 				response.push_back(current);
	 				prev_max = val;
	 			}

 			}	
		} else {
			// printf("%d ", 0);
			// printf("%d ", current );
			response.push_back(0);
			response.push_back(current);
			tree.insert(val);
			prev_max = val;
		}
		++data_iterator;
	
 	}
// 	printf("%d \n", 0);
 	response.push_back(0);


 	for ( int i :  response){
 		printf(" %d", i);
 	}

 	printf("\n");
 //	return response;
}	
