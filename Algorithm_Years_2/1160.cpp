#include <bits/stdc++.h>

using namespace std;

struct cable {
    int a, b, l;
};

bool compare(cable a, cable b) {
    return a.l < b.l; 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<cable> lst; 
    int a, b, l;
    for (int i = 0; i < m; ++i) { 
        cin >> a >> b >> l;
        lst.push_back((cable){a - 1, b - 1, l});
    }
    sort(lst.begin(), lst.end(), compare); // Sort from ben to large

    vector<int> used_points (n, -1); // array with all elements = -1, help define hub used or not
    vector<int> used_cables(m, 0); // array with all elements = 0, help define cable used or not

    int netID = 0, max = 0, counter = 0;
    for (int i = 0; i < m; i++) { 

        if (used_points[lst[i].a]!= -1 && used_points[lst[i].a]== used_points[lst[i].b]) continue; 

        else if(used_points[lst[i].a]== -1 && used_points[lst[i].b] == -1 ) { 
            ++netID; 
            used_points[lst[i].a]= netID; 
            used_points[lst[i].b] = netID;

        } else if ((used_points[lst[i].a]!= -1 && used_points[lst[i].b] == -1 ) ||
         (used_points[lst[i].a]== -1 && used_points[lst[i].b] != -1 )) { 
            used_points[lst[i].a] = used_points[lst[i].a]+ used_points[lst[i].b] + 1;; 
            used_points[lst[i].b] = used_points[lst[i].a]; 
        } else { 
            int minID, maxID;
            if(used_points[lst[i].b] > used_points[lst[i].a]) {
                minID = used_points[lst[i].a]; 
                maxID = used_points[lst[i].b];
            } else {
                minID = used_points[lst[i].b]; 
                maxID = used_points[lst[i].a];
            }
            for (int j = 0; j < n; j++){
                if(used_points[j] == maxID) 
                {
                    used_points[j] = minID;
                }
            }
            
        }
        used_cables[i] = 1;
        max = lst[i].l;
        ++counter;
    }
    // result
    cout << max << endl ;
    cout << counter << endl; 
    for (int j = 0; j < m; j++) if (used_cables[j]){
        cout << lst[j].a + 1 << " " << lst[j].b + 1 << endl; 

    }
            
    return 0;
}