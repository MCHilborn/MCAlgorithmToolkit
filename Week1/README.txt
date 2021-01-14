Maximum Pairwise product
Finds the product of the two largest elements in a vector
Stresstest deals with n random elements with seed s.
Three methods of solving this are compared: A trivial solution, and a slightly faster solution, and a solution that is even faster.
The trivial solution compares the product of all the elements against eachother and picks the largest value.
The faster solution finds the two largest numbers in the vector and returns the product, for a total of 2n-1 comparisons.
The fastest solution divides each pair of elements (2*i) and (2*i+1) such that (2*i)>(2*i+1) and then only compares the (2*i) elements with the second algorithm, plus the (2*n+1) element of the largest found number for a total of 1.5n+1 comparisons.
