<h1>C Programming Interview Questions</h1>
<h2>1. What is the difference between a compiler and an interpreter?</h2>
<p>A compiler translates the entire program into machine code before execution, while an interpreter translates and executes the program line by line.</p>
<h2>2. What is the difference between "malloc" and "calloc" functions in C?</h2>
<p>"malloc" is used to dynamically allocate memory, while "calloc" is used to dynamically allocate memory and initialize it to zero.</p>
<h2>3. Explain the concept of pointers in C.</h2>
<p>Pointers in C are variables that store memory addresses. They allow direct manipulation of memory, dynamic memory allocation, and efficient access to data structures.</p>
<h2>4. What are the storage classes in C? Explain each one.</h2>
<p>In C, there are four storage classes: auto, register, static, and extern. The "auto" class is the default and is used for local variables. "Register" is used for variables that should be stored in registers. "Static" is used for variables that retain their values across function calls. "Extern" is used for variables that are defined in other files.</p>
<h2>5. What is the purpose of the "const" keyword in C?</h2>
<p>The "const" keyword in C is used to declare constants. It ensures that the value of the variable cannot be modified once it is assigned.</p>
<h2>6. Explain the concept of structures in C.</h2>
<p>Structures in C are user-defined data types that allow grouping related variables together. They can contain variables of different data types and enable the creation of complex data structures.</p>
<h2>7. What is the difference between "scanf" and "printf" functions in C?</h2>
<p>"scanf" is used for reading input from the user, while "printf" is used for displaying output to the user. They both use format specifiers to specify the type and format of the data being read or printed.</p>
<h2>8. What is the purpose of the "sizeof" operator in C?</h2>
<p>The "sizeof" operator in C is used to determine the size (in bytes) of a data type or variable. It is often used to allocate memory dynamically and perform type checking.</p>
<h2>9. Explain the concept of dynamic memory allocation in C.</h2>
<p>Dynamic memory allocation in C allows programs to allocate and deallocate memory during runtime. It involves using functions like "malloc", "calloc", and "realloc" to allocate memory on the heap and "free" to deallocate it.</p>
<h2>10. How do you swap two variables without using a temporary variable in C?</h2>
<p>To swap two variables without using a temporary variable, you can use arithmetic or bitwise operations. One common approach is using the XOR (^) operator.</p>
<h2>11. What is the difference between "++i" and "i++" in C?</h2>
<p>The "++i" is the pre-increment operator, which increments the value of "i" and then returns the incremented value. The "i++" is the post-increment operator, which returns the current value of "i" and then increments it.</p>
<h2>12. How do you find the length of a string in C?</h2>
<p>You can use the "strlen" function from the "string.h" library to find the length of a string in C.</p>
<h2>13. What is a function prototype in C?</h2>
<p>A function prototype in C declares the function name, return type, and parameters without providing the function body. It allows the compiler to perform type checking and detect errors before the actual function definition.</p>
<h2>14. Explain the "switch" statement in C.</h2>
<p>The "switch" statement in C allows multi-way branching based on the value of an expression. It provides an alternative to using multiple "if-else" statements. Each "case" represents a possible value, and the corresponding block of code is executed if the value matches.</p>
<h2>15. What is the purpose of the "break" statement in C?</h2>
<p>The "break" statement in C is used to exit from a loop or switch statement. It allows you to terminate the current iteration or switch case and continue executing the code after the loop or switch block.</p>
<h2>16. Explain the concept of file handling in C.</h2>
<p>File handling in C involves reading from and writing to files. It allows programs to store and retrieve data persistently. C provides functions like "fopen", "fclose", "fread", "fwrite", etc., for file operations.</p>
<h2>17. What are the bitwise operators in C?</h2>
<p>The bitwise operators in C perform operations on individual bits of integer operands. The bitwise operators include AND (&), OR (|), XOR (^), left shift (<<), right shift (>>), and complement (~).</p>
<h2>18. Explain the concept of recursion in C.</h2>
<p>Recursion is a technique where a function calls itself. It allows solving complex problems by breaking them into simpler subproblems. Recursion requires a base case to stop the recursive calls.</p>
<h2>19. How do you reverse a string in C?</h2>
<p>You can reverse a string in C by swapping the characters from the beginning and end of the string until you reach the middle. Alternatively, you can use library functions like "strrev" from the "string.h" library.</p>
<h2>20. What is the purpose of the "typedef" keyword in C?</h2>
<p>The "typedef" keyword in C is used to create user-defined data type aliases. It allows you to define a new name for an existing data type, making the code more readable and easier to maintain.</p>

<h2>21. What is the purpose of the "typedef" keyword in C?</h2>
<p>The "typedef" keyword in C is used to create user-defined data type aliases. It allows you to define a new name for an existing data type, making the code more readable and easier to maintain.</p>
<h2>22. What are the different types of loops available in C?</h2>
<p>In C, there are three types of loops: "for", "while", and "do-while". The "for" loop is used when the number of iterations is known. The "while" loop is used when the number of iterations is not known in advance. The "do-while" loop is similar to the "while" loop but guarantees the execution of the loop body at least once.</p>
<h2>23. Explain the concept of dynamic memory allocation in C.</h2>
<p>Dynamic memory allocation in C allows programs to allocate and deallocate memory during runtime. It involves using functions like "malloc", "calloc", and "realloc" to allocate memory on the heap and "free" to deallocate it.</p>
<h2>24. What is the purpose of the "enum" keyword in C?</h2>
<p>The "enum" keyword in C is used to define an enumerated data type. It allows you to create a set of named constants, also known as enumerators, which can be used to represent a set of related values.</p>
<h2>25. What is the purpose of the "break" statement in C?</h2>
<p>The "break" statement in C is used to exit from a loop or switch statement. It allows you to terminate the current iteration or switch case and continue executing the code after the loop or switch block.</p>
<h2>26. How do you find the largest and smallest elements in an array in C?</h2>
<p>To find the largest and smallest elements in an array in C, you can iterate through the array and compare each element with the current largest and smallest values. Update the largest and smallest values accordingly.</p>
<h2>27. Explain the concept of function pointers in C.</h2>
<p>Function pointers in C are variables that store the address of functions. They allow passing functions as arguments to other functions, storing them in data structures, and invoking them dynamically at runtime.</p>

<h2>28. Explain the concept of recursion in C.</h2>
<p>Recursion is a technique where a function calls itself. It allows solving complex problems by breaking them into simpler subproblems. Recursion requires a base case to stop the recursive calls.</p>

<h2>29. What is the difference between a structure and union in C?</h2>
<p>
A structure is a user-defined data type that can contain multiple variables of different types. A union, on the other hand, can hold variables of different types but shares the same memory space, allowing only one member to be active at a time.
</p>

<h2>30. String arrays</h2>
<pre>
<code>
    int a = 1;
    int* ptr = &a;
</code>
</pre>