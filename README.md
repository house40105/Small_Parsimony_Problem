# Small_Parsimony_Problem

### Introduction
This C program (`Small_Parsimony_Problem.c`) addresses the Small Parsimony Problem, a fundamental problem in computational biology, where the goal is to reconstruct an ancestral DNA sequence given a phylogenetic tree and the DNA sequences of its leaves. The program reads an input file containing a tree in Newick format and performs the Small Parsimony algorithm to find the most parsimonious assignment of nucleotides at each internal node of the tree.

### Features
- **Input Reading:** The program reads the input tree from a file in Newick format, where each node is labeled with a unique index and a character representing a nucleotide (A, T, C, or G).
- **Small Parsimony Algorithm:** The Small Parsimony algorithm is applied to the input tree, assigning nucleotides to internal nodes to minimize the total score of changes in the tree.
- **Output Generation:** The program generates an output file (`output.txt`) containing the reconstructed ancestral sequences for each internal node, along with the total score of changes in the tree.
- **Console Output:** Additional information is printed to the console, including the reconstructed sequences, adjacency matrix, and total score.

### Input Format
The input file (`1.txt`) should contain a tree in Newick format with node indices and nucleotide labels, as follows:
```
1A
2A3C
4T5G
...
```

### Usage
1. Compile the program:
```sh
gcc small_parsimony.c -o small_parsimony
```
2. Run the program:
```sh
./small_parsimony
```
3. Review the output in the output.txt file.



### Example Output
The output file (`output.txt`) will contain information about each internal node's reconstructed sequence and the total score.
```
1,A 2,C 3,G 
2,A 4,T 5,G 
Total score: 3
```

### Conclusion
This Small Parsimony Problem solver provides a tool for reconstructing ancestral DNA sequences based on a given phylogenetic tree. The output file and console messages offer insights into the reconstructed sequences and the total score of changes in the tree. If you encounter any issues or have suggestions for improvement, please feel free to open an issue or contribute to the codebase.

**Note:** Ensure that the input file (`1.txt`) is correctly formatted, following the specified Newick format, for accurate results.
