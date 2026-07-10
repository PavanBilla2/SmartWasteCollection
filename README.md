# SmartWasteCollection
# ♻️ Smart Waste Collection Route Optimizer

A C++-based Smart Waste Collection Route Optimizer that models a city's road network as a weighted graph and generates an optimized waste collection route using **Graph Data Structures**, **Dijkstra's Shortest Path Algorithm**, and a **Greedy Route Optimization** approach.

---

## 📌 Project Overview

Efficient waste collection is an important challenge in modern smart cities. This project helps optimize the route of a garbage collection truck by finding the shortest paths between waste collection points and selecting the next nearest unvisited location using a greedy strategy.

The project demonstrates the practical application of Data Structures and Algorithms (DSA) in solving real-world logistics and route optimization problems.

---

## ✨ Features

- 🛣️ Create a weighted road network using Graphs
- 📍 Represent waste collection points as graph vertices
- 🔗 Add roads with distances as weighted edges
- 🌐 Display the complete road network
- 🔍 Check network connectivity using BFS
- 🌲 Traverse the graph using DFS
- 🚀 Find shortest paths using Dijkstra's Algorithm
- 🚛 Optimize the waste collection route using a Greedy Algorithm
- 🏠 Return the truck to the starting depot
- 📊 Generate a collection report with:
  - Optimized Route
  - Total Distance
  - Number of Waste Bins Covered
  - Estimated Fuel Consumption
  - Estimated Collection Time
- ⚠️ Handle disconnected road networks gracefully

---

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Graph Data Structure
- Standard Template Library (STL)
- Visual Studio Code
- MinGW (G++ Compiler)

---

## 📚 Algorithms Used

### Breadth First Search (BFS)
- Used to verify whether all waste bins are reachable from the starting depot.

### Depth First Search (DFS)
- Used for graph traversal and exploration.

### Dijkstra's Algorithm
- Calculates the shortest path from the current location to all other waste bins.

### Greedy Algorithm
- Selects the nearest unvisited waste bin at each step to generate an optimized collection route.

---

## 📂 Project Structure

```
Smart-Waste-Collection-Route-Optimizer
│
├── include
│   ├── Graph.h
│   └── DijkstraResult.h
│
├── src
│   ├── Graph.cpp
│   └── main.cpp
│
├── website
│   └── SmartWasteCollection.html
│
├── images
│
├── README.md
└── LICENSE
```

---

## ▶️ How to Run

### Compile

```bash
g++ src/main.cpp src/Graph.cpp -Iinclude -o SmartWasteCollection
```

### Execute

Windows

```bash
SmartWasteCollection.exe
```

Linux / macOS

```bash
./SmartWasteCollection
```

---

## 📊 Sample Output

```
========== SMART WASTE COLLECTION ==========

Starting Bin : 1

Optimized Route :
1 -> 3 -> 4 -> 2 -> 5 -> 1

Total Distance : 29 km

Waste Bins Covered : 5

Collection Status : SUCCESS
```

---

## 🚀 Future Enhancements

- Interactive web dashboard
- Live map visualization
- Animated garbage truck movement
- Database integration
- Real-time traffic support
- GPS integration
- IoT-enabled smart waste bins
- Multi-truck route optimization

---

## 🎯 Learning Outcomes

This project demonstrates practical implementation of:

- Graph Data Structures
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Dijkstra's Algorithm
- Greedy Algorithms
- Object-Oriented Programming
- Route Optimization
- Problem Solving using DSA

---

## 👨‍💻 Author

**Pavan Billa**

Computer Science Engineering Student

Interested in:
- Data Structures & Algorithms
- Data Analytics
- Artificial Intelligence
- Software Development

---

## 📄 License

This project is licensed under the MIT License.
