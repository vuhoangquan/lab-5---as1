#pragma once 
#include <iostream>
#include <vector>
using namespace std;
template <class types>
void merge( vector<types> a, vector<types> b, vector<types>& newcontainer ){

    int i=0,j=0;
    while (i != a.size() && j != b.size()) {
        if( a.at(i) < b.at(j) ){
            newcontainer.push_back(a.at(i));
            
            if (i >= a.size()) { break; }
            else{i++; }
            cout << newcontainer.at(i);

        }else if( a.at(i) > b.at(j) ){
            newcontainer.push_back(b.at(j));
            j++;
            if (j >= b.size()) { break; }
            else{j++; }
            cout << newcontainer.at(j);

        }else{
            newcontainer.push_back(a.at(i));
            newcontainer.push_back(b.at(j));
            i++;
            j++;
            if (i >= a.size()) { break; }
            else{i++; }
            if (j >= b.size()) { break; }
            else{j++; }
        }
    }
    while(i != a.size()){
        newcontainer.push_back(a.at(i));
        if (i >= a.size()) { break; }
        else{i++;}

    }
    while( j != b.size()){
        newcontainer.push_back(b.at(j));
        if (j >= b.size()) { break; }
        else{j++;}

    }
}

int mergerTest(){
    //populate 2 vector
    vector<float> vec1;
	vec1.push_back(1.15);
	vec1.push_back(12.56);
	vec1.push_back(57.54);
	vec1.push_back(68.34);


    vector<float> vec2;
	vec2.push_back(35.15);
	vec2.push_back(69.56);
	vec2.push_back(96.54);
	vec2.push_back(99.34);

    vector<float> vec3;
    vec3.push_back(0.01);
    merge(vec1, vec2, vec3);

    cout <<"merged vector printed: "<< endl;
    for( int i=0; i< vec3.size();i++){
        cout << vec3.at(i) << endl;
    }
    return 0;
}