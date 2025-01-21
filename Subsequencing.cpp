#include <iostream>
#include <vector>
using namespace std;

void SubSequence(int i, vector<int>& V, vector<int>& current, int size) {
    if (i >= size) {
        cout<<"[";
        for (int j = 0; j < current.size(); ++j) {
            cout << current[j] << " ";
        }
        cout<<"]";
        
    if(current.size()==0){
        cout<<"[]";
    }
        cout << endl;
        return;
    }
    
    // Include the current element
    current.push_back(V[i]);
    SubSequence(i + 1, V, current, size);
    
    // Exclude the current element
    current.pop_back();
    SubSequence(i + 1, V, current, size);
}

int main() {
    vector<int> V = {3, 1, 2};
    int size = V.size();
    vector<int> current;
    
    SubSequence(0, V, current, size);

    return 0;
}

// recursion tree

// subsequencing(0, {1, 2, 3, 4, 5}, [], 5)
// |
// ├── Include 1: subsequencing(1, {1, 2, 3, 4, 5}, [1], 5)
// |   |
// |   ├── Include 2: subsequencing(2, {1, 2, 3, 4, 5}, [1, 2], 5)
// |   |   |
// |   |   ├── Include 3: subsequencing(3, {1, 2, 3, 4, 5}, [1, 2, 3], 5)
// |   |   |   |
// |   |   |   ├── Include 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 2, 3, 4], 5)
// |   |   |   |   |
// |   |   |   |   ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 3, 4, 5], 5) → **[1, 2, 3, 4, 5]**
// |   |   |   |   └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 3, 4], 5) → **[1, 2, 3, 4]**
// |   |   |
// |   |   └── Exclude 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 2, 3], 5)
// |   |       |
// |   |       ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 3, 5], 5) → **[1, 2, 3, 5]**
// |   |       └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 3], 5) → **[1, 2, 3]**
// |   |
// |   └── Exclude 3: subsequencing(3, {1, 2, 3, 4, 5}, [1, 2], 5)
// |       |
// |       ├── Include 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 2, 4], 5)
// |       |   |
// |       |   ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 4, 5], 5) → **[1, 2, 4, 5]**
// |       |   └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 4], 5) → **[1, 2, 4]**
// |       |
// |       └── Exclude 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 2], 5)
// |           |
// |           ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2, 5], 5) → **[1, 2, 5]**
// |           └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 2], 5) → **[1, 2]**
// |
// └── Exclude 2: subsequencing(2, {1, 2, 3, 4, 5}, [1], 5)
//     |
//     ├── Include 3: subsequencing(3, {1, 2, 3, 4, 5}, [1, 3], 5)
//     |   |
//     |   ├── Include 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 3, 4], 5)
//     |   |   |
//     |   |   ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 3, 4, 5], 5) → **[1, 3, 4, 5]**
//     |   |   └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 3, 4], 5) → **[1, 3, 4]**
//     |   |
//     |   └── Exclude 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 3], 5)
//     |       |
//     |       ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 3, 5], 5) → **[1, 3, 5]**
//     |       └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 3], 5) → **[1, 3]**
//     |
//     └── Exclude 3: subsequencing(3, {1, 2, 3, 4, 5}, [1], 5)
//         |
//         ├── Include 4: subsequencing(4, {1, 2, 3, 4, 5}, [1, 4], 5)
//         |   |
//         |   ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 4, 5], 5) → **[1, 4, 5]**
//         |   └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 4], 5) → **[1, 4]**
//         |
//         └── Exclude 4: subsequencing(4, {1, 2, 3, 4, 5}, [1], 5)
//             |
//             ├── Include 5: subsequencing(5, {1, 2, 3, 4, 5}, [1, 5], 5) → **[1, 5]**
//             └── Exclude 5: subsequencing(5, {1, 2, 3, 4, 5}, [1], 5) → **[1]**
