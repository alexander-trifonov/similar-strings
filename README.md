# similar-strings
## Solved problems:
1. Generating large files fast
  - Multithread implementation
  - Singlethread implementation (faster)
2. Reading a large file into one string fast
  - Not used, because not necessary
3. Levenshtein Distance with limited memory usage (x10 of file size)
  - Matrix using implementation (fast, low memory usage)  
  - Recursive implementation (very slow, lower memory usage)

## Instructions:
`SimilarStringsMemory.exe <filepath> <targetString>`  
* filepath - path to file with strings separted by '\n'
* targetString - a string used to search similar strings to it  
Running example: 
`SimilarStringsMemory.exe input.txt pqwns`  

Or run without arguments:
1. Generate file, answering 'y' or use generated file after 'n';
2. Write a string to search in the file

Input:
```sh
[[ File generation ]]
Generate a new file, named 'input.txt'? y/n: y
...
[[ Searching a string ]]
To help you, you can write one of these first strings in the file:
* pqwns
* feqp
Enter string to search: pqwns
```
Output:
```sh
Target string to search: pqwns
Maximum number of changes allowed: 3
Done in: 6924ms
Memory used: 317840KB
Found more than 15 strings, displaying first 15:
Output:
pqwns
ppwj
mqln
hpwn
xqbn
picn
pqjk
pmcn
qqwo
pkdn
phwr
kqwa
kqun
pqwc
owns
```
