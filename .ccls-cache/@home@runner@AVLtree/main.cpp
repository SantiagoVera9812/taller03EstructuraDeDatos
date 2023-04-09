// C++ program to insert a node in AVL tree
#include <bits/stdc++.h>
#include "AVL.h"
#include "funcionalidades.h"
// An AVL tree node

// Driver Code
int main()
{ 

	AVL tr;
	/* Constructing tree given in
	the above figure */

  std::ifstream file("entrada.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file\n";
        return 1;
    }

    char c;
    int num;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> c >> num) {
            // do something with c and num
            std::cout << "Char: " << c << " Integer: " << num << std::endl;

          if(c == 'A'){

            tr.insertar(num);
          }
        }
    }

    file.close();
	
	std::cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	tr.mostrar();

  int numeroNodos;

  numeroNodos = contarNodos(tr);

  std::cout<<numeroNodos<<std::endl;

  int kmall;

  kmall = KthSmallest(tr, 3); 
  
  std::cout<<kmall<<std::endl;

  double mediana;
  mediana = findMedian(tr);
  std::cout<<mediana<<std::endl;
	return 0;
}

