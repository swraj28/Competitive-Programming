#include<iostream>
#include "vector.h"
using namespace std;

int main() {

    Vector<int> v;

    v.push_back(71);

    v.push_back(72);

    v.push_back(73);

    v.push_back(74);
    v.pop_back();
    v.push_back(76);
    v.push_back(80);

    cout << "Capacity " << v.capacity() << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}


//Using vector pair

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     vector<pair<int,int>> v;

//     for(int i=0;i<n;i++)
//     {
//         int x,y;
//         cin>>x>>y;

//         v.push_back(make_pair(x,y));
//     }

//     for(auto p:v)
//     {
//         cout<<p.first<<p.second<<" ";
//     }

//     cout<<endl;

//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i].first<<v[i].second<<" ";
//     }



//     return 0;
// }