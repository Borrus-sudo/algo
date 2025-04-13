# 📦 Ultimate C++ STL Reference Guide

AI generated ofc

---

## 📦 STL Containers — Time Complexities + Code + Underlying Structures

| Data Structure (Underlying) | **Access**<br>🕒 + 💻 | **Search**<br>🕒 + 💻 | **Insert**<br>🕒 + 💻 | **Delete**<br>🕒 + 💻 |
|-----------------------------|-----------------------|-----------------------|-----------------------|-----------------------|
| `int arr[5]` *(static array)* | `O(1)` → `arr[2];` | `O(n)` → `loop` | ❌ fixed size | ❌ fixed size |
| `new int[n]` *(heap array)* | `O(1)` → `arr[2];` | `O(n)` → `loop` | `O(1)` → `arr[i] = x;` | `delete[] arr;` |
| `vector<int>` *(dynamic array)* | `O(1)` → `v[2];` | `O(n)` → `find(...)` | `O(1)` amortized → `v.push_back(x);` | `O(n)` → `v.erase(pos);` |
| `list<int>` *(doubly linked list)* | ❌ → No index access | `O(n)` → `find(...)` | `O(1)` → `l.push_front(x);` | `O(1)` if iterator → `l.erase(it);` |
| `deque<int>` *(double-ended array)* | `O(1)` → `dq[2];` | `O(n)` | `O(1)` → `push_front/back` | `O(1)` → `pop_front/back` |
| `stack<int>` *(vector/deque)* | `O(1)` → `s.top();` | ❌ no search | `O(1)` → `s.push(x);` | `O(1)` → `s.pop();` |
| `queue<int>` *(deque/list)* | `O(1)` → `q.front();` | ❌ no search | `O(1)` → `q.push(x);` | `O(1)` → `q.pop();` |
| `map<int, string>` *(red-black tree)* | `O(log n)` → `m[k];` | `O(log n)` → `m.find(k)` | `O(log n)` → `m[k] = val;` | `O(log n)` → `m.erase(k);` |
| `multimap<int, string>` *(red-black tree)* | ❌ → no operator[] | `O(log n)` | `O(log n)` → `mm.insert(...)` | `O(log n)` → `mm.erase(it);` |
| `unordered_map<int, string>` *(hash table)* | `O(1)` avg → `um[k];` | `O(1)` avg | `O(1)` avg | `O(1)` avg |
| `set<int>` *(red-black tree)* | ❌ | `O(log n)` → `s.find(k)` | `O(log n)` → `s.insert(k)` | `O(log n)` → `s.erase(k)` |
| `unordered_set<int>` *(hash table)* | ❌ | `O(1)` avg | `O(1)` avg | `O(1)` avg |
| `multiset<int>` *(red-black tree)* | ❌ | `O(log n)` | `O(log n)` | `O(log n)` |
| `unordered_multiset<int>` *(hash table)* | ❌ | `O(1)` avg | `O(1)` avg | `O(1)` avg |
| `bitset<8>` *(bit array)* | `O(1)` → `bs[2];` | `O(1)` → `bs.test(2);` | `O(1)` → `bs.set(2);` | `O(1)` → `bs.reset(2);` |
| `string` *(dynamic char array)* | `O(1)` → `s[2];` | `O(n)` → `s.find("hi");` | `O(1)` → `+= "x";` | `O(n)` → `s.erase(...)` |
| `tuple<int, char>` *(fixed struct)* | `O(1)` → `get<0>(t);` | ❌ | `make_tuple(...)` | ❌ |
| `pair<int, int>` *(fixed struct)* | `O(1)` → `p.first;` | ❌ | `make_pair(...)` | ❌ |

---

## 🔁 Iterator Support Table

| Container | `begin()` / `end()` | `rbegin()` / `rend()` | `cbegin()` / `cend()` | ❌ Not Possible |
|----------|----------------------|------------------------|------------------------|----------------|
| `int arr[]` | ✅ (via pointers) | ❌ | ❌ | reverse, const iterators |
| `vector` | ✅ | ✅ | ✅ | — |
| `deque` | ✅ | ✅ | ✅ | — |
| `list` | ✅ | ✅ | ✅ | — |
| `stack` | ❌ | ❌ | ❌ | all iterators |
| `queue` | ❌ | ❌ | ❌ | all iterators |
| `map` | ✅ | ✅ | ✅ | — |
| `multimap` | ✅ | ✅ | ✅ | — |
| `unordered_map` | ✅ | ❌ ordered | ✅ | `rbegin()` |
| `set` | ✅ | ✅ | ✅ | — |
| `unordered_set` | ✅ | ❌ ordered | ✅ | `rbegin()` |
| `bitset` | ❌ | ❌ | ❌ | all |
| `string` | ✅ | ✅ | ✅ | — |
| `tuple` | ❌ | ❌ | ❌ | all |
| `pair` | ❌ | ❌ | ❌ | all |

---

## 🧰 Container Utility Method Support

| Container | `.size()` | `.empty()` | `.clear()` | `.resize()` | `.assign()` | `.swap()` |
|----------|-----------|------------|-------------|-------------|--------------|-----------|
| `array` | ❌ | ❌ | ❌ | ❌ | ❌ | ❌ |
| `vector` | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| `deque` | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| `list` | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| `stack` | ✅ | ✅ | ❌ | ❌ | ❌ | ✅ |
| `queue` | ✅ | ✅ | ❌ | ❌ | ❌ | ✅ |
| `map` | ✅ | ✅ | ✅ | ❌ | ❌ | ✅ |
| `multimap` | ✅ | ✅ | ✅ | ❌ | ❌ | ✅ |
| `unordered_map` | ✅ | ✅ | ✅ | ❌ | ❌ | ✅ |
| `set` | ✅ | ✅ | ✅ | ❌ | ❌ | ✅ |
| `unordered_set` | ✅ | ✅ | ✅ | ❌ | ❌ | ✅ |
| `bitset` | `.size()` | `none()` | `reset()` | ❌ | ❌ | ❌ |
| `string` | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

---

## ⚙️ STL Algorithms Overview

| Algorithm | Purpose | Time | Code Example | ❌ Not Supported |
|----------|---------|------|---------------|-----------------|
| `sort()` | Sort range | O(n log n) | `sort(v.begin(), v.end());` | `set`, `map` (auto-sorted) |
| `reverse()` | Reverse range | O(n) | `reverse(v.begin(), v.end());` | `stack`, `queue` |
| `unique()` | Remove duplicates (consecutive) | O(n) | `v.erase(unique(...), v.end());` | `set`, `map` (no dupes) |
| `count()` | Count value | O(n) | `count(v.begin(), v.end(), x);` | — |
| `find()` | Find first match | O(n) | `find(v.begin(), v.end(), x);` | `unordered_map` needs `um.find(x)` |
| `accumulate()` | Sum values | O(n) | `accumulate(v.begin(), v.end(), 0);` | — |
| `lower_bound()` | First ≥ x | O(log n) | `lower_bound(v.begin(), v.end(), x);` | unsorted containers |
| `upper_bound()` | First > x | O(log n) | `upper_bound(v.begin(), v.end(), x);` | unsorted containers |
| `binary_search()` | Exists or not | O(log n) | `binary_search(v.begin(), v.end(), x);` | unsorted containers |
| `next_permutation()` | Lex next perm | O(n) | `next_permutation(v.begin(), v.end());` | `set`, `map` |
| `all_of()` | Check all match cond | O(n) | `all_of(v.begin(), v.end(), pred);` | — |

---

## ✅ Bonus: Example STL Usages

```cpp
vector<int> v = {1, 2, 3, 4};
sort(v.begin(), v.end());               // ascending
reverse(v.begin(), v.end());            // reverse
v.erase(unique(v.begin(), v.end()), v.end()); // remove consecutive duplicates
int sum = accumulate(v.begin(), v.end(), 0);  // total sum
